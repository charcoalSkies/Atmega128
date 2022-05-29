#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

//Cathode - + ACT HIGH(1)
// 3f     00111111  0
// 06     00000110  1
// 5b     01011011  2
// 4f     01001111  3
// 66     01100110  4
// 6d     01101101  5       
// 7d     01111101  6
// 27     00100111  7
// 7f     01111111  8
// 6f     01101111  9
// 77     01110111  A
// 7c     01111100  B
// 39     00111001  C
// 5e     01011110  D
// 79     01111001  E
// 71     01110001  F


// ~Cathode
//Anode + - ACT LOW(0)
// c0   11000000 0
// f9   11111001 1
// a4   10100100 2
// b0   ...   
// 99   ...
// 92   ...

typedef unsigned char uchar;
typedef unsigned int uint; 

        

uchar SEGNum_char_CA_U4[]={0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x90};
void Init_IOPort(void)
{
    DDRB = 0xFF;
    DDRE = 0xFF;
}

void main()
{
    uchar i = 0;
    uchar j = 0;
    Init_IOPort();
    while(1)
    {
        SEGNum_char_CA_U4[i];
        PORTE = 0xFF;
        if(i > 9){ i = 0; j++; }    
        PORTE = SEGNum_char_CA_U4[j];   
        i++;
        _delay_ms(100);
    }
}

// for(i = 0; i < 16; i++)
// {
//     PORTA = SEGNum_char_CC[i];
//     PORTB = ~SEGNum_char_CC[i];
//     _delay_ms(500);
// }


