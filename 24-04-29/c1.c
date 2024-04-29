#include<stdio.h>
int main(){
    int a[3][4]={
        {1,2,3,4},
        {2,3,4,5},
        {3,4,5,6},
    };
    int i,j;
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j<= 3; j++)
        {
                printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    return 0;
}