#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x[] = {-2,3,-1,4,-3,5,-2};
	int max = 0;
	int index = 0;
	
	max = x[0];	
	for(index = 0;index < sizeof(x)/sizeof(x[0]);index++)
	{
		if(x[index] + x[index+1] > max)
			max = x[index] + x[index+1];
	
		printf("Max now is: %d\n",max);
		
	}
	printf("%d\n",max);

	return 0;
}
