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
#include "project.h"
#include <inttypes.h>
#include "UART_InterruptRoutine.h"
#include "TIMER_InterruptRoutine.h"
#include "RGBLedDriver.h"
#include <stdio.h>

uint8_t state=0;
char packet[5]={'\0'};

int main(void)
{
    CyGlobalIntEnable; 
    UART_Start();
    isr_UART_StartEx(Custom_UART_RX_ISR);
    isr_TIMER_StartEx(Custom_TIMER_5SEC_ISR);
    RGBLed_Start();
    state=0;
    for(;;)
    {
        if(state== IDLE){
            UART_PutString("Please send new packet of data!\r\n"); 
            while(state==IDLE);
          }
        if(state==HEADER){
            packet[0]=UART_ReadRxData();
            if(packet[0]== 0xA0){
            Timer_Start();
            }
            else if(packet[0]=='v'){
                UART_PutString("RGB LED Program $$$\r\n");
                UART_ClearRxBuffer();
                state=IDLE;
                packet[0]='\0';
            }
            else{
                UART_PutString("Haeder byte wrong, packet discarded!\r\n");
                UART_ClearRxBuffer();
                state=IDLE;
            }
            
            while(state==HEADER);
        }
        if(state==RED){
            packet[1]=UART_ReadRxData();
            Timer_Start();
            while(state==RED);
        }
        if(state== GREEN){
            packet[2]=UART_ReadRxData();
            Timer_Start();
            while(state==GREEN);
        }
        if(state==BLUE){
            packet[3]=UART_ReadRxData();
            Timer_Start();
            while(state==BLUE);
            }
        if(state==TAIL){
           packet[4]=UART_ReadRxData();
           if(packet[4]==0xC0){   
            Color newcolor;
            newcolor.red= (uint8_t)packet[1];
            newcolor.green=(uint8_t) packet[2];
            newcolor.blu=(uint8_t) packet[3];
            RGBLed_WriteColor(newcolor);
            state=IDLE;
            }
            else{
                UART_PutString("Tail byte wrong, packet discarded!\r\n");
                UART_ClearRxBuffer();
                state=IDLE;
            }
        }
    }
}

/* [] END OF FILE */
