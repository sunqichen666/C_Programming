#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int check(int i, int j);
int queen(int row, int i, int j, int *total);

int num = 0;
int b[8][2] = { {-1,-1} };

// check���������ж�λ���Ƿ��������Ҫ��
int check(int row, int col) {
    for (int k = 0; k < num; k++) {
        if (b[k][0] == row || b[k][1] == col || abs(b[k][0] - row) == abs(b[k][1] - col)) {
            return 1; // ���������Ҫ��
        }
    }
    return 0; // �������Ҫ��
}

// queen����ʵ�������㷨��������ÿһ�ж�����һ���ʺ� 
int queen(int row, int i, int j, int *total) {
    if (row == 8) {
        (*total)++;
        return 0;
    }
    for (int col = 0; col < 8; col++) {
        if (!check(row, col)) {
            b[num][0] = row;
            b[num][1] = col;
            num++;
            queen(row + 1, i, j, total);
            num--; // ����
        }
    }
    return 0;
}

int main() {
    int total = 0;
    queen(0, 0, 0, &total);
    printf("%d", total);
    return 0;
}
