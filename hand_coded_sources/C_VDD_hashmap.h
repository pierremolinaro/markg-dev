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
//  Copyright (C) 2005, ..., 2014 Pierre Molinaro.                           *
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

#ifndef C_VDD_hashmap_DEFINED
#define C_VDD_hashmap_DEFINED

//---------------------------------------------------------------------------*

#include "C_VDD.h"

//---------------------------------------------------------------------------*

#include <stddef.h>

//---------------------------------------------------------------------------*

class C_VDD_hashmap {
//--- Constructor
  public : C_VDD_hashmap (void) ;

//--- Destructor
  public : virtual ~C_VDD_hashmap (void) ;

//--- Search or insert
  public : C_VDD::cVDDnodeInfo * search_or_insert (const C_VDD::cVDDnodeInfo & inInfo,
                                                   bool & outInsertionPerformed) ;

//--- Search
  public : C_VDD::cVDDnodeInfo * search (const C_VDD::cVDDnodeInfo & inInfo) ;

//--- Change size
  public : void reallocMap (const int32_t inNewSize) ;

//--- Get map size (in bytes)
  public : uint32_t getMapSizeInBytes (void) const ;

//--- Get marked nodes count
  public : int32_t getMarkedNodesCount (void) const ;

//--- Sweep unmarked objects
  public : uint32_t sweepUnmarkedObjects (void) ;

//--- Unmarked all objects
  public : void unmarkAllObjects (void) ;

//--- Current Entry count
  protected : int32_t mEntryCurrentCount ;
  public : inline int32_t getHashMapEntryCount (void) const { return mEntryCurrentCount ; }

//--- Get node size (in bytes)
  public : static uint32_t getNodeSize (void) { return (uint32_t) sizeof (MyBlockavltree_element_for_collision) ; }

//--- Get allocated size (in bytes)
  public : static uint32_t getAllocatedSizeInBytes (void) ;

//--- No copy
  private : C_VDD_hashmap (const C_VDD_hashmap &) ;
  private : void operator = (const C_VDD_hashmap &) ;

  private : class MyBlockavltree_element_for_collision ;
  
//------------------- C_TreeForCollision embedded class
  private : class C_TreeForCollision {
//--- Constructor and destructor
  public : C_TreeForCollision (void) ;
  public : virtual ~C_TreeForCollision (void) ;

//--- Search or insert
  public : C_VDD::cVDDnodeInfo * search_or_insert (const C_VDD::cVDDnodeInfo & inInfo,
                                                   bool & outInsertionPerformed) ;

//--- Search
  public : inline C_VDD::cVDDnodeInfo * search (const C_VDD::cVDDnodeInfo & inInfo) ;

//--- Get marked nodes count
  public : int32_t getMarkedNodesCount (void) const ;

//--- Sweep unmarked objects
  public : uint32_t sweepUnmarkedObjects (void) ;

//--- No copy
  private : C_TreeForCollision (const C_TreeForCollision &) ;
  private : void operator = (const C_TreeForCollision &) ;
  
//--- Root
  protected : MyBlockavltree_element_for_collision * mRoot ;

//--- Unmarked all objects
  public : void unmarkAllObjects (void) ;

//--- Allocation of a block
  public : static void allocBlock (void) ;

//--- Transfer object in a new map array
  public : void transfertElementsInNewMapArray (C_TreeForCollision * inNewMapArray,
                                                const uint32_t inNewSize) ;

//--- Internal methods
  protected : static void rotateLeft (MyBlockavltree_element_for_collision * & ioPtr) ;

  protected : static void rotateRight (MyBlockavltree_element_for_collision * & ioPtr) ;

  protected : C_VDD::cVDDnodeInfo * avltree_search (MyBlockavltree_element_for_collision * ioRootPointer,
                                                       const C_VDD::cVDDnodeInfo & inInfo) ;

  protected : C_VDD::cVDDnodeInfo * recursiveSearchOrInsert (MyBlockavltree_element_for_collision * & ioRootPointer,
                                                             const C_VDD::cVDDnodeInfo & inInfo,
                                                             bool & outExtension,
                                                             bool & outInsertionPerformed) ;

  protected : static void recursiveInsertElement (MyBlockavltree_element_for_collision * & ioRootPointer,
                                           MyBlockavltree_element_for_collision * const inElementPointer,
                                           bool & outExtension,
                                           bool & outInsertionPerformed) ;

  protected : int32_t internalMarkedNodeCount (const MyBlockavltree_element_for_collision * const inElement) const ;

  protected : uint32_t internalRecursiveSweep (MyBlockavltree_element_for_collision * inElement) ;

  protected : void internalRecursiveUnmark (MyBlockavltree_element_for_collision * inElement) ;

  protected : static void recursiveTransfertElementsInNewMapArray
                                             (MyBlockavltree_element_for_collision * const inElementPointer,
                                              C_TreeForCollision * inNewMapArray,
                                              const uint32_t inNewSize) ;
//--- Friend
  friend class MyBlockavltree_element_for_collision ;
  friend class cAllocInfo ;
} ;

//------------------- MyBlockavltree_element_for_collision embedded class
  private : class MyBlockavltree_element_for_collision {
    public : C_VDD::cVDDnodeInfo mInfo ;
    public : MyBlockavltree_element_for_collision * mPtrToSup ;
    public : MyBlockavltree_element_for_collision * mPtrToInf ;
    public : int32_t mBalance ;
    public : MyBlockavltree_element_for_collision (const C_VDD::cVDDnodeInfo & inInfo) :
    mInfo (inInfo),
    mPtrToSup (NULL),
    mPtrToInf (NULL),
    mBalance (0) {
    }
    public : ~MyBlockavltree_element_for_collision (void) {
      delete mPtrToSup ;
      delete mPtrToInf ;
    }
    public : intptr_t compare (const MyBlockavltree_element_for_collision & inElement) const {
      return mInfo.compare (inElement.mInfo) ;
    }
    public : void * operator new (const size_t inByteSize) ;
    public : void operator delete (void * inPtr) ;
    private : MyBlockavltree_element_for_collision (const MyBlockavltree_element_for_collision & inSource) ;
    private : void operator = (const MyBlockavltree_element_for_collision & inSource) ;
  } ;

//------------------- MyBlockavltree_element_for_collision embedded class
  private : class cAllocInfo {
    public : char * * mAllocatedBlockList ;
    public : int32_t mAllocatedBlockListSize ;
    public : int32_t mAllocatedBlockCount ;
    public : MyBlockavltree_element_for_collision * mFreeList ;
    public : int32_t mAllocatedObjectCount ;
    public : int32_t mCreatedObjectCount ;
    public : cAllocInfo (void) :
    mAllocatedBlockList (NULL),
    mAllocatedBlockListSize (0),
    mAllocatedBlockCount (0),
    mFreeList (NULL),
    mAllocatedObjectCount (0),
    mCreatedObjectCount (0) {
    }
  } ;

//--- Minimum map array (1 entry)
  protected : C_TreeForCollision mMinimumMapArray ;

//--- map array
  protected : C_TreeForCollision * mMapArray ;

//--- Get created element count
  public : static int32_t getCreatedObjectCount (void) { return smAllocInfo.mCreatedObjectCount ; }

//--- Get currently used element count
  public : static int32_t getCurrentObjectCount (void) { return smAllocInfo.mAllocatedObjectCount ; }

//--- Allocation info (static variable)
  protected : static cAllocInfo smAllocInfo ;
} ;

//---------------------------------------------------------------------------*

#endif
