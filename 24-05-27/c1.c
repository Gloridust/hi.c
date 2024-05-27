#include<stdio.h>

float max(float b[15]){
    float m=b[0];
    int i,loc=0; // 初始化loc
    for ( i = 1; i < 15; i++)
    {
        if (m<b[i])
        {
            m=b[i];
            loc=i;
        }
    }
    printf("loc=%d\n",loc); // 位置打印移至for循环外
    return m;        
}

float avera(float b[15]){
    int i;
    float plus=0,average;
    for ( i = 0; i < 15; i++) // 将i初始化为0
    {
        plus=(plus+b[i]);     
    }
    average=(plus/15); // 应该除以实际元素个数
    return average;
}

int main(){
    float n,a[15]={2,3,4,5,6,34,5,6,7,8,23,4,5,6,7};
    n=max(a);
    printf("max=%f\n",n);
    float average;
    average=avera(a);
    printf("aver=%f\n",average);
    return 0; // 添加返回值
}
