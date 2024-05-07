#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    double s, area;

    printf("请输入三角形的三条边长：\n");
    printf("a = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);
    printf("c = ");
    scanf("%lf", &c);

    // 半周长
    s = (a + b + c) / 2;

    // 面积
    area = sqrt(s * (s - a) * (s - b) * (s - c));

    printf("三角形的面积为：%lf\n", area);

    return 0;
}
