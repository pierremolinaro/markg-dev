//---------------------------------------------------------------------------*
//                                                                           *
//  This file is part of libpm library                                       *
//  This library is free software; you can redistribute it and/or modify it  *
//  under the terms of the GNU Lesser General Public License as published    *
//  by the Free Software Foundation; either version 2 of the License, or     *
//  (at your option) any later version.                                      *
//                                                                           *
//  This program is distributed in the hope it will be useful, but WITHOUT   *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or    *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for *
//  more details.                                                            *
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

#ifndef cVDDnodeInfo_DEFINED
#define cVDDnodeInfo_DEFINED

//---------------------------------------------------------------------------*

#include "C_VDD.h"

//---------------------------------------------------------------------------*

class cVDDnodeInfo {
  public : uint32_t mNodeID ;
  public : C_VDD::cVDDnodeInfo * mVDDNode ;
  public : inline uint32_t getHashCodeForMap (void) const {
    return mNodeID ;
  }
  public : inline int32_t compare (const cVDDnodeInfo & inOperand) const {
    return ((int32_t) mNodeID) - ((int32_t) inOperand.mNodeID) ;
  }
  public : inline bool isMarked (void) const { return false ; }
  public : inline void unmark (void) { }
} ;

//---------------------------------------------------------------------------*

#endif
