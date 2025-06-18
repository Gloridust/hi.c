#include <stdio.h>
#include <stdlib.h>

// 定义分区节点结构
struct node {
    int address;        // 分区起始地址
    int size;          // 分区大小
    int flag;          // 分区标志，0空闲，1已分配
    struct node *next; // 指向下一个分区
};

// 全局变量
struct node *free_head = NULL;      // 空闲分区链表头
struct node *allocated_head = NULL; // 已分配分区链表头

// 函数声明
void init_memory();
void display_memory();
int allocate_memory(int size);
int free_memory(int size);
struct node* create_node(int address, int size, int flag);
void insert_free_node(struct node *new_node);
void insert_allocated_node(struct node *new_node);
struct node* remove_allocated_node(int size);
void merge_free_blocks();

// 初始化内存，创建640KB的空闲分区
void init_memory() {
    free_head = create_node(0, 640, 0);
}

// 创建新节点
struct node* create_node(int address, int size, int flag) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->address = address;
    new_node->size = size;
    new_node->flag = flag;
    new_node->next = NULL;
    return new_node;
}

// 按地址顺序插入空闲分区链表
void insert_free_node(struct node *new_node) {
    if (free_head == NULL || new_node->address < free_head->address) {
        new_node->next = free_head;
        free_head = new_node;
        return;
    }
    
    struct node *current = free_head;
    while (current->next != NULL && current->next->address < new_node->address) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
}

// 按地址顺序插入已分配分区链表
void insert_allocated_node(struct node *new_node) {
    if (allocated_head == NULL || new_node->address < allocated_head->address) {
        new_node->next = allocated_head;
        allocated_head = new_node;
        return;
    }
    
    struct node *current = allocated_head;
    while (current->next != NULL && current->next->address < new_node->address) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
}

// 首次适应算法分配内存
int allocate_memory(int size) {
    struct node *current = free_head;
    struct node *prev = NULL;
    
    // 寻找第一个满足条件的空闲分区
    while (current != NULL && current->size < size) {
        prev = current;
        current = current->next;
    }
    
    if (current == NULL) {
        printf("分配失败！没有足够的空闲分区\n");
        return -1;
    }
    
    // 记录分配的地址
    int allocated_address = current->address;
    
    // 创建已分配分区节点
    struct node *allocated_node = create_node(current->address, size, 1);
    insert_allocated_node(allocated_node);
    
    // 如果分区大小正好等于请求大小，直接移除该空闲分区
    if (current->size == size) {
        if (prev == NULL) {
            free_head = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
    } else {
        // 分区大小大于请求大小，分割分区
        current->address += size;
        current->size -= size;
    }
    
    printf("分配成功！地址：%d，大小：%dKB\n", allocated_address, size);
    return allocated_address;
}

// 根据大小找到并移除已分配分区
struct node* remove_allocated_node(int size) {
    struct node *current = allocated_head;
    struct node *prev = NULL;
    
    while (current != NULL && current->size != size) {
        prev = current;
        current = current->next;
    }
    
    if (current == NULL) {
        return NULL;
    }
    
    if (prev == NULL) {
        allocated_head = current->next;
    } else {
        prev->next = current->next;
    }
    
    current->next = NULL;
    return current;
}

// 合并相邻的空闲分区
void merge_free_blocks() {
    if (free_head == NULL) return;
    
    struct node *current = free_head;
    while (current != NULL && current->next != NULL) {
        // 如果当前分区的结束地址等于下一个分区的起始地址，则合并
        if (current->address + current->size == current->next->address) {
            struct node *next = current->next;
            current->size += next->size;
            current->next = next->next;
            free(next);
        } else {
            current = current->next;
        }
    }
}

// 释放内存
int free_memory(int size) {
    struct node *freed_node = remove_allocated_node(size);
    if (freed_node == NULL) {
        printf("释放失败！未找到大小为%dKB的已分配分区\n", size);
        return -1;
    }
    
    freed_node->flag = 0;
    insert_free_node(freed_node);
    merge_free_blocks();
    
    printf("释放成功！地址：%d，大小：%dKB\n", freed_node->address, size);
    return 0;
}

// 显示内存分区状态
void display_memory() {
    printf("\n********** 空闲分区表 **********\n");
    printf("序号\t起始地址\t结束地址\t大小\n");
    printf("------------------------------------\n");
    
    struct node *current = free_head;
    int index = 0;
    while (current != NULL) {
        printf("%d\t%d\t\t%d\t\t%d\n", index, current->address, 
               current->address + current->size - 1, current->size);
        current = current->next;
        index++;
    }
    
    printf("\n********** 已分配分区表 **********\n");
    printf("序号\t起始地址\t结束地址\t大小\n");
    printf("------------------------------------\n");
    
    current = allocated_head;
    index = 0;
    while (current != NULL) {
        printf("%d\t%d\t\t%d\t\t%d\n", index, current->address, 
               current->address + current->size - 1, current->size);
        current = current->next;
        index++;
    }
    printf("\n");
}

int main() {
    // 初始化内存
    init_memory();
    
    printf("=== 动态分区分配方式模拟实验 ===\n");
    printf("初始内存大小：640KB\n");
    
    char choice;
    int size;
    
    while (1) {
        display_memory();
        
        printf("请选择操作：\n");
        printf("a - 分配内存\n");
        printf("r - 释放内存\n");
        printf("q - 退出程序\n");
        printf("请输入选择：");
        
        scanf("%c", &choice);
        getchar(); // 清除换行符
        
        switch (choice) {
            case 'a':
            case 'A':
                printf("请输入要分配的内存大小（KB）：");
                scanf("%d", &size);
                getchar();
                allocate_memory(size);
                break;
                
            case 'r':
            case 'R':
                printf("请输入要释放的内存大小（KB）：");
                scanf("%d", &size);
                getchar();
                free_memory(size);
                break;
                
            case 'q':
            case 'Q':
                printf("程序退出\n");
                exit(0);
                
            default:
                printf("无效选择，请重新输入\n");
                break;
        }
    }
    
    return 0;
}