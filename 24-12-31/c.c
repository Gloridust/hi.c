#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
typedef struct list{
    int data;           // 节点数据
    struct list *next;  // 指向下一个节点的指针
} list;

// 在链表头部添加新节点
void addNode(list **head, int data) {
    list *newNode = (list*)malloc(sizeof(list)); // 创建新节点
    newNode->data = data;                       // 设置新节点的数据
    newNode->next = *head;                      // 新节点的next指向当前头节点
    *head = newNode;                           // 更新头节点为新节点
}

// 从链表中删除指定数据的节点
void deleteNode(list **head, int data) {
    list *current = *head;  // 当前节点
    list *previous = NULL; // 前一个节点
    
    while (current != NULL) { // 遍历链表
        if (current->data == data) { // 找到要删除的节点
            if (previous == NULL) {  // 如果要删除的是头节点
                *head = current->next; // 更新头节点
                free(current);         // 释放当前节点内存
                return;                // 删除完成，返回
            } else {                  // 如果要删除的不是头节点
                previous->next = current->next; // 前一个节点的next指向当前节点的next
                free(current);         // 释放当前节点内存
                return;                // 删除完成，返回
            }
        }
        previous = current;        // 更新前一个节点
        current = current->next;   // 更新当前节点
    }
}

// 打印链表所有节点的数据
void printList(list *head) {
    list *current = head; // 当前节点
    while (current != NULL) { // 遍历链表
        printf("%d ", current->data); // 打印当前节点的数据
        current = current->next;      // 更新当前节点
    }
    printf("\n"); // 换行
}

int main() {
    list *head = NULL; // 初始化头节点为空
    addNode(&head, 1);  // 添加节点1
    addNode(&head, 2);  // 添加节点2
    addNode(&head, 3);  // 添加节点3
    printList(head);    // 打印链表
    return 0;
}