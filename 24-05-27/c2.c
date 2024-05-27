#include <stdio.h>

float max(float b[], int n) {
    float m = b[0];
    int i;
    for (i = 1; i < n; i++) {
        if (m < b[i]) {
            m = b[i];
        }
    }
    return m;
}

int main() {
    int n, i;
    printf("Please input n: ");
    scanf("%d", &n);
    float a[n], s;
    for (i = 0; i < n; i++) {
        printf("Please input the %dth number: ", i + 1);
        scanf("%f", &a[i]);
    }
    s = max(a, n);
    printf("The maximum number is: %f\n", s);
    return 0;
}
