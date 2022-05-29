#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

typedef unsigned char uchar;

void LED_OnOff(unsigned int time);


void Init_IOPort(void)
{
    DDRB = 0xff;    //11111111 모든 포트 출력
    DDRD = 0x00;    //00000000 모두 입력
}

void main(void)
{   
    uchar* contSwap;    
    Init_IOPort(); 
    do
    {
        if(PIND != 0xFF)
            *contSwap = PIND;
        
        switch (*contSwap)
        {
            case 0xFE:  //0b11111110
                LED_OnOff(100);
                break;
            
            case 0xFD:  //0b11111101
                LED_OnOff(110);
                break;
            
            case 0xFB:  //0b11111011
                LED_OnOff(120);
                break;
            
            case 0xF7:  //0b11110111
                LED_OnOff(130);
                break;

            case 0xEF:  //0b11101111
                LED_OnOff(140);
                break;
            
            case 0xDF:  //0b11011111
                LED_OnOff(150);
                break;
            
            case 0xBF:  //0b10111111
                LED_OnOff(160);
                break;
            
            case 0x7F: //0b01111111
                LED_OnOff(170);
                break;
            
            default:
                break;
          }   
    } while (1);  
}


void LED_OnOff(unsigned int time)
{
    PORTB = 0x00;
    _delay_ms(time);;
    PORTB = 0xFF;
    _delay_ms(time);;
}


        


