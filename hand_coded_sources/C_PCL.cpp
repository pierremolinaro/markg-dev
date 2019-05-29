//---------------------------------------------------------------------------*
//                                                                           *
//     C++ class for implementing POST CONDITION LIST                        *
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

#include "C_PCL.h"

//---------------------------------------------------------------------------*

#include <stddef.h>
#include <string.h>
#include <limits.h>

//---------------------------------------------------------------------------*

#ifdef __MWERK__
  #pragma mark Set Parameters
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//                    Cache for addition                                     *
//                                                                           *
//---------------------------------------------------------------------------*

//--- Cache is handled by an prime integer sized array 
#include "cache/TC_prime_cache2.h"
typedef TC_prime_cache2 <C_PCL::cVDLnodeInfo *> cCacheClass ;
static cCacheClass gCache ;

//---------------------------------------------------------------------------*
//                                                                           *
//  VDD objects hash map                                                     *
//                                                                           *
//---------------------------------------------------------------------------*

#include "C_PCL_hashmap.h"
static C_PCL_hashmap gMap ;

//---------------------------------------------------------------------------*

void C_PCL::reallocUniqueTable (const int32_t inTableUniqueNewSize) {
  gMap.reallocMap (inTableUniqueNewSize) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//  Static VDL variable used as root of all existing C_PCL instances         *
//                                                                           *
//---------------------------------------------------------------------------*

static C_PCL gVDLlistRoot ;

//---------------------------------------------------------------------------*
//                                                                           *
//       Node count : for giving an unique ID to every node                  *
//                                                                           *
//---------------------------------------------------------------------------*

int32_t C_PCL::smNodeCount = 0 ;

//---------------------------------------------------------------------------*
//                                                                           *
//     Realloc addition cache                                                *
//                                                                           *
//---------------------------------------------------------------------------*

void C_PCL::reallocAdditionCache (const int32_t inNewCacheSize) {
  gCache.reallocCache (inNewCacheSize) ;
}

//---------------------------------------------------------------------------*

#ifdef __MWERK__
  #pragma mark Constructors and Assignment
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//       Default constructor                                                 *
//                                                                           *
//---------------------------------------------------------------------------*

C_PCL::C_PCL (void) :
mPtrToNextExisting (this),
mPtrToPreviousExisting (this),
mRootPointer (NULL) {
//--- Link
  initLinks () ;
}

//---------------------------------------------------------------------------*

void C_PCL::initLinks (void) {
  mPtrToNextExisting = this ;
  mPtrToPreviousExisting = this ;
  C_PCL * nextFromRoot = gVDLlistRoot.mPtrToNextExisting ;
  mPtrToPreviousExisting = & gVDLlistRoot ;
  nextFromRoot->mPtrToPreviousExisting = this ;
  mPtrToNextExisting = nextFromRoot ;
  gVDLlistRoot.mPtrToNextExisting = this ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Destructor                                                          *
//                                                                           *
//---------------------------------------------------------------------------*

C_PCL::~C_PCL (void) {
  mRootPointer = (cVDLnodeInfo *) NULL ;
//--- Unlink
  C_PCL * next = mPtrToNextExisting ;
  C_PCL * previous = mPtrToPreviousExisting ;
  previous->mPtrToNextExisting = next ;
  next->mPtrToPreviousExisting = previous ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Set to NULL vector                                                  *
//                                                                           *
//---------------------------------------------------------------------------*

void C_PCL::setToNullVector (void) {
  mRootPointer = (cVDLnodeInfo *) NULL ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Null vector ?                                                       *
//                                                                           *
//---------------------------------------------------------------------------*

bool C_PCL::isNullVector (void) const {
  return mRootPointer == NULL ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Vector comparison                                                   *
//                                                                           *
//---------------------------------------------------------------------------*

bool C_PCL::operator == (const C_PCL & inOperand) const {
  return mRootPointer == inOperand.mRootPointer ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Get index value                                                     *
//                                                                           *
//---------------------------------------------------------------------------*

T_vdd_zsl_value C_PCL::operator ()  (const T_vdd_zsl_index inIndex) const {
  T_vdd_zsl_value result = 0 ;
  cVDLnodeInfo * p = mRootPointer ;
  while (p != NULL) {
    if (p->mIndex < inIndex) {
      p = p->mPtrToNext ;
    }else if (p->mIndex > inIndex) {
      p = (cVDLnodeInfo *) NULL ; // Returns 0
    }else{ // p->mIndex == inIndex
      result = p->mValue ;
      p = (cVDLnodeInfo *) NULL ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Handle copy                                                         *
//                                                                           *
//---------------------------------------------------------------------------*

C_PCL::C_PCL (const C_PCL & inOperand) :
mPtrToNextExisting (this),
mPtrToPreviousExisting (this),
mRootPointer (inOperand.mRootPointer) {
  initLinks () ;
}

//---------------------------------------------------------------------------*

C_PCL & C_PCL::operator = (const C_PCL & inOperand) {
  mRootPointer = inOperand.mRootPointer ;
  return *this ;
}

//---------------------------------------------------------------------------*

#ifdef __MWERK__
  #pragma mark Get Parameters and Stats
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//       Cache for addition                                                  *
//                                                                           *
//---------------------------------------------------------------------------*

uint64_t C_PCL::getCacheEntriesCount (void) {
  return (uint64_t) gCache.getCacheEntriesCount () ;
}

//---------------------------------------------------------------------------*

uint64_t C_PCL::getCacheSuccessCount (void) {
  return (uint64_t) gCache.getCacheEntriesCount () ;
}

//---------------------------------------------------------------------------*

uint64_t C_PCL::getCacheFailureCount (void) {
  return gCache.getCacheMissCount () ;
}

//---------------------------------------------------------------------------*

uint64_t C_PCL::getCacheOverrideCount (void) {
  return gCache.getCacheOverrideCount () ;
}

//---------------------------------------------------------------------------*

uint64_t C_PCL::getUnusedCacheEntriesCount (void) {
  return gCache.getUnusedCacheEntriesCount () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Get node size                                                       *
//                                                                           *
//---------------------------------------------------------------------------*

uint32_t C_PCL::getNodeSize (void) {
  return C_PCL_hashmap::getNodeSize () ;
}

//---------------------------------------------------------------------------*

#ifdef __MWERK__
  #pragma mark Define Entry
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//       Add a value to an index                                             *
//                                                                           *
//---------------------------------------------------------------------------*

void C_PCL::defineEntry (const T_vdd_zsl_index inIndex,
                         const T_vdd_zsl_value inValue,
                         const bool inAssignment)  {
  if ((inValue != 0) || inAssignment) {
    mRootPointer = internalDefineEntry (inIndex, inValue, inAssignment, mRootPointer) ;
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Internal static method for adding a value to an index               *
//                                                                           *
//---------------------------------------------------------------------------*

C_PCL::cVDLnodeInfo * C_PCL::
internalDefineEntry (const T_vdd_zsl_index inIndex,
                     const T_vdd_zsl_value inValue,
                     const bool inAssignment,
                     cVDLnodeInfo * const inVector) {
  cVDLnodeInfo * result = (cVDLnodeInfo *) NULL ;
  if (inVector == NULL) {
    result = find_or_add (inIndex, inValue, inAssignment, (cVDLnodeInfo *) NULL) ;
  }else{
    const T_vdd_zsl_index currentIndex = inVector->mIndex ;
    if (inIndex > currentIndex) {
      cVDLnodeInfo * p = internalDefineEntry (inIndex, inValue, inAssignment, inVector->mPtrToNext) ;
      result = find_or_add (currentIndex, inVector->mValue, inVector->mAssignment, p) ;
    }else if (inIndex < currentIndex) {
      result = find_or_add (inIndex, inValue, inAssignment, inVector) ;
    }else{ // inIndex == currentIndex : error
      result = NULL ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Explore a VDL                                                       *
//                                                                           *
//---------------------------------------------------------------------------*

 C_PCL C_PCL::explore_pcl (T_vdd_zsl_index & outIndex,
                           T_vdd_zsl_value & outValue,
                           bool & outAssignment) const {
  C_PCL result ;
  if (mRootPointer == NULL) {
    outIndex  = 0 ;
    outValue = 0 ;
    outAssignment = false ;
  }else{
    outIndex = mRootPointer->mIndex ;
    outValue = mRootPointer->mValue ;
    outAssignment = mRootPointer->mAssignment ;
    result.mRootPointer = mRootPointer->mPtrToNext ;
  }
  return result ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Constructor for 'C_PCL::cVDLnodeInfo'                               *
//                                                                           *
//---------------------------------------------------------------------------*

int32_t C_PCL::smNodeCompare = 0 ;

intptr_t C_PCL::cVDLnodeInfo::compare (const cVDLnodeInfo & inInfo) const {
  smNodeCompare ++ ;
  intptr_t result = ((intptr_t) mPtrToNext) - ((intptr_t) inInfo.mPtrToNext) ;
  if (result == 0) {
    result = mIndex - inInfo.mIndex ;
  }
  if (result == 0) {
    result = mValue - inInfo.mValue ;
  }
  if (result == 0) {
    result = ((intptr_t) mAssignment) - ((intptr_t) inInfo.mAssignment) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

#ifdef __MWERK__
  #pragma mark Merge
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//    Merge an other vector (return false if merging cannot be performed)    *
//                                                                           *
//---------------------------------------------------------------------------*

C_PCL::cVDLnodeInfo * C_PCL::
internalMerge (C_PCL::cVDLnodeInfo * inRootPointer,
               C_PCL::cVDLnodeInfo * inOtherRootPointer,
               bool & ioOk) {
  C_PCL::cVDLnodeInfo * p = NULL ;
  if (inRootPointer == NULL) {
    p = inOtherRootPointer ;
  }else if (inOtherRootPointer == NULL) {
    p = inRootPointer ;
  }else{  
    const T_vdd_zsl_index index = inRootPointer->mIndex ;
    const T_vdd_zsl_index otherIndex = inOtherRootPointer->mIndex ;
    if (index < otherIndex) {
      p = find_or_add (index,
                       inRootPointer->mValue,
                       inRootPointer->mAssignment,
                       internalMerge (inRootPointer->mPtrToNext, inOtherRootPointer, ioOk)) ;
    }else if (index > otherIndex) {
      p = find_or_add (otherIndex,
                       inOtherRootPointer->mValue,
                       inOtherRootPointer->mAssignment,
                       internalMerge (inOtherRootPointer->mPtrToNext, inRootPointer, ioOk)) ;
    }else{ // index == otherIndex
      const int64_t temp = ((int64_t) inRootPointer->mValue) + ((int64_t) inOtherRootPointer->mValue) ;
      T_vdd_zsl_value result ;
      if (temp > ((int64_t) MAX_VDD_ZSL_VALUE)) {
        result = MAX_VDD_ZSL_VALUE ;
      }else{
        result = (T_vdd_zsl_value) temp ;
      }
      p = find_or_add (index,
                       result,
                       inRootPointer->mAssignment || inOtherRootPointer->mAssignment,
                       internalMerge (inOtherRootPointer->mPtrToNext, inRootPointer->mPtrToNext, ioOk)) ;
      if (ioOk) {
        ioOk = ((! inRootPointer->mAssignment) && (! inOtherRootPointer->mAssignment))
            || (inRootPointer->mAssignment && (! inOtherRootPointer->mAssignment) && (inOtherRootPointer->mValue == 0))
            || (inOtherRootPointer->mAssignment && (! inRootPointer->mAssignment) && (inRootPointer->mValue == 0)) ;
      }
    }
  }
  return p ;
}

//---------------------------------------------------------------------------*

bool C_PCL::merge (const C_PCL & inVector) {
  bool ok = true ;
  mRootPointer = internalMerge (mRootPointer, inVector.mRootPointer, ok) ;
  return ok ;
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

C_PCL::cVDLnodeInfo * C_PCL::
find_or_add (const T_vdd_zsl_index inIndex,
             const T_vdd_zsl_value inValue,
             const bool inAssignment,
             C_PCL::cVDLnodeInfo * const inPointerToNext) {
  cVDLnodeInfo * p = inPointerToNext ;
  if (inAssignment || (inValue != 0)) {
  //--- Do search or insert
    cVDLnodeInfo info ;
    info.mIndex = inIndex ;
    info.mValue = inValue ;
    info.mPtrToNext = inPointerToNext ;
    info.mAssignment = inAssignment ;
    bool insertionPerformed = false ; // Not used
    p = gMap.search_or_insert (info, insertionPerformed) ;
    if (insertionPerformed) {
      smNodeCount ++ ;
      p->mID = smNodeCount ;
    }
  }
  return p ;
}

//---------------------------------------------------------------------------*

#ifdef __MWERK__
  #pragma mark Print
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//       Print a vector                                                      *
//                                                                           *
//---------------------------------------------------------------------------*

 void C_PCL::printVector (AC_OutputStream & inStream,
                          const char * inPrefix,
                          const int32_t inFirst,
                          const int32_t inStep) const {
   bool firstPrint = true ;
   cVDLnodeInfo * p = mRootPointer ;
    while (p != NULL) {
     if (((p->mIndex - inFirst) % inStep) == 0) {
       if (firstPrint) {
         firstPrint = false ;
       }else{
         inStream << " " ;
       }
       inStream << inPrefix << cStringWithSigned ((p->mIndex - inFirst) / inStep)
                << ":"
                << cStringWithSigned (p->mValue) ;
     }
     p = p->mPtrToNext ;
   }
 }

//---------------------------------------------------------------------------*

 void C_PCL::printVector (AC_OutputStream & inStream,
                           const TC_UniqueArray <C_String> & inNames,
                           const int32_t inFirst,
                           const int32_t inStep) const {
   bool firstPrint = true ;
   cVDLnodeInfo * p = mRootPointer ;
    while (p != NULL) {
     if (((p->mIndex - inFirst) % inStep) == 0) {
       if (firstPrint) {
         firstPrint = false ;
       }else{
         inStream << " " ;
       }
       inStream << (inNames ((p->mIndex - inFirst) / inStep COMMA_HERE))
                << ":"
                << cStringWithSigned (p->mValue) ;
     }
     p = p->mPtrToNext ;
   }
 }

//---------------------------------------------------------------------------*
//                                                                           *
//       Collect unused elements                                             *
//                                                                           *
//---------------------------------------------------------------------------*

void C_PCL::collectUnusedNodes (void) {
//--- First : clear all addition cache entries
  gCache.clearAllCacheEntries () ;
//--- Second : mark all used elements
  C_PCL * p = gVDLlistRoot.mPtrToNextExisting ;
  while (p != & gVDLlistRoot) {
    cVDLnodeInfo * infoPtr = p->mRootPointer ;
    while ((infoPtr != NULL) && ! infoPtr->isMarked ()) {
      infoPtr->mark () ;
      infoPtr = infoPtr->mPtrToNext ;
    }
    p = p->mPtrToNextExisting ;
  }
//--- Third : sweep unused objets
  gMap.sweepUnmarkedObjects () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Print VDL summary                                                   *
//                                                                           *
//---------------------------------------------------------------------------*

void C_PCL::printVDLsummary (AC_OutputStream & inOutputStream) {
  const uint64_t n = getCacheSuccessCount () + getCacheFailureCount () ;
  inOutputStream << "Summary of VDL operations :\n"
                    "  " << cStringWithSigned (getVDLnodeCount ())
                 << " VDL used nodes (size " << cStringWithUnsigned (getNodeSize ()) << " bytes) ;\n"
                    "  " << cStringWithSigned (C_PCL_hashmap::getCreatedObjectCount ())
                 << " VDL created nodes (total size "
                 << cStringWithUnsigned (((uint32_t) C_PCL_hashmap::getCreatedObjectCount () * getNodeSize ()) / 1024UL)
                 << " kbytes) ;\n"
                    "  " << cStringWithSigned (getNodeComparesCount ()) << " comparisons ;\n"
                    "  " << cStringWithUnsigned (getCacheSuccessCount ())
                 << " cache successes (" << cStringWithUnsigned ((100ULL * getCacheSuccessCount ()) / n) << "%) ;\n"
                    "  " << cStringWithUnsigned (getCacheFailureCount ()) << " cache failures ("
                 << cStringWithUnsigned ((100ULL * getCacheFailureCount ()) / n) << "%), including "
                 << cStringWithUnsigned (getCacheOverrideCount ()) << " cache overrides ("
                 << cStringWithUnsigned ((100ULL * getCacheOverrideCount ()) / n) << "%) ;\n"
                    "  " << cStringWithUnsigned (getUnusedCacheEntriesCount ()) << " unused cache entries ("
                 << cStringWithUnsigned ((100ULL * getUnusedCacheEntriesCount ()) / getCacheEntriesCount ())
                 << "%, total entries = " << cStringWithUnsigned (getCacheEntriesCount ()) << ").\n" ;
}

//---------------------------------------------------------------------------*
