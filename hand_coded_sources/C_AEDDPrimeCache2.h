//---------------------------------------------------------------------------*
//                                                                           *
//     C++ class for implementing a software cache for 2 operands operation  *
//                        (size : a prime integer)                           *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2001, ..., 2005 Pierre Molinaro.                           *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
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

#ifndef CLASS_AEDD_PRIME_CACHE_2_DEFINED
#define CLASS_AEDD_PRIME_CACHE_2_DEFINED

//---------------------------------------------------------------------------*

#include "utilities/MF_MemoryControl.h"

//---------------------------------------------------------------------------*

class AC_OutputStream ;

//---------------------------------------------------------------------------*

class C_AEDDPrimeCache2 {
//--- Constructor
  public : C_AEDDPrimeCache2 (const int32_t inCacheSize) ;

//--- Destructor
  public : virtual ~ C_AEDDPrimeCache2 (void) ;

//--- Cache entry type
  protected : class cCacheEntry {
    public : intptr_t mOperand1 ;
    public : intptr_t mOperand2 ;
    public : intptr_t mResult ;
  } ;

//--- Cache read
  public : inline void getCacheEntry (const intptr_t inOperand1,
                                      const intptr_t inOperand2,
                                      bool & outCacheSuccess,
                                      int32_t & outHashCode,
                                      intptr_t & outResult)  {
  //--- Compute hash code
    outHashCode = (int32_t) (((uint32_t) ((inOperand2 * mCacheSizeIntegerSquareRoot) + inOperand1)) % ((uint32_t) mCacheSize)) ;
  //--- Cache success ?
    outCacheSuccess = (inOperand1 == mCache [outHashCode].mOperand1)
                   && (inOperand2 == mCache [outHashCode].mOperand2) ;
  //--- Update counts
    mCacheSuccessCount +=   outCacheSuccess ;
    mCacheMissCount    += ! outCacheSuccess ;
  //--- Get result
    outResult = mCache [outHashCode].mResult ;
  }

//--- Cache write
  public : inline void writeCacheEntry (const intptr_t inOperand1,
                                        const intptr_t inOperand2,
                                        const int32_t inHashCode,
                                        const intptr_t inResult) {
  //--- Cache overrides ?
    mCacheOverridesCount += (mCache [inHashCode].mOperand1 != 0) ;
  //--- Write Operands
    mCache [inHashCode].mOperand1 = inOperand1 ;
    mCache [inHashCode].mOperand2 = inOperand2 ;
  //--- Write result
    mCache [inHashCode].mResult = inResult ;
  //--- Signal that cache is not clear
    mCacheIsClear = false ;
  }

//--- Clear all cache entries
  public : void clearAllCacheEntries (void) ;

//--- Realloc cache
  public : void reallocCache (const int32_t inCacheNewSize
                              COMMA_LOCATION_ARGS) ;

//--- Free cache (release memory)
  public : void freeCache (void) ;

//--- Cache array pointer
  protected : cCacheEntry * mCache ;

//--- Cache size
  protected : size_t mCacheSize ;

//--- Integer square root of cache size
  protected : int32_t mCacheSizeIntegerSquareRoot ;

//--- Cache successes
  protected : int32_t mTrivialOperationsCount ;
  public : inline int32_t getTrivialOperationsCount (void) const {
     return mTrivialOperationsCount ;
  }
  public : inline void incTrivialOperationsCount (void) { mTrivialOperationsCount ++ ; }
  public : inline void decTrivialOperationsCount (void) { mTrivialOperationsCount -- ; }

//--- Cache successes
  protected : int32_t mCacheSuccessCount ;
  public : inline int32_t getCacheSuccessCount (void) const { return mCacheSuccessCount ; }

//--- Cache miss
  protected : int32_t mCacheMissCount ;
  public : inline int32_t getCacheMissCount (void) const { return mCacheMissCount ; }

//--- Cache override
  protected : int32_t mCacheOverridesCount ;
  public : inline int32_t getCacheOverrideCount (void) const { return mCacheOverridesCount ; }

//--- Get cache entries count
  public : inline size_t getCacheEntriesCount (void) {
    return mCacheSize ;
  }

//--- Get cache size in kbytes
  public : inline size_t getCacheSizeInKBytes (void) ;

//--- Get unused entries count
  public : size_t getUnusedCacheEntriesCount (void) const ;

//--- Print statistics
  public : void printStatistics (AC_OutputStream & inStream,
                                 const char * inTitle) const ;

//--- Is cache clear ?
  protected : bool mCacheIsClear ;

//--- No copy
  private : C_AEDDPrimeCache2 (C_AEDDPrimeCache2 &) ;
  private : C_AEDDPrimeCache2 & operator = (C_AEDDPrimeCache2 &) ;
} ;

//---------------------------------------------------------------------------*

#endif
