// 在主程序中输入正整数n，用函数计算1-n之间所有3的倍数的和。
#include <stdio.h>

int getSum(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int n;
    printf("请输入一个正整数：");
    scanf("%d", &n);
    int sum = getSum(n);
    printf("1到%d之间所有3的倍数的和为：%d\n", n, sum);
    return 0;
}
