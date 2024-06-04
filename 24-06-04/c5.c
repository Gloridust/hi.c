#include<stdio.h>

void main(){
    int a[12],b[12],i;
    for (i = 0; i < 12; i++)
    {
        printf("input the %dth number:",(i+1));
        scanf("%d",&a[i]);
    }
    for (i = 0; i < 12; i++)
    {
        b[11-i]=a[i];
    }
    for (i = 0; i < 12; i++)
    {
        a[i]=b[i];
    }
    for (i = 0; i < 12; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}