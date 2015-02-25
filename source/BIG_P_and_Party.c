#include <stdio.h>
#include <stdlib.h>

#define INF -1

int min(int a,int b)
{
	return (a<b)?a:b;
}

void luckiness(int **arr,long long int x,long long int y)
{
	int *luck;
	int num=0,index;
	
	luck = (int*)malloc(sizeof(int)*x);
	luck[0] = 0;
	for(index = 1;index < x;index++)
		luck[index] = INF;
	
	
	for(index = 0;index<y;index++)
	{
		
		if(arr[index][0] == 0)
		{
			num = arr[index][1];
			luck[num] = 1;
		}
		else if(arr[index][1] == 1)
		{
			num = arr[index][0];
			luck[num] = 1;
		}
		
		
		else
		{
			if(luck[arr[index][0]] != INF && luck[arr[index][1]] == INF)
				luck[arr[index][1]] = luck[arr[index][0]] + 1;
			else if(luck[arr[index][1]] != INF && luck[arr[index][0]] == INF)
				luck[arr[index][0]] = luck[arr[index][1]] + 1;
		}
		
	}
	
	for(index = 1;index<x;index++)
		printf("%d\n",luck[index]);
}


int main()
{
    long long int A,B;
    int index,index1;
    int **array;
    
    scanf("%llu %llu",&A,&B);
    
    array = (int**)malloc(sizeof(int*)*B);
    
    for(index=0;index<B;index++)
    	array[index] = (int*)malloc(sizeof(int)*2);
    
    for(index = 0;index < B;index++)
    {
    	for(index1 = 0;index1 < 2;index1++)
    	{
    		scanf("%d",&array[index][index1]);
    	}
    }
  	
  	luckiness(array,A,B);
    
    
    
    return 0;
}

