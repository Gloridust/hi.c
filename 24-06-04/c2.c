#include <stdio.h>

int main() {
    int a, b, c, temp;

    // 输入3个整数
    printf("请输入3个整数：\n");
    scanf("%d %d %d", &a, &b, &c);

    // 通过比较和交换排序
    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }
    if (a > c) {
        temp = a;
        a = c;
        c = temp;
    }
    if (b > c) {
        temp = b;
        b = c;
        c = temp;
    }

    // 输出从小到大的顺序
    printf("从小到大的顺序是：%d %d %d\n", a, b, c);

    return 0;
}
