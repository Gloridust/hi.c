#include<stdio.h>
int main(){
    int n,i;
    printf("input n:");
    scanf("%d",&n);
    float a[n];
    for(i=0;i<=n-1;i++)
    scanf("%f",&a[i]);
    for(i=n-1;i>=0;i--)
    printf("%f ",a[i]);
    printf("\n");
    return 0;
}