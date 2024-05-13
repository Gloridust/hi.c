#include<stdio.h>
#include<math.h>

int main(){
    int a,b,c;
    printf("Please input the int:");
    scanf("%d,%d,%d,",&a,&b,&c);
    int max(int,int);
    printf("%d\n",max(max(a,b),c));
}

int max(int x,int y){
    return(x>y?x:y);
}