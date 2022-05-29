#makefile

FILENAME=main
DEVICE=atmega128
F_CPU=16000000UL
COMPILE = avr-gcc -Wall -Os -DF_CPU=${F_CPU} -mmcu=${DEVICE}

default: compile clean

compile:
	${COMPILE} -c ${FILENAME}.c -o ${FILENAME}.o
	${COMPILE} -o ${FILENAME}.elf ${FILENAME}.o
	avr-objcopy -j .text -j .data -O ihex ${FILENAME}.elf ${FILENAME}.hex
	avr-size --format=avr --mcu=${DEVICE} ${FILENAME}.elf

clean:
	rm ${FILENAME}.o
	rm ${FILENAME}.elf
