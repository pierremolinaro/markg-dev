//---------------------------------------------------------------------------*
//                                                                           *
//     C++ class for implementing VECTOR DECISION DIAGRAMS (VDD)             *
//                                                                           *
//  This file is part of libpm library                                       *
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

#include "C_VDD.h"
#include "C_ZSV.h"
#include "C_PCL.h"
#include "C_AEDD.h"
#include "utilities/MF_MemoryControl.h"
#include "cVDDnodeInfo.h"

//---------------------------------------------------------------------------*

#include <stddef.h>
#include <string.h>
#include <limits.h>

//---------------------------------------------------------------------------*

static inline T_vdd_zsl_value sup (const T_vdd_zsl_value inA,
                                   const T_vdd_zsl_value inB) {
  return (inA > inB) ? inA : inB ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//        Compute operations duration (only on MacOS)                        *
//                                                                           *
//---------------------------------------------------------------------------*

//#define COMPUTE_OPERATIONS_DURATION

#ifdef COMPUTE_OPERATIONS_DURATION
  static uint64_t gGetFirableDuration = 0ULL ;
  static uint64_t gGetIntersectionWithNullSetDuration = 0ULL ;
  static uint64_t gNullSuppressDuration = 0ULL ;
  static uint64_t gGetGreaterOrEqualDuration = 0ULL ;
  static uint64_t gGetBoundDuration = 0ULL ;
  static uint64_t gAddVectorDuration = 0ULL ;
  static uint64_t gGetGreaterDuration = 0ULL ;
  static uint64_t gSetUnionDuration = 0ULL ;
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//  VDD objects hash map                                                     *
//                                                                           *
//---------------------------------------------------------------------------*

#include "C_VDD_hashmap.h"
static C_VDD_hashmap gMap ;

//---------------------------------------------------------------------------*

void C_VDD::reallocUniqueTable (const int32_t inTableUniqueNewSize) {
  gMap.reallocMap (inTableUniqueNewSize) ;
}

//---------------------------------------------------------------------------*

size_t C_VDD::getUniqueTableSizeInBytes (void) {
  return gMap.getMapSizeInBytes () + C_VDD_hashmap::getAllocatedSizeInBytes () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//  Total count of instancied cVDDmaxInfos objects                           *
//                                                                           *
//---------------------------------------------------------------------------*

static uint32_t gInstanciedMaxInfosObjects = 0 ;

//---------------------------------------------------------------------------*
//                                                                           *
//  Get RAM size allocated for cVDDmaxInfos objects                          *
//                                                                           *
//---------------------------------------------------------------------------*

size_t C_VDD::getSizeOf_cVDDmaxInfos_objects (void) {
  return gInstanciedMaxInfosObjects * sizeof (cVDDmaxInfos) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//  Sets Union computation cache                                             *
//                                                                           *
//---------------------------------------------------------------------------*

#include "TC_prime_cache2.h"
typedef TC_prime_cache2 <C_VDD::cVDDnodeInfo *> cSetsUnionCacheClass ;
static cSetsUnionCacheClass gSetUnionCache ;

//---------------------------------------------------------------------------*
//                                                                           *
//  Get Firable computation cache                                            *
//                                                                           *
//---------------------------------------------------------------------------*

#include "TC_prime_cache2.h"
typedef TC_prime_cache2 <C_VDD::cVDDnodeInfo *> cGetFirableCacheClass ;
static cGetFirableCacheClass gGetFirableCache ;

//---------------------------------------------------------------------------*
//                                                                           *
//  Add vector computation cache                                             *
//                                                                           *
//---------------------------------------------------------------------------*

#include "TC_prime_cache2.h"
typedef TC_prime_cache2 <C_VDD::cVDDnodeInfo *> cAddVectorCacheClass ;
static cAddVectorCacheClass gAddVectorCache ;

//---------------------------------------------------------------------------*
//                                                                           *
//  Realloc caches                                                           *
//                                                                           *
//---------------------------------------------------------------------------*

void C_VDD::reallocCaches (const size_t inNewCachesSize) {
// will select a prime greater than this value
  gGetFirableCache.reallocCache (inNewCachesSize) ;
  gAddVectorCache.reallocCache (inNewCachesSize) ;
  gSetUnionCache.reallocCache (inNewCachesSize) ;
}

//---------------------------------------------------------------------------*

size_t C_VDD::getCachesSizeEntriesCount (void) {
  return (size_t) gGetFirableCache.getCacheEntriesCount () ;
}

//---------------------------------------------------------------------------*

size_t C_VDD::getCachesSizeInBytes (void) {
  return gGetFirableCache.getCacheSizeInBytes ()
       + gAddVectorCache.getCacheSizeInBytes ()
       + gSetUnionCache.getCacheSizeInBytes () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//  Static VDL variable used as root of all existing C_VDD instances         *
//                                                                           *
//---------------------------------------------------------------------------*

static C_VDD * gFirstVDD = NULL ;
static C_VDD * gLastVDD = NULL ;

//---------------------------------------------------------------------------*
//                                                                           *
//       Node count : for giving an unique ID to every node                  *
//                                                                           *
//---------------------------------------------------------------------------*

size_t C_VDD::smNodeCount = 0 ;

//---------------------------------------------------------------------------*
//                                                                           *
//       Current nodes count                                                 *
//                                                                           *
//---------------------------------------------------------------------------*

size_t C_VDD::smCurrentNodeCount = 0 ;

//---------------------------------------------------------------------------*
//                                                                           *
//       Constants                                                           *
//                                                                           *
//---------------------------------------------------------------------------*

//--- kEMPTY_SET denotes the empty set
C_VDD::cVDDnodeInfo * const C_VDD::kEMPTY_SET = (C_VDD::cVDDnodeInfo *) 0 ;

//--- kNULL_SET denotes the set that contains only the null vector
C_VDD::cVDDnodeInfo * const C_VDD::kNULL_SET = (C_VDD::cVDDnodeInfo *) 1 ;

static const int32_t bit0mask = (int32_t) 0xFFFFFFFE ;

//---------------------------------------------------------------------------*
//                                                                           *
//       cVDDnodeInfo destructor                                             *
//                                                                           *
//---------------------------------------------------------------------------*

C_VDD::cVDDmaxInfos * C_VDD::gNodeInfoFreeList = (C_VDD::cVDDmaxInfos *) NULL ;

//---------------------------------------------------------------------------*

C_VDD::cVDDnodeInfo::~cVDDnodeInfo (void) {
  cVDDmaxInfos * ptr = (cVDDmaxInfos *) (mMaxInfosPtr & bit0mask) ;
  if (ptr != NULL) {
    ptr->mPtrToNext = gNodeInfoFreeList ;
    gNodeInfoFreeList = ptr ;
  }
  mMaxInfosPtr = 0L ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Default constructor                                                 *
//                                                                           *
//---------------------------------------------------------------------------*

C_VDD::C_VDD (void) :
mPtrToNextExisting (this),
mPtrToPreviousExisting (this),
mRootPointer (kEMPTY_SET) {
  initLinks () ;
}

//---------------------------------------------------------------------------*

void C_VDD::initLinks (void) {
  if (gFirstVDD == NULL) {
    gLastVDD = this ;
  }else{
    gFirstVDD->mPtrToPreviousExisting = this ;
  }
  mPtrToNextExisting = gFirstVDD ;
  gFirstVDD = this ;

//  mPtrToNextExisting = this ;
//  mPtrToPreviousExisting = this ;
//  C_VDD * nextFromRoot = gVDLlistRoot.mPtrToNextExisting ;
//  mPtrToPreviousExisting = & gVDLlistRoot ;
//  nextFromRoot->mPtrToPreviousExisting = this ;
//  mPtrToNextExisting = nextFromRoot ;
//  gVDLlistRoot.mPtrToNextExisting = this ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Destructor                                                          *
//                                                                           *
//---------------------------------------------------------------------------*

C_VDD::~C_VDD (void) {
  mRootPointer = kEMPTY_SET ;
//--- Unlink
  if (mPtrToPreviousExisting == NULL) {
    gFirstVDD = gFirstVDD->mPtrToNextExisting ;
  }else{
    mPtrToPreviousExisting->mPtrToNextExisting = mPtrToNextExisting ;
  }
  if (mPtrToNextExisting == NULL) {
    gLastVDD = gLastVDD->mPtrToPreviousExisting ;
  }else{
    mPtrToNextExisting->mPtrToPreviousExisting = mPtrToPreviousExisting ;
  }

//  C_VDD * next = mPtrToNextExisting ;
//  C_VDD * previous = mPtrToPreviousExisting ;
//  previous->mPtrToNextExisting = next ;
//  next->mPtrToPreviousExisting = previous ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Set to NULL set                                                     *
//                                                                           *
//---------------------------------------------------------------------------*

void C_VDD::setToNullSet (void) {
  mRootPointer = kNULL_SET ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Set to empty set                                                    *
//                                                                           *
//---------------------------------------------------------------------------*

void C_VDD::setToEmptySet (void) {
  mRootPointer = kEMPTY_SET ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Empty set test                                                      *
//                                                                           *
//---------------------------------------------------------------------------*

bool C_VDD::isEmptySet (void) const {
  return mRootPointer == kEMPTY_SET ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Vector comparison                                                   *
//                                                                           *
//---------------------------------------------------------------------------*

bool C_VDD::operator == (const C_VDD & inOperand) const {
  return mRootPointer == inOperand.mRootPointer ;
}

//---------------------------------------------------------------------------*

bool C_VDD::operator != (const C_VDD & inOperand) const {
  return mRootPointer != inOperand.mRootPointer ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Handle copy                                                         *
//                                                                           *
//---------------------------------------------------------------------------*

C_VDD::C_VDD (const C_VDD & inOperand) :
mPtrToNextExisting (this),
mPtrToPreviousExisting (this),
mRootPointer (inOperand.mRootPointer) {
  initLinks () ;
}

//---------------------------------------------------------------------------*

C_VDD & C_VDD::operator = (const C_VDD & inOperand) {
  mRootPointer = inOperand.mRootPointer ;
  return *this ;
}

//---------------------------------------------------------------------------*

#ifdef __MWERK__
  #pragma mark Stats
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//       Cache for 'SetUnion'                                                *
//                                                                           *
//---------------------------------------------------------------------------*

uint64_t C_VDD::getSetUnionCacheEntriesCount (void) {
  return (uint64_t) gSetUnionCache.getCacheEntriesCount () ;
}

//---------------------------------------------------------------------------*

uint64_t C_VDD::getSetUnionCacheFailureCount (void) {
  return gSetUnionCache.getCacheMissCount () ;
}

//---------------------------------------------------------------------------*

uint64_t C_VDD::getSetUnionCacheOverrideCount (void) {
  return gSetUnionCache.getCacheOverrideCount () ;
}

//---------------------------------------------------------------------------*

uint64_t C_VDD::getSetUnionUnusedCacheEntriesCount (void) {
  return gSetUnionCache.getUnusedCacheEntriesCount () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Cache for 'GetFirable'                                              *
//                                                                           *
//---------------------------------------------------------------------------*

uint64_t C_VDD::getGetFirableCacheEntriesCount (void) {
  return (uint64_t) gGetFirableCache.getCacheEntriesCount () ;
}

//---------------------------------------------------------------------------*

uint64_t C_VDD::getGetFirableCacheFailureCount (void) {
  return gGetFirableCache.getCacheMissCount () ;
}

//---------------------------------------------------------------------------*

uint64_t C_VDD::getGetFirableCacheOverrideCount (void) {
  return gGetFirableCache.getCacheOverrideCount () ;
}

//---------------------------------------------------------------------------*

uint64_t C_VDD::getGetFirableUnusedCacheEntriesCount (void) {
  return gGetFirableCache.getUnusedCacheEntriesCount () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Cache for 'AddVector'                                               *
//                                                                           *
//---------------------------------------------------------------------------*

uint64_t C_VDD::getAddVectorCacheEntriesCount (void) {
  return (uint64_t) gAddVectorCache.getCacheEntriesCount () ;
}

//---------------------------------------------------------------------------*

uint64_t C_VDD::getAddVectorCacheFailureCount (void) {
  return gAddVectorCache.getCacheMissCount () ;
}

//---------------------------------------------------------------------------*

uint64_t C_VDD::getAddVectorCacheOverrideCount (void) {
  return gAddVectorCache.getCacheOverrideCount () ;
}

//---------------------------------------------------------------------------*

uint64_t C_VDD::getAddVectorUnusedCacheEntriesCount (void) {
  return gAddVectorCache.getUnusedCacheEntriesCount () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Static C_VDD members                                                *
//                                                                           *
//---------------------------------------------------------------------------*

uint64_t C_VDD::smTrivialUnion = 0ULL ;
uint64_t C_VDD::smSetUnionCacheSuccesses = 0ULL ;
uint64_t C_VDD::smTrivialGetFirable = 0ULL ;
uint64_t C_VDD::smGetFirableCacheSuccesses = 0ULL ;
uint64_t C_VDD::smTrivialAddVector = 0ULL ;
uint64_t C_VDD::smAddVectorCacheSuccesses = 0ULL ;

//---------------------------------------------------------------------------*
//                                                                           *
//       Get node size                                                       *
//                                                                           *
//---------------------------------------------------------------------------*

size_t C_VDD::getNodeSize (void) {
  return C_VDD_hashmap::getNodeSize () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       'C_VDD::cVDDnodeInfo' node compare                                  *
//                                                                           *
//---------------------------------------------------------------------------*

size_t C_VDD::smNodeCompare = 0 ;

intptr_t C_VDD::cVDDnodeInfo::compare (const cVDDnodeInfo & inInfo) const {
  smNodeCompare ++ ;
  intptr_t result = ((intptr_t) mPtrToSameIndex) - ((intptr_t) inInfo.mPtrToSameIndex) ;
  if (result == 0) {
    result = ((intptr_t) mPtrToNextIndex) - ((intptr_t) inInfo.mPtrToNextIndex) ;
  }
  if (result == 0) {
    result = mIndex - inInfo.mIndex ;
  }
  if (result == 0) {
    result = ((intptr_t) mValue) - ((intptr_t) inInfo.mValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

#ifdef __MWERK__
  #pragma mark Find or Add
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//       Internal static method for adding a value to an index               *
//                                                                           *
//---------------------------------------------------------------------------*

C_VDD::cVDDnodeInfo * C_VDD::
find_or_add (const T_vdd_zsl_index inIndex,
             const T_vdd_zsl_value inValue,
             cVDDnodeInfo * const inPtrToNextIndex,
             cVDDnodeInfo * const inPtrToSameIndex) {
  cVDDnodeInfo * p ;
  if (inPtrToNextIndex == kEMPTY_SET) {
    p = inPtrToSameIndex ;
  }else if ((inValue == 0) && (inPtrToSameIndex == kEMPTY_SET)) {
    p = inPtrToNextIndex ;
  }else{
  //--- Do search or insert
    cVDDnodeInfo info ;
    info.mIndex = inIndex ;
    info.mValue = inValue ;
    info.mPtrToNextIndex = inPtrToNextIndex ;
    info.mPtrToSameIndex = inPtrToSameIndex ;
    bool insertionPerformed = false ; // Not used
    p = gMap.search_or_insert (info, insertionPerformed) ;
    if (insertionPerformed) {
      smCurrentNodeCount ++ ;
      smNodeCount ++ ;
      p->mMaxInfosPtr = 0 ;
    }
  }
  return p ;
}

//---------------------------------------------------------------------------*

#ifdef __MWERK__
  #pragma mark Add Value at Index
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//       Add a value at index                                                *
//                                                                           *
//---------------------------------------------------------------------------*

C_VDD::cVDDnodeInfo * C_VDD::
internalAddValueAtIndex (cVDDnodeInfo * const inPtr,
                         const T_vdd_zsl_value inValue,
                         const T_vdd_zsl_index inIndex) {
  cVDDnodeInfo * result ;
  if (inPtr == kEMPTY_SET) {
    result = kEMPTY_SET ;
  }else if (inPtr == kNULL_SET) {
    result = find_or_add (inIndex, inValue, kNULL_SET, kEMPTY_SET) ;
  }else{
    const T_vdd_zsl_index index = inPtr->mIndex ;
    if (index < inIndex) {
      result = find_or_add (index, inPtr->mValue,
                            internalAddValueAtIndex (inPtr->mPtrToNextIndex, inValue, inIndex),
                            internalAddValueAtIndex (inPtr->mPtrToSameIndex, inValue, inIndex)) ;
    }else if (index == inIndex) {
      result = find_or_add (index, (T_vdd_zsl_value) (inPtr->mValue + inValue),
                            inPtr->mPtrToNextIndex,
                            internalAddValueAtIndex (inPtr->mPtrToSameIndex, inValue, inIndex)) ;
    }else{ // index > inIndex
      result = find_or_add (inIndex, inValue, inPtr, kEMPTY_SET) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

void C_VDD::
addValueAtIndex (const T_vdd_zsl_value inValue,
                 const T_vdd_zsl_index inIndex) {
  if (inValue != 0) {
    mRootPointer = internalAddValueAtIndex (mRootPointer, inValue, inIndex) ;
  }
}


//---------------------------------------------------------------------------*

#ifdef __MWERK__
  #pragma mark Print Set
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//       Print a set                                                         *
//                                                                           *
//---------------------------------------------------------------------------*

 void C_VDD::
 internalPrintSet (AC_OutputStream & inStream,
                   cVDDnodeInfo * const inPtr,
                   const TC_UniqueArray <String> & inNames,
                   int32_t inArray [],
                   const T_vdd_zsl_index inIndex) {
  if (inPtr == kNULL_SET) {
    inStream.addString ("  <") ;
    bool firstPrint = true ;
    for (int32_t i=0 ; i<inIndex ; i++) {
      if (inArray [i] != 0) {
        if (firstPrint) {
          firstPrint = false ;
        }else{
          inStream.addString (" ") ;
        }
        inStream.addString (inNames (i COMMA_HERE)) ;
        inStream.addString (":") ;
        inStream.addSigned (inArray [i]) ;
      }
    }
    inStream.addString (">\n") ;
  }else if (inPtr != kEMPTY_SET){
    const T_vdd_zsl_index index = inPtr->mIndex ;
    for (T_vdd_zsl_index i=inIndex ; i<index ; i++) {
      inArray [i] = 0 ;
    }
    inArray [index] = inPtr->mValue ;
    internalPrintSet (inStream, inPtr->mPtrToNextIndex, inNames, inArray, (T_vdd_zsl_index) (index + 1)) ;
    internalPrintSet (inStream, inPtr->mPtrToSameIndex, inNames, inArray, index) ;
  }
}

//---------------------------------------------------------------------------*

void C_VDD
::printSet (AC_OutputStream & inStream,
            const TC_UniqueArray <String> & inNames) const {
  if (mRootPointer == kEMPTY_SET) {
    inStream.addString ("  (empty set)\n") ;
  }else if (mRootPointer == kNULL_SET) {
    inStream.addString ("  <>\n") ;
  }else{
    int32_t * array = (int32_t *) NULL ;
    macroMyNewArray (array, int32_t, size_t (inNames.count ())) ;
    internalPrintSet (inStream, mRootPointer, inNames, array, 0) ;
    macroMyDeleteArray (array) ;
  }
}

//---------------------------------------------------------------------------*

#ifdef __MWERK__
  #pragma mark Print Nodes
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//       Print the nodes of a set                                            *
//                                                                           *
//---------------------------------------------------------------------------*

 void C_VDD
 ::internalPrintSetNodes (AC_OutputStream & inStream,
                          cVDDnodeInfo * const inPtr,
                          const TC_UniqueArray <String> & inNames) {
  if ((inPtr != kEMPTY_SET) && (inPtr != kNULL_SET) && (! inPtr->isMarked ())) {
    inPtr->mark () ;
    inStream.addString ("  ") ;
    inStream.addPointer (inPtr) ;
    inStream.addString (":") ;
    inStream.addString (inNames (inPtr->mIndex COMMA_HERE)) ;
    inStream.addString (":") ;
    inStream.addSigned (inPtr->mValue);
    inStream.addString (", next index : ") ;
    if (inPtr->mPtrToNextIndex == kNULL_SET) {
      inStream.addString ("NULL") ;
    }else{
      inStream.addPointer (inPtr->mPtrToNextIndex) ;
    }
    inStream.addString (", same index : ") ;
    if (inPtr->mPtrToSameIndex == kEMPTY_SET) {
      inStream.addString ("EMPTY") ;
    }else{
      inStream.addPointer (inPtr->mPtrToSameIndex) ;
    }
    inStream.addString ("\n") ;
    internalPrintSetNodes (inStream, inPtr->mPtrToNextIndex, inNames) ;
    internalPrintSetNodes (inStream, inPtr->mPtrToSameIndex, inNames) ;
  }
}

//---------------------------------------------------------------------------*

void C_VDD
::printSetNodes (AC_OutputStream & inStream,
                 const TC_UniqueArray <String> & inNames) const {
//--- Count nodes (for being able to display the elements count)
  getSetCardinal () ;
  gMap.unmarkAllObjects () ;
  internalPrintSetNodes (inStream, mRootPointer, inNames) ;
}

//---------------------------------------------------------------------------*

#ifdef __MWERK__
  #pragma mark Get Firable From ZSV
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//       Get subset greater or equal to vector                               *
//                                                                           *
//---------------------------------------------------------------------------*

C_VDD::cVDDnodeInfo * C_VDD::
internalGetFirable (cVDDnodeInfo * const inPtr,
                    const C_ZSV & inVector) {
  cVDDnodeInfo * result ;
  if (inPtr == kEMPTY_SET) {
    result = kEMPTY_SET ;
    smTrivialGetFirable ++ ;
  }else if (inVector.isNullVector ()) {
    result = inPtr ;
    smTrivialGetFirable ++ ;
  }else if (inPtr == kNULL_SET) {
    result = kEMPTY_SET ;
    smTrivialGetFirable ++ ;
  }else{
  //--- Here, inVector is not null and inPtr set is neither empty, neither NULL
    bool cacheSuccess = false ; int32_t hashCode ;
    gGetFirableCache.getCacheEntry ((intptr_t) inPtr, inVector.getLongID (), cacheSuccess, hashCode, result) ;
    if (cacheSuccess) {
      smGetFirableCacheSuccesses ++ ;
    }else{
      C_ZSV v = inVector ;
      T_vdd_zsl_index vectorIndex ; T_vdd_zsl_value vectorValue ;
      C_ZSV::explore_vdl (v, vectorIndex, vectorValue) ;
      const T_vdd_zsl_index setIndex = inPtr->mIndex ;
      if (setIndex < vectorIndex) {
        result = find_or_add (setIndex, inPtr->mValue,
                              internalGetFirable (inPtr->mPtrToNextIndex, inVector),
                              internalGetFirable (inPtr->mPtrToSameIndex, inVector)) ;
      }else if (setIndex == vectorIndex) {
        if (inPtr->mValue < vectorValue) {
          result = internalGetFirable (inPtr->mPtrToSameIndex, inVector) ;
        }else{
          result = find_or_add (setIndex, inPtr->mValue,
                                internalGetFirable (inPtr->mPtrToNextIndex, v),
                                internalGetFirable (inPtr->mPtrToSameIndex, inVector)) ;
        }
      }else{ // setIndex > vectorIndex
        result = kEMPTY_SET ;
      }
      gGetFirableCache.writeCacheEntry ((intptr_t) inPtr, inVector.getLongID (), hashCode, result) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

C_VDD C_VDD::getFirable (const C_ZSV & inVector) const {
  C_VDD result ;
  #ifdef COMPUTE_OPERATIONS_DURATION
    uint64_t start ; ::Microseconds ((UnsignedWide *) & start) ;
  #endif
  result.mRootPointer = internalGetFirable (mRootPointer, inVector) ;
  #ifdef COMPUTE_OPERATIONS_DURATION
    uint64_t end ; ::Microseconds ((UnsignedWide *) & end) ;
    gGetFirableDuration += end - start ;
  #endif
  return result ;
}

//---------------------------------------------------------------------------*

#ifdef __MWERK__
  #pragma mark Get Firable From AEDD
#endif

//---------------------------------------------------------------------------*

C_VDD::cVDDnodeInfo * C_VDD::internalGetFirableFromAEDD (cVDDnodeInfo * const inVDDptr,
                                                         const intptr_t inAEDDptr) {
  cVDDnodeInfo * result = kEMPTY_SET ;
  if (inVDDptr == kEMPTY_SET) {
    result = kEMPTY_SET ;
    smTrivialGetFirable ++ ;
  }else if (inAEDDptr == 1) { // True
    result = inVDDptr ;
    smTrivialGetFirable ++ ;
  }else if (inAEDDptr == 0) { // False
    result = kEMPTY_SET ;
    smTrivialGetFirable ++ ;
  }else{
    bool cacheSuccess = false ; int32_t hashCode ;
    gGetFirableCache.getCacheEntry ((intptr_t) inVDDptr, inAEDDptr, cacheSuccess, hashCode, result) ;
    if (cacheSuccess) {
      smGetFirableCacheSuccesses ++ ;
    }else{
      const int32_t complement = ((int32_t) inAEDDptr) & 1L ;
      C_AEDD::C_AEDDnode * p = (C_AEDD::C_AEDDnode *) (inAEDDptr & bit0mask) ;
      const intptr_t AEDDelseBranch = p->mFalseBranch ^ complement ;
      const intptr_t AEDDthenBranch = p->mTrueBranch ^ complement ;
      const uint16_t AEDDindex = p->mVar ;
      const intptr_t AEDDvalue = p->mConstant ;
      if (inVDDptr == kNULL_SET) {
        if (AEDDvalue > 0) {
          result = internalGetFirableFromAEDD (inVDDptr, AEDDelseBranch) ;
        }else{
          result = internalGetFirableFromAEDD (inVDDptr, AEDDthenBranch) ;
        }
      }else{ //--- Here, inVDDptr is not null and inAEDDptr set is neither empty, neither NULL
        const T_vdd_zsl_index vddIndex = inVDDptr->mIndex ;
        const T_vdd_zsl_value vddValue = inVDDptr->mValue ;
        if (vddIndex < AEDDindex) {
          result = find_or_add (vddIndex, vddValue,
                                internalGetFirableFromAEDD (inVDDptr->mPtrToNextIndex, inAEDDptr),
                                internalGetFirableFromAEDD (inVDDptr->mPtrToSameIndex, inAEDDptr)) ;
         }else if (vddIndex > AEDDindex) {
           if (AEDDvalue > 0) {
             result = internalGetFirableFromAEDD (inVDDptr, AEDDelseBranch) ;
           }else{
             result = internalGetFirableFromAEDD (inVDDptr, AEDDthenBranch) ;
           }
        }else{ // vddIndex == AEDDindex
          if (AEDDvalue < vddValue) {
            result = find_or_add (vddIndex, vddValue,
                                  internalGetFirableFromAEDD (inVDDptr->mPtrToNextIndex, AEDDthenBranch),
                                  internalGetFirableFromAEDD (inVDDptr->mPtrToSameIndex, AEDDthenBranch)) ;
          }else if (AEDDvalue > vddValue) {
            result = find_or_add (vddIndex, vddValue,
                                  internalGetFirableFromAEDD (inVDDptr->mPtrToNextIndex, AEDDelseBranch),
                                  internalGetFirableFromAEDD (inVDDptr->mPtrToSameIndex, inAEDDptr)) ;
          }else{ // AEDDvalue == vddValue
            result = find_or_add (vddIndex, vddValue,
                                  internalGetFirableFromAEDD (inVDDptr->mPtrToNextIndex, AEDDthenBranch),
                                  internalGetFirableFromAEDD (inVDDptr->mPtrToSameIndex, AEDDthenBranch)) ;
          }
        }
      }
      gGetFirableCache.writeCacheEntry ((intptr_t) inVDDptr, inAEDDptr, hashCode, result) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

C_VDD C_VDD::getFirableFromAEDD (const C_AEDD & inVector) const {
  C_VDD result ;
  result.mRootPointer = internalGetFirableFromAEDD (mRootPointer, inVector.mAEDDvalue) ;
  return result ;
}

//---------------------------------------------------------------------------*

#ifdef __MWERK__
  #pragma mark Get NULL suppressed Set
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//       NULL suppress                                                       *
//                                                                           *
//---------------------------------------------------------------------------*

C_VDD::cVDDnodeInfo * C_VDD
::internalGetNullSuppressed (cVDDnodeInfo * const inPtr) {
  cVDDnodeInfo * result ;
  if (inPtr == kEMPTY_SET) {
    result = kEMPTY_SET ;
  }else if (inPtr == kNULL_SET) {
    result = kEMPTY_SET ;
  }else{
    const T_vdd_zsl_index index = inPtr->mIndex ;
    const T_vdd_zsl_value value = inPtr->mValue ;
    if (value < 0) {
      result = find_or_add (index, value,
                            inPtr->mPtrToNextIndex,
                            internalGetNullSuppressed (inPtr->mPtrToSameIndex)) ;
    }else if (value == 0) {
      result = find_or_add (index, value,
                            internalGetNullSuppressed (inPtr->mPtrToNextIndex),
                            inPtr->mPtrToSameIndex) ;
    }else{ // value > 0
      result = inPtr ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

C_VDD C_VDD::getNullSuppressed (void) const {
  C_VDD result ;
  #ifdef COMPUTE_OPERATIONS_DURATION
    uint64_t start ; ::Microseconds ((UnsignedWide *) & start) ;
  #endif
  result.mRootPointer = internalGetNullSuppressed (mRootPointer) ;
  #ifdef COMPUTE_OPERATIONS_DURATION
    uint64_t end ; ::Microseconds ((UnsignedWide *) & end) ;
    gNullSuppressDuration += end - start ;
  #endif
  return result ;
}

//---------------------------------------------------------------------------*

#ifdef __MWERK__
  #pragma mark Get Intersection with NULL
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//       Get intersection with NULL vector                                   *
//                                                                           *
//---------------------------------------------------------------------------*

C_VDD::cVDDnodeInfo * C_VDD
::internalGetIntersectionWithNull (cVDDnodeInfo * const inPtr) {
  cVDDnodeInfo * result ;
  if (inPtr == kEMPTY_SET) {
    result = kEMPTY_SET ;
  }else if (inPtr == kNULL_SET) {
    result = kNULL_SET ;
  }else{
    const int32_t value = inPtr->mValue ;
    if (value < 0) {
      result = internalGetIntersectionWithNull (inPtr->mPtrToSameIndex) ;
    }else if (value == 0) {
      result = internalGetIntersectionWithNull (inPtr->mPtrToNextIndex) ;
    }else{ // value > 0
      result = kEMPTY_SET ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

C_VDD C_VDD::getIntersectionWithNull (void) const {
  C_VDD result ;
  #ifdef COMPUTE_OPERATIONS_DURATION
    uint64_t start ; ::Microseconds ((UnsignedWide *) & start) ;
  #endif
  result.mRootPointer = internalGetIntersectionWithNull (mRootPointer) ;
  #ifdef COMPUTE_OPERATIONS_DURATION
    uint64_t end ; ::Microseconds ((UnsignedWide *) & end) ;
    gGetIntersectionWithNullSetDuration += end - start ;
  #endif
  return result ;
}

//---------------------------------------------------------------------------*

#ifdef __MWERK__
  #pragma mark Get Greater or Equal
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//       Get greater or equal                                                *
//                                                                           *
//  Get the set of 'inPtr' vectors that are greater or equal of              *
//  a vector in 'inTestPtr'                                                  *
//                                                                           *
//---------------------------------------------------------------------------*

C_VDD::cVDDnodeInfo * C_VDD
::internalGetGreaterOrEqual (cVDDnodeInfo * const inPtr,
                             cVDDnodeInfo * const inTestPtr) {
  cVDDnodeInfo * result ;
  if (inTestPtr == kEMPTY_SET) {
    result = inPtr ; // All vectors are greater or equal
  }else if (inTestPtr == kNULL_SET) {
    result = inPtr ; // All vectors are greater or equal
  }else if (inPtr == kEMPTY_SET) {
    result = kEMPTY_SET ;
  }else if (inPtr == kNULL_SET) {
    result = internalGetIntersectionWithNull (inPtr) ; // Only null vector, if it exists
  }else{
    const T_vdd_zsl_index index = inPtr->mIndex ;
    const T_vdd_zsl_value value = inPtr->mValue ;
    const T_vdd_zsl_index testIndex = inTestPtr->mIndex ;
    const T_vdd_zsl_value testValue = inTestPtr->mValue ;
    if (index < testIndex) {
      if (value < 0) {
        result = internalGetGreaterOrEqual (inPtr->mPtrToSameIndex, inTestPtr) ;
      }else{ // value >= 0
        result = find_or_add (index, value,
                              internalGetGreaterOrEqual (inPtr->mPtrToNextIndex, inTestPtr),
                              internalGetGreaterOrEqual (inPtr->mPtrToSameIndex, inTestPtr)) ;
      }
    }else if (index == testIndex) {
      if (value < testValue) {
        result = internalGetGreaterOrEqual (inPtr->mPtrToSameIndex, inTestPtr) ;
      }else if (value == testValue) {
        result = find_or_add (index, value,
                              internalGetGreaterOrEqual (inPtr->mPtrToNextIndex, inTestPtr->mPtrToNextIndex),
                              internalGetGreaterOrEqual (inPtr->mPtrToSameIndex, inTestPtr->mPtrToSameIndex)) ;
      }else{ // value > testValue
        result = find_or_add (index, value,
                              internalGetGreaterOrEqual (inPtr->mPtrToNextIndex, inTestPtr->mPtrToNextIndex),
                              internalGetGreaterOrEqual (inPtr->mPtrToSameIndex, inTestPtr)) ;
      }
    }else{ // index > testIndex
      if (testValue < 0) {
        result = find_or_add (testIndex, 0,
                              internalGetUnion (
                                internalGetGreaterOrEqual (inPtr, inTestPtr->mPtrToNextIndex),
                                internalGetGreaterOrEqual (inPtr, inTestPtr->mPtrToSameIndex)),
                              kEMPTY_SET) ;
      }else if (testValue == 0) {
        result = internalGetGreaterOrEqual (inPtr, inTestPtr->mPtrToNextIndex) ;
      }else{ // testValue > 0
        result = kEMPTY_SET ;
      }
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

C_VDD C_VDD::getGreaterOrEqual (const C_VDD & inOperand) const {
  C_VDD result ;
  #ifdef COMPUTE_OPERATIONS_DURATION
    uint64_t start ; ::Microseconds ((UnsignedWide *) & start) ;
  #endif
  result.mRootPointer = internalGetGreaterOrEqual (mRootPointer, inOperand.mRootPointer) ;
  #ifdef COMPUTE_OPERATIONS_DURATION
    uint64_t end ; ::Microseconds ((UnsignedWide *) & end) ;
    gGetGreaterOrEqualDuration += end - start ;
  #endif
  return result ;
}

//---------------------------------------------------------------------------*

#ifdef __MWERK__
  #pragma mark Get (strictly) Greater
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//       Get greater                                                         *
//  Get the set of 'inPtr' vectors that are (strictly) greater of            *
//  a vector in 'inTestPtr'                                                  *
//                                                                           *
//---------------------------------------------------------------------------*

C_VDD::cVDDnodeInfo * C_VDD
::internalGetGreater (cVDDnodeInfo * const inPtr,
                      cVDDnodeInfo * const inTestPtr) {
  cVDDnodeInfo * result ;
  if (inPtr == inTestPtr) {
    result = kEMPTY_SET ; // Empty
  }else if (inTestPtr == kEMPTY_SET) {
    result = inPtr ; // All vectors are stricly greater
  }else if (inTestPtr == kNULL_SET) {
    result = internalGetNullSuppressed (inPtr) ; // All vector but null vector
  }else if (inPtr == kEMPTY_SET) {
    result = kEMPTY_SET ; // No vector
  }else if (inPtr == kNULL_SET) {
    result = kEMPTY_SET ; // No vector
  }else{
    const T_vdd_zsl_index index = inPtr->mIndex ;
    const T_vdd_zsl_value value = inPtr->mValue ;
    const T_vdd_zsl_index testIndex = inTestPtr->mIndex ;
    const T_vdd_zsl_value testValue = inTestPtr->mValue ;
    if (index < testIndex) {
      if (value < 0) {
        result = internalGetGreater (inPtr->mPtrToSameIndex, inTestPtr) ;
      }else if (value == 0) {
        result = find_or_add (index, 0,
                              internalGetGreater (inPtr->mPtrToNextIndex, inTestPtr),
                              internalGetGreaterOrEqual (inPtr->mPtrToSameIndex, inTestPtr)) ;
      }else{ // value > 0
        result = find_or_add (index, value,
                              internalGetGreaterOrEqual (inPtr->mPtrToNextIndex, inTestPtr),
                              internalGetGreaterOrEqual (inPtr->mPtrToSameIndex, inTestPtr)) ;
      }
    }else if (index == testIndex) {
      if (value < testValue) {
        result = internalGetGreater (inPtr->mPtrToSameIndex, inTestPtr) ;
      }else if (value == testValue) {
        result = find_or_add (index, value,
                              internalGetGreater (inPtr->mPtrToNextIndex, inTestPtr->mPtrToNextIndex),
                              internalGetGreaterOrEqual (inPtr->mPtrToSameIndex, inTestPtr)) ;
      }else{ // value > testValue
        result = find_or_add (index, value,
                              internalGetGreaterOrEqual (inPtr->mPtrToNextIndex, inTestPtr->mPtrToNextIndex),
                              internalGetGreater (inPtr->mPtrToSameIndex, inTestPtr->mPtrToSameIndex)) ;
      }
    }else{ // index > testIndex
      if (testValue < 0) {
        result = find_or_add (testIndex, 0,
                              internalGetUnion (
                                internalGetGreaterOrEqual (inPtr, inTestPtr->mPtrToNextIndex),
                                internalGetGreater (inPtr, inTestPtr->mPtrToSameIndex)),
                              kEMPTY_SET) ;
      }else if (testValue == 0) {
        result = internalGetGreater (inPtr, inTestPtr->mPtrToNextIndex) ;
      }else{ // testValue > 0
        result = kEMPTY_SET ;
      }
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

C_VDD C_VDD::getGreaterThan (const C_VDD & inOperand) const {
  C_VDD result ;
  #ifdef COMPUTE_OPERATIONS_DURATION
    uint64_t start ; ::Microseconds ((UnsignedWide *) & start) ;
  #endif
  result.mRootPointer = internalGetGreater (mRootPointer, inOperand.mRootPointer) ;
  #ifdef COMPUTE_OPERATIONS_DURATION
    uint64_t end ; ::Microseconds ((UnsignedWide *) & end) ;
    gGetGreaterDuration += end - start ;
  #endif
  return result ;
}

//---------------------------------------------------------------------------*

#ifdef __MWERK__
  #pragma mark Get Bound Set
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//   Get the vector subset that has one (or more) index equal to the bound   *
//                                                                           *
//---------------------------------------------------------------------------*

C_VDD::cVDDnodeInfo * C_VDD::
internalGetBoundSet (cVDDnodeInfo * const inPtr,
                     const T_vdd_zsl_value inBound) {
  cVDDnodeInfo * result ;
  if (inPtr == kEMPTY_SET) {
    result = kEMPTY_SET ;
  }else if (inPtr == kNULL_SET) {
    result = (inBound > 0) ? kEMPTY_SET : kNULL_SET ;
  }else{
    const T_vdd_zsl_value value = inPtr->mValue ;
    if (value < inBound) {
       result = find_or_add (inPtr->mIndex, value,
                             internalGetBoundSet (inPtr->mPtrToNextIndex, inBound),
                             internalGetBoundSet (inPtr->mPtrToSameIndex, inBound)) ;
    }else{
      result = inPtr ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

C_VDD C_VDD::getBoundSet (void) const {
  const T_vdd_zsl_value bound = getMaxValue () ;
  C_VDD result ;
  #ifdef COMPUTE_OPERATIONS_DURATION
    uint64_t start ; ::Microseconds ((UnsignedWide *) & start) ;
  #endif
  result.mRootPointer = internalGetBoundSet (mRootPointer, bound) ;
  #ifdef COMPUTE_OPERATIONS_DURATION
    uint64_t end ; ::Microseconds ((UnsignedWide *) & end) ;
    gGetBoundDuration += end - start ;
  #endif
  return result ;
}

//---------------------------------------------------------------------------*

#ifdef __MWERK__
  #pragma mark Add Vector
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//       Add vector                                                          *
//                                                                           *
//---------------------------------------------------------------------------*

C_VDD::cVDDnodeInfo * C_VDD
::internalAddVector (cVDDnodeInfo * const inPtr,
                     const C_ZSV & inVector) {
  cVDDnodeInfo * result ;
  if (inPtr == kEMPTY_SET) {
    result = kEMPTY_SET ;
    smTrivialAddVector ++ ;
  }else if (inVector.isNullVector ()) {
    result = inPtr ;
    smTrivialAddVector ++ ;
  }else{
    bool cacheSuccess = false ; int32_t hashCode ;
    gAddVectorCache.getCacheEntry ((intptr_t) inPtr, inVector.getLongID (), cacheSuccess, hashCode, result) ;
    if (cacheSuccess) {
      smAddVectorCacheSuccesses ++ ;
    }else{
      if (inPtr == kNULL_SET) { //--- inVector is not NULL
        C_ZSV v = inVector ;
        T_vdd_zsl_index vectorIndex ; T_vdd_zsl_value vectorValue ;
        C_ZSV::explore_vdl (v, vectorIndex, vectorValue) ;
        result = find_or_add (vectorIndex, vectorValue,
                              internalAddVector (kNULL_SET, v),
                              kEMPTY_SET) ;
      }else{
        C_ZSV v = inVector ;
        T_vdd_zsl_index vectorIndex ; T_vdd_zsl_value vectorValue ;
        C_ZSV::explore_vdl (v, vectorIndex, vectorValue) ;
        const T_vdd_zsl_index setIndex = inPtr->mIndex ;
        if (setIndex < vectorIndex) {
          result = find_or_add (setIndex, inPtr->mValue,
                                internalAddVector (inPtr->mPtrToNextIndex, inVector),
                                internalAddVector (inPtr->mPtrToSameIndex, inVector)) ;
        }else if (setIndex == vectorIndex) {
          result = find_or_add (setIndex, (T_vdd_zsl_value) (inPtr->mValue + vectorValue),
                                internalAddVector (inPtr->mPtrToNextIndex, v),
                                internalAddVector (inPtr->mPtrToSameIndex, inVector)) ;
        }else{ // setIndex > vectorIndex
          result = find_or_add (vectorIndex, vectorValue,
                                internalAddVector (inPtr, v),
                                kEMPTY_SET) ;
        }
      }
      gAddVectorCache.writeCacheEntry ((intptr_t) inPtr, inVector.getLongID (), hashCode, result) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

C_VDD C_VDD::addVector (const C_ZSV & inVector) const {
  C_VDD result ;
  #ifdef COMPUTE_OPERATIONS_DURATION
    uint64_t start ; ::Microseconds ((UnsignedWide *) & start) ;
  #endif
  result.mRootPointer = internalAddVector (mRootPointer, inVector) ;
  #ifdef COMPUTE_OPERATIONS_DURATION
    uint64_t end ; ::Microseconds ((UnsignedWide *) & end) ;
    gAddVectorDuration += end - start ;
  #endif
  return result ;
}


//---------------------------------------------------------------------------*

#ifdef __MWERK__
  #pragma mark Target Vector
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//       Compute target vector                                               *
//                                                                           *
//---------------------------------------------------------------------------*

C_VDD::cVDDnodeInfo * C_VDD
::internalComputeTargetVector (cVDDnodeInfo * const inPtr,
                               const C_PCL & inVector) {
  cVDDnodeInfo * result ;
  if (inPtr == kEMPTY_SET) {
    result = kEMPTY_SET ;
    smTrivialAddVector ++ ;
  }else if (inVector.isNullVector ()) {
    result = inPtr ;
    smTrivialAddVector ++ ;
  }else{
    bool cacheSuccess = false ; int32_t hashCode ;
    gAddVectorCache.getCacheEntry (intptr_t (inPtr), inVector.getLongID (), cacheSuccess, hashCode, result) ;
    if (cacheSuccess) {
      smAddVectorCacheSuccesses ++ ;
    }else{
      int16_t vectorIndex ; T_vdd_zsl_value vectorValue ; bool assignment ;
      const C_PCL v = inVector.explore_pcl (vectorIndex, vectorValue, assignment) ;
      if (inPtr == kNULL_SET) {
        result = find_or_add (vectorIndex, vectorValue,
                              internalComputeTargetVector (kNULL_SET, v),
                              kEMPTY_SET) ;
      }else if (inPtr->mIndex < vectorIndex) {
        result = find_or_add (inPtr->mIndex, inPtr->mValue,
                              internalComputeTargetVector (inPtr->mPtrToNextIndex, inVector),
                              internalComputeTargetVector (inPtr->mPtrToSameIndex, inVector)) ;
      }else if (inPtr->mIndex == vectorIndex) {
        if (assignment) {
          result = inPtr->mPtrToNextIndex ;
          cVDDnodeInfo * p = inPtr->mPtrToSameIndex ;
          while (p != kEMPTY_SET) {
            result = internalGetUnion (result, p->mPtrToNextIndex) ;
            p = p->mPtrToSameIndex ;
          }
          result = find_or_add (vectorIndex, vectorValue,
                                internalComputeTargetVector (result, v),
                                kEMPTY_SET) ;
        }else if ((inPtr->mValue == MAX_VDD_ZSL_VALUE) || (vectorValue == MAX_VDD_ZSL_VALUE)) {
          //printf ("******** A ******* %ld %ld \n", inPtr->mValue, vectorValue) ;
          result = inPtr->mPtrToNextIndex ;
          cVDDnodeInfo * p = inPtr->mPtrToSameIndex ;
          while (p != kEMPTY_SET) {
            result = internalGetUnion (result, p->mPtrToNextIndex) ;
            p = p->mPtrToSameIndex ;
          }
          result = find_or_add (vectorIndex, MAX_VDD_ZSL_VALUE,
                                internalComputeTargetVector (result, v),
                                kEMPTY_SET) ;
        }else if ((((int64_t) inPtr->mValue) + ((int64_t) vectorValue)) > ((int64_t) MAX_VDD_ZSL_VALUE)) {
          //printf ("******** B ******* %ld %ld \n", inPtr->mValue, vectorValue) ;
          result = inPtr->mPtrToNextIndex ;
          cVDDnodeInfo * p = inPtr->mPtrToSameIndex ;
          while (p != kEMPTY_SET) {
            result = internalGetUnion (result, p->mPtrToNextIndex) ;
            p = p->mPtrToSameIndex ;
          }
          result = find_or_add (vectorIndex, MAX_VDD_ZSL_VALUE,
                                internalComputeTargetVector (result, v),
                                kEMPTY_SET) ;
        }else{
           //printf ("******** C ******* %ld %ld \n", inPtr->mValue, vectorValue) ;
           result = find_or_add (vectorIndex, (T_vdd_zsl_value) (inPtr->mValue + vectorValue),
                                 internalComputeTargetVector (inPtr->mPtrToNextIndex, v),
                                 internalComputeTargetVector (inPtr->mPtrToSameIndex, inVector)) ;
        }
      }else{ // inPtr->mIndex > vectorIndex
        result = find_or_add (vectorIndex, vectorValue,
                              internalComputeTargetVector (inPtr, v),
                              kEMPTY_SET) ;
      }
      gAddVectorCache.writeCacheEntry ((intptr_t) inPtr, inVector.getLongID (), hashCode, result) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

C_VDD C_VDD::computeTargetVector (const C_PCL & inVector) const {
  C_VDD result ;
  #ifdef COMPUTE_OPERATIONS_DURATION
    uint64_t start ; ::Microseconds ((UnsignedWide *) & start) ;
  #endif
  result.mRootPointer = internalComputeTargetVector (mRootPointer, inVector) ;
  #ifdef COMPUTE_OPERATIONS_DURATION
    uint64_t end ; ::Microseconds ((UnsignedWide *) & end) ;
    gAddVectorDuration += end - start ;
  #endif
  return result ;
}

//---------------------------------------------------------------------------*

#ifdef __MWERK__
  #pragma mark Compute Union
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//       Set union                                                           *
//                                                                           *
//---------------------------------------------------------------------------*

C_VDD::cVDDnodeInfo * C_VDD
::internalGetUnion (cVDDnodeInfo * const inS1,
                    cVDDnodeInfo * const inS2) {
  cVDDnodeInfo * result ;
  if (inS1 == inS2) {
    result = inS1 ;
    smTrivialUnion ++ ;
  }else{
  //--- Reorder
    cVDDnodeInfo * s1 = inS1 ;
    cVDDnodeInfo * s2 = inS2 ;
    if ((intptr_t) inS1 > ((intptr_t) inS2)) {
      s1 = inS2 ; s2 = inS1 ;
    }
  //--- Cases for S1,         S2
  //          empty set    null set
  //          empty set    non trivial
  //          null set     non trivial
  //          non trivial  non trivial
    if (s1 == kEMPTY_SET) {
      result = s2 ;
      smTrivialUnion ++ ;
    }else{
      bool cacheSuccess = false ; int32_t hashCode ;
      gSetUnionCache.getCacheEntry ((intptr_t) s1, (intptr_t) s2, cacheSuccess, hashCode, result) ;
      if (cacheSuccess) {
        smSetUnionCacheSuccesses ++ ;
      }else{
        if (s1 == kNULL_SET) {
          const T_vdd_zsl_value s2Value = s2->mValue ;
          if (s2Value < 0) {
            result = find_or_add (s2->mIndex, s2Value,
                                  s2->mPtrToNextIndex,
                                  internalGetUnion (kNULL_SET, s2->mPtrToSameIndex)) ;
          }else if (s2Value == 0) {
            result = find_or_add (s2->mIndex, s2Value,
                                  internalGetUnion (kNULL_SET, s2->mPtrToNextIndex),
                                  s2->mPtrToSameIndex) ;
          }else{ // s2Value > 0
            result = find_or_add (s2->mIndex, 0, kNULL_SET, s2) ;
          }
        }else{ // non trivial, non trivial
        //--- In s1, the lower index
          if (s1->mIndex > s2->mIndex) {
            cVDDnodeInfo * temporary = s1 ; s1 = s2 ; s2 = temporary ;
          }
        //--- Get values ans indexes
          const T_vdd_zsl_index s1Index = s1->mIndex ;
          const T_vdd_zsl_index s2Index = s2->mIndex ;
          const T_vdd_zsl_value s1Value = s1->mValue ;
          const T_vdd_zsl_value s2Value = s2->mValue ;
          if (s1Index < s2Index) {
            if (s1Value < 0) {
              result = find_or_add (s1Index, s1Value,
                                    s1->mPtrToNextIndex,
                                    internalGetUnion (s1->mPtrToSameIndex, s2)) ;
            }else if (s1Value == 0) {
              result = find_or_add (s1Index, 0,
                                    internalGetUnion (s1->mPtrToNextIndex, s2),
                                    s1->mPtrToSameIndex) ;
            }else{ // s1Value > 0
              result = find_or_add (s1Index, 0, s2, s1) ;
            }
          }else{ // s1Index == s2Index
            if (s1Value < s2Value) {
              result = find_or_add (s1Index, s1Value,
                                    s1->mPtrToNextIndex,
                                    internalGetUnion (s1->mPtrToSameIndex, s2)) ;
            }else if (s1Value == s2Value) {
              result = find_or_add (s1Index, s1Value,
                                    internalGetUnion (s1->mPtrToNextIndex, s2->mPtrToNextIndex),
                                    internalGetUnion (s1->mPtrToSameIndex, s2->mPtrToSameIndex)) ;
            }else{ // s1Value > s2Value
              result = find_or_add (s1Index, s2Value,
                                    s2->mPtrToNextIndex,
                                    internalGetUnion (s2->mPtrToSameIndex, s1)) ;
            }
          }
        }
      //--- Enter result in cache
        gSetUnionCache.writeCacheEntry ((intptr_t) s1, (intptr_t) s2, hashCode, result) ;
      }
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

C_VDD C_VDD::operator | (const C_VDD & inOperand) const {
  C_VDD result ;
  #ifdef COMPUTE_OPERATIONS_DURATION
    uint64_t start ; ::Microseconds ((UnsignedWide *) & start) ;
  #endif
  result.mRootPointer = internalGetUnion (mRootPointer, inOperand.mRootPointer) ;
  #ifdef COMPUTE_OPERATIONS_DURATION
    uint64_t end ; ::Microseconds ((UnsignedWide *) & end) ;
    gSetUnionDuration += end - start ;
  #endif
  return result ;
}

//---------------------------------------------------------------------------*

void C_VDD::operator |= (const C_VDD & inOperand) {
  #ifdef COMPUTE_OPERATIONS_DURATION
    uint64_t start ; ::Microseconds ((UnsignedWide *) & start) ;
  #endif
  mRootPointer = internalGetUnion (mRootPointer, inOperand.mRootPointer) ;
  #ifdef COMPUTE_OPERATIONS_DURATION
    uint64_t end ; ::Microseconds ((UnsignedWide *) & end) ;
    gSetUnionDuration += end - start ;
  #endif
}

//---------------------------------------------------------------------------*

#ifdef __MWERK__
  #pragma mark Get Node Count
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//       Get node count                                                      *
//                                                                           *
//---------------------------------------------------------------------------*

int32_t C_VDD::internalGetNodesCount (cVDDnodeInfo * const inPtr) {
  int32_t result = 0 ;
  if ((inPtr != kEMPTY_SET) && (inPtr != kNULL_SET) && (! inPtr->isMarked ())) {
    inPtr->mark () ;
    result = 1 + internalGetNodesCount (inPtr->mPtrToNextIndex)
               + internalGetNodesCount (inPtr->mPtrToSameIndex) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

void C_VDD::internalUnmarkNodes (cVDDnodeInfo * const inPtr) {
  if ((inPtr != kEMPTY_SET) && (inPtr != kNULL_SET) && inPtr->isMarked ()) {
    inPtr->unmark () ;
    internalUnmarkNodes (inPtr->mPtrToNextIndex) ;
    internalUnmarkNodes (inPtr->mPtrToSameIndex) ;
  }
}

//---------------------------------------------------------------------------*

int32_t C_VDD::getNodesCount (void) const {
//--- First : count and mark nodes
  const int32_t nodeCount = internalGetNodesCount (mRootPointer) ;
//--- Second : unmark nodes
  internalUnmarkNodes (mRootPointer) ;
  return nodeCount ;
}

//---------------------------------------------------------------------------*

#ifdef __MWERK__
  #pragma mark Save On File
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//       Save VDD object array on file                                       *
//                                                                           *
//---------------------------------------------------------------------------*

void C_VDD::
internalSaveNode (cVDDnodeInfo * const inPtr,
                  AC_OutputStream & inOutputStream) {
  if ((inPtr != kEMPTY_SET) && (inPtr != kNULL_SET) && (! inPtr->isMarked ())) {
    inPtr->mark () ;
    internalSaveNode (inPtr->mPtrToNextIndex, inOutputStream) ;
    internalSaveNode (inPtr->mPtrToSameIndex, inOutputStream) ;
    inOutputStream.addPointer (inPtr) ;
    inOutputStream.addString (" ") ;
    inOutputStream.addSigned (inPtr->mIndex) ;
    inOutputStream.addString (" ") ;
    inOutputStream.addSigned (inPtr->mValue) ;
    inOutputStream.addString (" ") ;
    inOutputStream.addPointer (inPtr->mPtrToSameIndex) ;
    inOutputStream.addString (" ") ;
    inOutputStream.addPointer (inPtr->mPtrToNextIndex) ;
    inOutputStream.addString ("\n") ;
  }
}

//---------------------------------------------------------------------------*

void C_VDD::
saveArrayOnFile (const TC_UniqueArray <C_VDD> & inArray,
                 AC_OutputStream & inOutputStream) {
//--- Save nodes
  for (int32_t i=0 ; i<inArray.count () ; i++) {
    internalSaveNode (inArray (i COMMA_HERE).mRootPointer, inOutputStream) ;
  }
//--- Signal end of nodes list by zeros
  inOutputStream.addString ("0 0 0 0 0\n") ;
//--- Save root node for each object
  for (int32_t i=0 ; i<inArray.count () ; i++) {
    inOutputStream.addPointer (inArray (i COMMA_HERE).mRootPointer) ;
    inOutputStream.addString ("\n") ;
  }
//--- Unmark all nodes
  for (int32_t i=0 ; i<inArray.count () ; i++) {
    internalUnmarkNodes (inArray (i COMMA_HERE).mRootPointer) ;
  }
}

//---------------------------------------------------------------------------*

#ifdef __MWERK__
  #pragma mark -
#endif

//---------------------------------------------------------------------------*

//#include "generic_maps/TC_Block_AVL_TreeForCollision.h"
//const int32_t kNodeBlockSize = 131072 ;
//typedef TC_Block_AVL_TreeForCollision <cVDDnodeInfo, kNodeBlockSize> cVDDnodeInfoMapType ;

//---------------------------------------------------------------------------*

//--- Class protected static variable for allocation info
//cVDDnodeInfoMapType::cAllocInfo cVDDnodeInfoMapType::smAllocInfo ;

#include "cNode_hashmap.h"

static cVDDnodeInfo_hashmap gNodeMap ;

//---------------------------------------------------------------------------*
//                                                                           *
//       Compute node informations                                           *
//                                                                           *
//---------------------------------------------------------------------------*

void C_VDD::internalComputeInfos (cVDDnodeInfo * const inPtr,
                                  uint64_t & outElementCount,
                                  T_vdd_zsl_value & outMaxValue,
                                  T_vdd_zsl_value & outMaxTokens) {
  if (inPtr == kEMPTY_SET) {
    outElementCount = 0 ;
    outMaxValue = 0 ;
    outMaxTokens = 0 ;
  }else if (inPtr == kNULL_SET) {
    outElementCount = 1 ;
    outMaxValue = 0 ;
    outMaxTokens = 0 ;
  }else{
    cVDDmaxInfos * ptr = (cVDDmaxInfos *) (inPtr->mMaxInfosPtr & bit0mask) ;
    if (ptr != NULL) {
      outElementCount = ptr->mElementsCount ;
      outMaxValue = ptr->mMaxValue ;
      outMaxTokens = ptr->mMaxTokens ;
    }else{
      uint64_t elementCount1 ;
      T_vdd_zsl_value maxValue1 ;
      T_vdd_zsl_value maxTokens1 ;
      uint64_t elementCount2 ;
      T_vdd_zsl_value maxValue2 ;
      T_vdd_zsl_value maxTokens2 ;
      internalComputeInfos (inPtr->mPtrToNextIndex, elementCount1, maxValue1, maxTokens1) ;
      internalComputeInfos (inPtr->mPtrToSameIndex, elementCount2, maxValue2, maxTokens2) ;
      outElementCount = elementCount1 + elementCount2 ;
      outMaxValue = sup (sup (maxValue1, maxValue2), inPtr->mValue) ;
      outMaxTokens = sup (maxTokens2, (T_vdd_zsl_value) (maxTokens1 + inPtr->mValue)) ;
      if (gNodeInfoFreeList == NULL) {
        ptr = new cVDDmaxInfos ;
        gInstanciedMaxInfosObjects ++ ;
      }else{
        ptr = gNodeInfoFreeList ;
        gNodeInfoFreeList = gNodeInfoFreeList->mPtrToNext ;
      }
      ptr->mElementsCount = outElementCount ;
      ptr->mMaxValue = outMaxValue ;
      ptr->mMaxTokens = outMaxTokens ;
      inPtr->mMaxInfosPtr = ((intptr_t) ptr) | (inPtr->mMaxInfosPtr & 1) ;
    }
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Get elements count                                                  *
//                                                                           *
//---------------------------------------------------------------------------*

uint64_t C_VDD::getSetCardinal (void) const {
  uint64_t result ;
  T_vdd_zsl_value maxValue, maxTokens ;
  internalComputeInfos (mRootPointer, result, maxValue, maxTokens) ;
  return result ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Get set max value for all indexes                                   *
//                                                                           *
//---------------------------------------------------------------------------*

T_vdd_zsl_value C_VDD::getMaxValue (void) const {
  uint64_t result ;
  T_vdd_zsl_value maxValue, maxTokens ;
  internalComputeInfos (mRootPointer, result, maxValue, maxTokens) ;
  return maxValue ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Get set max tokens for all vectors                                  *
//                                                                           *
//---------------------------------------------------------------------------*

T_vdd_zsl_value C_VDD::getMaxTokens (void) const {
  uint64_t result ;
  T_vdd_zsl_value maxValue, maxTokens ;
  internalComputeInfos (mRootPointer, result, maxValue, maxTokens) ;
  return maxTokens ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Compute min and max value for each index                            *
//                                                                           *
//---------------------------------------------------------------------------*

void C_VDD::
internalComputeMinMax (cVDDnodeInfo * const inPtr,
                       TC_UniqueArray <int32_t> & inMinArray,
                       TC_UniqueArray <int32_t> & inMaxArray,
                       const int32_t inIndexCount) {
  if ((inPtr != kEMPTY_SET) && (inPtr != kNULL_SET) && (! inPtr->isMarked ())) {
    inPtr->mark () ;
    const int32_t index = (int32_t) inPtr->mIndex ;
    if (index < inIndexCount) {
      const int32_t value = inPtr->mValue ;
      if (value < inMinArray (index COMMA_HERE)) {
        inMinArray (index COMMA_HERE) = value ;
      }
      if (value > inMaxArray (index COMMA_HERE)) {
        inMaxArray (index COMMA_HERE) = value ;
      }
    }
    internalComputeMinMax (inPtr->mPtrToNextIndex, inMinArray, inMaxArray, inIndexCount) ;
    internalComputeMinMax (inPtr->mPtrToSameIndex, inMinArray, inMaxArray, inIndexCount) ;
  }
}

//---------------------------------------------------------------------------*

void C_VDD::
computeMinAndMax (TC_UniqueArray <int32_t> & inMinArray,
                  TC_UniqueArray <int32_t> & inMaxArray,
                  const int32_t inIndexCount) const {
  for (int32_t i=0 ; i<inIndexCount ; i++) {
    inMinArray (i COMMA_HERE) = 0 ;
    inMaxArray (i COMMA_HERE) = 0 ;
  }
  internalUnmarkNodes (mRootPointer) ;
  internalComputeMinMax (mRootPointer, inMinArray, inMaxArray, inIndexCount) ;
  internalUnmarkNodes (mRootPointer) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Collect unused elements                                             *
//                                                                           *
//---------------------------------------------------------------------------*

void C_VDD::internalMarkNode (cVDDnodeInfo * const inPtr) {
  if (inPtr == kEMPTY_SET) {
    // Nothing to do
  }else if (inPtr == kNULL_SET) {
    // Nothing to do
  }else if (! inPtr->isMarked ()) {
    inPtr->mark () ;
    internalMarkNode (inPtr->mPtrToNextIndex) ;
    internalMarkNode (inPtr->mPtrToSameIndex) ;
  }
}

//---------------------------------------------------------------------------*

void C_VDD::collectUnusedNodes (void) {
//--- Second : mark all used elements
  C_VDD * p = gFirstVDD ;
  while (p != NULL) {
    internalMarkNode (p->mRootPointer) ;
    p = p->mPtrToNextExisting ;
  }
//--- First : clear all cache entries
  gSetUnionCache.clearAllCacheEntries () ;
  gGetFirableCache.clearAllCacheEntries () ;
  gAddVectorCache.clearAllCacheEntries () ;
//--- Third : sweep unused objets
  smCurrentNodeCount -= gMap.sweepUnmarkedObjects () ;
//--- Four : if no VDD object, collect cVDDmaxInfos objects from free list
  if (gFirstVDD == NULL) {
    while (gNodeInfoFreeList != NULL) {
      cVDDmaxInfos * ptr = gNodeInfoFreeList->mPtrToNext ;
      delete gNodeInfoFreeList ;
      gNodeInfoFreeList = ptr ;
    }
  }
}

//---------------------------------------------------------------------------*

size_t C_VDD::getHashMapEntriesCount (void) {
  return gMap.getHashMapEntryCount () ;
}

//---------------------------------------------------------------------------*

size_t C_VDD::getMapSizeInBytes (void) {
  return gMap.getMapSizeInBytes () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Print VDD summary                                                   *
//                                                                           *
//---------------------------------------------------------------------------*

void C_VDD::printVDDsummary (AC_OutputStream & inOutputStream) {
  inOutputStream.addString ("Summary of VDD operations :\n"
                    "  ") ;
  inOutputStream.addUnsigned (getCurrentVDDnodeCount ());
  inOutputStream.addString (" VDD currently used nodes ;\n"
                    "  ") ;
  inOutputStream.addUnsigned (C_VDD_hashmap::getCreatedObjectCount ()) ;
  inOutputStream.addString (" created nodes ("
                    "each node : ") ;
  inOutputStream.addUnsigned (getNodeSize ()) ;
  inOutputStream.addString (" bytes, total : ") ;
  inOutputStream.addUnsigned ((uint32_t) (C_VDD_hashmap::getAllocatedSizeInBytes () / 1048576)) ;
  inOutputStream.addString (" Mb)\n"
                    "  VDD unique table : ") ;
  inOutputStream.addUnsigned (gMap.getHashMapEntryCount ()) ;
  inOutputStream.addString (" entries (") ;
  inOutputStream.addUnsigned ((uint32_t) (gMap.getMapSizeInBytes () / 1048576)) ;
  inOutputStream.addString (" Mb).\n"
                    "  ") ;
  inOutputStream.addUnsigned (getNodeComparesCount ()) ;
  inOutputStream.addString (" VDD comparisons ;\n") ;
//--- Set union statistics
  inOutputStream.addString ("Statistics about 'SetUnion' operations :\n"
                    "  ") ;
  inOutputStream.addUnsigned (getSetUnionCacheEntriesCount ());
  inOutputStream.addString (" entries , size : ") ;
  inOutputStream.addSigned (gSetUnionCache.getCacheSizeInKBytes () / 1024);
  inOutputStream.addString (" Mb.\n") ;
  #ifdef COMPUTE_OPERATIONS_DURATION
    inOutputStream.addString ("    Total duration : ") ;
    inOutputStream.addSigned (gSetUnionDuration) ;
    inOutputStream.addString (" microseconds\n") ;
  #endif
  uint64_t n = getTrivialUnionCount () + getSetUnionCacheSuccessCount () + getSetUnionCacheFailureCount () ;
  inOutputStream.addString ("  ") ;
  inOutputStream.addUnsigned (getTrivialUnionCount ()) ;
  inOutputStream.addString (" trivial union (") ;
  inOutputStream.addUnsigned ((100ULL * getTrivialUnionCount ()) / n) ;
  inOutputStream.addString ("%) ;\n"
                    "  ") ;
  inOutputStream.addUnsigned (getSetUnionCacheSuccessCount ()) ;
  inOutputStream.addString (" cache successes (") ;
  inOutputStream.addUnsigned ((100ULL * getSetUnionCacheSuccessCount ()) / n) ;
  inOutputStream.addString ("%) ;\n"
                    "  ") ;
  inOutputStream.addUnsigned (getSetUnionCacheFailureCount ()) ;
  inOutputStream.addString (" cache failures (") ;
  inOutputStream.addUnsigned ((100ULL * getSetUnionCacheFailureCount ()) / n) ;
  inOutputStream.addString ("%), including ") ;
  inOutputStream.addUnsigned (getSetUnionCacheOverrideCount ()) ;
  inOutputStream.addString (" cache overrides (") ;
  inOutputStream.addUnsigned ((100ULL * getSetUnionCacheOverrideCount ()) / n) ;
  inOutputStream.addString ("%) ;\n") ;
//--- Get Firable statistics
  inOutputStream.addString ("Statistics about 'Get firable' operations :\n"
                    "  ") ;
  inOutputStream.addUnsigned (getGetFirableCacheEntriesCount ());
  inOutputStream.addString (" entries , size : ") ;
  inOutputStream.addSigned (gGetFirableCache.getCacheSizeInKBytes () / 1024);
  inOutputStream.addString (" Mb.\n") ;
  #ifdef COMPUTE_OPERATIONS_DURATION
    inOutputStream.addString ("  Total duration : ") ;
    inOutputStream.addUnsigned (gGetFirableDuration) ;
    inOutputStream.addString (" microseconds\n") ;
  #endif
  n = getTrivialGetFirableCount () + getGetFirableCacheSuccessCount () + getGetFirableCacheFailureCount () ;
  inOutputStream.addString ("  ") ;
  inOutputStream.addUnsigned (getTrivialGetFirableCount ()) ;
  inOutputStream.addString (" trivial get firable (") ;
  inOutputStream.addUnsigned ((100ULL * getTrivialGetFirableCount ()) / n) ;
  inOutputStream.addString ("%) ;\n"
                    "  ") ;
  inOutputStream.addUnsigned (getGetFirableCacheSuccessCount ()) ;
  inOutputStream.addString (" cache successes (") ;
  inOutputStream.addUnsigned ((100ULL * getGetFirableCacheSuccessCount ()) / n) ;
  inOutputStream.addString ("%) ;\n"
                    "  ") ;
  inOutputStream.addUnsigned (getGetFirableCacheFailureCount ()) ;
  inOutputStream.addString (" cache failures (") ;
  inOutputStream.addUnsigned ((100ULL * getGetFirableCacheFailureCount ()) / n) ;
  inOutputStream.addString ("%), including ") ;
  inOutputStream.addUnsigned (getGetFirableCacheOverrideCount ()) ;
  inOutputStream.addString (" cache overrides (") ;
  inOutputStream.addUnsigned ((100ULL * getGetFirableCacheOverrideCount ()) / n) ;
  inOutputStream.addString ("%) ;\n") ;
//--- AddVector statistics
  inOutputStream.addString ("Statistics about 'AddVector' operations :\n"
                    "  ") ;
  inOutputStream.addUnsigned (getAddVectorCacheEntriesCount ());
  inOutputStream.addString (" entries, size : ") ;
  inOutputStream.addSigned (gAddVectorCache.getCacheSizeInKBytes () / 1024) ;
  inOutputStream.addString (" Mb.\n") ;
  #ifdef COMPUTE_OPERATIONS_DURATION
    inOutputStream.addString ("  Total duration : ") ;
    inOutputStream.addUnsigned (gAddVectorDuration) ;
    inOutputStream.addString (" microseconds\n") ;
  #endif
  n = getTrivialAddVectorCount () + getAddVectorCacheSuccessCount () + getAddVectorCacheFailureCount () ;
  inOutputStream.addString ("  ") ;
  inOutputStream.addUnsigned (getTrivialAddVectorCount ()) ;
  inOutputStream.addString (" trivial add vector (") ;
  inOutputStream.addUnsigned ((100ULL * getTrivialAddVectorCount ()) / n) ;
  inOutputStream.addString ("%) ;\n"
                    "  ") ;
  inOutputStream.addUnsigned (getAddVectorCacheSuccessCount ()) ;
  inOutputStream.addString (" cache successes (") ;
  inOutputStream.addUnsigned ((100ULL * getAddVectorCacheSuccessCount ()) / n) ;
  inOutputStream.addString ("%) ;\n"
                    "  ") ;
  inOutputStream.addUnsigned (getAddVectorCacheFailureCount ()) ;
  inOutputStream.addString (" cache failures (") ;
  inOutputStream.addUnsigned ((100ULL * getAddVectorCacheFailureCount ()) / n) ;
  inOutputStream.addString ("%), including ") ;
  inOutputStream.addUnsigned (getAddVectorCacheOverrideCount ()) ;
  inOutputStream.addString (" cache overrides (") ;
  inOutputStream.addUnsigned ((100ULL * getAddVectorCacheOverrideCount ()) / n) ;
  inOutputStream.addString ("%) ;\n") ;
}

//---------------------------------------------------------------------------*
