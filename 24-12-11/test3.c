#include <stdio.h>

int main(){

    printf("请输入一个数字（1-3）：\n");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("你选择了选项 1\n");
            break;
        case 2:
            printf("你选择了选项 2\n");
            break;
        case 3:
            printf("你选择了选项 3\n");
            break;
        default:
            printf("无效的选择，请输入 1 到 3 之间的数字。\n");
            break;
    }

    return 0;
}