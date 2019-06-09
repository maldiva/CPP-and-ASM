#include <immintrin.h>
#include <stdio.h>

float a = 10.33;
float b = 11.76;

float summ_float ()
{
    asm volatile(
    "subq $0x10, %%rsp\n\t"
    "xorq %%rax, %%rax\n\t"

    "flds (%0)\n\t"
    "flds (%1)\n\t"
    "faddp \n\t"

    "fstps (%%rsp)\n\t"
    "vmovapd (%%rsp), %%xmm0\n\t"
    "addq $0x10, %%rsp\n\t"
    ::
    "D"(&a), "S"(&b)
    :
    "%rax"
    );
}

int main(void)
{
    printf("%.2f\n", summ_float(&a, &b));

  
    return 0;
}