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
#include "UART.h"
#include "stdio.h"
//static char message[20] = {'\0'};
extern uint8_t state;
extern char packet[5];

CY_ISR(Custom_UART_RX_ISR) {
    //if (UART_ReadRxStatus() == UART_RX_STS_FIFO_NOTEMPTY) {
    //sprintf(message, "Received: %c\r\n", UART_ReadRxData());
    //UART_PutString(message);
    switch(state)
    {
        case IDLE:
        if( UART_ReadRxStatus()==UART_RX_STS_FIFO_NOTEMPTY){
        UART_PutString("Sono nella interrupt\r\n");    
        state=HEADER;
        }
        break;
        
    
        case HEADER:
        if( UART_ReadRxStatus()==UART_RX_STS_FIFO_NOTEMPTY){
        Timer_Stop();
        Timer_WriteCounter(255);    
        UART_PutString("Sono nella interrupt UART RED\r\n");    
        state=RED;
        }
        break;
        case RED:
        if( UART_ReadRxStatus()==UART_RX_STS_FIFO_NOTEMPTY){
        Timer_Stop();
        Timer_WriteCounter(255); 
        UART_PutString("Sono nella interrupt UART GREEN\r\n");    
        state=GREEN;
        }
        break;
        case GREEN:
        if( UART_ReadRxStatus()==UART_RX_STS_FIFO_NOTEMPTY){
        Timer_Stop();
        Timer_WriteCounter(255);     
        UART_PutString("Sono nella interrupt UART BLUE\r\n");    
        state=BLUE;
        }
        break;
        case BLUE:
        if( UART_ReadRxStatus()==UART_RX_STS_FIFO_NOTEMPTY){
        Timer_Stop();
        Timer_WriteCounter(255);     
        UART_PutString("Sono nella interrupt UART TAIL\r\n");    
        state=TAIL;
        }
        break;
        
        default: 
        break;
        
    }
}
/* [] END OF FILE */