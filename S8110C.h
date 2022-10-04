// License       : License.txt
// Specifications: Spec-S-8110C_8120C.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : S8110C.h
// Reason for change: 01.00.00 : 03/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#ifndef __S8110C_H__
#define __S8110C_H__

#include "user_define.h"

// Components number
#define iS8110C                 105U                    // ABLIC S-8110C, S-8120C

// S-8110C, S-8120C System Parts definitions
#define iS8110C_xoff            1.474F                  // X offset [V]
#define iS8110C_yoff            30.0F                   // Y offset [degree celsius]
#define iS8110C_gain            -0.0082F                // Gain [V/degree celsius]
#define iS8110C_max             100.0F                  // Temperature Max [degree celsius]
#define iS8110C_min             -30.0F                  // Temperature Min [degree celsius]

extern const tbl_adc_t tbl_S8110C;

#endif /*__S8110C_H__*/
