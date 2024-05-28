// 输入12个数
// 并输出3行4列矩阵
// 不用函数实现

#include <stdio.h>

int main() {
    float matrix[3][4];
    int i, j;

    printf("Please enter 12 numbers:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    printf("The matrix is:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
