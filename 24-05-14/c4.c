#include <stdio.h>

#define SIZE 4  // 定义图案的行数

int main() {
    int maxStars = SIZE * 2 - 1;
    char pattern[SIZE][maxStars]; 

    // 初始化
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < maxStars; j++) {
            pattern[i][j] = ' ';
        }
    }

    // 填充
    for (int i = 0; i < SIZE; i++) {
        int stars = i * 2 + 1;
        int start = (maxStars - stars) / 2;
        for (int j = start; j < start + stars; j++) {
            pattern[i][j] = '*';
        }
    }

    // 打印图案
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < maxStars; j++) {
            printf("%c", pattern[i][j]);
        }
        printf("\n");
    }

    return 0;
}
