#include <stdint.h>
#include "uart.h"
#include "gpio.h"

#define PIN_BUTTON_A 17
#define PIN_BUTTON_B 26

#define BTN_A GPIO->PIN_CNF[PIN_BUTTON_A]
#define BTN_B GPIO->PIN_CNF[PIN_BUTTON_B]


int main(){

	while(1){


        for (int sleep = 0; sleep < 10000; sleep++);
	}
	return 0;
}
