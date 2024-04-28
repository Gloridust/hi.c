#include<stdio.h>
int main(){
    int c[3][4]={{1,2,5,8},
                {2,3,6,9},
                {3,4,7,10}};
    // printf("%d",c);
    // int d[3][4]={1,2,5,8,2,3,6,9,3,4,7,10};
    int i,j;
    for ( i = 0; i <= 2; i++){
        for ( j = 0; j <= 3; j++)
            printf("%d ",c[i][j]);
        printf("\n");
    }
    return 0;
}