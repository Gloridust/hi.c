// 输入一个具有n个数据元素的一维数组
// 找出最小的数据元素
// 用函数实现。

#include <stdio.h>

float input_nums(n){
    float nums[n],j;
    int i;
    for (i = 0; i < n; i++)
    {
        printf("please input the %dth num:",i);
        scanf("%f",&j);
        nums[i]=j;
    }
    return nums;
}

float find_min(n,nums){
    int i;
    float min;
    for (i = 0; i < n; i++)
    {
        if (min<nums[i])
        {
            min=nums[i];
        }
    }
    return min;
}

int main(){
    int n;
    printf("please input n:");
    scanf("%d",&n);
    float nums[],min_num;
    nums[]=input_nums;
    min_num=(n,nums);
 
    return 0;
}