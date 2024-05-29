// 编写一函数计算y=(a-b)/(a+b) 的值
// 在主函数中输入a和b的值,输出y的值

#include<stdio.h>

float compute(float a,float b){
    float y;
    y=((a-b)/(a+b));
    return y;
}

void main(){
    float a,b,y;
    printf("input a:");
    scanf("%f",&a);
    printf("input b:");
    scanf("%f",&b);
    y=compute(a,b);
    printf("y=%.2f",y);
}