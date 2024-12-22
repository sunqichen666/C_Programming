#include <stdio.h>
int main() {
    int a[2][3] = { {1, 2, 3}, {4, 5, 6} };
    printf("按顺序输出二维数组元素：\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", a[i][j]);}
        }
    printf("\n");
	printf("按地址输出二维数组元素：\n");       
    for (int i = 0; i < 2; i++) {
    	for (int j = 0; j < 3; j++) {
            printf("%p ", &a[i][j]);
        }
    }
    printf("比较个元素的地址的高低可以看出在内存中数组的存储是按照行存放而不是列存放的");
}

