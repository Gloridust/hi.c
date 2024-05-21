// 算出任意两个整数的和，并返回相应的结果
#include <stdio.h>

int calculateSum(int a, int b) {
    return a + b;
}

int main() {
    int num1, num2;
    printf("请输入两个整数：");
    scanf("%d %d", &num1, &num2);
    int sum = calculateSum(num1, num2);
    printf("它们的和为：%d\n", sum);
    return 0;
}