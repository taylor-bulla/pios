//#include<stdio.h>
#include"list.h"
//#include"gpio.h"
#include "rprintf.h"
#include "serial.h"
#include "page.h"

#define NULL (void*)0
//int *mu_io_reg = 0x3F215040;

extern long __bss_start;
extern long __bss_end;
extern struct ppage* free_list;
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
	init_pfa_list();
	while(1){


//	esp_printf(putc, "memory location: %d\r\n", kernel_main);
	}
}

