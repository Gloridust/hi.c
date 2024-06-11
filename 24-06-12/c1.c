// 输入任意正整数n，求1-n之间奇数的个数
#include <stdio.h>

void main() {
    int n, count;

    printf("input any int: ");
    scanf("%d", &n);

    if (n % 2 == 0) {
        count = n / 2;
    } else {
        count = n / 2 + 1;
    }

    printf("The number of odd numbers between 1 and %d is: %d\n", n, count);
}