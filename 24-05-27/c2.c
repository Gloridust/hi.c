#include<stdio.h>

float max(float m=b,int n){
    int i;
    for ( i = 1; i < n; i++)
    {
        if (m<b[i])
        {
            m=b[i];
        }
        
    }
    return m;
}

int main(){
    int n,i;
    printf("please input n:");
    scanf("%d",&n);
    float a[n],s;
    for (i = 0; i < n; i++)
    {
        scanf("%f",&a[i]);
    }
    s=max(a,n);
    printf("%f\n",s);
    return 0; 
}