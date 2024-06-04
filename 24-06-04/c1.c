#include<stdio.h>

void main(){
    int a,b;
    printf("input a:");
    scanf("%d",&a);
    printf("input b:");
    scanf("%d",&b);

    if (a<b)
    {
        printf("a=%d\n",a);
        printf("b=%d\n",b);
    }
    else
    {
        printf("b=%d\n",b);
        printf("a=%d\n",a);
    }
}