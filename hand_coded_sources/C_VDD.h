//---------------------------------------------------------------------------*
//                                                                           *
//     C++ class for implementing VECTOR DECISION DIAGRAMS (VDD)             *
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

#ifndef VECTOR_DECISION_DIAGRAMS_DEFINED
#define VECTOR_DECISION_DIAGRAMS_DEFINED

//---------------------------------------------------------------------------*

#include "C_vdd_types.h"
#include "generic-arraies/TC_UniqueArray.h"
#include "strings/String-class.h"

//---------------------------------------------------------------------------*

#include <stdio.h>

//---------------------------------------------------------------------------*

class C_AEDD ;
class C_ZSV ;
class C_PCL ;

//---------------------------------------------------------------------------*

class C_VDD {
//--- Constructor et destructor
  public : C_VDD (void) ; // Null Set
  public : virtual ~C_VDD (void) ;

//--- Control copy
  public : C_VDD (const C_VDD & inSource) ;
  public : C_VDD & operator = (const C_VDD & inSource) ;

//--- Pointers for handling a double-linked list of all existing variables
  protected : C_VDD * mPtrToNextExisting ;
  protected : C_VDD * mPtrToPreviousExisting ;
  private : void initLinks (void) ;

//--- Internal class for storing info for a node
  protected : class cVDDmaxInfos {
    public : union { uint64_t mElementsCount ;
                     cVDDmaxInfos * mPtrToNext ;
                   } ;
    public : T_vdd_zsl_value mMaxValue ;
    public : T_vdd_zsl_value mMaxTokens ;
  } ;

//--- Internal nodes
  public : class cVDDnodeInfo {
    public : cVDDnodeInfo * mPtrToSameIndex ;
    public : cVDDnodeInfo * mPtrToNextIndex ;
    public : intptr_t mMaxInfosPtr ; // CAUTION !! Bit 0 is used for handling the mark bit
    public : T_vdd_zsl_index mIndex ;
    public : T_vdd_zsl_value mValue ;

    public : cVDDnodeInfo (void) :
    mPtrToSameIndex (NULL),
    mPtrToNextIndex (NULL),
    mMaxInfosPtr (0),
    mIndex (0),
    mValue (0) {
    }

    public : ~cVDDnodeInfo (void) ;

    public : cVDDnodeInfo (const cVDDnodeInfo & inSource) :
    mPtrToSameIndex (inSource.mPtrToSameIndex),
    mPtrToNextIndex (inSource.mPtrToNextIndex),
    mMaxInfosPtr (inSource.mMaxInfosPtr),
    mIndex (inSource.mIndex),
    mValue (inSource.mValue) {
    }

    private : cVDDnodeInfo & operator = (const cVDDnodeInfo &) ;

    public : intptr_t compare (const cVDDnodeInfo & inOperand) const ;

    public : inline bool isMarked (void) const {
      return (mMaxInfosPtr & 1) != 0 ;
    }

    public : inline void mark (void) {
      mMaxInfosPtr |= 1 ;
    }

    public : inline void unmark (void) {
      mMaxInfosPtr &= -2 ;
    }

    public : inline uintptr_t getHashCodeForMap (void) const {
      return (uintptr_t) ((((uintptr_t) mIndex) << 11)
                       ^ ((uintptr_t) mValue)
                       ^ (((uintptr_t) mPtrToSameIndex) << 5)
                       ^ ((uintptr_t) mPtrToNextIndex)
                      ) ;
    }
  } ;

//--- Realloc unique table
  public : static void reallocUniqueTable (const int32_t inTableUniqueNewSize) ;

//--- Get unique table size (in bytes)
  public : static size_t getUniqueTableSizeInBytes (void) ;

//--- Realloc caches
  public : static void reallocCaches (const size_t inNewCachesSize) ;

//--- Get caches size (in bytes)
  public : static size_t getCachesSizeInBytes (void) ;

//--- Get caches size (in entries count)
  public : static size_t getCachesSizeEntriesCount (void) ;

//--- Get RAM size allocated for cVDDmaxInfos objects
  public : static size_t getSizeOf_cVDDmaxInfos_objects (void) ;

//--- Save an array of VDD objects in text file
  public : static void saveArrayOnFile (const TC_UniqueArray <C_VDD> & inArray,
                                        AC_OutputStream & inOutputStream) ;

//--- Decision Diagram
  protected : cVDDnodeInfo * mRootPointer ;

//--- Set to NULL set
  public : void setToNullSet (void) ;

//--- Set to empty set
  public : void setToEmptySet (void) ;

//--- Empty set test
  public : bool isEmptySet (void) const ;

//--- Get elements count
  public : uint64_t getSetCardinal (void) const ;

//--- Get set max value
  public : T_vdd_zsl_value getMaxValue (void) const ;

//--- Get set max tokens
  public : T_vdd_zsl_value getMaxTokens (void) const ;

//--- Get the vector subset that has one (or more) index equal to the bound
  public : C_VDD getBoundSet (void) const ;

//---  Compute min and max value for each index
  public : void computeMinAndMax (TC_UniqueArray <int32_t> & inMinArray,
                                  TC_UniqueArray <int32_t> & inMaxArray,
                                  const int32_t inIndexCount) const ;

//--- Set comparison
  public : bool operator == (const C_VDD & inOperand) const ;
  public : bool operator != (const C_VDD & inOperand) const ;

//--- Add a value at index
  public : void addValueAtIndex (const T_vdd_zsl_value inValue,
                                 const T_vdd_zsl_index inIndex) ;

//--- Get firable subset for a pure Petri nets transition
  public : C_VDD getFirable (const C_ZSV & inVector) const ;

//--- Get firable subset for a extended Petri nets transition
  public : C_VDD getFirableFromAEDD (const C_AEDD & inVector) const ;

//--- Add vector to every element
  public : C_VDD addVector (const C_ZSV & inVector) const ;

