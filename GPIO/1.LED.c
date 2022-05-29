#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

typedef unsigned char uchar;
void main(void)
{
    uchar LED = 0xFE;
    DDRB = 0xff;        // B포트를 전부 출력으로        0b11111111
    PORTB = 0xFF;       // 모든 LED를 OFF로 초기화      0b11111111
    while(1)
    {          
        PORTB = LED;
        LED = ~(~LED << 1);
        if(LED == 0xFF)
            LED = 0xFE;
        _delay_ms(500);
    }    
}