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
#include "TIMER_InterruptRoutine.h"
//#include <inttypes.h>
extern uint8_t state;
CY_ISR(Custom_TIMER_5SEC_ISR){
    //Timer_ReadStatusRegister();
    if(state==HEADER){
        //UART_PutString("Sono nella interrupt TIMER stato header");
        UART_ClearRxBuffer();
        state=IDLE;
        Timer_ReadStatusRegister();
        Timer_Stop();
        Timer_WriteCounter(255);
    }
    if(state==RED){
        //UART_PutString("Sono nella interrupt TIMER stato red");
        state=IDLE;
        Timer_ReadStatusRegister();
        Timer_Stop();
        Timer_WriteCounter(255);
    }
    if(state==GREEN){
        //UART_PutString("Sono nella interrupt TIMER stato GREEN");
        UART_ClearRxBuffer();
        state=IDLE;
        Timer_ReadStatusRegister();
        Timer_Stop();
        Timer_WriteCounter(255);
    }
    if(state==BLUE){
        //UART_PutString("Sono nella interrupt TIMER stato BLUE");
        UART_ClearRxBuffer();
        state=IDLE;
        Timer_ReadStatusRegister();
        Timer_Stop();
        Timer_WriteCounter(255);
    }
}

/* [] END OF FILE */
