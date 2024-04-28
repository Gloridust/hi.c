#include<stdio.h>
int main(){
    int n,i;
    printf("input n:");
    scanf("%d",&n);
    float a[n],sum=0;
    for(i=0;i<=n-1;i++)
        scanf("%f",&a[i]);
    for(i=0;i<n;i++)
        sum+=a[i];
    printf("%f\n",sum/n);
    return 0;
}