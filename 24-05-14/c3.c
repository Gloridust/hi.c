#include <stdio.h>

int main() {
    int n;
    int sum = 0;

    printf("请输入一个正整数: ");
    scanf("%d", &n);

    // 计算1到n之间所有5的倍数的和
    for (int i = 1; i <= n; i++) {
        if (i % 5 == 0) {
            sum += i;
        }
    }

    printf("1到%d之间所有5的倍数的和为: %d\n", n, sum);

    return 0;
}
