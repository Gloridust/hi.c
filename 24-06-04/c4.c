#include <stdio.h>

int main() {
    int arr[15];
    int i, minIndex, temp;

    printf("pls input 15 int：\n");
    for (i = 0; i < 15; i++) {
        scanf("%d", &arr[i]);
    }

    minIndex = 0;
    for (i = 1; i < 15; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    if (minIndex != 0) {
        temp = arr[0];
        arr[0] = arr[minIndex];
        arr[minIndex] = temp;
    }

    printf("changed：\n");
    for (i = 0; i < 15; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
