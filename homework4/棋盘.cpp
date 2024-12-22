#include <stdio.h>
#include <stdlib.h>

#define MAX_ROW 15
#define MAX_COL 15
#define WHITE -1
#define BLACK 1
#define BLANK 0

// ��������
void draw_chessboardn(int row, int col, int chessboard[][MAX_COL]);
// ��������
void draw_chessman(int type, char *tableline);
// ����㷨��ȡ���ӵ�����
int random_create_point(void);
// ���˶�ս
void person_person(void);
// �˻���ս
void person_computer_random(void);
// �ж������Ƿ�����
int is_full(int chessboard[][MAX_COL], int row, int col);
// �ж�ʤ��
int is_win(int chessboard[][MAX_COL], int row, int col);

int main() {
    int choice;
    // ���Ʋ˵�
    printf("******************************\n");
    printf("******* ��ӭʹ�������� *******\n");
    printf("***     ��ѡ���ս��ʽ     ***\n");
    printf("*      1.��-�˶�ս           *\n");
    printf("*      2.��-����ս(����㷨) *\n");
    printf("*      3.�˳�                *\n");
    printf("******************************\n");
    printf("��ѡ��");

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
            printf("�������������ѡ��\n");
        }
    }
    return 0;
}

// ��������
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
                    draw_chessman(chessboard[i][j], "�� ");
                else if (j == 14)
                    draw_chessman(chessboard[i][j], "��");
                else
                    draw_chessman(chessboard[i][j], "�� ");
            }
            printf("\n");
        } else if (i == 14) {
            for (int j = 0; j < col; j++) {
                if (j == 0)
                    draw_chessman(chessboard[i][j], "�� ");
                else if (j == 14)
                    draw_chessman(chessboard[i][j], "�� ");
                else
                    draw_chessman(chessboard[i][j], "�� ");
            }
            printf("\n");
        } else {
            for (int j = 0; j < col; j++) {
                if (j == 0)
                    draw_chessman(chessboard[i][j], "�� ");
                else if (j == 14)
                    draw_chessman(chessboard[i][j], "��");
                else
                    draw_chessman(chessboard[i][j], "�� ");
            }
            printf("\n");
        }
    }
}

// ��������
void draw_chessman(int type, char *tableline) {
    if (type == WHITE)
        printf("�� ");
    if (type == BLACK)
        printf("�� ");
    if (type == BLANK)
        printf("%s", tableline);
}

// ����㷨��ȡ���ӵ�����
int random_create_point(void) {
    int point;
    point = rand() % MAX_ROW;
    return point;
}
// ���˶�ս
void person_person(void) {
    int chessboard[MAX_ROW][MAX_COL] = {BLANK};
    int i, j;
    char key;
    draw_chessboardn(MAX_ROW, MAX_COL, chessboard);
    for (int step = 1; step <= MAX_ROW * MAX_COL; step++) {    // �������У�Ȼ��˫����������
        if (step % 2 == 1) {                                   // ��ǰ����Ϊ�������������ӡ�
            printf("���������:");
            while (1) {
                scanf("%d %d", &i, &j);
                if (chessboard[i][j]!= BLANK) {
                    printf("��λ���������ӣ�����������\n");        // ����ֻ�����ڿհ״�
                    continue;
                }
                if (i >= MAX_ROW || j >= MAX_COL || i < 0 || j < 0) {
                    printf("���볬�����̷�Χ������������\n");      // �������겻�ɳ�������
                    continue;
                }
                break;
            }
            chessboard[i][j] = BLACK;
            draw_chessboardn(MAX_ROW, MAX_COL, chessboard);
            if (is_win(chessboard, MAX_ROW, MAX_COL) == BLACK) {
                printf("����ʤ");
                return;
            }
        } else if (step % 2 == 0) {                            // ��ǰ����Ϊ˫�������������
            printf("���������:");
            while (1) {
                scanf("%d %d", &i, &j);
                if (chessboard[i][j]!= BLANK) {
                    printf("��λ���������ӣ�����������\n");        // ����ֻ�����ڿհ״�
                    continue;
                }
                if (i >= MAX_ROW || j >= MAX_COL || i < 0 || j < 0) {
                    printf("���볬�����̷�Χ������������\n");     // �������겻�ɳ�������
                    continue;
                }
                break;
            }
            chessboard[i][j] = WHITE;
            draw_chessboardn(MAX_ROW, MAX_COL, chessboard);
            if (is_win(chessboard, MAX_ROW, MAX_COL) == WHITE) {
                printf("����ʤ");
                return;
            }
        }
    }
    if (is_full(chessboard, MAX_ROW, MAX_COL) == 1)
        printf("��������");
}

// �ж������Ƿ�����
int is_full(int chessboard[][MAX_COL], int row, int col) {
    int ret = 1;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (chessboard[i][j] == BLANK) {        // �������飬����һ��λ��Ϊ�գ������̲���
                ret = 0;
                break;
            }
        }
    }
    return ret;
}

// �ж�ʤ��
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

// �˻���ս
void person_computer_random(void) {
    int chessboard[MAX_ROW][MAX_COL] = {BLANK};
    int i, j;
    draw_chessboardn(MAX_ROW, MAX_COL, chessboard);
    for (int step = 1; step <= MAX_ROW * MAX_COL; step++) {
        if (step % 2 == 1) {
            printf("���������:");
            while (1) {
                scanf("%d %d", &i, &j);
                if (chessboard[i][j]!= BLANK) {
                    printf("��λ���������ӣ�����������\n");
                    continue;
                }
                if (i >= MAX_ROW || j >= MAX_COL || i < 0 || j < 0) {
                    printf("���볬�����̷�Χ������������\n");
                    continue;
                }
                break;
            }
            chessboard[i][j] = BLACK;
            draw_chessboardn(MAX_ROW, MAX_COL, chessboard);
            if (is_win(chessboard, MAX_ROW, MAX_COL) == BLACK) {
                printf("����ʤ");
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
                printf("����ʤ");
                return;
            }
        }
    }
    if (is_full(chessboard, MAX_ROW, MAX_COL) == 1)
        printf("��������");
}
                                                                                               
