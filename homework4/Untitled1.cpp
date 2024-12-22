#include <stdio.h>
#include <stdlib.h>

#define MAX_ROW 15
#define MAX_COL 15
#define WHITE -1
#define BLACK 1
#define BLANK 0

// 绘制棋盘
void draw_chessboardn(int row, int col, int chessboard[][MAX_COL]);
// 绘制棋子
void draw_chessman(int type, char *tableline);
// 随机算法获取棋子的坐标
int random_create_point(void);
// 人人对战
void person_person(void);
// 人机对战
void person_computer_random(void);
// 判断棋盘是否已满
int is_full(int chessboard[][MAX_COL], int row, int col);
// 判断胜负
int is_win(int chessboard[][MAX_COL], int row, int col);

int main() {
    int choice;
    // 绘制菜单
    printf("******************************\n");
    printf("******* 欢迎使用五子棋 *******\n");
    printf("***     请选择对战方式     ***\n");
    printf("*      1.人-人对战           *\n");
    printf("*      2.人-机对战(随机算法) *\n");
    printf("*      3.退出                *\n");
    printf("******************************\n");
    printf("请选择：");

    while (1) {
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            person_person();
            break;
        case 2:
            person_computer_random();
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("输入错误，请重新选择\n");
        }
    }
    return 0;
}

// 绘制棋盘
void draw_chessboardn(int row, int col, int chessboard[][MAX_COL]) {
    printf("  0 1 2 3 4 5 6 7 8 9 1011121314\n");
    for (int i = 0; i < row; i++) {
        if (i < 10) {
            printf("%d ", i);
        } else {
            printf("%d", i);
        }

        if (i == 0) {
            for (int j = 0; j < col; j++) {
                if (j == 0)
                    draw_chessman(chessboard[i][j], "┌ ");
                else if (j == 14)
                    draw_chessman(chessboard[i][j], "┐");
                else
                    draw_chessman(chessboard[i][j], "┬ ");
            }
            printf("\n");
        } else if (i == 14) {
            for (int j = 0; j < col; j++) {
                if (j == 0)
                    draw_chessman(chessboard[i][j], "└ ");
                else if (j == 14)
                    draw_chessman(chessboard[i][j], "┘ ");
                else
                    draw_chessman(chessboard[i][j], "┴ ");
            }
            printf("\n");
        } else {
            for (int j = 0; j < col; j++) {
                if (j == 0)
                    draw_chessman(chessboard[i][j], "├ ");
                else if (j == 14)
                    draw_chessman(chessboard[i][j], "┤");
                else
                    draw_chessman(chessboard[i][j], "┼ ");
            }
            printf("\n");
        }
    }
}

// 绘制棋子
void draw_chessman(int type, char *tableline) {
    if (type == WHITE)
        printf("● ");
    if (type == BLACK)
        printf("○ ");
    if (type == BLANK)
        printf("%s", tableline);
}

// 随机算法获取棋子的坐标
int random_create_point(void) {
    int point;
    point = rand() % MAX_ROW;
    return point;
}
// 人人对战
void person_person(void) {
    int chessboard[MAX_ROW][MAX_COL] = {BLANK};
    int i, j;
    char key;
    draw_chessboardn(MAX_ROW, MAX_COL, chessboard);
    for (int step = 1; step <= MAX_ROW * MAX_COL; step++) {    // 黑子先行，然后双方轮流下棋
        if (step % 2 == 1) {                                   // 当前步数为单数，黑棋落子。
            printf("请黑棋落子:");
            while (1) {
                scanf("%d %d", &i, &j);
                if (chessboard[i][j]!= BLANK) {
                    printf("该位置已有棋子，请重新输入\n");        // 棋子只能落在空白处
                    continue;
                }
                if (i >= MAX_ROW || j >= MAX_COL || i < 0 || j < 0) {
                    printf("输入超出棋盘范围，请重新输入\n");      // 棋子坐标不可超出棋盘
                    continue;
                }
                break;
            }
            chessboard[i][j] = BLACK;
            draw_chessboardn(MAX_ROW, MAX_COL, chessboard);
            if (is_win(chessboard, MAX_ROW, MAX_COL) == BLACK) {
                printf("黑棋胜");
                return;
            }
        } else if (step % 2 == 0) {                            // 当前步数为双数，则白棋落子
            printf("请白棋落子:");
            while (1) {
                scanf("%d %d", &i, &j);
                if (chessboard[i][j]!= BLANK) {
                    printf("该位置已有棋子，请重新输入\n");        // 棋子只能落在空白处
                    continue;
                }
                if (i >= MAX_ROW || j >= MAX_COL || i < 0 || j < 0) {
                    printf("输入超出棋盘范围，请重新输入\n");     // 棋子坐标不可超出棋盘
                    continue;
                }
                break;
            }
            chessboard[i][j] = WHITE;
            draw_chessboardn(MAX_ROW, MAX_COL, chessboard);
            if (is_win(chessboard, MAX_ROW, MAX_COL) == WHITE) {
                printf("白棋胜");
                return;
            }
        }
    }
    if (is_full(chessboard, MAX_ROW, MAX_COL) == 1)
        printf("棋盘已满");
}

