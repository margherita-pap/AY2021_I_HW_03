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
    CyGlobalIntEnable; /* Enable global interrupts. */
    UART_Start();
    isr_UART_StartEx(Custom_UART_RX_ISR);
    isr_TIMER_StartEx(Custom_TIMER_5SEC_ISR);
    RGBLed_Start();
    //UART_PutString("Please send Header byte!\r\n");
    state=0;

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        if(state== IDLE){
           /* int i=0;
            for(i=0; i<5;i++ ){
                packet[i]='0';
            }*/
            //Timer_Stop();
            
            UART_PutString("Please send Header byte!\r\n"); 
            while(state==IDLE);
          }
        if(state==HEADER){
            //UART_PutString("Sono nel main-header\r\n");
            //char message[20]={'\0'};
            packet[0]=UART_ReadRxData();
            if(packet[0]== 0xA0){
            //sprintf( message,"Received: %X !\r\n",packet[0]);
            //UART_PutString(message);
            Timer_Start();
            }
            else if(packet[0]=='v'){
                UART_PutString("RGB LED Program $$$");
                UART_ClearRxBuffer();
                state=IDLE;
                packet[0]='\0';
            }
            else{
                UART_PutString("Haeder sbagliato\r\n");
                UART_ClearRxBuffer();
                state=IDLE;
            }
            
            while(state==HEADER);
        }
        if(state==RED){
            
            //UART_PutString("SEND RED BYTE\r\n");
            //char message[20]={'\0'};
            packet[1]=UART_ReadRxData();
            //sprintf( message,"Received: %X !\r\n",packet[1]);
            //UART_PutString(message);
            Timer_Start();
            while(state==RED);
        }
        if(state== GREEN){
            
            //UART_PutString("SEND GREEN BYTE \r\n");
            //char message[20]={'\0'};
            packet[2]=UART_ReadRxData();
            //sprintf( message,"Received: %X !\r\n",packet[2]);
            //UART_PutString(message);
            Timer_Start();
            while(state==GREEN);
        }
            
        
        if(state==BLUE){
            
            //UART_PutString("SEND BLUE BYTE\r\n");
            //char message[20]={'\0'};
            packet[3]=UART_ReadRxData();
            //sprintf( message,"Received: %X !\r\n",packet[3]);
            //UART_PutString(message);
            Timer_Start();
            while(state==BLUE);
            }
        
        if(state==TAIL){
           //UART_PutString("SEND TAIL BYTE\r\n");
           //char message[20]={'\0'};
           packet[4]=UART_ReadRxData();
           //sprintf( message,"Received: %X !\r\n",packet[4]);
           //UART_PutString(message);
           if(packet[4]==0xC0){   
            //UART_PutString("PAcchetto inviato\r\n");
            Color newcolor;
            newcolor.red= (uint8_t)packet[1];
            newcolor.green=(uint8_t) packet[2];
            newcolor.blu=(uint8_t) packet[3];
            RGBLed_WriteColor(newcolor);
            state=IDLE;
            }
            else{
                UART_PutString("TAIL SBAGLIATA\r\n");
                UART_ClearRxBuffer();
                state=IDLE;
            }
        }
        
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
