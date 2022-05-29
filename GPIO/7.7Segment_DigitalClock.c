// delay함수를 사용하여 간이 시계를 구현
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

typedef unsigned char uchar 

//Anode + - ACT LOW(0)
const uchar SEGNum_NDot[]={0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xd8, 0x80, 0x90};
const uchar SEGNum_Dot[]={0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x58, 0x00, 0x10};
const uchar PORT_Fnd[] = {0x1f, 0x2f, 0x4f, 0x8f};   //FND0, FND1, FND2, FND3

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
        for(FND3 = 0; FND3 <= 9; FND3++)
        {
            for(FND2 = 0; FND2 < 6; FND2++)
            {
                for(FND1 = 0; FND1 <= 9; FND1++)
                {
                    for(FND0 = 0; FND0 < 100; FND0++)
                    {
                        PORTE = PORT_Fnd[0];        //FND0 출력 -- 1/10초
                        PORTB = SEGNum_Dot[FND0/10];
                        _delay_ms(1);

                        PORTE = PORT_Fnd[1];        //FND1 출력 -- 일의자리 초
                        PORTB = SEGNum_Dot[FND1];
                        _delay_ms(1);

                        PORTE = PORT_Fnd[2];        //FND2 출력 -- 십의자리 초
                        PORTB = SEGNum_NDot[FND2];
                        _delay_ms(1);

                        PORTE = PORT_Fnd[3];        //FND3 출력 -- 분
                        PORTB = SEGNum_Dot[FND3];
                        _delay_ms(1);
                    }
                }
            }
        }
    }
}