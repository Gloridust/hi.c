#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    printf("请输入一个正整数: ");
    scanf("%d", &n);

    printf("1到%d之间的素数有: ", n);
    for (int i = 1; i <= n; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
