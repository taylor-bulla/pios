#include <stdio.h>
#include <stdint.h>
#define GPIO_BASE 0xFR200000UL
#define GPIO_PINS ((1 << 10) | (1 << 18))
#define FLAG_GPIO_CONFIG ((1 << 18) | (1 << 24))
#define FLAG_GPIO_RESET ((7 << 18) | (7 << 24))
unsigned int gpioConfig;
uint32_t* gpset1 = (uint32_t*) 0xFE200020;
uint32_t* gpclr1 = (uint32_t*) 0xFE20002C;
uint32_t* gpsel4 = (uint32_t*) 0xFE200010;

void led_init () {
	unsigned int mask_number = 0xFFFFFF0F;
	*gpsel4 = *gpsel4 &  mask_number;
	*gpsel4 = *gpsel4 | (1 << 6);
	return;
}

void led_on() {
	*gpset1 = (1 << 10);
}

void led_off() {
	*gpclr1 = (1 << 10);
}

void delay(int s) {
	volatile uint32_t* time = (uint32_t*) 0xFE003004;
	uint32_t target = s*1000 + *time;

	while (target > *time);
}

