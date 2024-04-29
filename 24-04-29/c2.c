// 输入任意 n*m 矩阵，并打印
#include<stdio.h>
int main(){
    int n,m;
    printf("input n:");
    scanf("%d",&n);
    printf("input m:");
    scanf("%d",&m);

    int i,j;
    float a[n][m];
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < m; j++)
        {
            printf("input num:\n");
            scanf("%f",&a[i][j]);
        }
        
    }
    
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j< m; j++)
        {
                printf("%5.1f ",a[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    return 0;
}