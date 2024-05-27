#include<stdio.h>

float max(float b[15]){
    float m=b[0];
    int i,loc;
    for ( i = 1; i < 15; i++)
    {
        if (m<b[i])
        {
            m=b[i];
            loc=i;
        }
        printf("loc=%d\n",loc);
        return m;        
    }
    
}

float avera(float b[15]){
    int i;
    float plus=0,average;
    for ( i = 1; i < 15; i++)
    {
        plus=(plus+b[i]);     
    }
    average=(plus/15);
    return average;
}

int main(){
    float n,a[15]={2,3,4,5,6,34,5,6,7,8,23,4,5,6,7};
    n=max(a);
    printf("max=%f\n",n);
    float average;
    average=avera(a);
    printf("aver=%f\n",average);
}