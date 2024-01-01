//---------------------------------------------------------------------------*
//                                                                           *
//                                                                           *
//                                                                           *
//  For heap efficiency, elements are allocated by blocks.                   *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  COPY OF ITS INSTANCES IS FORBIDDEN BY REDEFINITION OF COPY CONSTRUCTOR   *
//  AND ASSIGNMENT OPERATOR.                                                 *
//                                                                           *
//  Copyright (C) 2001, ..., 2008 Pierre Molinaro.                           *
//                                                                           *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
//                                                                           *
//  IRCCyN, Institut de Recherche en Communications et Cybernetique de Nantes*
//  ECN, Ecole Centrale de Nantes                                            *
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

#include "cNode_hashmap.h"
#include "F_GetPrime.h"

//---------------------------------------------------------------------------*

static const int32_t BLOCK_SIZE = 131072 ;

//---------------------------------------------------------------------------*

cVDDnodeInfo_hashmap::cAllocInfo cVDDnodeInfo_hashmap::smAllocInfo ;

//---------------------------------------------------------------------------*
//                                                                           *
//       Constructor for avl tree                                            *
//                                                                           *
//---------------------------------------------------------------------------*

void * cVDDnodeInfo_hashmap::MyBlockavltree_element_for_collision::operator new (const size_t /*inByteSize*/) {
  if (smAllocInfo.mFreeList == NULL) {
    C_TreeForCollision::allocBlock () ;
  }
  smAllocInfo.mAllocatedObjectCount ++ ;
  MyBlockavltree_element_for_collision * result = smAllocInfo.mFreeList ;
  smAllocInfo.mFreeList = smAllocInfo.mFreeList->mPtrToSup ;
  return result ;
}

//---------------------------------------------------------------------------*

