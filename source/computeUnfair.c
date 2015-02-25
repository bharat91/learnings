#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100000
#define MAX_VAL 1000000001

long int *candies;

int diff(long int *x, int sz)
    {
    long int max = x[0]; 
    long int min = x[0];
    int i;
    
    for(i=0;i<sz;i++)
        {
        if(x[i] > max)
            max = x[i];
    }
    
    printf("max %ld\n",max);
    for(i=0;i<sz;i++)
        {
        if(x[i] < min)
            min = x[i];
    }
    printf("min %ld\n",min);
    return (max - min);
    
    
}




int computeUnfair(long int *arr, long int n, long int k)
    {
    int i,index,res;
    long int kay = 0;
    int flag = 0;
    long int min, max, *b;
    
    b=(long int*)malloc(sizeof(long int)*k);
    
    while(kay<k)
        {
        if(flag == 0)
            {
                min = arr[0];
                for(i=0;i<n;i++)
                    {
                        if(arr[i] < min)
                            {
                            min = arr[i];
                            index = i;
                        }
                             
        
                }
            flag = 1;
            b[kay] = min;
            kay++;
        }
        
        else if(flag == 1)
            {
            min = MAX_VAL;
            arr[index] = MAX_VAL;
            
            for(i=0;i<n;i++)
                    {
                        if(abs(arr[i]-b[kay-1]) < min)
                            {
                            min = arr[i];
                            index = i;
                        }
                }
            
            b[kay] = min;
            kay++;
            
        }
        
           
    }

    res = diff(b,k);
    return res;
   
}

 
int main() {
    
    long int N,K;
    int i;
    
    scanf("%ld %ld",&N,&K);
    candies = (long int*)malloc(sizeof(long int)*N);
    for(i = 0;i < N;i++)
        scanf("%ld",&candies[i]);
  
    int unfairness = computeUnfair(candies,N,K);
        
    printf("%d",unfairness);
    return 0;
}

