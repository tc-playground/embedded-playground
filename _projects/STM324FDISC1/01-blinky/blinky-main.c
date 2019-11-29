#include <stdint.h>

#include "Board_LED.h"
#include "Board_Buttons.h"

// extern int32_t LED_Initialize (void);

void delay() {
	// unsigned int i = 0;
	// uint32_t i = 0;
	for (int i = 0; i < 500000; i++);
}

void clear() {
	LED_Off(0);
	LED_Off(1);
	LED_Off(2);
	LED_Off(3);
}


void all() {
	LED_On(0);
	LED_On(1);
	LED_On(2);
	LED_On(3);
}

void blink(int n) {
	for (int i = 0; i < n; i++) {
		all();
		delay();
		clear();
		delay();
	}
}

void cycle() {
	clear();
	LED_On(0);
	delay();
	LED_Off(0);
	LED_On(1);
	delay();
	LED_Off(1);
	LED_On(2);
	delay();
	LED_Off(2);
	LED_On(3);
	delay();
	clear();
}

void spin(int n) {
	for (int i = 0; i < n; i++) {
		cycle();
	}
	LED_On(0);
	delay();
	clear();
}

void raise_hard_fault(void) {
		// Create and invoke a function pointer using and invalid address
		void (*jump_addr) (void) = 0x00000000;
		jump_addr();
}

int main(void) {
	LED_Initialize();
	Buttons_Initialize();
	// raise_hard_fault();
	int n = 5;
	while (1) {
		uint32_t isPressed = Buttons_GetState();
		if (isPressed == 1) {
			for (int i = 0; i < n; i++) {
				blink(n);
				delay();
				spin(n);
				delay();
			}
		}
	}

	return 0;
}
