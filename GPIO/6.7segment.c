#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

typedef unsigned char uchar;
typedef unsigned int uint;
//Anode + - ACT LOW(0)
                    //   0      1    2     3     4     5     6     7     8     9     A     B     C     D     E     F
uchar SEGNum_char_CA[]={0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xd8, 0x80, 0x90, 0x88, 0x83, 0xc6, 0xa1, 0x84, 0x8e};
uint PORT_Fnd[] = {0b00011111, 0b00101111, 0b01001111, 0b10001111};   //FND0, FND1, FND2, FND3

void Init_IOPort(void)
{
    DDRE = 0xf0; //PORTE.4 ~ PORTE.7 FND 출력 (PE.4 ~ PE.7 : FND0 ~ FND3)
    DDRB = 0xff; //PORTB 전부 출력
}

void main()
{
    uchar FND0, FND1, FND2, FND3;
    Init_IOPort();

    while(1)
    {
        for(FND3 = 0; FND3 < 16; FND3++)
        {
            for(FND2 = 0; FND2 < 16; FND2++)
            {
                for(FND1 = 0; FND1 < 16; FND1++)
                {
                    for(FND0 = 0; FND0 < 16; FND0++)
                    {
                        PORTE = PORT_Fnd[0];        //FND0 출력
                        PORTB = SEGNum_char_CA[FND0];
                        _delay_ms(10);

                        PORTE = PORT_Fnd[1];        //FND1 출력
                        PORTB = SEGNum_char_CA[FND1];
                        _delay_ms(10);

                        PORTE = PORT_Fnd[2];        //FND2 출력
                        PORTB = SEGNum_char_CA[FND2];
                        _delay_ms(10);

                        PORTE = PORT_Fnd[3];        //FND3 출력
                        PORTB = SEGNum_char_CA[FND3];
                        _delay_ms(10);
                    }
                }
            }
        }
    }
}