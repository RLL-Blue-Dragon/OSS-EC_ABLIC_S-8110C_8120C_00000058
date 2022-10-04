// License       : License.txt
// Specifications: Spec-S-8110C_8120C.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : S8110C.cpp
// Reason for change: 01.00.00 : 03/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include        "S8110C.h"

#if     iS8110C_ma == iSMA                              // Simple moving average filter
static float32 S8110C_sma_buf[iS8110C_SMA_num];
static sma_f32_t S8110C_Phy_SMA =
{
        iInitial ,                                      // Initial state
        iS8110C_SMA_num ,                               // Simple moving average number & buf size
        0U ,                                            // buffer position
        0.0F ,                                          // sum
        &S8110C_sma_buf[0]                              // buffer
};

#elif   iS8110C_ma == iEMA                              // Exponential moving average filter
static ema_f32_t S8110C_Phy_EMA =
{
        iInitial ,                                      // Initial state
        0.0F ,                                          // Xn-1
        iS8110C_EMA_K                                   // Exponential smoothing factor 
};

#elif   iS8110C_ma == iWMA                              // Weighted moving average filter
static float32 S8110C_wma_buf[iS8110C_WMA_num];
static wma_f32_t S8110C_Phy_WMA =
{
        iInitial ,                                      // Initial state
        iS8110C_WMA_num ,                               // Weighted moving average number & buf size
        0U ,                                            // buffer poition
        iS8110C_WMA_num * (iS8110C_WMA_num + 1)/2 ,     // kn sum
        &S8110C_wma_buf[0]                              // Xn buffer
};

#else                                                   // Non-moving average filter
#endif

#define iDummy_adr       0xffffffff                     // Dummy address

const tbl_adc_t tbl_S8110C =
{
        iS8110C                 ,
        iS8110C_pin             ,
        iS8110C_xoff            ,
        iS8110C_yoff            ,
        iS8110C_gain            ,
        iS8110C_max             ,
        iS8110C_min             ,
        iS8110C_ma              ,
        
#if     iS8110C_ma == iSMA                              // Simple moving average filter
        &S8110C_Phy_SMA         ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#elif   iS8110C_ma == iEMA                              // Exponential moving average filter
        (sma_f32_t*)iDummy_adr  ,
        &S8110C_Phy_EMA         ,
        (wma_f32_t*)iDummy_adr
#elif   iS8110C_ma == iWMA                              // Weighted moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        &S8110C_Phy_WMA
#else                                                   // Non-moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#endif

};
