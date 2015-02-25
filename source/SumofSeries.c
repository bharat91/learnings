#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007

int *res;


int fact(int x)
{
	int f=1;
	int i;
	for(i=x-1;i>=1;i--)
	{
		f *= i;
	}
	return f;
}

float encee(int n,int r)
{
	return (float)fact(n)/(float)(fact(n-r)*fact(r));
}

int f(int p)
{
	int s = 0;
	int i;
	for(i=1;i<=p;i++)
	{
		s += (i*i)*(int)(encee(p,i))*(int)(encee(p,i));
	}
	return s%MOD;	
}

int sumOfSeries(int *numArray,int num,int cnt)
{

	int i;
	int sum = 0;
	for(i=0;i<cnt;i++)
	{
		//printf("%d\n",f(numArray[i]));		
		sum += f(numArray[i]);
	}
	return sum%MOD;

	/*int s = 0;
	for(i=1;i<=num;i++)
	{
		s += (i*i)*(int)(encee(num,i))*(int)(encee(num,i));
	}
	return s%MOD;*/
}


void findPrimes(int n,int N)
{
	int count = 0;
	static int c = 0;
	int i,j;
	int *ar;
	int fl = 1;
	int sum;
	ar = (int*)malloc(sizeof(int)*n);
	//printf("Hi");

	ar[0] = 2;

	if(n==1)
		ar[count] = 1;
	
	
	
	for(i=3;i<=n;i++)
	{
		for(j=(i-1);j>=2;j--)
		{
			if(i%j == 0)
			{
				fl = 0;
			}
				
		}
		if(fl == 1)
			ar[count++] = i;

	}
	
	//for(i=0;i<count;i++)
		printf("%d \n",ar[1]);
	
	/*for(i=0;i<count;i++)
	{
		printf("%d ",ar[i]);
	} */

	if(c<N)
		res[c++] = sumOfSeries(ar,n,count);
	
}




int main()
{
    int noOfCases;
    int *num,i;
    scanf("%d",&noOfCases);
    
    res = (int*)malloc(sizeof(int)*noOfCases);
    num = (int*)malloc(sizeof(int)*noOfCases);
    
    printf("\n");
    for(i=0;i<noOfCases;i++)
    {
    	scanf("%d",&num[i]);
    	findPrimes(num[i],noOfCases);
    }
   
  //  for(i=0;i<noOfCases;i++)
    //	printf("%d\n",res[i]);
    
    return 0;
}

