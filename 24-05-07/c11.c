#include <stdio.h>
#include <ctype.h>
// 输入任意字符串，统计大写字母、小写字母、数字及其它字符的个数。
int main() {
    char str[100];
    int upper_count = 0, lower_count = 0, digit_count = 0, other_count = 0;
    int i = 0;

    printf("请输入一个字符串：\n");
    fgets(str, sizeof(str), stdin);

    while (str[i] != '\0') {
        if (isupper(str[i])) {
            upper_count++;
        } else if (islower(str[i])) {
            lower_count++;
        } else if (isdigit(str[i])) {
            digit_count++;
        } else {
            other_count++;
        }
        i++;
    }

    printf("大写字母个数：%d\n", upper_count);
    printf("小写字母个数：%d\n", lower_count);
    printf("数字个数：%d\n", digit_count);
    printf("其他字符个数：%d\n", --other_count); //去除换行符

    return 0;
}
