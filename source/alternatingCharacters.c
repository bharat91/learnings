#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int removeDuplicates(char* str)
    {
    int i,j,cnt=0;
    
    for(i=0;i<strlen(str);i++)
        {
        if(str[i]==str[i+1])
            cnt++;
    }
    
    return cnt;
}




int main() {
    
    int noOfCases,i;
    char **buff;
    
    scanf("%d",&noOfCases);
    
    buff = (char**)malloc(sizeof(char*)*noOfCases);
    for(i=0;i<noOfCases;i++)
        {
        buff[i] = (char*)malloc(100000);
    }
    
    for(i=0;i<noOfCases;i++)
        {
        scanf("%s",buff[i]);
    }
    
    for(i=0;i<noOfCases;i++)
        {
        printf("%d\n",removeDuplicates(buff[i]));
    }
    
    
    
    
     
    return 0;
}

