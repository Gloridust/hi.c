//求一个3×3的整型矩阵对角线元素之和
#include <stdio.h>

int main() {
    int matrix[3][3]; // 定义一个3x3的整型矩阵
    int i, j, sum = 0;

    printf("Please input the elements of the 3x3 matrix:\n");

    // 用户依次输入矩阵的每个元素
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Enter element at position (%d, %d): ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    // 计算主对角线和副对角线的元素之和
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (i == j || i + j == 2) {
                sum += matrix[i][j];
            }
        }
    }

    // 输出结果
    printf("Sum of diagonal elements: %d\n", sum);

    return 0;
}
