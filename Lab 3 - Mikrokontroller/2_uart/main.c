#include <stdint.h>
#include <stdio.h>
#include "uart.h"
#include "gpio.h"

#define PIN_BUTTON_A 17
#define PIN_BUTTON_B 26

#define BTN_A GPIO->PIN_CNF[PIN_BUTTON_A]
#define BTN_B GPIO->PIN_CNF[PIN_BUTTON_B]


int main(){
	iprintf("The average grade in TTK%d was in %d and %d: %c\n\r",4235,2019,2018,'C');

	// Configure LED Matrix
	for(int i = 4; i <= 15; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
	}

	while(1){
		if (!(GPIO->IN & (1 << PIN_BUTTON_A))) {
			uart_send('A');
		}
		if (!(GPIO->IN & (1 << PIN_BUTTON_B))) {
			uart_send('B');
		}

		if (uart_read()) {
			for(int i = 13; i <= 15; i++) GPIO->OUT ^= (1 << i);
		}

        for (int sleep = 0; sleep < 10000; sleep++);
	}
	return 0;
}

ssize_t _write(int fd, const void *buf, size_t count){
	char * letter = (char *)(buf);
	for(int i = 0; i < count; i++){
		uart_send(*letter);
		letter++;
	}
	return count;
}