  public : C_VDD computeTargetVector (const C_PCL & inVector) const ;

//--- Get union
  public : C_VDD operator | (const C_VDD & inOperand) const ;
  public : void operator |= (const C_VDD & inOperand) ;

//--- Suppress NULL vector in a set
  public : C_VDD getNullSuppressed (void) const ;

//--- Get intersection of a set with null vector
// ( returns empty set or null set)
  public : C_VDD getIntersectionWithNull (void) const ;

//--- Routines for verify if a petri net is bounded
  public : C_VDD getGreaterOrEqual (const C_VDD & inOperand) const ;
  public : C_VDD getGreaterThan (const C_VDD & inOperand) const ;

//--- Print a set
  public : void printSet (AC_OutputStream & inStream,
                          const TC_UniqueArray <String> & inNames) const ;

//--- Print the nodes of a set
  public : void printSetNodes (AC_OutputStream & inStream,
                          const TC_UniqueArray <String> & inNames) const ;

//--- Get node count
  public : int32_t getNodesCount (void) const ;

//--- Print VDD summary
  public : static void printVDDsummary (AC_OutputStream & inOutputStream) ;

//--- Collect unused elements
  public : static void collectUnusedNodes (void) ;

  public : static size_t getHashMapEntriesCount (void) ;
  public : static size_t getMapSizeInBytes (void) ;

//--- Statistics about SetUnion cache
  protected : static uint64_t smTrivialUnion ;
  protected : static uint64_t smSetUnionCacheSuccesses ;
  public : static uint64_t getTrivialUnionCount (void) { return smTrivialUnion ; }
  public : static uint64_t getSetUnionCacheSuccessCount (void) { return smSetUnionCacheSuccesses ; }
  public : static uint64_t getSetUnionCacheFailureCount (void) ;
  public : static uint64_t getSetUnionCacheOverrideCount (void) ;
  public : static uint64_t getSetUnionUnusedCacheEntriesCount (void) ;
  public : static uint64_t getSetUnionCacheEntriesCount (void) ;

//--- Statistics about GetFirable cache
  protected : static uint64_t smTrivialGetFirable ;
  protected : static uint64_t smGetFirableCacheSuccesses ;
  public : static uint64_t getTrivialGetFirableCount (void) { return smTrivialGetFirable ; }
  public : static uint64_t getGetFirableCacheSuccessCount (void) { return smGetFirableCacheSuccesses ; }
  public : static uint64_t getGetFirableCacheFailureCount (void) ;
  public : static uint64_t getGetFirableCacheOverrideCount (void) ;
  public : static uint64_t getGetFirableUnusedCacheEntriesCount (void) ;
  public : static uint64_t getGetFirableCacheEntriesCount (void) ;

//--- Statistics about AddVector cache
  protected : static uint64_t smTrivialAddVector ;
  protected : static uint64_t smAddVectorCacheSuccesses ;
  public : static uint64_t getTrivialAddVectorCount (void) { return smTrivialAddVector ; }
  public : static uint64_t getAddVectorCacheSuccessCount (void) { return smAddVectorCacheSuccesses ; }
  public : static uint64_t getAddVectorCacheFailureCount (void) ;
  public : static uint64_t getAddVectorCacheOverrideCount (void) ;
  public : static uint64_t getAddVectorUnusedCacheEntriesCount (void) ;
  public : static uint64_t getAddVectorCacheEntriesCount (void) ;

//--- Internal methods
  private : static cVDDnodeInfo * find_or_add (const T_vdd_zsl_index inIndex,
                                               const T_vdd_zsl_value inValue,
                                               cVDDnodeInfo * const inPtrToEq,
                                               cVDDnodeInfo * const inPtrToSup) ;

