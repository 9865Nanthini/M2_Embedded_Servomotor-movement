
#define  F_CPU 1000000UL


#include "user_utils.h"

int main(void)
{
    DDRB |= 0xFF;

    ICR1 = 19999;
    TCCR1A |= 1<<WGM11 | 1<<COM1A1 | 1<<COM1A0 | 1<<COM1B1 | 1<<COM1B0;
    TCCR1B |= 1<<WGM13 | 1<<WGM12 | 1<<CS10; //Prescaler=1,inverted, fast PWM,Mode 14
    
    while(1)
    {
        for( int i=1000; i<=2000; i+=100 )
        {
            OCR1A = ICR1 - i;
            OCR1B = ICR1 - i;
            _delay_ms(100);
        }
    }
}
