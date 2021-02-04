#include<stdio.h>

extern long __bss_start;
extern long __bss_end;

void clear_bss() {
	int x=0;
	while ((&__bss_start)+x != &__bss_end) {
		(&__bss_start)[x]=0;
		x++;
	}
}


void kernel_main() {

    while(1){
    }
}
