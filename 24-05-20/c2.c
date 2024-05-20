// 输入3个数，要求输出最大的数
// 用函数找最大数

#include<stdio.h>

float max(float x, float y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
}

float find(float a,float b,float c){
    float result = max(max(a, b), c);
    return result;
}

int main() {
    float a, b, c;
    printf("请输入3个数，以空格分隔：");
    scanf("%f %f %f", &a, &b, &c);

    float result = find(a,b,c);

    printf("最大的数是：%.2f\n", result);

    return 0;
}
