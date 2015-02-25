#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int isPerfectSquare(long long int x)
    {
    long long int p = sqrt(x);
    if(p*p==x)
        return 1;
    else
        return 0;
}



int isFibo(long long int num)
    {
    if(isPerfectSquare(5*num*num + 4) || isPerfectSquare(5*num*num - 4))
        {
        return 1;
    }
    else
        return 0;
}

int main() {

    int noOfCases,i;
    long long int *arr;
    scanf("%d",&noOfCases);
    
    arr = (long long int*)malloc(sizeof(long long int)*noOfCases);
    for(i=0;i<noOfCases;i++)
        {
        scanf("%lld",&arr[i]);
    }
    
    for(i=0;i<noOfCases;i++)
        {
        if(isFibo(arr[i]))
            printf("IsFibo\n");
        else
            printf("IsNotFibo\n");
    }
    
    return 0;
}

