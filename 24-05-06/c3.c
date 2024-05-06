#include <stdio.h>
#include <string.h>

int main() {
    char a[256], b[256], c[512]; // c数组大小需要足够大以容纳两个字符串的连接结果
    printf("Please input the 1st string:");
    gets(a);
    printf("Please input the 2nd string:");
    gets(b);

    if (strlen(a) + strlen(b) < sizeof(c)) { // 检查数组越界的情况
        strcpy(c, a); // 将第一个字符串拷贝到c中
        strcat(c, b); // 将第二个字符串连接到c的末尾
        puts(c);
    } else {
        printf("Combined strings exceed buffer size.\n");
    }

    return 0;
}
