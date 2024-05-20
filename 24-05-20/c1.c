// 输入4个数，要求输出最大的数

#include<stdio.h>

float max(float x, float y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
}

int main() {
    float a, b, c, d;
    printf("请输入四个数，以空格分隔：");
    scanf("%f %f %f %f", &a, &b, &c, &d);

    float result = max(max(a, b), max(c, d));

    printf("最大的数是：%.2f\n", result);

    return 0;
}
