// 输入20个数，用数组、函数找出最大的数
#include <stdio.h>
#define SIZE 20

float findMax(float arr[], int size) {
    float max = arr[0]; 
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

int main() {
    float numbers[SIZE];

    printf("请输入20个数：\n");
    for (int i = 0; i < SIZE; i++) {
        printf("请输入第%d个数：", i + 1);
        scanf("%f", &numbers[i]);
    }

    float maxNumber = findMax(numbers, SIZE);

    printf("最大的数是：%.2f\n", maxNumber);

    return 0;
}