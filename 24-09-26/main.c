#include <stdio.h>
#include "SqListOpBase.h"

// 初始化顺序表
void InitList(SqList *L) {
    L->length = 0;  // 初始化长度为0
}

// 在位置i插入元素e
int InsertElem(SqList *L, int i, int e) {
    // 检查插入位置是否合法
    if (i < 1 || i > L->length + 1 || L->length >= MAXSIZE) {
        return 0;  // 插入失败
    }
    
    // 将第i个元素及之后的元素后移
    for (int j = L->length; j >= i; j--) {
        L->data[j] = L->data[j-1];
    }
    
    L->data[i-1] = e;  // 在位置i插入新元素
    L->length++;       // 表长增加1
    return 1;          // 插入成功
}

// 删除位置i的元素，并将被删除的元素存储到e中
int DeleteElem(SqList *L, int i, int *e) {
    // 检查删除位置是否合法
    if (i < 1 || i > L->length) {
        return 0;  // 删除失败
    }
    
    *e = L->data[i-1];  // 将被删除的元素赋值给e
    
    // 将第i个位置后的元素前移
    for (int j = i; j < L->length; j++) {
        L->data[j-1] = L->data[j];
    }
    
    L->length--;  // 表长减少1
    return 1;     // 删除成功
}

// 获取位置i的元素，将其存储到e中
int GetElem(SqList L, int i, int *e) {
    if (i < 1 || i > L.length) {
        return 0;  // 获取失败
    }
    *e = L.data[i-1];
    return 1;      // 获取成功
}

// 查找元素e在顺序表中的位置
int LocateElem(SqList L, int e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            return i + 1;  // 返回元素位置（从1开始）
        }
    }
    return 0;  // 未找到元素
}

// 打印顺序表
void PrintList(SqList L) {
    printf("顺序表内容: ");
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

// 主函数，用于测试
int main() {
    SqList L;
    int e;
    
    InitList(&L);  // 初始化顺序表
    
    // 插入元素
    InsertElem(&L, 1, 10);
    InsertElem(&L, 2, 20);
    InsertElem(&L, 3, 30);
    
    printf("插入元素后：\n");
    PrintList(L);
    
    // 删除元素
    DeleteElem(&L, 2, &e);
    printf("删除第2个元素（%d）后：\n", e);
    PrintList(L);
    
    // 获取元素
    GetElem(L, 2, &e);
    printf("第2个元素是：%d\n", e);
    
    // 查找元素
    int pos = LocateElem(L, 30);
    printf("元素30的位置是：%d\n", pos);
    
    return 0;
}