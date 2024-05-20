// 输入4个数，用函数求平均数
#include<stdio.h>

float aver(float a,float b,float c,float d){
    return ((a+b+c+d)/4);
}

int main(){
    float a,b,c,d,result;
    printf("input four numbers apart with space:");
    scanf("%f %f %f %f",&a,&b,&c,&d);
    result=aver(a,b,c,d);
    printf("result is %.2f\n",result);
}