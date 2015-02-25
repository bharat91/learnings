#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int findDigits(long long int no){
    long long int j,*arr;
    int count = 0,i,dig=0;
    long long int num;
    num = no;
    while(no>0)
        {
            j = no%10;
            no = no/10;
            count++;
        }
    
    arr = (long long int*)malloc(sizeof(long long int)*count);
        
	    i=0;
	    no = num;
        while(no>0)
        {
            j = no%10;
            no = no/10;
            arr[i++]=j;  
        }

	for(i=0;i<count;i++)
		printf("%lld ",arr[i]);
	printf("\n");
    
   for(i=0;i<count;i++)
        {
          if(arr[i]!=0 && (num%arr[i]==0))
                dig++;
        }
    
    return dig;
}

int main() {
    
    int noOfCases;
    int i,num,digits;
    long long int *input;
    
    
    scanf("%d",&noOfCases);
    input = (long long int*)malloc(sizeof(long long int)*noOfCases);
    for(i=0;i<noOfCases;i++)
        {
        scanf("%lld",&input[i]);
    }
    
    for(i=0;i<noOfCases;i++)
	{
	    digits = findDigits(input[i]);
            printf("%d\n",digits);
	}    
    return 0;
}


