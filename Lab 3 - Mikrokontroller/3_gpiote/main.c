#include <stdint.h>
#include "gpio.h"
#include "gpiote.h"
#include "ppi.h"

#define PIN_BUTTON_A 17
#define PIN_BUTTON_B 26

int main(){
	// Configure LED Matrix
	for(int i = 4; i <= 12; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
	}
	
	GPIOTE->CONFIG[0] = (1<<0) | (PIN_BUTTON_A<<8) | (2<<16); // A = Event = 1, B = PIN_A, C = HiToLo = 2
	GPIOTE->CONFIG[1] = (3<<0) | (13<<8) | (3<<16); // A = Taskt = 3, B = PIN_13, C = Toggle = 3
	GPIOTE->CONFIG[2] = (3<<0) | (14<<8) | (3<<16); // A = Taskt = 3, B = PIN_14, C = Toggle = 3
	GPIOTE->CONFIG[3] = (3<<0) | (15<<8) | (3<<16); // A = Taskt = 3, B = PIN_15, C = Toggle = 3

	PPI->CHENSET = 0b1110;

	// Setter på PPI, slik at Btn_A er koblet opp til LED-pins 13, 14, 15
	PPI->PPI_CH[1].EEP = (uint32_t)&(GPIOTE->IN[0]);
	PPI->PPI_CH[1].TEP = (uint32_t)&(GPIOTE->OUT[1]);

	PPI->PPI_CH[2].EEP = (uint32_t)&(GPIOTE->IN[0]);
	PPI->PPI_CH[2].TEP = (uint32_t)&(GPIOTE->OUT[2]);

	PPI->PPI_CH[3].EEP = (uint32_t)&(GPIOTE->IN[0]);
	PPI->PPI_CH[3].TEP = (uint32_t)&(GPIOTE->OUT[3]);
	
	while(1){

		for (int sleep = 0; sleep < 10000; sleep++);
	}
	return 0;
}
