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
#include "utilities/F_GetPrime.h"
#include "streams/AC_OutputStream.h"
#include "utilities/MF_MemoryControl.h"
#include "strings/C_String.h"

//---------------------------------------------------------------------------*

#include <math.h>

//---------------------------------------------------------------------------*

C_AEDDPrimeCache2::C_AEDDPrimeCache2 (const int32_t inCacheSize) :
mCache (NULL),
mCacheSize ((int32_t) getPrimeGreaterThan ((inCacheSize < 1) ? 1 : (uint32_t) inCacheSize)),
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
  const int32_t newCacheSize = (int32_t) getPrimeGreaterThan ((uint32_t) inCacheSize) ;
  if (newCacheSize != mCacheSize) {
    cCacheEntry * newCache = NULL ;
    macroMyNewArrayThere (newCache, cCacheEntry, newCacheSize) ;
    if (newCache != NULL) {
      cCacheEntry * previousCache = mCache ;
      mCache = newCache ;
      const int32_t previousCacheSize = mCacheSize ;
      mCacheSize = newCacheSize ;
      mCacheSizeIntegerSquareRoot = (int32_t) ::sqrt ((float) mCacheSize) ;
      clearAllCacheEntries () ;
      bool cacheSuccess ;
      int32_t hashCode ;
      intptr_t cacheResult ;
      for (int32_t i=0 ; i<previousCacheSize ; i++) {
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
    for (int32_t i=0 ; i<mCacheSize ; i++) {
      mCache [i].mOperand1 = 0 ;
    }
    mCacheIsClear = true ;
  }
}


//---------------------------------------------------------------------------*

int32_t C_AEDDPrimeCache2::getCacheSizeInKBytes (void) {
  return (mCacheSize * (int32_t) sizeof (cCacheEntry)) / 1024 ;
}

//---------------------------------------------------------------------------*

int32_t C_AEDDPrimeCache2::getUnusedCacheEntriesCount (void) const {
  int32_t unusedEntriesCount = 0 ;
  for (int32_t i=0 ; i<mCacheSize ; i++) {
    unusedEntriesCount += (mCache [i].mOperand1 == 0) ;
  }
  return unusedEntriesCount ;
}

//---------------------------------------------------------------------------*

void C_AEDDPrimeCache2::
printStatistics (AC_OutputStream & inStream,
                 const char * inTitle) const {
  const int32_t total = mTrivialOperationsCount
                     + mCacheSuccessCount
                     + mCacheMissCount ;
  const int32_t used = mCacheSize - getUnusedCacheEntriesCount () ;
  inStream << "Statistics about " << inTitle << " operations :\n"
//--- Cache properties
              "  cache entries: " << cStringWithSigned (mCacheSize)
           << ", used: " << cStringWithSigned (used)
           << " (" << cStringWithSigned ((int32_t) ((used * 100) / mCacheSize)) << "%)"
           << ", size " << cStringWithSigned (mCacheSize * ((int32_t) sizeof (cCacheEntry)) / 1024) << " kbytes\n"
//--- Trivial
           << "  trivial: " << cStringWithSigned (mTrivialOperationsCount) ;
  if (total != 0) {
    inStream << " (" << cStringWithSigned ((int32_t) (mTrivialOperationsCount * 100 / total)) << "%)" ;
  }
  inStream << "\n" ;
//--- Cached
  inStream << "  cached: " << cStringWithSigned (mCacheSuccessCount) ;
  if (total != 0) {
    inStream << " (" << cStringWithSigned ((int32_t) (mCacheSuccessCount * 100 / total)) << "%)" ;
  }
  inStream << "\n" ;
//--- Computed
  inStream << "  computed: " << cStringWithSigned (mCacheMissCount) ;
  if (total != 0) {
    inStream << " (" << cStringWithSigned ((int32_t) (mCacheMissCount * 100 / total)) << "%)"
                ", overridden: " << cStringWithSigned (mCacheOverridesCount)
             << " (" << cStringWithSigned ((int32_t) (mCacheOverridesCount * 100 / total)) << "%)" ;
  }
  inStream << "\n" ;
}

//---------------------------------------------------------------------------*
