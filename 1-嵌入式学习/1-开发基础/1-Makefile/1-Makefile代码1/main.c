#include<stdio.h>
#include "input.h"
#include "calcu.h"

int main()
{
	int a, b, num;
	
	input_int(&a, &b);
	num = calcu(a, b);
	printf("%d + %d = %d\n",a,b,num);

	return 0;

}
