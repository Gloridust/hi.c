#include <stdio.h>

int main() {
    int num;

    printf("请输入一个四位数字：");
    scanf("%d", &num);

    char str[5];
    sprintf(str, "%d", num);

    printf("%c  %c  %c  %c\n", str[0], str[1], str[2], str[3]);
    return 0;
}
