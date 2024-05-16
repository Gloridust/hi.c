#include <stdio.h>

int findMax(int nums[], int size);
int findMin(int nums[], int size);

int main() {
    int nums[4];

    printf("请输入4个数：\n");
    for (int i = 0; i < 4; i++) {
        printf("请输入第%d个数：", i + 1);
        scanf("%d", &nums[i]);
    }

    int max = findMax(nums, 4);
    int min = findMin(nums, 4);

    printf("输入的4个数中最大的数是：%d\n", max);
    printf("输入的4个数中最小的数是：%d\n", min);

    return 0;
}

int findMax(int nums[], int size) {
    int max = nums[0]; 

    for (int i = 1; i < size; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }

    return max;
}

int findMin(int nums[], int size) {
    int min = nums[0]; 

    for (int i = 1; i < size; i++) {
        if (nums[i] < min) {
            min = nums[i];
        }
    }

    return min;
}