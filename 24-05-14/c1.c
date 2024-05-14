#include <stdio.h>
#include <ctype.h>  // 字符处理头文件

int main() {
    char lowercase[100];
    char uppercase[100];
    printf("请输入一个由小写字母组成的字符串：");
    scanf("%s", lowercase);

    int i = 0;
    while (lowercase[i] != '\0') {
        if (islower(lowercase[i])) { 
            uppercase[i] = toupper(lowercase[i]);
        } else {
            uppercase[i] = lowercase[i];
        }
        i++;
    }
    uppercase[i] = '\0';  // 字符串结束符

    printf("对应的大写字母字符串为：%s\n", uppercase);
    return 0;
}
