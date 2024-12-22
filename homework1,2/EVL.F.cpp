#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    printf("ÇëÊäÈëÒ»¸ö×Ö·û´®(EBLA)£º\n");
    scanf("%s", &str);  
    int len = strlen(str); 
    for (int i = 0; i < len; i++) {
        char a = str[i]; 	
		if (a=='E')
		{	
			printf("*****\n");
			printf("*\n");
			printf("*\n");
			printf("*****\n");
			printf("*\n");
			printf("*\n");
			printf("*****\n");
		}
		if (a=='B')
		{
			printf("**** \n");
			printf("*   *\n");
			printf("*   *\n");
			printf("**** \n");
			printf("*    *\n");
			printf("*    *\n");
			printf("***** \n");
		}
		if (a=='L')
		{
			printf("*\n");
			printf("*\n");
			printf("*\n");
			printf("*\n");
			printf("*\n");
			printf("*\n");
			printf("*****\n");
		}
		if (a=='A'){
			    printf("   *   \n");
   				printf("  * *  \n");
    			printf(" *   * \n");
    			printf("*******\n");
    			printf("*     *\n");
    			printf("*     *\n");
    			printf("*     *\n");
		}
		printf("\n");
}
}
