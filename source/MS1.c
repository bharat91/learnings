#include <stdio.h>
#include <stdlib.h>

unsigned op(unsigned x,unsigned y)
{
	unsigned int t=0, l = x ^ y;
	
	while(l)
	{
		++t;
		l &= (l-1);
	}
	return t;
	
}


int main()
{
	unsigned int a = 123, b= 231;
	unsigned z = op(a,b);
	printf("%d\n",z);
	
	return 0;
}
