#include <avr/io.h>
#include <util/delay.h>

typedef unsigned char uchar;

uchar count;

interrupt [EXT_INT0] void ext_int0_isr(void)
{
    count++;
}

void Interrupt_init(void)
{
    SREG |= 0b10000000; // Status Register - Global Interrupt Enable 

    EICRA = 0b00000010; // External Interrupt Control Register A 
    EIMSK = 0b00000001; // External Interrupt Mask Register - INT0
    
    DDRB = 0xFF;
    DDRD = 0x00;
}

void main()
{
    count = 0;
    Interrupt_init();
    while(1)
    {
        PORTB = ~count;
        delay_ms(50);
        if(count >= 255) count = 0;
    }
}