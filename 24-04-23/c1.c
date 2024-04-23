#include<stdio.h>
#include<math.h>

int main(){
    float x,y;
    printf("input your x:");
    scanf("%f",&x);

    if (x<2)
    {
        y=fabs(x-105);
    }
    if(x>=2&&x<25){
        y=sqrt(pow(x,3)+3*x+1);
    }
    if(x>=25){
        y=pow(5,x);
    }
    printf("y=%f\n",y);
}