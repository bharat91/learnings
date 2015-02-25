#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char str[] = "hello";
	char *str1 = "hello";

	//str1[2] = 'g';
	str[2] = 'g';

	printf("%s %s\n",str,str1);
	return 0;
	
}


//Lesson Learnt: normal char arrays can be changed but when they are referenced with a pointer then they cannot
