#ifndef SQLISTOPBASE_H
#define SQLISTOPBASE_H

#define MAXSIZE 100  // 定义顺序表的最大容量

// 定义顺序表结构
typedef struct {
    int data[MAXSIZE];  // 使用数组存储数据
    int length;         // 当前顺序表的长度
} SqList;

// 函数声明

// 初始化顺序表
void InitList(SqList *L);

// 在位置i插入元素e
int InsertElem(SqList *L, int i, int e);

// 删除位置i的元素，并将被删除的元素存储到e中
int DeleteElem(SqList *L, int i, int *e);

// 获取位置i的元素，将其存储到e中
int GetElem(SqList L, int i, int *e);

// 查找元素e在顺序表中的位置
int LocateElem(SqList L, int e);

// 打印顺序表
void PrintList(SqList L);

#endif // SQLISTOPBASE_H