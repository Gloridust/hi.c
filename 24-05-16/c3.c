#include <stdio.h>

char convertToUpperIfLower(char ch);

int main() {
    char inputChar, resultChar;

    printf("请输入一个字符：");
    scanf("%c", &inputChar);

    resultChar = convertToUpperIfLower(inputChar);

    printf("转换后的字符是：%c\n", resultChar);
    return 0;
}

char convertToUpperIfLower(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return ch - 32;
    }
    return ch;
}
