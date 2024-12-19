#include <stdio.h>
#include <stdlib.h>

// 最大顶点数
#define MAX_VERTICES 100
// 队列的最大容量
#define MAX_QUEUE_SIZE 100

typedef struct {
    int vertices;
    int** matrix;
} Graph;

// 队列结构
typedef struct {
    int data[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

// 队列操作
void initQueue(Queue* q) {
    q->front = q->rear = 0;
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

int isFull(Queue* q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void enqueue(Queue* q, int value) {
    if (!isFull(q)) {
        q->data[q->rear] = value;
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    }
}

int dequeue(Queue* q) {
    int value = -1;
    if (!isEmpty(q)) {
        value = q->data[q->front];
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    }
    return value;
}

// 图操作
Graph* createGraph(int vertices) {
    Graph* g = malloc(sizeof(Graph));
    g->vertices = vertices;
    g->matrix = malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        g->matrix[i] = calloc(vertices, sizeof(int));
    }
    return g;
}

void addEdge(Graph* g, int v1, int v2) {
    g->matrix[v1][v2] = 1;
    g->matrix[v2][v1] = 1;
}

// DFS
void DFSUtil(Graph* g, int v, int* visited) {
    visited[v] = 1;
    printf("%d ", v);
    
    for (int i = 0; i < g->vertices; i++) {
        if (g->matrix[v][i] && !visited[i]) {
            DFSUtil(g, i, visited);
        }
    }
}

void DFS(Graph* g, int start) {
    int* visited = calloc(g->vertices, sizeof(int));
    printf("DFS starting from vertex %d: ", start);
    DFSUtil(g, start, visited);
    printf("\n");
    free(visited);
}

// BFS
void BFS(Graph* g, int start) {
    Queue q;
    initQueue(&q);
    int* visited = calloc(g->vertices, sizeof(int));
    
    printf("BFS starting from vertex %d: ", start);
    visited[start] = 1;
    printf("%d ", start);
    enqueue(&q, start);
    
    while (!isEmpty(&q)) {
        int v = dequeue(&q);
        for (int i = 0; i < g->vertices; i++) {
            if (g->matrix[v][i] && !visited[i]) {
                visited[i] = 1;
                printf("%d ", i);
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
    free(visited);
}

void freeGraph(Graph* g) {
    for (int i = 0; i < g->vertices; i++) {
        free(g->matrix[i]);
    }
    free(g->matrix);
    free(g);
}

// 打印邻接矩阵
void printGraph(Graph* g) {
    printf("邻接矩阵:\n");
    for (int i = 0; i < g->vertices; i++) {
        for (int j = 0; j < g->vertices; j++) {
            printf("%d ", g->matrix[i][j]);
        }
        printf("\n");
    }
}

// 测试代码
int main() {
    Graph* g = createGraph(5);
    
    // 添加边
    addEdge(g, 0, 1);
    addEdge(g, 0, 4);
    addEdge(g, 1, 2);
    addEdge(g, 1, 3);
    addEdge(g, 2, 3);
    
    // 打印邻接矩阵
    printGraph(g);
    
    printf("\nDFS遍历:\n");
    DFS(g, 0);
    
    printf("\nBFS遍历:\n");
    BFS(g, 0);
    
    // 等待用户输入
    getchar();
    
    freeGraph(g);
    return 0;
}
