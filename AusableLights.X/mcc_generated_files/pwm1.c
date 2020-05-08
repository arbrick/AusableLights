/**
  PWM1 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    pwm1.c

  @Summary
    This is the generated driver implementation file for the PWM1 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides implementations for driver APIs for PWM1.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.78.1
        Device            :  PIC12F1572
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.10 and above or later
        MPLAB             :  MPLAB X 5.30
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

/**
  Section: Included Files
*/

#include <xc.h>
#include "pwm1.h"

/**
  Section: PWM1 APIs
*/

void PWM1_Initialize(void)
{
    // set the PWM1 to the options selected in the User Interface

     //PHIE disabled; DCIE disabled; OFIE disabled; PRIE disabled; 
    PWM1INTE = 0x00;

     //PHIF cleared; OFIF cleared; DCIF cleared; PRIF cleared; 
    PWM1INTF = 0x00;

     //PS Divide_clock_src_by_64; CS FOSC; 
    PWM1CLKCON = 0x60;

     //LDS reserved; LDT disabled; LDA do_not_load; 
    PWM1LDCON = 0x00;

     //OFM independent_run; OFS reserved; OFO match_incrementing; 
    PWM1OFCON = 0x00;

     //PWM1PHH 0; 
    PWM1PHH = 0x00;

     //PWM1PHL 0; 
    PWM1PHL = 0x00;

     //PWM1DCH 0; 
    PWM1DCH = 0x00;

     //PWM1DCL 0; 
    PWM1DCL = 0x00;

     //PWM1PRH 0; 
    PWM1PRH = 0x00;

     //PWM1PRL 15; 
    PWM1PRL = 0x0F;

     //PWM1OFH 0; 
    PWM1OFH = 0x00;

     //PWM1OFL 1; 
    PWM1OFL = 0x01;

     //PWM1TMRH 0; 
    PWM1TMRH = 0x00;

     //PWM1TMRL 0; 
    PWM1TMRL = 0x00;

     //MODE standard_PWM; POL active_hi; OE enabled; EN enabled; 
    PWM1CON = 0xC0;

}    


void PWM1_Start(void)
{
    PWM1CONbits.EN = 1;		
}

void PWM1_Stop(void)
{
    PWM1CONbits.EN = 0;		
}

bool PWM1_CheckOutputStatus(void)
{
    return (PWM1CONbits.OUT);		
}

void PWM1_LoadBufferSet(void)
{
    PWM1LDCONbits.LDA = 1;		
}

void PWM1_PhaseSet(uint16_t phaseCount)
{
    PWM1PHH = (phaseCount>>8);        //writing 8 MSBs to PWMPHH register
    PWM1PHL = (phaseCount);           //writing 8 LSBs to PWMPHL register
}

void PWM1_DutyCycleSet(uint16_t dutyCycleCount)
{
    PWM1DCH = (dutyCycleCount>>8);	//writing 8 MSBs to PWMDCH register
    PWM1DCL = (dutyCycleCount);	//writing 8 LSBs to PWMDCL register		
}

void PWM1_PeriodSet(uint16_t periodCount)
{
    PWM1PRH = (periodCount>>8);	//writing 8 MSBs to PWMPRH register
    PWM1PRL = (periodCount);	//writing 8 LSBs to PWMPRL register		
}

void PWM1_OffsetSet(uint16_t offsetCount)
{
    PWM1OFH = (offsetCount>>8);	//writing 8 MSBs to PWMOFH register
    PWM1OFL = (offsetCount);	//writing 8 LSBs to PWMOFL register		
}

uint16_t PWM1_TimerCountGet(void)
{
    return ((uint16_t)((PWM1TMRH<<8) | PWM1TMRL));       		
}

bool PWM1_IsOffsetMatchOccured(void)
{
    return (PWM1INTFbits.OFIF);		
}

bool PWM1_IsPhaseMatchOccured(void)
{
    return (PWM1INTFbits.PHIF);	
}

bool PWM1_IsDutyCycleMatchOccured(void)
{
    return (PWM1INTFbits.DCIF);		
}

bool PWM1_IsPeriodMatchOccured(void)
{
    return (PWM1INTFbits.PRIF);		
}

/**
 End of File
*/


