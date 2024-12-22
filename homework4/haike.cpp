#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// �������̨���ڵĿ�Ⱥ͸߶�
#define WIDTH 80
#define HEIGHT 20

// �����������õ��ַ�����ģ����ḻ�Ĵ�����ʽ
const char code_chars[] = "0123456789ABCDEF";

int main() {
    // ��ά����洢�������ַ�
    char matrix[HEIGHT][WIDTH];
    // ��ά����洢ÿ���ַ���������ȣ�������0��9ģ�⣬0��ʾ�������䣬Խ���ʾ���´�����ԽԶ��
    int progress[HEIGHT][WIDTH];

    srand((unsigned int)time(NULL));

    // ��ʼ�����������������飬���ո������ʼ���������
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            matrix[i][j] =' ';
            progress[i][j] = rand() % 10;
        }
    }

    // ���岢��ȡ����ʼʱ��ʱ�ӵδ���
    clock_t start_time = clock();
    // ���ó������е���ʱ������������Ϊ10�루�ɸ�����Ҫ������
    const double total_duration = 10.0;
    double elapsed_time = 0.0;

    while (1) {
        // ���ƴ������ַ�����
        for (int i = HEIGHT - 1; i > 0; i--) {
            for (int j = 0; j < WIDTH; j++) {
                if (progress[i][j] == 0) {
                    matrix[i][j] = matrix[i - 1][j];
                    progress[i][j] = rand() % 5 + 1;  // ������������´�������ȣ���Χ1-5
                } else {
                    progress[i][j]--;
                }
            }
        }

        // ����������һ�У�����������ַ��������������
        for (int j = 0; j < WIDTH; j++) {
            if (rand() % 10 < 3) {  // 30%�����������ַ�
                matrix[0][j] = code_chars[rand() % (sizeof(code_chars) - 1)];
                progress[0][j] = rand() % 5 + 1;
            } else {
                matrix[0][j] =' ';
            }
        }

        // ģ������Ч����ͨ��ѭ������˸��ַ�������֮ǰ������
        for (int i = 0; i < WIDTH * HEIGHT; i++) {
            printf("\b");
        }

        // �����ǰ������״̬������̨
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                printf("%c", matrix[i][j]);
            }
            printf("\n");
        }

        // ʹ��clock������ȡ��ǰʱ�ӵδ���������������ʱ��
        clock_t current_time = clock();
        elapsed_time = (double)(current_time - start_time) / CLOCKS_PER_SEC;
        if (elapsed_time >= total_duration) {
            break;
        }

        // ʹ��clock������ȡ��ǰʱ�ӵδ����������뿪ʼʱ��Ĳ�ֵ��ʵ����ʱ
        current_time = clock();
        double delay_time = (double)(current_time - start_time) / CLOCKS_PER_SEC;
        if (delay_time < 0.08) {  // ���������ٶȣ������Լ�൱��80���룬�ɸ�����Ҫ����
            continue;
        }
        start_time = current_time;
    }

    return 0;
}
