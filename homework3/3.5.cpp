#include <stdio.h>
int main() {
    int a[2][3] = { {1, 2, 3}, {4, 5, 6} };
    printf("��˳�������ά����Ԫ�أ�\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", a[i][j]);}
        }
    printf("\n");
	printf("����ַ�����ά����Ԫ�أ�\n");       
    for (int i = 0; i < 2; i++) {
    	for (int j = 0; j < 3; j++) {
            printf("%p ", &a[i][j]);
        }
    }
    printf("�Ƚϸ�Ԫ�صĵ�ַ�ĸߵͿ��Կ������ڴ�������Ĵ洢�ǰ����д�Ŷ������д�ŵ�");
}

