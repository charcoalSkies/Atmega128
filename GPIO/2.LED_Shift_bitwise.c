#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

void main(void)
{
    DDRB = 0xff;        // B포트를 전부 출력으로        0b11111111
    PORTB = 0x01;          
    while(1)
    {
        if(PORTB == 0x00)
            PORTB = 0x01;
        _delay_ms(500);
        PORTB <<= 1;
    }    
}