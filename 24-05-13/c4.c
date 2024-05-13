#include<stdio.h>
#include<math.h>

int main(){
    float a,b,c;
    printf("Please input the numbers:");
    scanf("%f,%f,%f,",&a,&b,&c);
    int max(float,float);
    printf("%d\n",max(max(a,b),c));
}

int max(float x,float y){
    return(x>y?x:y);
}