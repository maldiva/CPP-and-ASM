#include <immintrin.h>
#include <stdio.h>

int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int result = 0;
int chosenMonth = 1;



int daysInMonth()
{
	asm volatile(
	"subq $0x10, %%rsp\n\t"
	"movq %%rdi, %%rcx\n\t"
	"vmovq (%0,%%rcx,0x4), %%xmm0\n\t"
	"vmovq %%xmm0, (%%rsp)\n\t"
	"movq (%%rsp), %%rax\n\t"
	"addq $0x10, %%rsp\n\t"
	::
	"S"(days_in_month),"D"(chosenMonth-1), "d"(result)
	:
	"%rax","%rcx","xmm0"
	);
	
}

int main() {

	result = daysInMonth();
	printf("%d\n", result);
	return 0;
}