#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int height(int p)
    {
    int ht = 1;
    
    if(p==0)
        return 1;
    
    while(p>0)
        {
        if(p%2 == 0)
            ht = ht+1;
        else
            ht = 2*ht;
        
        p--;
    }
    
    
    return ht;    
}



int main() {

    int noOfCases;
    int *num,i;
    
    scanf("%d",&noOfCases);
    
    num = (int*)malloc(sizeof(int)*noOfCases);
    for(i=0;i<noOfCases;i++)
        {
        scanf("%d",&num[i]);
    }
    
    for(i=0;i<noOfCases;i++)
        {
        printf("%d\n",height(num[i]));
    }
    
    
    
    return 0;
}

