#include <stdio.h>
#include <stdlib.h>
int A[1000],B[1000];
int C[2000];

int Sup(int f,int s,int n)
{
	int i,j,k;
	
	for(i=1;i<=500;i++)
    {
    	A[i] = i * f;
    }
    
    
    for(i=1;i<=500;i++)
    {
    	B[i] = i * s;
    }  
    
    i=1;
    k=1;
    for(j=0;j<2000;j++)
    {
    	if(A[i]<B[k])
	{
    		C[j] = A[i];
		i++;
		
    	}	
    	else if(A[i]==B[k])
	{
		C[j] = A[i];
		i++;
		k++;
	}
    	else if(B[k]<A[i])
	{
    		C[j] = B[k];
		k++;
	}
	
	//printf("%d ",C[j++]);
		
		
    }
    
    return C[n-1];
}


int main()
{
    int numOfCases;
    int *fnum,*snum,*N,i;
    int *res;
    int j,k;
    int b;
    
    
    scanf("%d",&numOfCases);
    
    fnum = (int*)malloc(sizeof(int)*numOfCases);
    snum = (int*)malloc(sizeof(int)*numOfCases);
    N = (int*)malloc(sizeof(int)*numOfCases);
    res = (int*)malloc(sizeof(int)*numOfCases);
    
    //memset(A,0,1000);
    //memset(B,0,1000);
    for(b=0;b<numOfCases;b++)
    {
    	scanf("%d %d %d",&fnum[b],&snum[b],&N[b]);
    	res[b] = Sup(fnum[b],snum[b],N[b]);
    }
    for(i=0;i<numOfCases;i++)
    {
    	printf("%d\n",res[i]);
    }
    
    
    return 0;
}

