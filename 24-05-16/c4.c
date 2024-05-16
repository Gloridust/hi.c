#include <stdio.h>

int isLeapYear(int year);

int main() {
    int year;
    printf("请输入一个年份：");
    scanf("%d", &year);

    if (isLeapYear(year)) {
        printf("%d 是闰年。\n", year);
    } else {
        printf("%d 不是闰年。\n", year);
    }

    return 0;
}

int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1;
    }
    return 0;
}