// 判断棋盘是否已满
int is_full(int chessboard[][MAX_COL], int row, int col) {
    int ret = 1;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (chessboard[i][j] == BLANK) {        // 遍历数组，当有一个位置为空，则棋盘不满
                ret = 0;
                break;
            }
        }
    }
    return ret;
}

// 判断胜负
int is_win(int chessboard[][MAX_COL], int row, int col) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (chessboard[i][j] == BLANK)
                continue;
            if (j < col - 4)
                if (chessboard[i][j] == chessboard[i][j + 1] && chessboard[i][j] == chessboard[i][j + 2]
                    && chessboard[i][j] == chessboard[i][j + 3] && chessboard[i][j] == chessboard[i][j + 4])
                    return chessboard[i][j];
            if (i < row - 4)
                if (chessboard[i][j] == chessboard[i + 1][j] && chessboard[i][j] == chessboard[i + 2][j]
                    && chessboard[i][j] == chessboard[i + 3][j] && chessboard[i][j] == chessboard[i + 4][j])
                    return chessboard[i][j];
            if (i < row - 4 && j < col - 4)
                if (chessboard[i][j] == chessboard[i + 1][j + 1] && chessboard[i][j] == chessboard[i + 2][j + 2]
                    && chessboard[i][j] == chessboard[i + 3][j + 3] && chessboard[i][j] == chessboard[i + 4][j + 4])
                    return chessboard[i][j];
            if (i < row - 4 && j > 4)
                if (chessboard[i][j] == chessboard[i + 1][j - 1] && chessboard[i][j] == chessboard[i + 2][j - 2]
                    && chessboard[i][j] == chessboard[i + 3][j - 3] && chessboard[i][j] == chessboard[i + 4][j - 4])
                    return chessboard[i][j];
        }
    }
    return BLANK;
}

// 人机对战
void person_computer_random(void) {
    int chessboard[MAX_ROW][MAX_COL] = {BLANK};
    int i, j;
    draw_chessboardn(MAX_ROW, MAX_COL, chessboard);
    for (int step = 1; step <= MAX_ROW * MAX_COL; step++) {
        if (step % 2 == 1) {
            printf("请黑棋落子:");
            while (1) {
                scanf("%d %d", &i, &j);
                if (chessboard[i][j]!= BLANK) {
                    printf("该位置已有棋子，请重新输入\n");
                    continue;
                }
                if (i >= MAX_ROW || j >= MAX_COL || i < 0 || j < 0) {
                    printf("输入超出棋盘范围，请重新输入\n");
                    continue;
                }
                break;
            }
            chessboard[i][j] = BLACK;
            draw_chessboardn(MAX_ROW, MAX_COL, chessboard);
            if (is_win(chessboard, MAX_ROW, MAX_COL) == BLACK) {
                printf("黑棋胜");
                return;
            }
        } else if (step % 2 == 0) {
            while (1) {
                i = random_create_point();
                j = random_create_point();
                if (chessboard[i][j] == BLANK)
                    break;
            }
            chessboard[i][j] = WHITE;
            draw_chessboardn(MAX_ROW, MAX_COL, chessboard);
            if (is_win(chessboard, MAX_ROW, MAX_COL) == WHITE) {
                printf("白棋胜");
                return;
            }
        }
    }
    if (is_full(chessboard, MAX_ROW, MAX_COL) == 1)
        printf("棋盘已满");
}
                                                                                               
