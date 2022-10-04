// License       : License.txt
// Specifications: Spec-00000058.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : S8110C_00000058.cpp
// BSL              : 00000058
// Model number     : ABLIC S-8110C, S-8120C
// Spec               Component type       : ADC
//                    OS                   : Mbed
//                    Calculation          : Floating-point
//                    Conversion type      : Linear
//                    Moving average filter: Moving average filter select
//                    Diagnosis            : Range (Min to Max)
// Reason for change: 01.00.00 : 03/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include "S8110C.h"

AnalogIn S8110C_adc( iS8110C_pin , iVref );             // AnalogIn object

// Main Function
pp2ap_adc_t S8110C_00000058( void )
{
        pp2ap_adc_t res = pp_00000058( S8110C_adc , tbl_S8110C );
        return( res );
}
