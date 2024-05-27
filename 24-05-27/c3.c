#include <stdio.h>

float max(float b[][100], int m, int n) { 
    float max_val = b[0][0];
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (b[i][j] > max_val) {
                max_val = b[i][j];
            }
        }
    }
    return max_val;
}

int main() {
    int m, n, i, j; 
    printf("Please input m: ");
    scanf("%d", &m);
    printf("Please input n: ");
    scanf("%d", &n);

    float a[m][n];
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("Input a[%d][%d]: ", (i+1), (j+1));
            scanf("%f", &a[i][j]);
        }
    }

    float maximum = max(a, m, n);
    printf("\nThe maximum value in the array is: %f\n", maximum);

    return 0;
}

