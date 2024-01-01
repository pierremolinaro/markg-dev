//---------------------------------------------------------------------------*
//                                                                           *
//     C++ class for implementing ZERO SUPPRESS VECTOR (ZSV)                 *
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

#ifndef VDD_BASE_TYPES_DEFINED
#define VDD_BASE_TYPES_DEFINED

//---------------------------------------------------------------------------*

#include "M_machine.h"

//---------------------------------------------------------------------------*

#define VDD_AND_ZSL_VALUE_SIZE 16

#ifndef VDD_AND_ZSL_VALUE_SIZE
  typedef int32_t T_vdd_zsl_value ;
  const T_vdd_zsl_value MAX_VDD_ZSL_VALUE = INT32_MAX ;
#else
  #if VDD_AND_ZSL_VALUE_SIZE == 8
    typedef int8_t T_vdd_zsl_value ;
    const T_vdd_zsl_value MAX_VDD_ZSL_VALUE = INT8_MAX ;
  #elif VDD_AND_ZSL_VALUE_SIZE == 16
    typedef int16_t T_vdd_zsl_value ;
    const T_vdd_zsl_value MAX_VDD_ZSL_VALUE = INT16_MAX ;
  #elif VDD_AND_ZSL_VALUE_SIZE == 32
    typedef int32_t T_vdd_zsl_value ;
    const T_vdd_zsl_value MAX_VDD_ZSL_VALUE = INT32_MAX ;
  #else
    #error "incorrect VDD_AND_ZSL_VALUE_SIZE value"
  #endif
#endif

//---------------------------------------------------------------------------*

#define VDD_AND_ZSL_INDEX_SIZE 16

#ifndef VDD_AND_ZSL_INDEX_SIZE
  typedef int32_t T_vdd_zsl_index ;
#else
  #if VDD_AND_ZSL_INDEX_SIZE == 8
    typedef int8_t T_vdd_zsl_index ;
  #elif VDD_AND_ZSL_INDEX_SIZE == 16
    typedef int16_t T_vdd_zsl_index ;
  #elif VDD_AND_ZSL_INDEX_SIZE == 32
    typedef int32_t T_vdd_zsl_index ;
  #else
    #error "incorrect VDD_AND_ZSL_INDEX_SIZE value"
  #endif
#endif

//---------------------------------------------------------------------------*

#endif
