#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printSubset(int x[],int sz)
{
	int index;
	for(index = 0;index < sz;index++)
		printf("%d ",x[index]);
	printf("\n");
}

void findSubset(int a[],int n)
{
		int index=0;
		static int *subset;
		
		subset = (int*)malloc(sizeof(int)*(pow(2,n) - 1));
		
		if(n == 1)
			return a[index];
		if(
		else
		{
			findSubset(a+1,n-1);
			subset[index++] = a[index];
		}
		
		printSubset(subset,(pow(2,n) - 1));
}



int main()
{
    int noOfTestCases;
    int index,index1;
    int **array;
    int *noOfElements;
    
    scanf("%d",&noOfTestCases);
    
    array = (int**)malloc(sizeof(int*)*noOfTestCases);
    noOfElements = (int*)malloc(sizeof(int)*noOfTestCases);
    
    for(index = 0; index<noOfTestCases ;index++)
    {
    	scanf("%d",&noOfElements[index]);
    	array[index] = (int*)malloc(sizeof(int)*noOfElements[index]);
    	for(index1 = 0; index1 < noOfElements[index]; index1++)
    	{
    		scanf("%d",&array[index][index1]);
    	}
    	findSubset(array[index],noOfElements[index]);
    }
    
    return 0;
}

