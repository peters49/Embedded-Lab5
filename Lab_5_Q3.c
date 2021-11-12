// Code for question 3

#include "msp430G2553.h"
void main(void)
{
 WDTCTL = WDTPW + WDTHOLD;  // Stop WDT

 P1DIR |= BIT6;             // P1.6 to output
 TA0CTL = TASSEL_2 + MC_1 + ID_3 + TACLR; // SMCLK, up mode, clock divider, clock divider reset

 TA0CCR0 = 31250 - 1; // Set maximum count value (PWM Period)
 TA0CCR1 = 6250 - 1; // 20% of TACCR0 for 20% duty cycle

 TA0CCTL0 |= CCIE; // interrupt enabled for TA0CCTL0
 TA0CCTL1 |= CCIE; // interrupt enabled for TA0CCTL1

 TA0CCTL0 &=~CCIFG; // interrupt flag cleared for TA0CCTL0
 TA0CCTL1 &=~CCIFG; // interrupt flag cleared for TA0CCTL1

 _enable_interrupts(); // interrupts are enabled
}
#pragma vector = TIMER0_A0_VECTOR       //define the interrupt service vector
__interrupt void TA0_ISR (void)    // interrupt service routine
    {
    P1OUT |=BIT6; // toggles LED
    TA0CCTL0 &=~CCIFG; // interrupt flag cleared for TA0CCTL0
    }

#pragma vector = TIMER0_A1_VECTOR       //define the interrupt service vector
__interrupt void TA1_ISR (void)    // interrupt service routine
    {
    P1OUT &=~BIT6; // toggles LED
    TA0CCTL1 &=~CCIFG; // interrupt flag cleared for TA0CCTL1

    }
