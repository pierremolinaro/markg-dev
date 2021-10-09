//---------------------------------------------------------------------------*
//                                                                           *
//     AEDD package                                                          *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2003, 2004 Pierre Molinaro and Cedric Motsch.              *
//  Copyright (C) 2005, ..., 2009 Pierre Molinaro.                           *
//                                                                           *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
//                                                                           *
//  IRCCyN, Institut de Recherche en Communications et Cybernetique de Nantes*
//  ECN, Ecole Centrale de Nantes (France)                                   *
//                                                                           *
//  This library is free software; you can redistribute it and/or modify it  *
//  under the terms of the GNU Lesser General Public License as published    *
//  by the Free Software Foundation; either version 2 of the License, or     *
//  (at your option) any later version.                                      *
//                                                                           *
//  This program is distributed in the hope it will be useful, but WITHOUT   *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or    *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for *
//  more details.                                                            *
//                                                                           *
//---------------------------------------------------------------------------*

#include "C_AEDD.h"
#include "utilities/F_GetPrime.h"
#include "C_AEDDPrimeCache2.h"
#include "streams/C_ConsoleOut.h"
#include "strings/C_String.h"

//---------------------------------------------------------------------------*

#include <string.h>

//---------------------------------------------------------------------------*
//                                                                           *
//  And computation cache                                                    *
//                                                                           *
//---------------------------------------------------------------------------*

static C_AEDDPrimeCache2 gAndOperationCache (150000) ;  // select a prime greater than this value

//---------------------------------------------------------------------------*
//                                                                           *
//                    Taille initiale des tables                             *
//                                                                           *
//---------------------------------------------------------------------------*

static const int32_t kInitialHashMapSize = 4099UL ;

//---------------------------------------------------------------------------*
//                                                                           *
//            Declaration de la classe 'C_AEDDnode'                          *
//               definissant un element d'un AEDD                            *
//                                                                           *
//---------------------------------------------------------------------------*

//---------------------------------------------------------------------------*
//                                                                           *
//  AEDD objects collision map : an AVL tree                                 *
//                                                                           *
//---------------------------------------------------------------------------*

class cBDDcollisionsMap {
  public : C_AEDD::C_AEDDnode * mRoot ;
  public : cBDDcollisionsMap (void) :
    mRoot (NULL) {
  }
} ;

//---------------------------------------------------------------------------*

//--- Allocation information (BDD nodes are block-allocated for efficiency)
class cAllocInfo {
  public : char * * mAllocatedBlockList ;
  public : size_t mAllocatedBlockListSize ;
  public : size_t mAllocatedBlockCount ;
  public : C_AEDD::C_AEDDnode * mFreeList ;
  public : size_t mAllocatedObjectsCount ;
  public : size_t mCreatedObjectsCount ;
  public : cAllocInfo (void) :
    mAllocatedBlockList (NULL),
    mAllocatedBlockListSize (0),
    mAllocatedBlockCount (0),
    mFreeList (NULL),
    mAllocatedObjectsCount (0),
    mCreatedObjectsCount (0) {
   }
} ;

//---------------------------------------------------------------------------*

static cAllocInfo gBDDallocationInfo ;

//---------------------------------------------------------------------------*

//--- cBDDnodes instances allocation quantum (in kbytes)
static const int32_t kBlockSize = 640000 ;

//---------------------------------------------------------------------------*

static void allocBlock (void) {
//--- Realloc block list ?
  if (gBDDallocationInfo.mAllocatedBlockListSize <= gBDDallocationInfo.mAllocatedBlockCount) {
    const size_t newSize = gBDDallocationInfo.mAllocatedBlockCount + 1024 ;
    char ** newBlockList = new char * [newSize] ;
    for (size_t i=0 ; i<gBDDallocationInfo.mAllocatedBlockCount ; i++) {
      newBlockList [i] = gBDDallocationInfo.mAllocatedBlockList [i] ;
    }
    delete [] gBDDallocationInfo.mAllocatedBlockList ;
    gBDDallocationInfo.mAllocatedBlockList = newBlockList ;
    gBDDallocationInfo.mAllocatedBlockListSize = newSize ;
  }
//--- Alloc block
  gBDDallocationInfo.mAllocatedBlockList [gBDDallocationInfo.mAllocatedBlockCount] = new char [kBlockSize] ;
  char * ptr = & (gBDDallocationInfo.mAllocatedBlockList [gBDDallocationInfo.mAllocatedBlockCount] [0]) ;
  gBDDallocationInfo.mAllocatedBlockCount ++ ;
  size_t blockSize = kBlockSize ;
  const size_t ALIGNMENT = 32 ;
//--- Align pointer
  if ((size_t (ptr) % ALIGNMENT) != 0) {
    ptr = (char *) (((size_t (ptr) / ALIGNMENT) + 1) * ALIGNMENT) ;
    blockSize -= ALIGNMENT ;
  }
  const size_t nbNewObjects = blockSize / sizeof (C_AEDD::C_AEDDnode) ;
  for (size_t i=0 ; i<nbNewObjects ; i++) {
    C_AEDD::C_AEDDnode * newObjectPtr = (C_AEDD::C_AEDDnode *) ptr ;
    newObjectPtr->mPtrToSup = gBDDallocationInfo.mFreeList ;
    gBDDallocationInfo.mFreeList = newObjectPtr ;
    ptr += sizeof (C_AEDD::C_AEDDnode) ;
  }
  gBDDallocationInfo.mCreatedObjectsCount += nbNewObjects ;
}

