#include <stdio.h>

int findMax(int nums[], int size);

int main() {
    int nums[5];

    printf("请输入5个数：\n");
    for (int i = 0; i < 5; i++) {
        printf("请输入第%d个数：", i + 1);
        scanf("%d", &nums[i]);
    }

    int max = findMax(nums, 5);

    printf("输入的5个数中最大的数是：%d\n", max);

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
