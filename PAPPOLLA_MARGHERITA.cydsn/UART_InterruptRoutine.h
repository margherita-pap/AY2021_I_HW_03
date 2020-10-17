/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#ifndef __UART_INTERRUPT_ROUTINES_H 
    #define __UART_INTERRUPT_ROUTINES_H
    #include "cytypes.h"
    CY_ISR_PROTO(Custom_UART_RX_ISR); 
    //CY_ISR_PROTO(Custom_TIMER5SEC_ISR);
#endif

#define IDLE 0
#define HEADER 1
#define RED 2
#define GREEN 3
#define BLUE 4
#define TAIL 5

/* [] END OF FILE */
