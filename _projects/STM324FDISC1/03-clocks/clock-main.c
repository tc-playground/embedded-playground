
#include <stdint.h>

// Example - Configure ADC (Analogue to Digital Converter) `SCAN` mode via 
// the Peripheral Control Registers (CR1)
// Configure via the corresponding RCC Register - See ST32F407 Reference Manual Section 7.3 and 13.13.


// A - Enable ADC Clock - We need to enable the clock on the ADC peripheral bus in-order to set registers.
//     1. Find where ADC peripheral is configured in the system.
//		 2. Find which bus the ADC is located on. (It is APB2)
//     3. Find the base address of the RCC subsystem from the memory map.
//     4. Find which RCC register can be used to enable the clock for the bus (enable APB2 clock).
//     5. Fin which bit must be set in-order to enable the clock.
//
//     NB: If this is no performed the ADC cannot be configured.

// Obtain the `base address` of the RCC subsystem.
#define RCC_BASE_ADDR 0x40023800UL
// Obtain the bus the ADC peripheral operates on from the reference manual - APB2
// Obtain the offset of the `APB2` bus `clock enable register` by searching for `peripheral clock enable register` for RCC_APB2ENR.
#define RCC_APB2ENR_OFFSET 0x44UL
// 3. Obtain which register bit needs to be set to enable the register clock - ADC1 .
const int APB2_CLOCK_ENABLE_BIT=8;

// Calculate the target register.
#define RCC_APB2ENR_ADDR (RCC_BASE_ADDR + RCC_APB2ENR_OFFSET)

// B - Configure ADC (Analogue to Digital Converter) `SCAN` mode
// 1. Obtain the `base address` of the ADC peripheral (on APB2 bus) from the `Memory Map` in the manual.
#define ADC1_BASE_ADDR 0x40012000UL
// 2. Obtain the `ADC CR1 register offset` from the 13.13 `DAC` section of the manual. 
#define ADC1_CR1_REG_SCAN_MODE_OFFSET 0x4UL
// 3. Obtain which register bit needs to be set to enable SCAN mode from the 13.13 `DAC` section of the manual.
const int ADC1_SCAN_MODE_BIT = 8;

// Calculate the target ADC1 control register.
#define ADC1_CR1_ADDR (ADC1_BASE_ADDR + ADC1_CR1_REG_SCAN_MODE_OFFSET)

int main(void) {
	
	// Create a pointers to the target registers.
	uint32_t *rcc_apb2enr_addr_ptr = (uint32_t*) RCC_APB2ENR_ADDR; // APB2 clock enable register.
	uint32_t *adc1_cr1_addr_ptr = (uint32_t*) ADC1_CR1_ADDR;       // ADC1 contorl register.
	
	// 1. Enabled the required APB2 clock 
	*rcc_apb2enr_addr_ptr |= (1 << APB2_CLOCK_ENABLE_BIT);
	// 2. Set the required SCAN bit to enable ADC1 SCAN mode.
	*adc1_cr1_addr_ptr |= (1 << ADC1_SCAN_MODE_BIT);

	// In debug mode we can now look at these in the System Viewer Window to check the values are set.
	//
	// 1. RCC -> APB2ENR -> ADC1EN  (Memory: 0x40023844)
	// 2. ADC1 -< CR1 -> SCAN       (Memory: 0x40012040)
	for (;;);
}
