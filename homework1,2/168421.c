#include <stdio.h>

int main() {
    int a,i,k;
    k = 0;
    char *str[]={"first", "second", "third", "forth", "fifth", "sixth","seventh", "eighth"};
    scanf("%d", &a);
    while (a!=0) {
        i = a % 2;
        printf("%s bit is %c\n", str[k], i?'1':'0');
        a = a / 2;
        k++;
    }
    k = 0;
    while (k < 8) {
        printf("%s bit is 0\n", str[k]);
        k++;
    }
    return 0;
}
