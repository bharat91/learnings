#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char *s;
	s = (char*)malloc(sizeof(char)*10);	
	s = "HelloWorld";
	//s[5] = 'd';
	printf("%s\n",s);
}
