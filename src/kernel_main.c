//#include<stdio.h>
#include"list.h"
//#include"gpio.h"
#include "rprintf.h"
#include "serial.h"
//#include "page.h"
#include "fat.h"
#include "sd.h"

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

/*	init_pfa_list();
	struct ppage* test = free_list->next;
	esp_printf(putc, "Physcial address:  %x \n", test->physical_addr);
	test = allocate_physical_pages(2);
	esp_printf(putc, "ppages -->  %x \n", test);
	esp_printf(putc, "ppages -->  %x \n", test->physical_addr);
	free_physical_pages(test);
	test = free_list->next;
	esp_printf(putc, "Freed:  %x \n", test->physical_addr);
*/
//	return_zero();
//	mmu_on();

	struct file fat_test;
	esp_printf(putc, "test");
	sd_init();
	fat_init();
	fat_open(&fat_test, "TEST");

	while(1){


//	esp_printf(putc, "memory location: %d\r\n", kernel_main);
	}
}

//unsigned long get_count() {
//	unsigned long *timer_count_register = 0x3f003004;
//	return *timer_count_register;
//}
