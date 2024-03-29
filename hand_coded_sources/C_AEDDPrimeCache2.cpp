//---------------------------------------------------------------------------*
//                                                                           *
//     C++ class for implementing a software cache for 2 operands operation  *
//                        (size : a prime integer)                           *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2001, ..., 2006 Pierre Molinaro.                           *
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

#include "C_AEDDPrimeCache2.h"
#include "F_GetPrime.h"
#include "AbstractOutputStream.h"
#include "MF_MemoryControl.h"
#include "String-class.h"

//---------------------------------------------------------------------------*

#include <math.h>

//---------------------------------------------------------------------------*

C_AEDDPrimeCache2::C_AEDDPrimeCache2 (const int32_t inCacheSize) :
mCache (NULL),
mCacheSize ((size_t) getPrimeGreaterThan ((inCacheSize < 1) ? 1 : (uint32_t) inCacheSize)),
mCacheSizeIntegerSquareRoot ((int32_t) ::sqrt ((float) mCacheSize)),
mTrivialOperationsCount (0),
mCacheSuccessCount (0),
mCacheMissCount (0),
mCacheOverridesCount (0),
mCacheIsClear (false) {
  macroMyNewArray (mCache, cCacheEntry, mCacheSize) ;
  clearAllCacheEntries () ;
}

//---------------------------------------------------------------------------*

C_AEDDPrimeCache2::~ C_AEDDPrimeCache2 (void) {
  macroMyDeleteArray (mCache) ;
}

//---------------------------------------------------------------------------*

void C_AEDDPrimeCache2::freeCache (void) {
  macroMyDeleteArray (mCache) ;
  mCacheSize = 0 ;
  mCacheSizeIntegerSquareRoot = 0 ;
}

//---------------------------------------------------------------------------*

void C_AEDDPrimeCache2::reallocCache (const int32_t inCacheSize
                                      COMMA_LOCATION_ARGS) {
  const size_t newCacheSize = (size_t) getPrimeGreaterThan ((uint32_t) inCacheSize) ;
  if (newCacheSize != mCacheSize) {
    cCacheEntry * newCache = NULL ;
    macroMyNewArrayThere (newCache, cCacheEntry, newCacheSize) ;
    if (newCache != NULL) {
      cCacheEntry * previousCache = mCache ;
      mCache = newCache ;
      const size_t previousCacheSize = mCacheSize ;
      mCacheSize = newCacheSize ;
      mCacheSizeIntegerSquareRoot = (int32_t) ::sqrt ((float) mCacheSize) ;
      clearAllCacheEntries () ;
      bool cacheSuccess ;
      int32_t hashCode ;
      intptr_t cacheResult ;
      for (size_t i=0 ; i<previousCacheSize ; i++) {
        if (previousCache [i].mOperand1 != 0) {
          getCacheEntry (previousCache [i].mOperand1,
                         previousCache [i].mOperand2,
                         cacheSuccess,
                         hashCode,
                         cacheResult) ;
          if (! cacheSuccess) {
            writeCacheEntry (previousCache [i].mOperand1,
                             previousCache [i].mOperand2,
                             hashCode,
                             previousCache [i].mResult) ;
          }
        }
      }
      macroMyDeleteArray (previousCache) ;
    }
  }
}

//---------------------------------------------------------------------------*

void C_AEDDPrimeCache2::clearAllCacheEntries (void) {
  if (! mCacheIsClear) {
    for (size_t i=0 ; i<mCacheSize ; i++) {
      mCache [i].mOperand1 = 0 ;
    }
    mCacheIsClear = true ;
  }
}


//---------------------------------------------------------------------------*

size_t C_AEDDPrimeCache2::getCacheSizeInKBytes (void) {
  return (mCacheSize * sizeof (cCacheEntry)) / 1024 ;
}

//---------------------------------------------------------------------------*

size_t C_AEDDPrimeCache2::getUnusedCacheEntriesCount (void) const {
  size_t unusedEntriesCount = 0 ;
  for (size_t i=0 ; i<mCacheSize ; i++) {
    unusedEntriesCount += (mCache [i].mOperand1 == 0) ;
  }
  return unusedEntriesCount ;
}

//---------------------------------------------------------------------------*

void C_AEDDPrimeCache2::
printStatistics (AbstractOutputStream & inStream,
                 const char * inTitle) const {
  const int32_t total = mTrivialOperationsCount
                     + mCacheSuccessCount
                     + mCacheMissCount ;
  const size_t used = mCacheSize - getUnusedCacheEntriesCount () ;
  inStream.appendString ("Statistics about ") ;
  inStream.appendString (inTitle) ;
  inStream.appendString (" operations :\n") ;
//--- Cache properties
  inStream.appendString ( "  cache entries: ") ;
  inStream.appendUnsigned (mCacheSize);
  inStream.appendString (", used: ") ;
  inStream.appendUnsigned (used);
  inStream.appendString (" (") ;
  inStream.appendSigned ((int32_t) ((used * 100) / mCacheSize)) ;
  inStream.appendString ("%)") ;
  inStream.appendString (", size ") ;
  inStream.appendSigned (mCacheSize * ((int32_t) sizeof (cCacheEntry)) / 1024) ;
  inStream.appendString (" kbytes\n") ;
//--- Trivial
  inStream.appendString ("  trivial: ") ;
  inStream.appendSigned (mTrivialOperationsCount) ;
  if (total != 0) {
    inStream.appendString (" (") ;
    inStream.appendSigned ((int32_t) (mTrivialOperationsCount * 100 / total)) ;
    inStream.appendString ("%)") ;
  }
  inStream.appendString ("\n") ;
//--- Cached
  inStream.appendString ("  cached: ") ;
  inStream.appendSigned (mCacheSuccessCount) ;
  if (total != 0) {
    inStream.appendString (" (") ;
    inStream.appendSigned ((int32_t) (mCacheSuccessCount * 100 / total)) ;
    inStream.appendString ("%)") ;
  }
  inStream.appendString ("\n") ;
//--- Computed
  inStream.appendString ("  computed: ") ;
  inStream.appendSigned (mCacheMissCount) ;
  if (total != 0) {
    inStream.appendString (" (") ;
    inStream.appendSigned ((int32_t) (mCacheMissCount * 100 / total)) ;
    inStream.appendString ("%)"
                  ", overridden: ") ;
    inStream.appendSigned (mCacheOverridesCount);
    inStream.appendString (" (") ;
    inStream.appendSigned ((int32_t) (mCacheOverridesCount * 100 / total)) ;
    inStream.appendString ("%)") ;
  }
  inStream.appendString ("\n") ;
}

//---------------------------------------------------------------------------*
