#include <stdio.h>

int main() {
    int a = 5;
    int b = 10;
    int temp;

    printf("初始值：\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    // 交换变量值
    temp = a;
    a = b;
    b = temp;

    printf("交换后的值：\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    return 0;
}
