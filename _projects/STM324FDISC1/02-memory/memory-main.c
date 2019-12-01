#include <stdint.h>

#define BASE_ADDR_OF_FLASH 0x0800038E
#define BASE_ADDR_OF_SRAM 0x20000000

// This will be stored at the start of Flash memory - 0x0800038E
const char flash[] = "Constant data is stored in Flash memory.";	// read-only
// This will be stored at the start of RAM memory - 0x20000000
char ram[] = "Global data is stored in RAM memory.";

int global_value = 0;

// Read the base byte (0x20000000) of RAM from the board.
int read_ram_first_byte(void) {
	// Set this to a value using the memory view.
	uint32_t *ram_ptr = (uint32_t*) 0x20000000;
	// Make this volatile so it is not compiled out! You can then see it in the debugger.
	volatile int value = *ram_ptr;
	global_value = *ram_ptr;
	return *ram_ptr;
}

// Debug here and check with 'watch' and 'memory' views.
void access_data(void) {
	char start_flash = flash[0];
	char start_ram = ram[0];
}

int main(void) {
	read_ram_first_byte();
	access_data();
	
	// Copy the 'flash[]' (Flash memory buffer) to the RAM memory after 'ram[]'. 
	int offset = sizeof(ram);
	for (int i = 0; i < sizeof(flash); i++) {
		// Copy the byte by byte - the value of flash[i] to the specified address in RAM.
		*((uint8_t*) BASE_ADDR_OF_SRAM + offset + i) = flash[i];
	}
}
