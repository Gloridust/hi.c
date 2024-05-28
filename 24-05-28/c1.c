// 输入一个具有n个数据元素的一维数组
// 找出最小的数据元素
// 用函数实现

#include <stdio.h>

void input_nums(int n, float nums[]) {
    int i;
    for (i = 0; i < n; i++) {
        printf("please input the %dth num:", i + 1);
        scanf("%f", &nums[i]);
    }
}

float find_min(int n, float nums[]) {
    float min = nums[0];
    int i;
    for (i = 1; i < n; i++) {
        if (nums[i] < min) {
            min = nums[i];
        }
    }
    return min;
}

int main() {
    int n;
    printf("please input n:");
    scanf("%d", &n);
    float nums[n];
    input_nums(n, nums);
    float min_num = find_min(n, nums);
    printf("The min number is: %f\n", min_num);
    return 0;
}
