#include <stdint.h>
#include "gpio.h"
#include "gpiote.h"
#include "ppi.h"

#define PIN_BUTTON_A 17
#define PIN_BUTTON_B 26

#define BTN_A GPIO->PIN_CNF[PIN_BUTTON_A]
#define BTN_B GPIO->PIN_CNF[PIN_BUTTON_B]

int main(){
	// Configure LED Matrix
	for(int i = 4; i <= 15; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
	}

	// Configure buttons
	BTN_A = 0; // A
	BTN_B = 0; // B
	
	while(1){



		for (int sleep = 0; sleep < 10000; sleep++);
	}
	return 0;
}
