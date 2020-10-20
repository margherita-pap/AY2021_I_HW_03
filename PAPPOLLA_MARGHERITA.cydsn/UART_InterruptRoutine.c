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
 *\file UART_interruptRoutine.c
 *\Interrupt file that is executed each time we receive a byte. If we receive 1 byte within 5 sec, I stop 
   the timer thanks to the function reset and i switch the state.
 *\date: October 20, 2020
 *\author: Margherita Pappolla
*/
#include "UART_InterruptRoutine.h" 
#include "TIMER_InterruptRoutine.h"
#include "RGBLedDriver.h"
#include "UART.h"
#include "stdio.h"

extern uint8_t state;
extern char packet[5];

CY_ISR(Custom_UART_RX_ISR) {
    
    switch(state)
    {
        case IDLE:
        if( UART_ReadRxStatus()==UART_RX_STS_FIFO_NOTEMPTY){ 
        state=HEADER;
        }
        break;
        
        case HEADER:
        if( UART_ReadRxStatus()==UART_RX_STS_FIFO_NOTEMPTY){
        reset_timer();
        state=RED;
        }
        break;
        case RED:
        if( UART_ReadRxStatus()==UART_RX_STS_FIFO_NOTEMPTY){
        reset_timer();  
        state=GREEN;
        }
        break;
        case GREEN:
        if( UART_ReadRxStatus()==UART_RX_STS_FIFO_NOTEMPTY){
        reset_timer();      
        state=BLUE;
        }
        break;
        case BLUE:
        if( UART_ReadRxStatus()==UART_RX_STS_FIFO_NOTEMPTY){
        reset_timer();     
        state=TAIL;
        }
        break;
        
        default: 
        break;
        
    }
}
/* [] END OF FILE */