//---------------------------------------------------------------------*

void * C_AEDD::C_AEDDnode::operator new (const size_t /*inByteSize*/) {
  if (gBDDallocationInfo.mFreeList == NULL) {
    allocBlock () ;
  }
  gBDDallocationInfo.mAllocatedObjectsCount ++ ;
  C_AEDDnode * result = gBDDallocationInfo.mFreeList ;
  gBDDallocationInfo.mFreeList = gBDDallocationInfo.mFreeList->mPtrToSup ;
  return result ;
}

//---------------------------------------------------------------------*

void C_AEDD::C_AEDDnode::operator delete (void * inPtr) {
  C_AEDDnode * p = (C_AEDDnode *) inPtr ;
  p->mPtrToSup = gBDDallocationInfo.mFreeList ;
  gBDDallocationInfo.mFreeList = p ;
  gBDDallocationInfo.mAllocatedObjectsCount -- ;
  if (gBDDallocationInfo.mAllocatedObjectsCount == 0) {
    for (size_t i=0 ; i<gBDDallocationInfo.mAllocatedBlockCount ; i++) {
      delete [] gBDDallocationInfo.mAllocatedBlockList [i] ;
    }
    delete [] gBDDallocationInfo.mAllocatedBlockList ;
    gBDDallocationInfo.mAllocatedBlockList = (char * *) NULL ;
    gBDDallocationInfo.mAllocatedBlockCount = 0 ;
    gBDDallocationInfo.mAllocatedBlockListSize = 0 ;
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//  BDD objects hash map                                                     *
//                                                                           *
//---------------------------------------------------------------------------*

static cBDDcollisionsMap * gMap = new cBDDcollisionsMap [kInitialHashMapSize] ;
static size_t gHashMapSize = kInitialHashMapSize ;

//---------------------------------------------------------------------*

uint32_t C_AEDD::C_AEDDnode::smComparisonsCount = 0UL ;

//---------------------------------------------------------------------*
//                                                                     *
//       Get BDD node pointer                                          *
//                                                                     *
//---------------------------------------------------------------------*


static inline C_AEDD::C_AEDDnode * getAEDDnodePointer (const intptr_t inValue) {
  return (C_AEDD::C_AEDDnode *) (inValue & -2) ;
}

//---------------------------------------------------------------------*
//                                                                     *
//       Implementation de la table des elements BDD existants         *
//                                                                     *
//---------------------------------------------------------------------*

int32_t C_AEDD::getAEDDnodeSize (void) {
  return (int32_t) sizeof (C_AEDDnode) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       BDD unique table implementation                                     *
//                                                                           *
//---------------------------------------------------------------------------*

static inline void rotateLeftBDDnode (C_AEDD::C_AEDDnode * & ioPtr) {
//--- Rotate 
  C_AEDD::C_AEDDnode * ptr = ioPtr->mPtrToSup ;
  ioPtr->mPtrToSup = ptr->mPtrToInf ;
  ptr->mPtrToInf = ioPtr ;
//--- Update balance 
  if (ptr->mBalance < 0) {
    ioPtr->mBalance = (int8_t) (ioPtr->mBalance - ptr->mBalance) ;
  }
  ioPtr->mBalance ++ ;
  if (ioPtr->mBalance > 0) {
    ptr->mBalance = (int8_t) (ioPtr->mBalance + ioPtr->mBalance) ;
  }
  ptr->mBalance ++ ;
  ioPtr = ptr ;
}

//---------------------------------------------------------------------------*

static inline void rotateRightBDDnode (C_AEDD::C_AEDDnode * & ioPtr) {
//--- Rotate 
  C_AEDD::C_AEDDnode * ptr = ioPtr->mPtrToInf ;
  ioPtr->mPtrToInf = ptr->mPtrToSup ;
  ptr->mPtrToSup = ioPtr ;
//--- Update balance 
  if (ptr->mBalance > 0) {
    ioPtr->mBalance = (int8_t) (ioPtr->mBalance - ptr->mBalance) ;
  }
  ioPtr->mBalance -- ;
  if (ioPtr->mBalance < 0) {
    ptr->mBalance = (int8_t) (ioPtr->mBalance + ioPtr->mBalance) ;
  }
  ptr->mBalance -- ;
  ioPtr = ptr ;
}
 
//---------------------------------------------------------------------------*

static C_AEDD::C_AEDDnode *
recursive_find_or_add (C_AEDD::C_AEDDnode * & ioRootPointer,
                       const intptr_t inBranch0,
                       const intptr_t inBranch1,
                       const uint16_t inVar,
                       const intptr_t inValue,
                       bool & outExtension) {
  C_AEDD::C_AEDDnode * result ;
  if (ioRootPointer == NULL) {
    ioRootPointer = new C_AEDD::C_AEDDnode (inBranch0, inBranch1, inVar, inValue) ;
    result = ioRootPointer ;
    outExtension = true ;
  }else{
    const intptr_t comp = ioRootPointer->compare (inBranch0, inBranch1, inVar, inValue) ;
    if (comp > 0) {
      result = recursive_find_or_add
                 (ioRootPointer->mPtrToSup, inBranch0, inBranch1, inVar, inValue, outExtension) ;
      if (outExtension) {
        ioRootPointer->mBalance -- ;
        switch (ioRootPointer->mBalance) {
        case 0:
          outExtension = false;
          break;
        case -1:
          break;
        case -2:
          if (ioRootPointer->mPtrToSup->mBalance == 1) {
            ::rotateRightBDDnode (ioRootPointer->mPtrToSup) ;
          }
          ::rotateLeftBDDnode (ioRootPointer) ;
          outExtension = false;
          break;
        default :
          break ;
        }
      }
    }else if (comp < 0) {
      result = recursive_find_or_add
                 (ioRootPointer->mPtrToInf, inBranch0, inBranch1, inVar, inValue, outExtension) ;
      if (outExtension) {
        ioRootPointer->mBalance ++ ;
        switch (ioRootPointer->mBalance) {
        case 0:
          outExtension = false;
          break;
        case 1:
          break;
        case 2:
          if (ioRootPointer->mPtrToInf->mBalance == -1) {
            ::rotateLeftBDDnode (ioRootPointer->mPtrToInf) ;
          }
          ::rotateRightBDDnode (ioRootPointer) ;
          outExtension = false;
          break;
        default :
          break ;
        }
      }
    }else{ // Found
      result = ioRootPointer ;
      outExtension = false;
    }
  }
  return result ;
}

//---------------------------------------------------------------------*

static intptr_t
find_or_add (const uint16_t inVar,
             const intptr_t inValue,
             const intptr_t inBranch0,
             const intptr_t inBranch1) {
  intptr_t result = inBranch0 ;
  if (inBranch0 != inBranch1) {
    const intptr_t complement = inBranch0 & 1 ;
    const intptr_t c0 = inBranch0 ^ complement ;
    const intptr_t c1 = inBranch1 ^ complement ;
    const uint32_t hashCode = C_AEDD::C_AEDDnode::getHashCodeForMap (c0, c1, inVar, inValue, gHashMapSize) ;
    bool extension = false ;
    result = complement ^
      (intptr_t)  recursive_find_or_add (gMap [hashCode].mRoot,
                                       c0, c1, inVar, inValue,
                                       extension) ;
  }
  return result ;
}

//---------------------------------------------------------------------*

static void
recursiveInsertBDDnode (C_AEDD::C_AEDDnode * & ioRootPointer,
                        C_AEDD::C_AEDDnode * inElementPointer,
                        bool & outExtension) {
  if (ioRootPointer == NULL) {
    ioRootPointer = inElementPointer ;
    inElementPointer->mPtrToInf = (C_AEDD::C_AEDDnode *) NULL ;
    inElementPointer->mPtrToSup = (C_AEDD::C_AEDDnode *) NULL ;
    inElementPointer->mBalance = 0 ;
    outExtension = true ;
  }else{
    const intptr_t comp = ioRootPointer->compare (* inElementPointer) ;
    if (comp > 0) {
      recursiveInsertBDDnode (ioRootPointer->mPtrToSup, inElementPointer, outExtension) ;
      if (outExtension) {
        ioRootPointer->mBalance -- ;
        switch (ioRootPointer->mBalance) {
        case 0:
          outExtension = false;
          break;
        case -1:
          break;
        case -2:
          if (ioRootPointer->mPtrToSup->mBalance == 1) {
            ::rotateRightBDDnode (ioRootPointer->mPtrToSup) ;
          }
          ::rotateLeftBDDnode (ioRootPointer) ;
          outExtension = false;
          break;
        default :
          break ;
        }
      }
    }else if (comp < 0) {
      recursiveInsertBDDnode (ioRootPointer->mPtrToInf, inElementPointer, outExtension) ;
      if (outExtension) {
        ioRootPointer->mBalance ++ ;
        switch (ioRootPointer->mBalance) {
        case 0:
          outExtension = false;
          break;
        case 1:
          break;
        case 2:
          if (ioRootPointer->mPtrToInf->mBalance == -1) {
            ::rotateLeftBDDnode (ioRootPointer->mPtrToInf) ;
          }
          ::rotateRightBDDnode (ioRootPointer) ;
          outExtension = false;
          break;
        default :
          break ;
        }
      }
    }else{ // Found
      outExtension = false;
    }
  }
}
//---------------------------------------------------------------------*

static void
recursiveTransfertElementsInNewMapArray (C_AEDD::C_AEDDnode * inElementPointer,
                                         cBDDcollisionsMap * inNewMapArray,
                                         const uint32_t inNewSize) {
  if (inElementPointer != NULL) {
    recursiveTransfertElementsInNewMapArray (inElementPointer->mPtrToInf, inNewMapArray, inNewSize) ;
    recursiveTransfertElementsInNewMapArray (inElementPointer->mPtrToSup, inNewMapArray, inNewSize) ;
    inElementPointer->mPtrToInf = (C_AEDD::C_AEDDnode *) NULL ;
    inElementPointer->mPtrToSup = (C_AEDD::C_AEDDnode *) NULL ;
    inElementPointer->mBalance = 0 ;
    const uint32_t hash = C_AEDD::C_AEDDnode::getHashCodeForMap (inElementPointer->mFalseBranch,
                                                       inElementPointer->mTrueBranch,
                                                       inElementPointer->mVar,
                                                       inElementPointer->mConstant,
                                                       inNewSize) ;
    bool extension ; // Unused
    recursiveInsertBDDnode (inNewMapArray [hash].mRoot, inElementPointer, extension) ;
  }
}

//---------------------------------------------------------------------*

void C_AEDD::changeHashMapSize (const uint16_t inSizeInKBytes) {
  const size_t newSize = (getPrimeGreaterThan ((inSizeInKBytes < 1) ? 1 : inSizeInKBytes)) * 1000 ;
  if (newSize != gHashMapSize) {
    cBDDcollisionsMap * newMapArray = new cBDDcollisionsMap [newSize] ;
    for (size_t i=0 ; i<gHashMapSize ; i++) {
      recursiveTransfertElementsInNewMapArray (gMap [i].mRoot, newMapArray, (uint32_t) newSize) ;
      gMap [i].mRoot = (C_AEDDnode *) NULL ;
    }
    delete [] gMap ;
    gMap = newMapArray ;
    gHashMapSize = newSize ;
  }
}

//---------------------------------------------------------------------*

size_t C_AEDD::getHashMapEntriesCount (void) {
  return gHashMapSize ;
}

//---------------------------------------------------------------------*

size_t C_AEDD::getCreatedNodesCount (void) {
  return gBDDallocationInfo.mCreatedObjectsCount ;
}

//------------------------------------------------------------------------*

size_t C_AEDD::getExistingNodesCount (void) {
  return gBDDallocationInfo.mAllocatedObjectsCount ;
}

//---------------------------------------------------------------------*

static C_AEDD * gFirstAEDD = NULL ;
static C_AEDD * gLastAEDD = NULL ;

//------------------------------------------------------------------------*

size_t C_AEDD::getAEDDinstancesCount (void) {
  size_t n = 0 ;
  C_AEDD * p = gFirstAEDD ;
  while (p != NULL) {
    n ++ ;
    p = p->mPtrToNextBDD ;
  }
  return n ;
}

//------------------------------------------------------------------------*

static void internalRecursiveUnmark (C_AEDD::C_AEDDnode * inElement) {
  if (inElement != NULL) {
    inElement->unmark () ;
    internalRecursiveUnmark (inElement->mPtrToInf) ;
    internalRecursiveUnmark (inElement->mPtrToSup) ;
  }
}

//------------------------------------------------------------------------*

void C_AEDD::unmarkAllExistingAEDDnodes (void) {
  for (size_t i=0 ; i<gHashMapSize ; i++) {
    internalRecursiveUnmark (gMap [i].mRoot) ;
  }
}

//------------------------------------------------------------------------*

static int32_t internalMarkedNodeCount (const C_AEDD::C_AEDDnode * const inElement) {
  int32_t result = 0 ;
  if (inElement != NULL) {
    if (inElement->isMarked ()) {
      result ++ ;
    }
    result += internalMarkedNodeCount (inElement->mPtrToInf) ;
    result += internalMarkedNodeCount (inElement->mPtrToSup) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

int32_t C_AEDD::getMarkedNodesCount (void) {
  int32_t count = 0 ;
  for (size_t i=0 ; i<gHashMapSize ; i++) {
    count += internalMarkedNodeCount (gMap [i].mRoot) ;
  }
  return count ;
}

//------------------------------------------------------------------------*

static void markBDDNodes (const intptr_t inValue) {
  C_AEDD::C_AEDDnode * p = getAEDDnodePointer (inValue) ;
  if ((p != NULL) && (! p->isMarked ())) {
    p->mark () ;
    markBDDNodes (p->mTrueBranch) ;
    markBDDNodes (p->mFalseBranch) ;
  }
}

//------------------------------------------------------------------------*

static void internalRecursiveSweep (C_AEDD::C_AEDDnode * inElement,
                                    C_AEDD::C_AEDDnode * & ioRoot) {
  if (inElement != NULL) {
    internalRecursiveSweep (inElement->mPtrToInf, ioRoot) ;
    internalRecursiveSweep (inElement->mPtrToSup, ioRoot) ;
    inElement->mPtrToInf = (C_AEDD::C_AEDDnode *) NULL ;
    inElement->mPtrToSup = (C_AEDD::C_AEDDnode *) NULL ;
    inElement->mBalance = 0 ;
    if (inElement->isMarked ()) {
      inElement->unmark () ;
      bool extension ; // Unused
      recursiveInsertBDDnode (ioRoot, inElement, extension) ;
    }else{
      delete inElement ;
    }
  }
}

//------------------------------------------------------------------------*

void C_AEDD::markAndSweepUnusedNodes  (void) {
//--- Clear operation caches
  gAndOperationCache.clearAllCacheEntries () ;
//--- Effacer tous les champ marquage des elements BDD existants
  unmarkAllExistingAEDDnodes () ;
//--- Marquer tous les elements utilises
  C_AEDD * p = gFirstAEDD ;
  while (p != NULL) {
    markBDDNodes (p->mAEDDvalue) ;
    p = p->mPtrToNextBDD ;
  }
//--- Parcourir la table des elements BDD et recycler ceux qui sont inutilises
  for (size_t i=0 ; i<gHashMapSize ; i++) {
   C_AEDDnode * temporaryRoot = gMap [i].mRoot ;
   gMap [i].mRoot = (C_AEDDnode *) NULL ;
   internalRecursiveSweep (temporaryRoot, gMap [i].mRoot) ;
  }
}

//---------------------------------------------------------------------*

C_AEDD::C_AEDD (void) :
mAEDDvalue (0),
mPtrToPreviousBDD (this),
mPtrToNextBDD (this) {
  initLinks () ;
}

//---------------------------------------------------------------------*

C_AEDD::C_AEDD (const intptr_t inValue) :
mAEDDvalue (inValue),
mPtrToPreviousBDD (this),
mPtrToNextBDD (this) {
  initLinks () ;
}

//---------------------------------------------------------------------*

C_AEDD::C_AEDD (const C_AEDD & inSource) :
mAEDDvalue (inSource.mAEDDvalue),
mPtrToPreviousBDD (this),
mPtrToNextBDD (this) {
  initLinks () ;
}

//---------------------------------------------------------------------*

void C_AEDD::initLinks (void) {
  if (gFirstAEDD == NULL) {
    gLastAEDD = this ;
  }else{
    gFirstAEDD->mPtrToPreviousBDD = this ;
  }
  mPtrToNextBDD = gFirstAEDD ;
  gFirstAEDD = this ;

//  mPtrToPreviousBDD = this ;
//  mPtrToNextBDD = this ;
//  C_AEDD * suivantRacine = gBDDinstancesListRoot.mPtrToNextBDD ;
//  mPtrToPreviousBDD = & gBDDinstancesListRoot ;
//  suivantRacine->mPtrToPreviousBDD = this ;
//  mPtrToNextBDD = suivantRacine ;
//  gBDDinstancesListRoot.mPtrToNextBDD = this ;
}

//---------------------------------------------------------------------*

C_AEDD::~C_AEDD (void) {
  if (mPtrToPreviousBDD == NULL) {
    gFirstAEDD = gFirstAEDD->mPtrToNextBDD ;
  }else{
    mPtrToPreviousBDD->mPtrToNextBDD = mPtrToNextBDD ;
  }
  if (mPtrToNextBDD == NULL) {
    gLastAEDD = gLastAEDD->mPtrToPreviousBDD ;
  }else{
    mPtrToNextBDD->mPtrToPreviousBDD = mPtrToPreviousBDD ;
  }

//  C_AEDD * suivant = mPtrToNextBDD ;
//  C_AEDD * precedent = mPtrToPreviousBDD ;
//  precedent->mPtrToNextBDD = suivant ;
//  suivant->mPtrToPreviousBDD = precedent ;
}

//---------------------------------------------------------------------*

C_AEDD & C_AEDD::operator = (const C_AEDD & inSource) {
  mAEDDvalue = inSource.mAEDDvalue ;
  return *this ;
}

//---------------------------------------------------------------------*
//                                                                     *
//             Internal AND operation                                  *
//                                                                     *
//---------------------------------------------------------------------*

static intptr_t
internalANDoperation (const intptr_t opf, const intptr_t opg) {
  intptr_t f = opf ;
  intptr_t g = opg ;
  #ifdef DEBUG_AND
    printf ("internalANDoperation (0x%lX, 0x%lX)\n", f, g) ; fflush (stdout) ;
  #endif
  intptr_t result ;
//--- Simplification 1 : si f > g, and (f, g) -> and (g, f) ;
  if ( f > g) {
    intptr_t tempo = g ; g = f ; f = tempo ;
  }
//--- Test trivial 1 : and (0, g) -> 0 ;
  if (f == 0) {
    gAndOperationCache.incTrivialOperationsCount () ;
    result = 0 ;
//--- Test trivial 2 : and (1, g) -> g ;
  }else if (f == 1) {
    gAndOperationCache.incTrivialOperationsCount () ;
    result = g ;
//--- Test trivial 3 : and (f, f) -> f ;
  }else if (f == g) {
    gAndOperationCache.incTrivialOperationsCount () ;
    result = g ;
//--- Test trivial 3 : and (f, ~f) -> 0 ;
  }else if ((f ^ g) == 1) {
    gAndOperationCache.incTrivialOperationsCount () ;
    result = 0 ;
//--- Effectuer le calcul
  }else{
  //--- Calculer le hash code de l'entree
    bool cacheSuccess ; int32_t hashCode ;
    gAndOperationCache.getCacheEntry (f, g, cacheSuccess, hashCode, result) ;
    if (! cacheSuccess) {
    //--- Faire l'operation
      C_AEDD::C_AEDDnode * ptrF = getAEDDnodePointer (f) ; // n'est pas NULL
      C_AEDD::C_AEDDnode * ptrG = getAEDDnodePointer (g) ; // n'est pas NULL
      const intptr_t compF = f & 1 ;
      const intptr_t compG = g & 1 ;
      const intptr_t constF = ptrF->mConstant ;
      const intptr_t constG = ptrG->mConstant ;
      const uint16_t varF = ptrF->mVar ;
      const uint16_t varG = ptrG->mVar ;
    //--- Compute
      if (varF < varG) {
          result = find_or_add (varF, constF,
                                internalANDoperation (ptrF->mFalseBranch ^ compF, g),
                                internalANDoperation (ptrF->mTrueBranch ^ compF, g)) ;
      }else if (varF == varG) {
        if (constF < constG) { // Simplification 2, si on a false pour x < k+n, on aura false pour x < n ou n <= x < n+k
          if ((ptrG->mFalseBranch ^ compG) == 0) {
	          result = find_or_add (varG, constG, 0, internalANDoperation(ptrF->mTrueBranch ^ compF, ptrG->mTrueBranch ^ compG));
	        }else{
	          result = find_or_add (varF, constF,
                                  internalANDoperation (ptrF->mFalseBranch ^ compF, ptrG->mFalseBranch ^ compG),
                                  internalANDoperation (ptrF->mTrueBranch ^ compF, g)) ;
	        }
      	}else if (constF == constG) {
          result = find_or_add (varF, constF,
                                internalANDoperation (ptrF->mFalseBranch ^ compF, ptrG->mFalseBranch ^ compG),
                                internalANDoperation (ptrF->mTrueBranch ^ compF, ptrG->mTrueBranch ^ compG)) ;
      	}else{ // ConstF > ConstG
      	  if ((ptrF->mFalseBranch ^ compF) == 0) { // Simplification 2
	          result = find_or_add (varF, constF, 0, internalANDoperation(ptrF->mTrueBranch ^ compF, ptrG->mTrueBranch ^ compG));
	        }else{
	          result = find_or_add (varG, constG,
                                  internalANDoperation (ptrF->mFalseBranch ^ compF, ptrG->mFalseBranch ^ compG),
                                  internalANDoperation (f, ptrG->mTrueBranch ^ compG)) ;
	        }
	      }
      }else{ // varF > varG
	      result = find_or_add (varG, constG,
                              internalANDoperation (f, ptrG->mFalseBranch ^ compG),
                              internalANDoperation (f, ptrG->mTrueBranch ^ compG)) ;
      }
    //--- Insert result into cache
      gAndOperationCache.writeCacheEntry (f, g, hashCode, result) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------*
//                                                                     *
//             Internal ITE operation                                  *
//                                                                     *
//---------------------------------------------------------------------*

static intptr_t
internalITEoperation (const intptr_t opf, const intptr_t opg, const intptr_t oph) {
   return internalANDoperation (internalANDoperation (opf, opg)      ^ 1,
                               internalANDoperation (opf ^ 1, oph) ^ 1)
          ^ 1 ;
}

//---------------------------------------------------------------------*

void C_AEDD::setToFalse (void) {
  mAEDDvalue = 0  ;
}

//---------------------------------------------------------------------*

void C_AEDD::setToTrue (void) {
  mAEDDvalue = 1  ;
}

//---------------------------------------------------------------------*

C_AEDD C_AEDD::implies (const C_AEDD & inOperand) const {
//--- f -> g est defini par (non f) ou g, c'est a dire non (f et (non g))
  return C_AEDD (internalANDoperation (mAEDDvalue, inOperand.mAEDDvalue ^ 1) ^ 1) ;
}

//---------------------------------------------------------------------*

C_AEDD C_AEDD::operator & (const C_AEDD & inOperand) const {
  return C_AEDD (internalANDoperation (mAEDDvalue, inOperand.mAEDDvalue)) ;
}

//---------------------------------------------------------------------*

void C_AEDD::operator &= (const C_AEDD & inOperand) {
   mAEDDvalue = internalANDoperation (mAEDDvalue, inOperand.mAEDDvalue) ;
}

//---------------------------------------------------------------------*

C_AEDD C_AEDD::operator | (const C_AEDD & inOperand) const {
  return C_AEDD (internalANDoperation (mAEDDvalue ^ 1, inOperand.mAEDDvalue ^ 1) ^ 1) ;
// return ~ ((~ *this) & (~ inOperand)) ;
}

//---------------------------------------------------------------------*

void C_AEDD::operator |= (const C_AEDD & inOperand) {
  mAEDDvalue = internalANDoperation (mAEDDvalue ^ 1, inOperand.mAEDDvalue ^ 1) ^ 1 ;
}

//---------------------------------------------------------------------*

C_AEDD C_AEDD::operator ^ (const C_AEDD & inOperand) const {
  return C_AEDD (internalITEoperation (mAEDDvalue, inOperand.mAEDDvalue ^ 1, inOperand.mAEDDvalue)) ;
}

//---------------------------------------------------------------------*

C_AEDD C_AEDD::operator ~ (void) const {
  return C_AEDD (mAEDDvalue ^ 1) ;
}

//---------------------------------------------------------------------*

void C_AEDD::negate (void) {
  mAEDDvalue ^= 1 ;
}

//---------------------------------------------------------------------*

C_AEDD C_AEDD::ite (const C_AEDD & f, const C_AEDD & g, const C_AEDD & h) {
  return C_AEDD (internalITEoperation (f.mAEDDvalue, g.mAEDDvalue, h.mAEDDvalue)) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//     Build a AEDD result of comparison between a variable and a constant   *
//                                                                           *
//---------------------------------------------------------------------------*

C_AEDD C_AEDD::
varSupOrEqualToConstant (const uint16_t inVar,
                         const int32_t inConstant) {
  C_AEDD aedd (find_or_add (inVar, inConstant, 0, 1)) ;
//  printf ("varSupOrEqualToConstant (%u, %ld : 0x%lX)\n", inVar, inConstant, aedd.mAEDDvalue) ;
  return aedd ;
}

//---------------------------------------------------------------------------*

C_AEDD C_AEDD::
varInfOrEqualToConstant (const uint16_t inVar,
                         const int32_t inConstant) {
  return C_AEDD (find_or_add (inVar, inConstant + 1, 1 ,0)) ;
}

//---------------------------------------------------------------------------*

C_AEDD C_AEDD::
varEqualToConstant (const uint16_t inVar,
                    const int32_t inConstant) {
  return varSupOrEqualToConstant (inVar, inConstant)
       & varInfOrEqualToConstant (inVar, inConstant) ;
}

//---------------------------------------------------------------------------*

C_AEDD C_AEDD::
varDifferentThanConstant (const uint16_t inVar,
                          const int32_t inConstant) {
  return varStrictSupThanConstant (inVar, inConstant) | varStrictInfThanConstant (inVar, inConstant);
}

//---------------------------------------------------------------------------*

C_AEDD C_AEDD::
varStrictInfThanConstant (const uint16_t inVar,
                          const int32_t inConstant) {
  C_AEDD aedd (find_or_add (inVar, inConstant, 1, 0)) ;
//  printf ("varStrictInfThanConstant (%u, %ld : 0x%lX)\n", inVar, inConstant, aedd.mAEDDvalue) ;
  return aedd ;
}

//---------------------------------------------------------------------------*

C_AEDD C_AEDD::
varStrictSupThanConstant (const uint16_t inVar,
                          const int32_t inConstant) {
  return C_AEDD (find_or_add (inVar, inConstant + 1, 0, 1)) ;
}

//---------------------------------------------------------------------*

bool C_AEDD::isComplemented (void) const {
  return (mAEDDvalue & 1) != 0 ;
}

//---------------------------------------------------------------------*

bool C_AEDD::infPtr (const C_AEDD & inOperand) const {
  return mAEDDvalue < inOperand.mAEDDvalue ;
}

//---------------------------------------------------------------------*

static void
internalRef (const intptr_t inAEDDvalue) {
  if (inAEDDvalue == 0) {
    co << "false" ;
  }else if (inAEDDvalue == 1) {
    co << "true" ;
  }else if ((inAEDDvalue & 1) == 0) {
    co << "node " ;
    co.appendUnsignedHex ((uint64_t) inAEDDvalue) ;
  }else{
    co << "complement of node " ;
    co.appendUnsignedHex (((uintptr_t) (inAEDDvalue & ~1))) ;
  }
}

//---------------------------------------------------------------------*

static void
internalPrintAEDDnodes (const intptr_t inAEDDvalue,
                        const uint32_t inIndentation) {
  C_AEDD::C_AEDDnode * ptr = getAEDDnodePointer (inAEDDvalue) ;
  if ((ptr != NULL) && ! ptr->isMarked ()) {
    ptr->mark () ;
    co.appendSpaces ((int32_t) inIndentation) ;
    co << "at " ;
    co.appendUnsignedHex ((uintptr_t) ptr) ;
    co << ": if var" << cStringWithSigned (ptr->mVar) << " >= " << cStringWithSigned (ptr->mConstant) << " then " ;
    internalRef (ptr->mTrueBranch) ;
    co << " else " ;
    internalRef (ptr->mFalseBranch) ;
    co << "\n" ;
    internalPrintAEDDnodes (ptr->mTrueBranch, inIndentation + 1) ;
    internalPrintAEDDnodes (ptr->mFalseBranch, inIndentation + 1) ;
  }
}

//---------------------------------------------------------------------*

void C_AEDD::printAEDDnodes (const char * inMessage) const {
  unmarkAllExistingAEDDnodes () ;
  co << inMessage ;
  internalRef (mAEDDvalue) ;
  co << "\n" ;
  internalPrintAEDDnodes (mAEDDvalue, 0) ;
}

//---------------------------------------------------------------------*

static void marquerElementsInterne (const intptr_t inValue) {
  C_AEDD::C_AEDDnode * ptr = getAEDDnodePointer (inValue) ;
  if ((ptr != NULL) && ! ptr->isMarked ()) {
    ptr->mark () ;
    marquerElementsInterne (ptr->mFalseBranch) ;
    marquerElementsInterne (ptr->mTrueBranch) ;
  }
}

//---------------------------------------------------------------------*

void C_AEDD::markAEDDnodes (void) {
  marquerElementsInterne (mAEDDvalue) ;
}

//---------------------------------------------------------------------*

static uintptr_t nombreElementsRecursif (const intptr_t inValue) {
  C_AEDD::C_AEDDnode * ptr = getAEDDnodePointer (inValue) ;
  uintptr_t n = 0 ;
  if (ptr != 0) {
     if (! ptr->isMarked ()) {
       ptr->mark () ;
       n = 1 + nombreElementsRecursif (ptr->mFalseBranch) + nombreElementsRecursif (ptr->mTrueBranch) ;
     }
  }
  return n ;
}

//---------------------------------------------------------------------*

uintptr_t C_AEDD::getAEDDnodesCount (void) const {
  uintptr_t result = 0 ;
  if (getAEDDnodePointer (mAEDDvalue) != NULL) {
    unmarkAllExistingAEDDnodes () ;
    result = nombreElementsRecursif (mAEDDvalue) ;
  }
  return result ;
}

//---------------------------------------------------------------------*

void C_AEDD::
printAEDDpackageOperationsSummary (AC_OutputStream & inStream) {
  inStream << "\n"
              "Bilan du AEDD (" << cStringWithSigned (getAEDDnodeSize ()) << " octets par element AEDD)\n"
              "  Nombre courant de AEDD  : " << cStringWithUnsigned (getAEDDinstancesCount ()) << "\n"
              "  Nombre d'elements crees : " << cStringWithUnsigned (getCreatedNodesCount ()) << "\n"
              "  Nombre de comparaisons pour recherches/insertions des elements : " << cStringWithUnsigned (C_AEDDnode::smComparisonsCount) << "\n" ;
  gAndOperationCache.printStatistics (inStream, "AND") ;
}

//---------------------------------------------------------------------*
