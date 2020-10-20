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
#ifndef __TIMER_INTERRUPT_ROUTINE_H_
    
    #define __TIMER_INTERRUPT_ROUTINE_H_
    #include "project.h"
    #include "UART_InterruptRoutine.h"
    
    void back_to_idle(void);
    
    void reset_timer(void);
    
    CY_ISR_PROTO(Custom_TIMER_5SEC_ISR);
    
#endif
/* [] END OF FILE */
