#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

typedef unsigned char uchar;

void LED_LShift(uchar* LED);
void LED_Rshift(uchar* LED);
void LED_LRShift(uchar* LED);

void main(void)
{
    DDRB = 0xFF;        // B포트를 전부 출력으로        0b11111111
    PORTB = 0xFF;       // 모든 LED를 OFF으로 초기화      0b11111111
    DDRD = 0x00;        // D포트를 전부 입력으로
    PIND = 0xFF;        
    while(1)
    {
        uchar* LED = 0x00; 
        if(PIND == 0b11111110)
            LED_LRShift(LED); 
        if(PIND == 0b11111101)
            LED_Rshift(LED);
        if(PIND == 0b11111011)
            LED_LShift(LED); 
    }    
}


void LED_LShift(uchar* LED)
{
    uchar i;
    *LED = 0b11111110;
    for(i = 0; i < 8; i++)
    {
        _delay_ms(100);
        *LED = (*LED << 1) | 0b00000001;
        PORTB = *LED;
        _delay_ms(100);
    } 
}

void LED_Rshift(uchar* LED)
{
    uchar i;
    *LED = 0b01111111;
    for(i = 0; i < 8; i++)
    {
        __delay_ms(100);
        PORTB = *LED;
        *LED = (*LED >> 1) | 0b10000000;
        __delay_ms(100);
    }    
}

void LED_LRShift(uchar* LED)
{
    uchar i;   
    *LED = 0b11111110;
    for(i=0; i < 8; i++)
    {
        __delay_ms(500);
        PORTB = *LED;
        *LED = (*LED << 1) | 0b00000001;
    }                         
    *LED = 0b01111111;
    for(i = 0; i < 8; i++)
    {
        __delay_ms(500);
        PORTB = *LED;
        *LED = (*LED >> 1) | 0b10000000;
    } 
}