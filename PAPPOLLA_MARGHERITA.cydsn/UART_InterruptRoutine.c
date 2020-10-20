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
        //Timer_Stop();
        //Timer_WriteCounter(255);    
        state=RED;
        }
        break;
        case RED:
        if( UART_ReadRxStatus()==UART_RX_STS_FIFO_NOTEMPTY){
        reset_timer();
        //Timer_Stop();
        //Timer_WriteCounter(255);     
        state=GREEN;
        }
        break;
        case GREEN:
        if( UART_ReadRxStatus()==UART_RX_STS_FIFO_NOTEMPTY){
        reset_timer();
        //Timer_Stop();
        //Timer_WriteCounter(255);       
        state=BLUE;
        }
        break;
        case BLUE:
        if( UART_ReadRxStatus()==UART_RX_STS_FIFO_NOTEMPTY){
        reset_timer();
        //Timer_Stop();
        //Timer_WriteCounter(255);      
        state=TAIL;
        }
        break;
        
        default: 
        break;
        
    }
}
/* [] END OF FILE */
