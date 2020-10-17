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

#include "RGBLedDriver.h"

static void RGBLed_WriteRed(uint8_t red);       // Write new red value
static void RGBLed_WriteGreen(uint8_t green);   // Write new green value
static void RGBLed_WriteBlu(uint8_t blu);       // Write new blu value

void RGBLed_Start(void)
{
    // Start PWM Components
    PWM_RG_Start(); // Start PWM connected to red and green channels
    PWM_B_Start();  // Start PWM connected to blu channel
}

void RGBLed_Stop(void)
{
    // Stop PWM Components
    PWM_RG_Stop(); // Stop PWM connected to red and green channels
    PWM_B_Stop();  // Stop PWM connected to blu channel
}

void RGBLed_WriteColor(Color c)
{
    RGBLed_WriteRed(c.red);
    RGBLed_WriteGreen(c.green);
    RGBLed_WriteBlu(c.blu);
}

static void RGBLed_WriteRed(uint8_t red)
{
    PWM_RG_WriteCompare1(red);
    // For common anode
    // PWM_RG_WriteCompare1(255-red);
}

static void RGBLed_WriteGreen(uint8_t green)
{
    PWM_RG_WriteCompare2(green);
    // For common anode
    // PWM_RG_WriteCompare2(255-green);
}

static void RGBLed_WriteBlu(uint8_t blu)
{
    PWM_B_WriteCompare(blu);
    // For common anode
    // PWM_B_WriteCompare(255-blu);
}
/* [] END OF FILE */
