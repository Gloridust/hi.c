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
    // int main(){
    // int i=9,a[10]={0,1,2,3,4,5,6,7,8,9};
    // for(;i>=0;i--)
    // printf("%d \n",a[i]);
    return 0;
}