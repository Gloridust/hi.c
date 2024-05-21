// 输入12个整数，组成一个3x4的矩阵，输出第一行和第一列的所有元素
#include <stdio.h>

int main() {
    int matrix[3][4];

    printf("请输入12个整数：");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("第一行的元素为：");
    for (int j = 0; j < 4; j++) {
        printf("%d ", matrix[0][j]);
    }
    printf("\n");

    printf("第一列的元素为：\n");
    for (int i = 0; i < 3; i++) {
        printf("%d\n", matrix[i][0]);
    }

    return 0;
}