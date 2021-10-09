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

#ifndef POST_CONDITIONS_LIST_DEFINED
#define POST_CONDITIONS_LIST_DEFINED

//---------------------------------------------------------------------------*

#include "C_vdd_types.h"
#include "collections/TC_UniqueArray.h"
#include "strings/C_String.h"

//---------------------------------------------------------------------------*

#include <stdio.h>

//---------------------------------------------------------------------------*

//--- Only the MSB is One
const intptr_t MARK_PCL_NODE = INTPTR_MIN ;

//---------------------------------------------------------------------------*

class C_PCL {
//--- Constructor et destructor
  public : C_PCL (void) ; // Null vector
  public : virtual ~C_PCL (void) ;

//--- Control copy
  public : C_PCL (const C_PCL & inSource) ;
  public : C_PCL & operator = (const C_PCL & inSource) ;

//--- Pointers for handling a double-linked list of all existing variables
  protected : C_PCL * mPtrToNextExisting ;
  protected : C_PCL * mPtrToPreviousExisting ;
  private : void initLinks (void) ;
  
//--- Internal nodes
  public : class cVDLnodeInfo {
    public : cVDLnodeInfo * mPtrToNext ;
    public : intptr_t mID ;
    public : T_vdd_zsl_value mValue ;
    public : T_vdd_zsl_index mIndex ;
    public : bool mAssignment ;
    
    public : intptr_t compare (const cVDLnodeInfo & inOperand) const ;
    
    public : inline bool isMarked (void) const {
      return (mID & MARK_PCL_NODE) != 0 ;
    }

    public : inline void mark (void) {
      mID |= MARK_PCL_NODE ;
    }

    public : inline void unmark (void) {
      mID &= ~ MARK_PCL_NODE ;
    }
    
    public : inline uint32_t getHashCodeForMap (void) const {
      return (uint32_t) ((mIndex << 11)
                              ^ mValue
                              ^ ((mPtrToNext == NULL) ? -1 : mPtrToNext->mID)) ;
    }
  } ;

//--- Realloc unique table
  public : static void reallocUniqueTable (const int32_t inTableUniqueNewSize) ;

//--- Realloc addition cache
  public : static void reallocAdditionCache (const size_t inNewCacheSize) ;

//--- Decision list
  protected : cVDLnodeInfo * mRootPointer ;

//--- Set to NULL vector
  public : void setToNullVector (void) ;

//--- Merge an other vector (return false if merging cannot be performed)
  public : bool merge (const C_PCL & inVector) ;

//--- Null vector ?
  public : bool isNullVector (void) const ;

//--- Vector comparison
  public : bool operator == (const C_PCL & inOperand) const ;

//--- Define an entry
  public : void defineEntry (const T_vdd_zsl_index inIndex,
                             const T_vdd_zsl_value inValue,
                             const bool inAssignment) ;

//--- Explore a VDL
  public : C_PCL explore_pcl (T_vdd_zsl_index & outIndex,
                              T_vdd_zsl_value & outValue,
                              bool & outAssignment) const ;

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

//--- Get index value
  public : T_vdd_zsl_value operator () (const T_vdd_zsl_index inIndex) const ;

//--- Collect unused elements
  public : static void collectUnusedNodes (void) ;

//--- Internal methods
  protected : static cVDLnodeInfo * find_or_add (const T_vdd_zsl_index inIndex,
                                                 const T_vdd_zsl_value inValue,
                                                 const bool inAssignment,
                                                 cVDLnodeInfo * const inPointerToNext) ;

  protected : static cVDLnodeInfo * internalDefineEntry (const T_vdd_zsl_index inIndex,
                                                 const T_vdd_zsl_value inValue,
                                                 const bool inAssignment,
                                                 cVDLnodeInfo * const inPointerToCurrent) ;

  protected : static cVDLnodeInfo * internalMerge (cVDLnodeInfo * inRootPointer,
                                                   cVDLnodeInfo * inOtherRootPointer,
                                                   bool & ioOk) ;

  protected : typedef enum {kNonComparable, kInf, kEqual, kSup} enumCompare ;

  protected : static int32_t smNodeCompare ;
  public : static uint32_t getNodeSize (void) ;
  public : static int32_t getNodeComparesCount (void) { return smNodeCompare ; }
  protected : static int32_t smNodeCount ;
  public : static int32_t getVDLnodeCount (void) { return smNodeCount ; }
  public : static uint64_t getCacheSuccessCount (void) ;
  public : static uint64_t getCacheFailureCount (void) ;
  public : static uint64_t getCacheOverrideCount (void) ;
  public : static uint64_t getUnusedCacheEntriesCount (void) ;
  public : static uint64_t getCacheEntriesCount (void) ;
  
  friend class cVDLnodeInfo ;
} ;

//---------------------------------------------------------------------------*

#endif
