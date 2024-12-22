#include<stdio.h>
int main()
{
	char a;
	printf("Which type do you want to check?\n");
	scanf("%c",&a);
	if (a=="int")	
	{
		printf("The size of %c is 4 bytes",a);
	}
	else if (a=="char")
	{
		printf("The size of %c is 1 bytes",a);	
	}
	else
	{
		printf("The size of %c is 4 bytes",a);		
	}
	printf("%d\n",a); 
	printf("%c\n",a); 
	return 0;
}
