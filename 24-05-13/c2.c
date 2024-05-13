#include<stdio.h>
#include<math.h>

int max(int x,int y,int z);
int main(){
    int a,b,c,d;
    printf("Please input the int:");
    scanf("%d,%d,%d,",&a,&b,&c);
    d=max(c,a,b);
    printf("%d\n",d);
}

int max(int x,int y,int z){
    int m;
    if(x>y)
    m=x;
    else m=y;
    if ((m<z))
    {
        m=z;
    }
}