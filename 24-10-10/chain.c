#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 定义链表结构
typedef struct {
    Node* head;
} LinkedList;

// 初始化链表
void initList(LinkedList* list) {
    list->head = NULL;
}

// 头插法创建链表
void createListHead(LinkedList* list) {
    int value;
    printf("请输入节点值（输入-1结束）：\n");
    while (1) {
        scanf("%d", &value);
        if (value == -1) break;
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = list->head;
        list->head = newNode;
    }
}

// 尾插法创建链表
void createListTail(LinkedList* list) {
    int value;
    Node* tail = NULL;
    printf("请输入节点值（输入-1结束）：\n");
    while (1) {
        scanf("%d", &value);
        if (value == -1) break;
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = NULL;
        if (list->head == NULL) {
            list->head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }
}

// 遍历链表
void traverseList(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 在指定位置插入元素
int insertElement(LinkedList* list, int position, int value) {
    if (position < 1) return 0;
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    
    if (position == 1) {
        newNode->next = list->head;
        list->head = newNode;
        return 1;
    }
    
    Node* current = list->head;
    for (int i = 1; i < position - 1 && current; i++) {
        current = current->next;
    }
    
    if (!current) return 0;
    
    newNode->next = current->next;
    current->next = newNode;
    return 1;
}

// 删除指定位置的元素
int deleteElement(LinkedList* list, int position, int* value) {
    if (position < 1 || list->head == NULL) return 0;
    
    Node* temp;
    if (position == 1) {
        temp = list->head;
        *value = temp->data;
        list->head = temp->next;
        free(temp);
        return 1;
    }
    
    Node* current = list->head;
    for (int i = 1; i < position - 1 && current->next; i++) {
        current = current->next;
    }
    
    if (current->next == NULL) return 0;
    
    temp = current->next;
    *value = temp->data;
    current->next = temp->next;
    free(temp);
    return 1;
}

// 获取指定位置的元素值
int getElement(LinkedList* list, int position, int* value) {
    if (position < 1 || list->head == NULL) return 0;
    
    Node* current = list->head;
    for (int i = 1; i < position && current; i++) {
        current = current->next;
    }
    
    if (!current) return 0;
    
    *value = current->data;
    return 1;
}

// 销毁链表
void destroyList(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    list->head = NULL;
}

// 合并两个已排序的链表
LinkedList mergeList(LinkedList* list1, LinkedList* list2) {
    LinkedList mergedList;
    initList(&mergedList);
    
    Node* current1 = list1->head;
    Node* current2 = list2->head;
    Node* tail = NULL;
    
    while (current1 && current2) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (current1->data <= current2->data) {
            newNode->data = current1->data;
            current1 = current1->next;
        } else {
            newNode->data = current2->data;
            current2 = current2->next;
        }
        newNode->next = NULL;
        
        if (mergedList.head == NULL) {
            mergedList.head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }
    
    while (current1) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = current1->data;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
        current1 = current1->next;
    }
    
    while (current2) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = current2->data;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
        current2 = current2->next;
    }
    
    return mergedList;
}

// 反转链表
void reverseList(LinkedList* list) {
    Node* prev = NULL;
    Node* current = list->head;
    Node* next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    list->head = prev;
}

// 主函数
int main() {
    LinkedList list;
    initList(&list);
    
    // 测试各种操作
    createListTail(&list);
    printf("原始链表：");
    traverseList(&list);
    
    insertElement(&list, 3, 100);
    printf("插入后的链表：");
    traverseList(&list);
    
    int deletedValue;
    deleteElement(&list, 2, &deletedValue);
    printf("删除后的链表：");
    traverseList(&list);
    printf("被删除的元素：%d\n", deletedValue);
    
    int value;
    if (getElement(&list, 2, &value)) {
        printf("第2个位置的元素：%d\n", value);
    }
    
    reverseList(&list);
    printf("反转后的链表：");
    traverseList(&list);
    
    // 测试合并链表
    LinkedList list2;
    initList(&list2);
    createListTail(&list2);
    printf("第二个链表：");
    traverseList(&list2);
    
    LinkedList mergedList = mergeList(&list, &list2);
    printf("合并后的链表：");
    traverseList(&mergedList);
    
    // 销毁链表
    destroyList(&list);
    destroyList(&list2);
    destroyList(&mergedList);
    
    return 0;
}