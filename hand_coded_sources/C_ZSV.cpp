//---------------------------------------------------------------------------*
//                                                                           *
//     C++ class for implementing ZERO SUPPRESS VECTOR (ZSV)                 *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2001, ..., 2009 Pierre Molinaro.                           *
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

#include "C_ZSV.h"

//---------------------------------------------------------------------------*

#include <stddef.h>
#include <string.h>
#include <limits.h>

//---------------------------------------------------------------------------*
//                                                                           *
//                    Cache for addition                                     *
//                                                                           *
//---------------------------------------------------------------------------*


//--- Cache is handled by an prime integer sized array 
#include "cache/TC_prime_cache2.h"
typedef TC_prime_cache2 <C_ZSV::cZSVinfo *> cCacheClass ;
static cCacheClass gCache ;

//---------------------------------------------------------------------------*
//                                                                           *
//  ZSV objects hash map                                                     *
//                                                                           *
//---------------------------------------------------------------------------*

#include "C_ZSV_hashmap.h"

static C_ZSV_hashmap gMap ;

//---------------------------------------------------------------------------*

void C_ZSV::reallocUniqueTable (const size_t inTableUniqueNewSize) {
  gMap.reallocMap (inTableUniqueNewSize) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//  Static VDL variable used as root of all existing C_ZSV instances         *
//                                                                           *
//---------------------------------------------------------------------------*

static C_ZSV * gFirstZSV = NULL ;
static C_ZSV * gLastZSV = NULL ;

//---------------------------------------------------------------------------*
//                                                                           *
//       Node count : for giving an unique ID to every node                  *
//                                                                           *
//---------------------------------------------------------------------------*

size_t C_ZSV::smNodeCount = 0 ;

//---------------------------------------------------------------------------*
//                                                                           *
//     Realloc addition cache                                                *
//                                                                           *
//---------------------------------------------------------------------------*

void C_ZSV::reallocAdditionCache (const size_t inNewCacheSize) {
  gCache.reallocCache (inNewCacheSize) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Default constructor                                                 *
//                                                                           *
//---------------------------------------------------------------------------*

C_ZSV::C_ZSV (void) :
mPtrToNextExisting (this),
mPtrToPreviousExisting (this),
mRootPointer (NULL) {
  initLinks () ;
}

//---------------------------------------------------------------------------*

void C_ZSV::initLinks (void) {
  if (gFirstZSV == NULL) {
    gLastZSV = this ;
  }else{
    gFirstZSV->mPtrToPreviousExisting = this ;
  }
  mPtrToNextExisting = gFirstZSV ;
  gFirstZSV = this ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Destructor                                                          *
//                                                                           *
//---------------------------------------------------------------------------*

C_ZSV::~C_ZSV (void) {
  mRootPointer = NULL ;
//--- Unlink
  if (mPtrToPreviousExisting == NULL) {
    gFirstZSV = gFirstZSV->mPtrToNextExisting ;
  }else{
    mPtrToPreviousExisting->mPtrToNextExisting = mPtrToNextExisting ;
  }
  if (mPtrToNextExisting == NULL) {
    gLastZSV = gLastZSV->mPtrToPreviousExisting ;
  }else{
    mPtrToNextExisting->mPtrToPreviousExisting = mPtrToPreviousExisting ;
  }


  C_ZSV * next = mPtrToNextExisting ;
  C_ZSV * previous = mPtrToPreviousExisting ;
  previous->mPtrToNextExisting = next ;
  next->mPtrToPreviousExisting = previous ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Set to NULL vector                                                  *
//                                                                           *
//---------------------------------------------------------------------------*

void C_ZSV::setToNullVector (void) {
  mRootPointer = (cZSVinfo *) NULL ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Null vector ?                                                       *
//                                                                           *
//---------------------------------------------------------------------------*

bool C_ZSV::isNullVector (void) const {
  return mRootPointer == NULL ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Vector comparison                                                   *
//                                                                           *
//---------------------------------------------------------------------------*

bool C_ZSV::operator == (const C_ZSV & inOperand) const {
  return mRootPointer == inOperand.mRootPointer ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Get index value                                                     *
//                                                                           *
//---------------------------------------------------------------------------*

T_vdd_zsl_value C_ZSV::operator ()  (const T_vdd_zsl_index inIndex) const {
  T_vdd_zsl_value result = 0 ;
  cZSVinfo * p = mRootPointer ;
  while (p != NULL) {
    if (p->mIndex < inIndex) {
      p = p->mPtrToNext ;
    }else if (p->mIndex > inIndex) {
      p = (cZSVinfo *) NULL ; // Returns 0
    }else{ // p->mIndex == inIndex
      result = p->mValue ;
      p = (cZSVinfo *) NULL ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Reset entry to zero                                                 *
//                                                                           *
//---------------------------------------------------------------------------*

void C_ZSV::clearEntry (const T_vdd_zsl_index inIndex) {
  mRootPointer = internalClearEntry (inIndex, mRootPointer) ;
}

//---------------------------------------------------------------------------*

C_ZSV::cZSVinfo * C_ZSV::
internalClearEntry (const T_vdd_zsl_index inIndex,
                    cZSVinfo * const inPointer) {
  cZSVinfo * result = (cZSVinfo *) NULL ;
  if (inPointer != NULL) {
    if (inPointer->mIndex < inIndex) {
      result = find_or_add (inPointer->mIndex,
                            inPointer->mValue,
                            internalClearEntry (inIndex, inPointer->mPtrToNext)) ;
    }else if (inPointer->mIndex > inIndex) {
      result = inPointer ; // Entry already zero
    }else{ // inPointer->mIndex == inIndex
      result = inPointer->mPtrToNext ; // set entry to zero
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Handle copy                                                         *
//                                                                           *
//---------------------------------------------------------------------------*

C_ZSV::C_ZSV (const C_ZSV & inOperand) :
mPtrToNextExisting (this),
mPtrToPreviousExisting (this),
mRootPointer (inOperand.mRootPointer) {
  initLinks () ;
}

//---------------------------------------------------------------------------*

C_ZSV & C_ZSV::operator = (const C_ZSV & inOperand) {
  mRootPointer = inOperand.mRootPointer ;
  return *this ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Cache for addition                                                  *
//                                                                           *
//---------------------------------------------------------------------------*

uint64_t C_ZSV::getCacheEntriesCount (void) {
  return (uint64_t) gCache.getCacheEntriesCount () ;
}

//---------------------------------------------------------------------------*

uint64_t C_ZSV::getCacheSuccessCount (void) {
  return (uint64_t) gCache.getCacheEntriesCount () ;
}

//---------------------------------------------------------------------------*

uint64_t C_ZSV::getCacheFailureCount (void) {
  return gCache.getCacheMissCount () ;
}

//---------------------------------------------------------------------------*

uint64_t C_ZSV::getCacheOverrideCount (void) {
  return gCache.getCacheOverrideCount () ;
}

//---------------------------------------------------------------------------*

uint64_t C_ZSV::getUnusedCacheEntriesCount (void) {
  return gCache.getUnusedCacheEntriesCount () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Add vectors                                                         *
//                                                                           *
//---------------------------------------------------------------------------*

C_ZSV C_ZSV::operator + (const C_ZSV & inOperand) const {
  C_ZSV result ;
  result.mRootPointer = internalSum (mRootPointer, inOperand.mRootPointer) ;
  return result ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Internal sum of vector                                              *
//                                                                           *
//---------------------------------------------------------------------------*

uint64_t C_ZSV::smTrivialAdd = 0 ;

C_ZSV::cZSVinfo * C_ZSV::internalSum (cZSVinfo * const inPtr1,
                                      cZSVinfo * const inPtr2) {
  cZSVinfo * result ;  
  if (inPtr1 == NULL) {
    result = inPtr2 ;
    smTrivialAdd ++ ;
  }else if (inPtr2 == NULL) {
    result = inPtr1 ;
    smTrivialAdd ++ ;
  }else{
  //--- In cache ?
 //   int32_t ID1 = ((int32_t) inPtr1) >> 5 ; int32_t ID2 = ((int32_t) inPtr2) >> 5 ;
    intptr_t ID1 = inPtr1->mID ;
    intptr_t ID2 = inPtr2->mID ;
  //--- Exchange ID1 and ID2 ?
    if (ID1 > ID2) {
      ID1 ^= ID2 ; ID2 ^= ID1 ; ID1 ^= ID2 ;
    }
    bool cacheSuccess ; int32_t hashCode ;
    gCache.getCacheEntry (ID1, ID2, cacheSuccess, hashCode, result) ;
    if (! cacheSuccess) {
      if (inPtr1->mIndex < inPtr2->mIndex) {
        result = find_or_add (inPtr1->mIndex,
                              inPtr1->mValue,
                              internalSum (inPtr1->mPtrToNext, inPtr2)) ;
      }else if (inPtr1->mIndex > inPtr2->mIndex) {
        result = find_or_add (inPtr2->mIndex,
                              inPtr2->mValue,
                              internalSum (inPtr1, inPtr2->mPtrToNext)) ;
      }else{ // inPtr1->mIndex == inPtr2->mIndex
        result = internalSum (inPtr1->mPtrToNext, inPtr2->mPtrToNext) ;
        const T_vdd_zsl_value r = (T_vdd_zsl_value) (inPtr1->mValue + inPtr2->mValue) ;
        if (r != 0) {
          result = find_or_add (inPtr1->mIndex, r, result) ;
        }
      }
    //--- Enter result in cache
      gCache.writeCacheEntry (ID1, ID2, hashCode, result) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Get sum of elements                                                 *
//                                                                           *
//---------------------------------------------------------------------------*

long C_ZSV::getSum (void) const {
  long sum = 0 ;
  cZSVinfo * p = mRootPointer ;
  while (p != NULL) {
    sum += p->mValue ;
    p = p->mPtrToNext ;
  }
  return sum ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Add a value to an index                                             *
//                                                                           *
//---------------------------------------------------------------------------*

void C_ZSV::add (const T_vdd_zsl_index inIndex,
                 const T_vdd_zsl_value inValue) {
  if (inValue != 0) {
    mRootPointer = internalAdd (inIndex, inValue, mRootPointer) ;
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Internal static method for adding a value to an index               *
//                                                                           *
//---------------------------------------------------------------------------*

C_ZSV::cZSVinfo * C_ZSV::internalAdd (const T_vdd_zsl_index inIndex,
                                            const T_vdd_zsl_value inValue,
                                            cZSVinfo * const inVector) {
  cZSVinfo * result = (cZSVinfo *) NULL ;
  if (inVector == NULL) {
    result = find_or_add (inIndex, inValue, (cZSVinfo *) NULL) ;
  }else{
    const T_vdd_zsl_index currentIndex = inVector->mIndex ;
    if (inIndex > currentIndex) {
      cZSVinfo * p = internalAdd (inIndex, inValue, inVector->mPtrToNext) ;
      result = find_or_add (currentIndex, inVector->mValue, p) ;
    }else if (inIndex < currentIndex) {
      result = find_or_add (inIndex, inValue, inVector) ;
    }else{ // inIndex == currentIndex
      const T_vdd_zsl_value r = (T_vdd_zsl_value) (inValue + inVector->mValue) ;
      if (r == 0) {
        result = inVector->mPtrToNext ;
      }else{
        result = find_or_add (currentIndex, r, inVector->mPtrToNext) ;
      }
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Explore a VDL                                                       *
//                                                                           *
//---------------------------------------------------------------------------*

 void C_ZSV::explore_vdl (C_ZSV & ioVDL,
                           T_vdd_zsl_index & outIndex,
                           T_vdd_zsl_value & outValue) {
  if (ioVDL.mRootPointer == NULL) {
    outIndex  = 0 ;
    outValue = 0 ;
  }else{
    outIndex = ioVDL.mRootPointer->mIndex ;
    outValue = ioVDL.mRootPointer->mValue ;
    ioVDL.mRootPointer = ioVDL.mRootPointer->mPtrToNext ;
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Constructor for 'C_ZSV::cZSVinfo'                                   *
//                                                                           *
//---------------------------------------------------------------------------*

size_t C_ZSV::smNodeCompare = 0 ;

intptr_t C_ZSV::cZSVinfo::compare (const cZSVinfo & inInfo) const {
  smNodeCompare ++ ;
  intptr_t result = ((intptr_t) mPtrToNext) - ((intptr_t) inInfo.mPtrToNext) ;
  if (result == 0) {
    result = mIndex - inInfo.mIndex ;
  }
  if (result == 0) {
    result = mValue - inInfo.mValue ;
  }
  return result ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Get node size                                                       *
//                                                                           *
//---------------------------------------------------------------------------*

size_t C_ZSV::getNodeSize (void) {
  return C_ZSV_hashmap::getNodeSize () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Internal static method for adding a value to an index               *
//                                                                           *
//---------------------------------------------------------------------------*

C_ZSV::cZSVinfo * C_ZSV::find_or_add (const T_vdd_zsl_index inIndex,
                                            const T_vdd_zsl_value inValue,
                                            C_ZSV::cZSVinfo * const inPointerToNext) {
//--- Do search or insert
  cZSVinfo info ;
  info.mIndex = inIndex ;
  info.mValue = inValue ;
  info.mPtrToNext = inPointerToNext ;
  bool insertionPerformed = false ; // Not used
  cZSVinfo * p = gMap.search_or_insert (info, insertionPerformed) ;
  if (insertionPerformed) {
    const T_vdd_zsl_value max = (inPointerToNext == NULL) ? ((T_vdd_zsl_value) 0) : inPointerToNext->mMaxVectorValue ;
    p->mMaxVectorValue = (inValue > max) ? inValue : max ;
    smNodeCount ++ ;
    p->mID = intptr_t (smNodeCount) ;
  }
  return p ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Print a vector                                                      *
//                                                                           *
//---------------------------------------------------------------------------*

 void C_ZSV::printVector (AC_OutputStream & inStream,
                           const char * inPrefix,
                           const int32_t inFirst,
                           const int32_t inStep) const {
   bool firstPrint = true ;
   cZSVinfo * p = mRootPointer ;
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

 void C_ZSV::printVector (AC_OutputStream & inStream,
                           const TC_UniqueArray <C_String> & inNames,
                           const int32_t inFirst,
                           const int32_t inStep) const {
   bool firstPrint = true ;
   cZSVinfo * p = mRootPointer ;
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
//       Special methods for Petri nets                                      *
//                                                                           *
//---------------------------------------------------------------------------*

 bool C_ZSV::greaterOrEqual (const C_ZSV & inOperand) const {
//--- true if every value in current nodes >= 'inOperand'
//  bool result = true ;
  bool result = getGreatestComponentValue () >= inOperand.getGreatestComponentValue () ;
  cZSVinfo * currentNodePointer = mRootPointer ;
  cZSVinfo * operandNodePointer = inOperand.mRootPointer ;
  while ((operandNodePointer != NULL) & result) {
     result = currentNodePointer != NULL ;
     if (result) {
       if (currentNodePointer == operandNodePointer) {
         operandNodePointer = (cZSVinfo *) NULL ; // For exiting loop
       }else if (currentNodePointer->mIndex < operandNodePointer->mIndex) {
         currentNodePointer = currentNodePointer->mPtrToNext ;
       }else if (currentNodePointer->mIndex > operandNodePointer->mIndex) {
         result = false ;
       }else{ // currentNodePointer->mIndex == operandNodePointer->mIndex
         result = currentNodePointer->mValue >= operandNodePointer->mValue ;
         currentNodePointer = currentNodePointer->mPtrToNext ;
         operandNodePointer = operandNodePointer->mPtrToNext ;
       }
     }
  }
  return result ; // operandNodePointer == NULL ;
}

//---------------------------------------------------------------------------*

// Intermediate calculus gives four different values :
//      non comparable, inf, equal, sup
// Final result is true if comparison result is sup
//--- Decision cases :
//          current          inOperand     result           comment
//                p                  p      equal       includes both NULL
//             NULL                  p        inf
//                p               NULL        sup
//                p                  q    compare (p, q)
//--- Compare (p, q) : two different pointers,
//  naming index pi et qi, values pv and qv :
//    pi < qi : compute r := compare (p->mPtrToNext, q)
//      r = non comparable --> non comparable
//      r = inf --> result := non comparable
//      r = equal --> result := sup
//      r = sup --> result := sup
//    pi = qi : compute r := compare (p->mPtrToNext, q->mPtrToNext)
//      pv < qv --> result := inf or non comparable
//      pv = qv --> result := compare (p->mPtrToNext, q->mPtrToNext)
//      pv > qv --> r := compare (p->mPtrToNext, q->mPtrToNext)
//        r = non comparable --> result := non comparable
//        r = inf --> result := non comparable
//        r = equal --> result := sup
//        r = sup --> result := sup
//    pi > qi -> result := non comparable
//
//---------------------------------------------------------------------------*

C_ZSV::enumCompare
C_ZSV::internalGreaterThan (C_ZSV::cZSVinfo * inCurrentNodePointer,
                            C_ZSV::cZSVinfo * inOperandNodePointer) {
  enumCompare result ;
  if (inCurrentNodePointer == inOperandNodePointer) {
    result = kEqual ;
  }else if (inCurrentNodePointer == NULL) {
    result = kInf ;
  }else if (inOperandNodePointer == NULL) {
    result = kSup ;
  }else{
    const int32_t pi = inCurrentNodePointer->mIndex ;
    const int32_t qi = inOperandNodePointer->mIndex ;
    if (pi < qi) {
      result = internalGreaterThan (inCurrentNodePointer->mPtrToNext, inOperandNodePointer) ;
      if (result <= kInf) {
        result = kNonComparable ;
      }else{
        result = kSup ;
      }
    }else if (pi > qi) {
      result = kNonComparable ;
    }else{ // pi == qi
      const int32_t pv = inCurrentNodePointer->mValue ;
      const int32_t qv = inOperandNodePointer->mValue ;
      if (pv < qv) {
        result = kInf ;
      }else if (pv > qv) {
        result = internalGreaterThan (inCurrentNodePointer->mPtrToNext,
                                      inOperandNodePointer->mPtrToNext) ;
        if (result <= kInf) {
          result = kNonComparable ;
        }else{
          result = kSup ;
        }
      }else{ // pv == qv
        result = internalGreaterThan (inCurrentNodePointer->mPtrToNext,
                                      inOperandNodePointer->mPtrToNext) ;
      }
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

bool C_ZSV::greaterThan (const C_ZSV & inOperand) const {
  return (getGreatestComponentValue () > inOperand.getGreatestComponentValue ())
      && (internalGreaterThan (mRootPointer, inOperand.mRootPointer) == kSup) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Collect unused elements                                             *
//                                                                           *
//---------------------------------------------------------------------------*

void C_ZSV::collectUnusedNodes (void) {
//--- First : clear all addition cache entries
  gCache.clearAllCacheEntries () ;
//--- Second : mark all used elements
  C_ZSV * p = gFirstZSV ;
  while (p != NULL) {
    cZSVinfo * infoPtr = p->mRootPointer ;
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

void C_ZSV::printVDLsummary (AC_OutputStream & inOutputStream) {
  const uint64_t n = getTrivialAddCount () + getCacheSuccessCount () + getCacheFailureCount () ;
  inOutputStream << "Summary of VDL operations :\n"
                    "  " << cStringWithUnsigned (getVDLnodeCount ())
                 << " VDL used nodes (size " << cStringWithUnsigned (getNodeSize ()) << " bytes) ;\n"
                    "  " << cStringWithUnsigned (C_ZSV_hashmap::getCreatedObjectCount ())
                 << " VDL created nodes (total size "
                 << cStringWithUnsigned (((uint32_t) C_ZSV_hashmap::getCreatedObjectCount () * getNodeSize ()) / 1024UL)
                 << " kbytes) ;\n"
                    "  " << cStringWithUnsigned (getNodeComparesCount ()) << " comparisons ;\n"
                    "  " << cStringWithUnsigned (getTrivialAddCount ())
                 << " trivial additions (" << cStringWithUnsigned ((100ULL * getTrivialAddCount ()) / n)
                 << "%) ;\n"
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
