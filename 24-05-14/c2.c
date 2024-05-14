#include <stdio.h>
#include <math.h>

#define PI 3.1415926

double r;
double s, area;

int get(){
    printf("请输入半径：\n");
    printf("r = ");
    scanf("%lf", &r);
    return r;
}

double c_circle(){
    double c;
    c=2*PI*r;
    return c;
}

double s_circle(){
    s = PI*r*r;
    return s;
}

double v_ball(){
    double v;
    v=4*PI*r*r*r/3;
    return v;
}

double s_ball(){
    double s;
    s=4*PI*r*r;
    return s;
}

int main() {
    r=get();
    printf("c_circle is: %f \n",c_circle(r));
    printf("s_circle is: %f \n",s_circle(r));
    printf("v_ball is: %f \n",v_ball(r));
    printf("s_ball is: %f \n",s_ball(r));
    
    return 0;
}
