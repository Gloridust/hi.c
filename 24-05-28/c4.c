#include <stdio.h>

void print(int x) {
    int i, j, k;

    for (i = 1; i <= x; i++) {
        for (j = 1; j <= x - i; j++) {
            printf(" ");
        }
        for (k = 1; k <= 2 * i - 1; k++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int x=3;
    print(x);

    return 0;
}
