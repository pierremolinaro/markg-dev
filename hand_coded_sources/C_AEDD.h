//---------------------------------------------------------------------------*
//                                                                           *
//     AEDD package                                                          *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2003, 2004 Pierre Molinaro and Cedric Motsch.              *
//  Copyright (C) 2005, ..., 2008 Pierre Molinaro.                           *
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

#ifndef ARITHMETIC_EXPRESSION_DECISION_DIAGRAMS_DEFINED
#define ARITHMETIC_EXPRESSION_DECISION_DIAGRAMS_DEFINED

//---------------------------------------------------------------------------*

#include "utilities/M_machine.h"

//---------------------------------------------------------------------------*

#include <stdio.h>

//---------------------------------------------------------------------------*

class AC_OutputStream ;

//---------------------------------------------------------------------------*

class C_AEDD {
//--- Constructor and destructor
  public : C_AEDD (void) ; // Build a false AEDD
  public : virtual ~C_AEDD (void) ;

//--- Build a AEDD result of comparison between a variable and a constant
  public : static C_AEDD varSupOrEqualToConstant (const uint16_t inVar,
                                                  const int32_t inConstant) ;
  public : static C_AEDD varInfOrEqualToConstant (const uint16_t inVar,
                                                  const int32_t inConstant) ;
  public : static C_AEDD varEqualToConstant (const uint16_t inVar,
                                             const int32_t inConstant) ;
  public : static C_AEDD varDifferentThanConstant (const uint16_t inVar,
                                                   const int32_t inConstant) ;
  public : static C_AEDD varStrictInfThanConstant (const uint16_t inVar,
                                                   const int32_t inConstant) ;
  public : static C_AEDD varStrictSupThanConstant (const uint16_t inVar,
                                                   const int32_t inConstant) ;

//--- Logical operations on a AEDD
  public : void operator &= (const C_AEDD & inOperand) ; // And
  public : void operator |= (const C_AEDD & inOperand) ; // Or
  public : void negate (void) ; 

//--- Logical operations between BDDs
  public : C_AEDD operator & (const C_AEDD & inOperand) const ; // And
  public : C_AEDD operator | (const C_AEDD & inOperand) const ; // Or
  public : C_AEDD operator ^ (const C_AEDD & inOperand) const ; // Exclusive or
  public : C_AEDD implies (const C_AEDD & inOperand) const ; 
  public : static C_AEDD ite (const C_AEDD & f, const C_AEDD & g, const C_AEDD & h) ; // ite (f, g, h)
  public : C_AEDD operator ~ (void) const ; // get complement


//--- Set to false or true
  public : void setToFalse (void) ;
  public : void setToTrue (void) ;

//--- Test AEDD
  public : inline bool isFalse (void) const { return mAEDDvalue == 0L ; }
  public : inline bool isTrue (void) const { return mAEDDvalue == 1L ; }
  public : bool isComplemented (void) const ;
  public : bool infPtr (const C_AEDD & inOperand) const ;
  public : bool isIdenticalToAEDD (const C_AEDD & inOperand) const { return mAEDDvalue == inOperand.mAEDDvalue ; }
  public : intptr_t getIntegerValue (void) const { return mAEDDvalue ; }

//--- Get AEDD nodes count
  public : uintptr_t getAEDDnodesCount (void) const ;

//--- Printing (sur stdout)
  public : void printAEDDnodes (const char * inMessage) const ;

//--- Controlling nodes unique map
  public : static void changeHashMapSize (const uint16_t inSizeInKBytes) ;
  public : static size_t getHashMapEntriesCount (void) ;
  public : static size_t getAEDDinstancesCount (void) ;
  public : static size_t getCreatedNodesCount (void)  ;

//--- Controlling caches
  public : static void clearAllCacheEntries (void) ;

//--- Marking AEDD nodes
  public : void markAEDDnodes (void) ;

//--- Unmark all AEDD nodes
  public : static void unmarkAllExistingAEDDnodes (void) ;

//--- Marked nodes count
  public : static int32_t getMarkedNodesCount (void) ;

//--- Get existing nodes count
  public : static size_t getExistingNodesCount (void) ;

//---- Suppress unused nodes
  public : static void markAndSweepUnusedNodes (void) ;

//--- Size of a node 
  public : static int32_t getAEDDnodeSize (void) ;

//--- Imprimer un bilan des operations 
  public : static void printAEDDpackageOperationsSummary (AC_OutputStream & inStream) ;

//------------------- Internals ---------------------
  public : class C_AEDDnode {
    public : C_AEDDnode * mPtrToInf ;
    public : C_AEDDnode * mPtrToSup ;
    public : intptr_t mFalseBranch ; // branch when variable < constante
    public : intptr_t mTrueBranch ; // branch when variable >= constant
    public : intptr_t mConstant ;
    public : uint16_t mVar ;
    public : int8_t mBalance ;
    protected : bool mNodeMarked ;
  //--- Allocator and deallocator
    public : void * operator new (const size_t inByteSize) ;
    public : void operator delete (void * inPtr) ;
  //--- Nombre de comparaisons effectuees
    public : static uint32_t smComparisonsCount ;
  //---- Constructor
    public : inline C_AEDDnode (const intptr_t inBranch0,
                                const intptr_t inBranch1,
                                const uint16_t inVar,
                                const intptr_t inConstant) :
      mPtrToInf ((C_AEDDnode *) NULL),
      mPtrToSup ((C_AEDDnode *) NULL),
      mFalseBranch (inBranch0),
      mTrueBranch (inBranch1),
      mConstant (inConstant),
      mVar (inVar),
      mBalance (0),
      mNodeMarked (false) {
    }
  //---- Comparisons
    public : inline intptr_t compare (const intptr_t inBranch0,
                                    const intptr_t inBranch1,
                                    const uint16_t inVar,
                                    const intptr_t inConstant) const {
      smComparisonsCount ++ ;
      intptr_t result = mFalseBranch - inBranch0 ;
      if (result == 0) {
        result = mTrueBranch - inBranch1 ;
        if (result == 0) {
          result = mVar - inVar ;
          if (result == 0) {
            result = mConstant - inConstant ;
          }
        }
      }
      return result ;
    }
    public : inline intptr_t compare (const C_AEDDnode & inOperand) const {
      return compare (inOperand.mFalseBranch, inOperand.mTrueBranch,
                      inOperand.mVar, inOperand.mConstant) ;
    }
  //--- Mark
    public : inline bool isMarked (void) const {
      return mNodeMarked ;
    }
    public : inline void mark (void) {
      mNodeMarked = true ;
    }
    public : inline void unmark (void) {
      mNodeMarked = false ;
    }
  //--- Get hash code
    public : inline static uint32_t getHashCodeForMap (const intptr_t inBranch0,
                                                       const intptr_t inBranch1,
                                                       const uint16_t inVar,
                                                       const intptr_t inConstant,
                                                       const size_t inMapSize) {
       uintptr_t hCode = ((uintptr_t) inBranch0) << 7 ;
       hCode = (~hCode) ^ (uintptr_t) inBranch1 ;
       hCode = ((~hCode) << 3) ^ inVar ;
       hCode = ((~hCode) << 3) ^ (uintptr_t) inConstant ;
       const uintptr_t result = hCode % ((uint32_t) inMapSize) ;
       return (uint32_t) result ;
    }
  } ;

//--- Internal method
  private : void initLinks (void) ;

//--- Internal contructor
  private : C_AEDD (const intptr_t inInternalValue) ; // Internal, do not use

//--- Control copy
  public : C_AEDD (const C_AEDD & inSource) ;
  public : C_AEDD & operator = (const C_AEDD & inSource) ;

//--- Decision diagram root
  private : intptr_t mAEDDvalue ;

//--- Link between existing instances
  private : C_AEDD * mPtrToPreviousBDD ;
  private : C_AEDD * mPtrToNextBDD ;

//--- Friend
  friend class C_VDD ;
} ;

//---------------------------------------------------------------------------*

#endif
