#include <stdio.h>

int main() {
    int rows, cols;
    int array[10][10];

    printf("请输入数组的行数和列数（最大值为10）：\n");
    printf("行数：");
    scanf("%d", &rows);
    printf("列数：");
    scanf("%d", &cols);

    // 检查范围
    if (rows <= 0 || rows > 10 || cols <= 0 || cols > 10) {
        printf("行数和列数必须在1到10之间。\n");
        return 1;
    }

    printf("请输入数组元素：\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("array[%d][%d] = ", i, j);
            scanf("%d", &array[i][j]);
        }
    }

    // 最大
    int maxElement = array[0][0];
    int maxRow = 0, maxCol = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (array[i][j] > maxElement) {
                maxElement = array[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }

    printf("最大元素是 %d\n第%d行\n第%d列", maxElement, maxRow, maxCol);

    return 0;
}
