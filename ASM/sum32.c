#include <immintrin.h>
#include <stdio.h>

float a = 15.33;
float b = 100.53;
float c= 0.0;
float summ_float ()
{
    asm volatile(
    "subl $0x10, %%esp\n\t"

     "flds (%0)\n\t"
     "flds (%1)\n\t"
     "faddp \n\t"
    "fstps (%%esp)\n\t"
    "vmovapd (%%esp), %%xmm0\n\t"
    "movq %%xmm0,(%2)\n\t"
        "addl $0x10, %%esp\n\t"
    ::
    "D"(&a), "S"(&b), "a"(&c)
    :
    "%edx"
    );
}

int main(void)
{
    summ_float(&a, &b, &c);
    printf("%.2f\n", c);


    return 0;
}