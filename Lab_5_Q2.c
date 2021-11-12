// Code for question 2

#include "msp430G2553.h"

void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;  // Stop WDT
     P1DIR |= BIT6;             // P1.6 set for output
     P1OUT = 0x00;              // starts LED turned off
     P1SEL |= BIT6;             // select TA0.1 output signal
     TACCR0 = 62500-1;             // maximum count value
     TACCTL1 = OUTMOD_7;          // reset/set mode 7 for output signal
     TACCR1 = 6250-1;                // PWM Duty cycle is 10%
     TACTL = TASSEL_2 + ID_3 + MC_1;   // SMCLK and Up Mode and clock divider


     while(1){


         P1OUT ^= BIT6; // causes the LED to blink with the 256ms delay
     }

}
