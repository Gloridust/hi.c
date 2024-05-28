// 输入任意一个3行4列的二维数组
// 找出最小的数据元素、行号及列号
// 用函数实现

#include <stdio.h>

void find_min_element(float matrix[3][4], float *min_value, int *row, int *col) {
    *min_value = matrix[0][0];
    *row = 0;
    *col = 0;
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            if (matrix[i][j] < *min_value) {
                *min_value = matrix[i][j];
                *row = i;
                *col = j;
            }
        }
    }
}

int main() {
    float matrix[3][4];
    int i, j;

    printf("Please enter a 3x4 matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    int row, col;
    float min_value;
    find_min_element(matrix, &min_value, &row, &col);

    printf("The min element is %f\n", min_value);
    printf("At row %d, column %d\n", row + 1, col + 1);

    return 0;
}
