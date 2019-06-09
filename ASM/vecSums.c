#include <immintrin.h>
#include <stdio.h>

float a [] = {1.0,1.0,1.0,1.0};
float b [] = {1.0,1.0,1.0,1.0};
float res[] = {0.0,0.0,0.0,0.0};



void sumVector()
{
	asm volatile(
		"vmovaps (%0), %%xmm0\n\t"
		"vmovaps (%1), %%xmm1\n\t"
		"addps %%xmm1, %%xmm0\n\t"
		
		"vmovaps %%xmm0, (%2)\n\t"
		::
		"S"(a), "D"(b), "d"(res)	
		:
		"%xmm0","%xmm1"
	);
}

int main() {

	sumVector();
	printf("%.2f, %.2f, %.2f, %.2f\n", res[0],res[1],res[2],res[3]);
	return 0;
}