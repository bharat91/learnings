#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int isPalind(char* s)
    {
    int len = strlen(s);
    int i,j,fl=1;
    
    i=0;
    j=len-1;
    
    while(i<=j)
        {
        if(s[i] == s[j])
            {
            i++;
            j--;
        }
        else
	{
            fl = 0;
	    break;
        }   
    }
    return fl;
    
}


int diff(char x,char y)
    {    
	return abs(y-x);
}


int palind(char* str)
    {
    
    int i,j,len,cnt=0;
    
       
    
    if(!isPalind(str))
        {
        len = strlen(str);
        j = len-1;
        i=0;
	        

        while(i <= j)
            {
            if(str[i]!=str[j])                
		cnt += diff(str[i],str[j]);		            
	    i++;
            j--;
        }
        
        return cnt;
    }
    else
        return 0;
}


int main() {

    int noOfCases,i;
    char **buff;
    
    scanf("%d",&noOfCases);
    
    buff = (char**)malloc(sizeof(char*)*noOfCases);
    for(i=0;i<noOfCases;i++)
        {
        buff[i] = (char*)malloc(10000);
    }
    
    for(i=0;i<noOfCases;i++)
        {
        scanf("%s",buff[i]);
    }
    
    for(i=0;i<noOfCases;i++)
        {
        printf("%d\n",palind(buff[i]));
    }
    
    
    return 0;
}

