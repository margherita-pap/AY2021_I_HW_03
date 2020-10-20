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
*\file TIMER_InterruptRoutines.c
*\This interrupt is executed each time the timer counts 5 sec, if this ISR is executed
  i have to go back to IDLE state and i send an error massage. 
*\date: October 20, 2020
*\author: Margherita Pappolla
*/
#include "TIMER_InterruptRoutine.h"
extern uint8_t state;

void reset_timer(void){
    Timer_Stop();
    Timer_WriteCounter(255);
}
    

void back_to_idle(void){
    UART_PutString("5 sec time out error!\r\n");
    UART_ClearRxBuffer();
    state=IDLE;
    Timer_ReadStatusRegister();
    reset_timer();    
}
    

CY_ISR(Custom_TIMER_5SEC_ISR){
    
    if(state==HEADER){
        back_to_idle();
      }
    if(state==RED){
        back_to_idle();
    }
    if(state==GREEN){
        back_to_idle();
     }
    if(state==BLUE){
        back_to_idle();
    }
}

/* [] END OF FILE */
