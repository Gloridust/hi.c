#include <stdio.h>   // 引入标准输入输出头文件
#include <stdlib.h>  // 引入标准库头文件，用于随机数生成
#include <time.h>    // 引入时间相关函数的头文件

int main(){
    srand(time(NULL));  // 使用当前时间作为随机数种子
    int magic = rand()%100+1;  // 生成1到100之间的随机数
    int num1 = 0;  // 用户输入的数字
    int attempts = 0;  // 记录猜测次数
    
    printf("欢迎来到猜数字游戏！\n");
    
    while(1) {  // 无限循环，直到猜对为止
        printf("请输入一个0-100的数字: ");
        scanf("%d", &num1);  // 读取用户输入
        attempts++;  // 增加猜测次数
        
        if(num1 > magic) {
            printf("太大了，请继续猜！\n");
        }
        else if(num1 < magic) {
            printf("太小了，请继续猜！\n");
        }
        else {
            printf("恭喜你猜对了！\n");
            printf("你总共猜了 %d 次\n", attempts);
            break;  // 猜对后跳出循环
        }
    }
    
    printf("游戏结束，答案是：%d\n", magic);  // 显示正确答案
    return 0;
}
