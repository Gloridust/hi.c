#include <stdio.h>

int main() {
    int matrix[4][3];
    int i, j;
    int min, minRow, minCol;

    printf("请输入4x3矩阵的元素：\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    min = matrix[0][0];
    minRow = 0;
    minCol = 0;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
                minRow = i;
                minCol = j;
            }
        }
    }

    printf("最小值是: %d, 位置: 行 %d, 列 %d\n", min, minRow, minCol);

    return 0;
}
