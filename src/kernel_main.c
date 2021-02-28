#include<stdio.h>
#include"list.h"
#include"gpio.h"
#include "rprintf.h"
#include "serial.h"

extern long __bss_start;
extern long __bss_end;

int global;

void clear_bss() {
	int x=0;
	while ((&__bss_start)+x != &__bss_end) {
		(&__bss_start)[x]=0;
		x++;
	}
}


void kernel_main() {
//	led_init();
//	clear_bss();
/*    	while(1){
		led_on();
		delay(1);
		led_off();
		delay(1);
*/

	esp_printf(putc, "memory location: %d\r\n", kernel_main);
	}
}

