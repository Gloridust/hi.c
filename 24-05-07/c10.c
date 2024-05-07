#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    double discriminant, root1, root2;

    // 从键盘输入方程的系数
    printf("请输入方程的系数：\n");
    printf("a = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);
    printf("c = ");
    scanf("%lf", &c);

    // 判断方程的类型
    if (a == 0) {
        // 一元一次方程
        if (b != 0) {
            printf("一元一次方程，根为：x = %lf\n", -c / b);
        } else {
            if (c == 0) {
                printf("方程为恒等式，有无穷多个根。\n");
            } else {
                printf("方程无实数根。\n");
            }
        }
    } else {
        // 一元二次方程
        discriminant = b * b - 4 * a * c;
        if (discriminant > 0) {
            root1 = (-b + sqrt(discriminant)) / (2 * a);
            root2 = (-b - sqrt(discriminant)) / (2 * a);
            printf("一元二次方程，根为：x1 = %lf, x2 = %lf\n", root1, root2);
        } else if (discriminant == 0) {
            root1 = root2 = -b / (2 * a);
            printf("一元二次方程，重根为：x1 = x2 = %lf\n", root1);
        } else {
            printf("一元二次方程，无实数根。\n");
        }
    }

    return 0;
}
