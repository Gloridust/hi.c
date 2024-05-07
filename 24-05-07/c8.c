#include <stdio.h>

int main() {
    char lowercase;
    char uppercase;
    printf("请输入一个小写字母：");
    scanf("%c", &lowercase);
    uppercase = lowercase - 32;
    printf("对应的大写字母为：%c\n", uppercase);
    return 0;
}
