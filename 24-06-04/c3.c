#include<stdio.h>

void main(){
    int a[10],i;
    for (i = 0; i < 10; i++)
    {
        printf("input the %dth number:",(i+1));
        scanf("%d",&a[i]);
    }

    for (i = 0; i < 10; i++)
    {
        a[i]=(a[i]+1);
        printf("%d ",a[i]);
    }
    printf("\n");
}