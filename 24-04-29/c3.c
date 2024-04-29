// 输入任意 n*m 矩阵，并打印
// 然后找到最大/最小元素
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
    
    printf("a:\n");
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j< m; j++)
        {
                printf("%5.1f ",a[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");

    float max,min;
    max=a[0][0];
    min=a[0][0];
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < m; j++)
        {
            if(max<a[i][j])
                max=a[i][j];
            if (min>a[i][j])
                min=a[i][j];
        }
        
    }
    printf("max=%5.1f\n",max);
    printf("min=%5.1f\n",min);

    return 0;
}