  private : static void internalPrintSet (AC_OutputStream & inStream,
                             cVDDnodeInfo * const inPtr,
                             const TC_UniqueArray <String> & inNames,
                             int32_t inArray [],
                             const T_vdd_zsl_index inIndex) ;

  private : static cVDDnodeInfo * internalAddValueAtIndex (cVDDnodeInfo * const inPtr,
                                      const T_vdd_zsl_value inValue,
                                      const T_vdd_zsl_index inIndex) ;

  private : static void internalMarkNode (cVDDnodeInfo * const inPtr) ;

  private : static cVDDnodeInfo * internalGetFirable (cVDDnodeInfo * const inPtr,
                                                      const C_ZSV & inVector) ;

  private : static cVDDnodeInfo * internalGetFirableFromAEDD (cVDDnodeInfo * const inPtr,
                                                              const intptr_t inAEDDptr) ;

  private : static cVDDnodeInfo * internalAddVector (cVDDnodeInfo * const inPtr,
                                                     const C_ZSV & inVector) ;

  private : static cVDDnodeInfo * internalComputeTargetVector (cVDDnodeInfo * const inPtr,
                                                               const C_PCL & inVector) ;

  private : static cVDDnodeInfo * internalGetUnion (cVDDnodeInfo * const inS1,
                                                    cVDDnodeInfo * const inS2) ;

  private : static cVDDnodeInfo * internalGetNullSuppressed (cVDDnodeInfo * const inPtr) ;

  private : static cVDDnodeInfo * internalGetIntersectionWithNull (cVDDnodeInfo * const inPtr) ;

  private : static cVDDnodeInfo * internalGetBoundSet (cVDDnodeInfo * const inPtr,
                                                       const T_vdd_zsl_value inBound) ;

  private : static cVDDnodeInfo * internalGetGreaterOrEqual (cVDDnodeInfo * const inPtr,
                                                             cVDDnodeInfo * const inTestPtr) ;

  private : static cVDDnodeInfo * internalGetGreater (cVDDnodeInfo * const inPtr,
                                                      cVDDnodeInfo * const inTestPtr) ;

  private : static int32_t internalGetNodesCount (cVDDnodeInfo * const inPtr) ;

  private : static void internalUnmarkNodes (cVDDnodeInfo * const inPtr) ;

  private : static void internalComputeMinMax (cVDDnodeInfo * const inPtr,
                                               TC_UniqueArray <int32_t> & inMinArray,
                                               TC_UniqueArray <int32_t> & inMaxArray,
                                               const int32_t inIndexCount) ;

  private : static void internalComputeInfos (cVDDnodeInfo * const inPtr,
                                              uint64_t & outElementCount,
                                              T_vdd_zsl_value & outMaxValue,
                                              T_vdd_zsl_value & outMaxTokens) ;

  private : static void internalPrintSetNodes (AC_OutputStream & inStream,
                                               cVDDnodeInfo * const inPtr,
                                               const TC_UniqueArray <String> & inNames) ;

  private : static void internalSaveNode (cVDDnodeInfo * const inPtr,
                                          AC_OutputStream & inOutputStream) ;

  protected : static size_t smNodeCompare ;
  public : static size_t getNodeSize (void) ;
  public : static size_t getNodeComparesCount (void) { return smNodeCompare ; }
  protected : static size_t smNodeCount ;
  public : static size_t getVDDnodeCount (void) { return smNodeCount ; }
  protected : static size_t smCurrentNodeCount ;
  public : static size_t getCurrentVDDnodeCount (void) { return smCurrentNodeCount ; }

//--- kEMPTY_SET denotes the empty set
  protected : static cVDDnodeInfo * const kEMPTY_SET ;

//--- kNULL_SET denotes the set that contains only the null vector
  protected : static cVDDnodeInfo * const kNULL_SET ;

//--- VDD max info free list
  protected : static cVDDmaxInfos * gNodeInfoFreeList ;

  friend class cVDDnodeInfo ;
} ;

//---------------------------------------------------------------------------*

#endif
