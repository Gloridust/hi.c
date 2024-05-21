// 输入n个正整数，找出其中奇数的个数与偶数的个数
#include <stdio.h>

void countOddAndEven(int arr[], int n) {
    int oddCount = 0, evenCount = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }
    printf("奇数个数：%d，偶数个数：%d\n", oddCount, evenCount);
}

int main() {
    int n;
    printf("请输入正整数个数：");
    scanf("%d", &n);
    int nums[n];
    printf("请输入%d个正整数：", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    countOddAndEven(nums, n);
    return 0;
}