void cVDDnodeInfo_hashmap::MyBlockavltree_element_for_collision::operator delete (void * inPtr) {
  MyBlockavltree_element_for_collision * p = (MyBlockavltree_element_for_collision *) inPtr ;
  p->mPtrToSup = smAllocInfo.mFreeList ;
  smAllocInfo.mFreeList = p ;
  smAllocInfo.mAllocatedObjectCount -- ;
  if (smAllocInfo.mAllocatedObjectCount == 0) {
    for (size_t i=0 ; i<smAllocInfo.mAllocatedBlockCount ; i++) {
      delete [] smAllocInfo.mAllocatedBlockList [i] ;
    }
    delete [] smAllocInfo.mAllocatedBlockList ;
    smAllocInfo.mAllocatedBlockList = (char * *) NULL ;
    smAllocInfo.mAllocatedBlockCount = 0 ;
    smAllocInfo.mAllocatedBlockListSize = 0 ;
    smAllocInfo.mFreeList = (MyBlockavltree_element_for_collision *) NULL ;
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Constructor for avl tree                                            *
//                                                                           *
//---------------------------------------------------------------------------*

void cVDDnodeInfo_hashmap::C_TreeForCollision::allocBlock (void) {
//--- Realloc block list ?
  if (smAllocInfo.mAllocatedBlockListSize <= smAllocInfo.mAllocatedBlockCount) {
    const size_t newSize = smAllocInfo.mAllocatedBlockCount + 1024 ;
    char ** newBlockList = new char * [newSize] ;
    for (size_t i=0 ; i<smAllocInfo.mAllocatedBlockCount ; i++) {
      newBlockList [i] = smAllocInfo.mAllocatedBlockList [i] ;
    }
    delete [] smAllocInfo.mAllocatedBlockList ;
    smAllocInfo.mAllocatedBlockList = newBlockList ;
    smAllocInfo.mAllocatedBlockListSize = newSize ;
  }
//--- Alloc block
  smAllocInfo.mAllocatedBlockList [smAllocInfo.mAllocatedBlockCount] = new char [BLOCK_SIZE] ;
  char * ptr = & (smAllocInfo.mAllocatedBlockList [smAllocInfo.mAllocatedBlockCount] [0]) ;
  smAllocInfo.mAllocatedBlockCount ++ ;
  size_t blockSize = BLOCK_SIZE ;
  const size_t ALIGNMENT = 32 ;
//--- Align pointer
  if ((size_t (ptr) % ALIGNMENT) != 0) {
    ptr = (char *) (((size_t (ptr) / ALIGNMENT) + 1) * ALIGNMENT) ;
    blockSize -= ALIGNMENT ;
  }
  const size_t nbNewObjects = blockSize / sizeof (MyBlockavltree_element_for_collision) ;
  for (size_t i=0 ; i<nbNewObjects ; i++) {
    MyBlockavltree_element_for_collision * newObjectPtr = (MyBlockavltree_element_for_collision *) ptr ;
    newObjectPtr->mPtrToSup = smAllocInfo.mFreeList ;
    smAllocInfo.mFreeList = newObjectPtr ;
    ptr += sizeof (MyBlockavltree_element_for_collision) ;
  }
  smAllocInfo.mCreatedObjectCount += nbNewObjects ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Constructor for avl tree                                            *
//                                                                           *
//---------------------------------------------------------------------------*

cVDDnodeInfo_hashmap::C_TreeForCollision::C_TreeForCollision (void) :
mRoot (NULL) {
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Destructor for avl tree                                             *
//                                                                           *
//---------------------------------------------------------------------------*

cVDDnodeInfo_hashmap::C_TreeForCollision::~C_TreeForCollision (void) {
  delete mRoot ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Get allocated size (in bytes)                                       *
//                                                                           *
//---------------------------------------------------------------------------*

uint32_t cVDDnodeInfo_hashmap::getAllocatedSizeInBytes (void) {
  return (uint32_t) (BLOCK_SIZE * smAllocInfo.mAllocatedBlockCount) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Rotate left                                                         *
//                                                                           *
//---------------------------------------------------------------------------*

void cVDDnodeInfo_hashmap::C_TreeForCollision::
rotateLeft (MyBlockavltree_element_for_collision * & ioPtr) {
//--- Rotate
  MyBlockavltree_element_for_collision * ptr = ioPtr->mPtrToSup ;
  ioPtr->mPtrToSup = ptr->mPtrToInf ;
  ptr->mPtrToInf = ioPtr ;
//--- Update balance
  if (ptr->mBalance < 0) {
    ioPtr->mBalance -= ptr->mBalance ;
  }
  ioPtr->mBalance ++ ;
  if (ioPtr->mBalance > 0) {
    ptr->mBalance += ioPtr->mBalance ;
  }
  ptr->mBalance ++ ;
  ioPtr = ptr ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Rotate right                                                        *
//                                                                           *
//---------------------------------------------------------------------------*

void cVDDnodeInfo_hashmap::C_TreeForCollision::
rotateRight (MyBlockavltree_element_for_collision * & ioPtr) {
//--- Rotate
  MyBlockavltree_element_for_collision * ptr = ioPtr->mPtrToInf ;
  ioPtr->mPtrToInf = ptr->mPtrToSup ;
  ptr->mPtrToSup = ioPtr ;
 //--- Update balance
  if (ptr->mBalance > 0) {
    ioPtr->mBalance -= ptr->mBalance ;
  }
  ioPtr->mBalance -- ;
  if (ioPtr->mBalance < 0) {
    ptr->mBalance += ioPtr->mBalance ;
  }
  ptr->mBalance-- ;
  ioPtr = ptr ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Recursive search and insert                                         *
//                                                                           *
//---------------------------------------------------------------------------*

cVDDnodeInfo * cVDDnodeInfo_hashmap::C_TreeForCollision::
avltree_search (MyBlockavltree_element_for_collision * ioRootPointer,
                 const cVDDnodeInfo & inInfo) {
  cVDDnodeInfo * result = NULL ;
  if (ioRootPointer == NULL) {
    result = (cVDDnodeInfo *) NULL ;
  }else{
    const int32_t comp = ioRootPointer->mInfo.compare (inInfo) ;
    if (comp > 0) {
      result = avltree_search (ioRootPointer->mPtrToSup, inInfo) ;
    }else if (comp < 0) {
      result = avltree_search (ioRootPointer->mPtrToInf, inInfo) ;
    }else{ // Found
      result = & (ioRootPointer->mInfo) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Recursive search and insert                                         *
//                                                                           *
//---------------------------------------------------------------------------*

cVDDnodeInfo * cVDDnodeInfo_hashmap::C_TreeForCollision::
recursiveSearchOrInsert (MyBlockavltree_element_for_collision * & ioRootPointer,
                         const cVDDnodeInfo & inInfo,
                         bool & outExtension,
                         bool & outInsertionPerformed) {
  cVDDnodeInfo * result ;
  if (ioRootPointer == NULL) {
    ioRootPointer = new MyBlockavltree_element_for_collision (inInfo) ;
    result = & (ioRootPointer->mInfo) ;
    outExtension = true ;
    outInsertionPerformed = true ;
  }else{
    outInsertionPerformed = false ;
    const int32_t comp = ioRootPointer->mInfo.compare (inInfo) ;
    if (comp > 0) {
      result = recursiveSearchOrInsert (ioRootPointer->mPtrToSup, inInfo, outExtension, outInsertionPerformed) ;
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
            rotateRight (ioRootPointer->mPtrToSup) ;
          }
          rotateLeft (ioRootPointer) ;
          outExtension = false;
          break;
        default :
          break ;
        }
      }
    }else if (comp < 0) {
      result = recursiveSearchOrInsert (ioRootPointer->mPtrToInf, inInfo, outExtension, outInsertionPerformed) ;
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
            rotateLeft (ioRootPointer->mPtrToInf) ;
          }
          rotateRight (ioRootPointer) ;
          outExtension = false;
          break;
        default :
          break ;
        }
      }
    }else{ // Found
      result = & (ioRootPointer->mInfo) ;
      outExtension = false;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Search and insert if not found                                      *
//                                                                           *
//---------------------------------------------------------------------------*

cVDDnodeInfo * cVDDnodeInfo_hashmap::C_TreeForCollision::
search_or_insert (const cVDDnodeInfo & inInfo,
                  bool & outInsertionPerformed) {
  bool unused = false ;
  return recursiveSearchOrInsert (mRoot, inInfo, unused, outInsertionPerformed) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Search only                                                         *
//                                                                           *
//---------------------------------------------------------------------------*

cVDDnodeInfo * cVDDnodeInfo_hashmap::C_TreeForCollision::
search (const cVDDnodeInfo & inInfo) {
  return avltree_search (mRoot, inInfo) ;
}

//---------------------------------------------------------------------------*

void cVDDnodeInfo_hashmap::C_TreeForCollision::
recursiveInsertElement (MyBlockavltree_element_for_collision * & ioRootPointer,
                        MyBlockavltree_element_for_collision * const inElementPointer,
                        bool & outExtension,
                        bool & outInsertionPerformed) {
  if (ioRootPointer == NULL) {
    ioRootPointer = inElementPointer ;
    inElementPointer->mPtrToInf = NULL ;
    inElementPointer->mPtrToSup = NULL ;
    inElementPointer->mBalance = 0 ;
    outExtension = true ;
    outInsertionPerformed = true ;
  }else{
    const intptr_t comp = ioRootPointer->compare (* inElementPointer) ;
    if (comp > 0) {
      recursiveInsertElement (ioRootPointer->mPtrToSup, inElementPointer, outExtension, outInsertionPerformed) ;
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
            rotateRight (ioRootPointer->mPtrToSup) ;
          }
          rotateLeft (ioRootPointer) ;
          outExtension = false;
          break;
        default :
          break ;
        }
      }
    }else if (comp < 0) {
      recursiveInsertElement (ioRootPointer->mPtrToInf, inElementPointer, outExtension, outInsertionPerformed) ;
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
            rotateLeft (ioRootPointer->mPtrToInf) ;
          }
          rotateRight (ioRootPointer) ;
          outExtension = false;
          break;
        default :
          break ;
        }
      }
    }else{ // Found
      outInsertionPerformed = false ;
      outExtension = false;
    }
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Sweep unmarked objects                                              *
//                                                                           *
//---------------------------------------------------------------------------*

uint32_t cVDDnodeInfo_hashmap::C_TreeForCollision::internalRecursiveSweep (cVDDnodeInfo_hashmap::MyBlockavltree_element_for_collision * inElement) {
  uint32_t sweepedNodes = 0 ;
  if (inElement != NULL) {
    sweepedNodes += internalRecursiveSweep (inElement->mPtrToInf) ;
    sweepedNodes += internalRecursiveSweep (inElement->mPtrToSup) ;
    inElement->mPtrToInf = NULL ;
    inElement->mPtrToSup = NULL ;
    inElement->mBalance = 0 ;
    if (inElement->mInfo.isMarked ()) {
      inElement->mInfo.unmark () ;
      bool extension ; // Unused
      bool insertionPerformed ; // Unused
      recursiveInsertElement (mRoot, inElement, extension, insertionPerformed) ;
    }else{
      delete inElement ;
      sweepedNodes ++ ;
    }
  }
  return sweepedNodes ;
}

//---------------------------------------------------------------------------*

uint32_t cVDDnodeInfo_hashmap::C_TreeForCollision::sweepUnmarkedObjects (void) {
  MyBlockavltree_element_for_collision * temporaryRoot = mRoot ;
  mRoot = (MyBlockavltree_element_for_collision *) NULL ;
  return internalRecursiveSweep (temporaryRoot) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Tranfert objects in a new map array                                 *
//                                                                           *
//---------------------------------------------------------------------------*

void cVDDnodeInfo_hashmap::C_TreeForCollision::
recursiveTransfertElementsInNewMapArray (MyBlockavltree_element_for_collision * const inElementPointer,
                                         C_TreeForCollision * inNewMapArray,
                                         const uint32_t inNewSize) {
  if (inElementPointer != NULL) {
    recursiveTransfertElementsInNewMapArray (inElementPointer->mPtrToInf, inNewMapArray, inNewSize) ;
    recursiveTransfertElementsInNewMapArray (inElementPointer->mPtrToSup, inNewMapArray, inNewSize) ;
    inElementPointer->mPtrToInf = (MyBlockavltree_element_for_collision *) NULL ;
    inElementPointer->mPtrToSup = (MyBlockavltree_element_for_collision *) NULL ;
    inElementPointer->mBalance = 0 ;
    const uint32_t hash = inElementPointer->mInfo.getHashCodeForMap () % inNewSize ;
    bool extension ; // Unused
    bool insertionPerformed ; // Unused
    recursiveInsertElement (inNewMapArray [hash].mRoot, inElementPointer, extension, insertionPerformed) ;
  }
}

//---------------------------------------------------------------------------*

void cVDDnodeInfo_hashmap::C_TreeForCollision::
transfertElementsInNewMapArray (C_TreeForCollision * inNewMapArray,
                                const uint32_t inNewSize) {
  recursiveTransfertElementsInNewMapArray (mRoot, inNewMapArray, inNewSize) ;
  mRoot = (MyBlockavltree_element_for_collision *) NULL ;
}

//---------------------------------------------------------------------------*

void cVDDnodeInfo_hashmap::C_TreeForCollision::
internalRecursiveUnmark (MyBlockavltree_element_for_collision * inElement) {
  if (inElement != NULL) {
    inElement->mInfo.unmark () ;
    internalRecursiveUnmark (inElement->mPtrToInf) ;
    internalRecursiveUnmark (inElement->mPtrToSup) ;
  }
}

//---------------------------------------------------------------------------*

void cVDDnodeInfo_hashmap::C_TreeForCollision::
unmarkAllObjects (void) {
  internalRecursiveUnmark (mRoot) ;
}

//---------------------------------------------------------------------------*

int32_t cVDDnodeInfo_hashmap::C_TreeForCollision::
internalMarkedNodeCount (const MyBlockavltree_element_for_collision * const inElement) const {
  int32_t result = 0 ;
  if (inElement != NULL) {
    if (inElement->mInfo.isMarked ()) {
      result ++ ;
    }
    result += internalMarkedNodeCount (inElement->mPtrToInf) ;
    result += internalMarkedNodeCount (inElement->mPtrToSup) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

int32_t cVDDnodeInfo_hashmap::C_TreeForCollision::
getMarkedNodesCount (void) const {
  return internalMarkedNodeCount (mRoot) ;
}

//---------------------------------------------------------------------------*

cVDDnodeInfo_hashmap::cVDDnodeInfo_hashmap (void) :
mEntryCurrentCount (1),
mMinimumMapArray (),
mMapArray (& mMinimumMapArray) {
}

//---------------------------------------------------------------------------*

cVDDnodeInfo_hashmap::~cVDDnodeInfo_hashmap (void) {
  if (mEntryCurrentCount > 1) {
    delete [] mMapArray ;
  }
}

//---------------------------------------------------------------------------*

cVDDnodeInfo * cVDDnodeInfo_hashmap::
search_or_insert (const cVDDnodeInfo & inInfo,
                  bool & outInsertionPerformed) {
  uint32_t hashCode = inInfo.getHashCodeForMap () ;
  hashCode %= (uint32_t) mEntryCurrentCount ;
  return mMapArray [hashCode].search_or_insert (inInfo, outInsertionPerformed) ;
}

//---------------------------------------------------------------------------*

cVDDnodeInfo * cVDDnodeInfo_hashmap::
search (const cVDDnodeInfo & inInfo) {
  uint32_t hashCode = inInfo.getHashCodeForMap () ;
  hashCode %= (uint32_t) mEntryCurrentCount ;
  return mMapArray [hashCode].search (inInfo) ;
}

//---------------------------------------------------------------------------*

uint32_t cVDDnodeInfo_hashmap::sweepUnmarkedObjects (void) {
  uint32_t sweepedNodes = 0 ;
  for (size_t i=0 ; i<mEntryCurrentCount ; i++) {
    sweepedNodes += mMapArray [i].sweepUnmarkedObjects () ;
  }
  return sweepedNodes ;
}

//---------------------------------------------------------------------------*

uint32_t cVDDnodeInfo_hashmap::getMapSizeInBytes (void) const {
  return (uint32_t) (((size_t) mEntryCurrentCount) * sizeof (C_TreeForCollision)) ;
}

//---------------------------------------------------------------------------*

void cVDDnodeInfo_hashmap::reallocMap (const int32_t inNewSize) {
  const size_t newSize = (inNewSize < 1) ? 1 : (size_t) getPrimeGreaterThan ((uint32_t) inNewSize) ;
  if (newSize != mEntryCurrentCount) {
    C_TreeForCollision * newMapArray = (newSize > 1) ? new C_TreeForCollision [newSize] : (& mMinimumMapArray) ;
    for (size_t i=0 ; i<mEntryCurrentCount ; i++) {
      mMapArray [i].transfertElementsInNewMapArray (newMapArray, (uint32_t) newSize) ;
    }
    if (mEntryCurrentCount > 1) {
      delete [] mMapArray ;
    }
    mMapArray = newMapArray ;
    mEntryCurrentCount = newSize ;
  }
}

//---------------------------------------------------------------------------*

void cVDDnodeInfo_hashmap::unmarkAllObjects (void) {
  for (size_t i=0 ; i<mEntryCurrentCount ; i++) {
    mMapArray [i].unmarkAllObjects () ;
  }
}

//---------------------------------------------------------------------------*

int32_t cVDDnodeInfo_hashmap::getMarkedNodesCount (void) const {
  int32_t count = 0 ;
  for (size_t i=0 ; i<mEntryCurrentCount ; i++) {
    count += mMapArray [i].getMarkedNodesCount () ;
  }
  return count ;
}

//---------------------------------------------------------------------------*
