// 输入10个数，找出最大值和最小值，并将其交换位置
#include <stdio.h>

void findMaxAndMin(int arr[], int n) {
    int max = arr[0], min = arr[0];
    int maxIndex = 0, minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
            maxIndex = i;
        }
        if (arr[i] < min) {
            min = arr[i];
            minIndex = i;
        }
    }
    printf("最大值：%d，最小值：%d\n", max, min);
    // 交换最大值和最小值的位置
    int temp = arr[maxIndex];
    arr[maxIndex] = arr[minIndex];
    arr[minIndex] = temp;
}

int main() {
    int nums[10];
    printf("请输入10个整数：");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &nums[i]);
    }
    findMaxAndMin(nums, 10);
    printf("交换后的数组：");
    for (int i = 0; i < 10; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}
