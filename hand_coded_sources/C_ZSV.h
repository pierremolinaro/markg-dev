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

#ifndef ZERO_SUPPRESS_VECTOR_DEFINED
#define ZERO_SUPPRESS_VECTOR_DEFINED

//---------------------------------------------------------------------------*

#include "C_vdd_types.h"
#include "collections/TC_UniqueArray.h"
#include "strings/C_String.h"

//---------------------------------------------------------------------------*

#include <stdio.h>

//---------------------------------------------------------------------------*

const intptr_t MARK_VDL_NODE = INTPTR_MIN ;

//---------------------------------------------------------------------------*

class C_ZSV {
//--- Constructor et destructor
  public : C_ZSV (void) ; // Null vector
  public : virtual ~C_ZSV (void) ;

//--- Control copy
  public : C_ZSV (const C_ZSV & inSource) ;
  public : C_ZSV & operator = (const C_ZSV & inSource) ;

//--- Pointers for handling a double-linked list of all existing variables
  protected : C_ZSV * mPtrToNextExisting ;
  protected : C_ZSV * mPtrToPreviousExisting ;
  private : void initLinks (void) ;
  
//--- Internal nodes
  public : class cZSVinfo {
    public : cZSVinfo * mPtrToNext ;
    public : intptr_t mID ;
    public : T_vdd_zsl_value mValue ;
    public : T_vdd_zsl_value mMaxVectorValue ;
    public : T_vdd_zsl_index mIndex ;
    
    public : intptr_t compare (const cZSVinfo & inOperand) const ;
    
    public : inline bool isMarked (void) const {
      return (mID & MARK_VDL_NODE) != 0 ;
    }

    public : inline void mark (void) {
      mID |= MARK_VDL_NODE ;
    }

    public : inline void unmark (void) {
      mID &= ~ MARK_VDL_NODE ;
    }
    
    public : inline uintptr_t getHashCodeForMap (void) const {
      return (uintptr_t) ((mIndex << 11)
                              ^ mValue
                              ^ ((mPtrToNext == NULL) ? -1 : mPtrToNext->mID)) ;
    }
  } ;

//--- Realloc unique table
  public : static void reallocUniqueTable (const int32_t inTableUniqueNewSize) ;

//--- Realloc addition cache
  public : static void reallocAdditionCache (const int32_t inNewCacheSize) ;

//--- Decision list
  protected : cZSVinfo * mRootPointer ;

//--- Set to NULL vector
  public : void setToNullVector (void) ;

//--- Null vector ?
  public : bool isNullVector (void) const ;

//--- Vector comparison
  public : bool operator == (const C_ZSV & inOperand) const ;

//--- Add vectors
  public : C_ZSV operator + (const C_ZSV & inOperand) const ;

//--- Add a value to an index
  public : void add (const T_vdd_zsl_index inIndex, const T_vdd_zsl_value inValue) ;

//--- Explore a VDL
  public : static void explore_vdl (C_ZSV & ioVDL,
                                    T_vdd_zsl_index & outIndex,
                                    T_vdd_zsl_value & outValue) ;

//--- print a vector
  public : void printVector (AC_OutputStream & inStream,
                             const TC_UniqueArray <C_String> & inNames,
                             const int32_t inFirst,
                             const int32_t inStep) const ;

  public : void printVector (AC_OutputStream & inStream,
                             const char * inPrefix,
                             const int32_t inFirst,
                             const int32_t inStep) const ;

//--- Print VDL summary
  public : static void printVDLsummary (AC_OutputStream & inOutputStream) ;

//--- Get value ID (as int32_t integer)
  public : inline int32_t getLongID (void) const {
    return (mRootPointer != NULL) ? ((int32_t) mRootPointer->mID) : 0 ;
  }

//--- Get greatest component value
  public : inline int32_t getGreatestComponentValue (void) const {
    return (mRootPointer == NULL) ? 0 : mRootPointer->mMaxVectorValue ;
  }

//--- Vector comparisons (means that every value is >= operand value)
  public : bool greaterOrEqual (const C_ZSV & inOperand) const ;

  public : bool greaterThan (const C_ZSV & inOperand) const ;

//--- Get index value
  public : T_vdd_zsl_value operator () (const T_vdd_zsl_index inIndex) const ;

//--- Reset entry to zero
  public : void clearEntry (const T_vdd_zsl_index inIndex) ;

//--- Collect unused elements
  public : static void collectUnusedNodes (void) ;

//--- Get sum of components
  public : long getSum (void) const ;

//--- Internal methods
  protected : static cZSVinfo * find_or_add (const T_vdd_zsl_index inIndex,
                                                 const T_vdd_zsl_value inValue,
                                                 cZSVinfo * const inPointerToNext) ;

  protected : static cZSVinfo * internalAdd (const T_vdd_zsl_index inIndex,
                                                 const T_vdd_zsl_value inValue,
                                                 cZSVinfo * const inPointerToCurrent) ;

  protected : static cZSVinfo * internalSum (cZSVinfo * const inPtr1,
                                             cZSVinfo * const inPtr2) ;

  protected : static cZSVinfo * internalClearEntry (const T_vdd_zsl_index inIndex,
                                                        cZSVinfo * const inPointer) ;

  protected : typedef enum {kNonComparable, kInf, kEqual, kSup} enumCompare ;

  protected : static enumCompare internalGreaterThan (C_ZSV::cZSVinfo * inCurrentNodePointer,
                                                      C_ZSV::cZSVinfo * inOperandNodePointer) ;
  protected : static int32_t smNodeCompare ;
  public : static uint32_t getNodeSize (void) ;
  public : static int32_t getNodeComparesCount (void) { return smNodeCompare ; }
  protected : static int32_t smNodeCount ;
  public : static int32_t getVDLnodeCount (void) { return smNodeCount ; }
  protected : static uint64_t smTrivialAdd ;
  public : static uint64_t getTrivialAddCount (void) { return smTrivialAdd ; }
  public : static uint64_t getCacheSuccessCount (void) ;
  public : static uint64_t getCacheFailureCount (void) ;
  public : static uint64_t getCacheOverrideCount (void) ;
  public : static uint64_t getUnusedCacheEntriesCount (void) ;
  public : static uint64_t getCacheEntriesCount (void) ;
  
  friend class cZSVinfo ;
} ;

//---------------------------------------------------------------------------*

#endif
