#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 定义控制台窗口的宽度和高度
#define WIDTH 80
#define HEIGHT 20

// 定义代码雨可用的字符集，模拟更丰富的代码样式
const char code_chars[] = "0123456789ABCDEF";

int main() {
    // 二维数组存储代码雨字符
    char matrix[HEIGHT][WIDTH];
    // 二维数组存储每个字符的下落进度（这里用0到9模拟，0表示可以下落，越大表示离下次下落越远）
    int progress[HEIGHT][WIDTH];

    srand((unsigned int)time(NULL));

    // 初始化矩阵和下落进度数组，填充空格并随机初始化下落进度
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            matrix[i][j] =' ';
            progress[i][j] = rand() % 10;
        }
    }

    // 定义并获取程序开始时的时钟滴答数
    clock_t start_time = clock();
    // 设置程序运行的总时长，这里设置为10秒（可根据需要调整）
    const double total_duration = 10.0;
    double elapsed_time = 0.0;

    while (1) {
        // 控制代码雨字符下落
        for (int i = HEIGHT - 1; i > 0; i--) {
            for (int j = 0; j < WIDTH; j++) {
                if (progress[i][j] == 0) {
                    matrix[i][j] = matrix[i - 1][j];
                    progress[i][j] = rand() % 5 + 1;  // 重新随机设置下次下落进度，范围1-5
                } else {
                    progress[i][j]--;
                }
            }
        }

        // 处理最上面一行，随机生成新字符并设置下落进度
        for (int j = 0; j < WIDTH; j++) {
            if (rand() % 10 < 3) {  // 30%概率生成新字符
                matrix[0][j] = code_chars[rand() % (sizeof(code_chars) - 1)];
                progress[0][j] = rand() % 5 + 1;
            } else {
                matrix[0][j] =' ';
            }
        }

        // 模拟清屏效果，通过循环输出退格字符来覆盖之前的内容
        for (int i = 0; i < WIDTH * HEIGHT; i++) {
            printf("\b");
        }

        // 输出当前代码雨状态到控制台
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                printf("%c", matrix[i][j]);
            }
            printf("\n");
        }

        // 使用clock函数获取当前时钟滴答数，更新已运行时长
        clock_t current_time = clock();
        elapsed_time = (double)(current_time - start_time) / CLOCKS_PER_SEC;
        if (elapsed_time >= total_duration) {
            break;
        }

        // 使用clock函数获取当前时钟滴答数，计算与开始时间的差值来实现延时
        current_time = clock();
        double delay_time = (double)(current_time - start_time) / CLOCKS_PER_SEC;
        if (delay_time < 0.08) {  // 控制下落速度，这里大约相当于80毫秒，可根据需要调整
            continue;
        }
        start_time = current_time;
    }

    return 0;
}
