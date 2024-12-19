#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_SIZE 100

struct Graph {
    int V;
    int **adj;
};

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

bool isEmpty(Queue *q) {
    return q->front == q->rear;
}

bool isFull(Queue *q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    q->data[q->rear] = value;
    q->rear = (q->rear + 1) % MAX_SIZE;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    return value;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adj = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = (int*)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            graph->adj[i][j] = 0;
        }
    }
    
    return graph;
}

void addEdge(struct Graph* graph, int u, int v) {
    graph->adj[u][v] = 1;
    graph->adj[v][u] = 1;
}

void DFSUtil(struct Graph* graph, int v, bool visited[]) {
    visited[v] = true;
    printf("%d ", v);

    for (int i = 0; i < graph->V; ++i)
        if (graph->adj[v][i] && !visited[i])
            DFSUtil(graph, i, visited);
}

void DFS(struct Graph* graph, int v) {
    bool *visited = (bool*)malloc(graph->V * sizeof(bool));
    for (int i = 0; i < graph->V; i++)
        visited[i] = false;

    DFSUtil(graph, v, visited);
    free(visited);
}

/*补充BFS的代码*/
void BFS(struct Graph* graph, int v) {
    bool visited[MAX_SIZE] = {false};
    Queue q;
    initQueue(&q);
    visited[v] = true;
    enqueue(&q, v);

    while (!isEmpty(&q)) {
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->V; i++) {
            if (graph->adj[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
}

int main() {
    struct Graph* graph = createGraph(5);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    printf("Graph:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
           printf("%d",graph->adj[i][j]) ;
        }
        printf("\n");
    }
    printf("DFS:\n");
    DFS(graph, 0);
    printf("\n");

    printf("BFS:\n");
    BFS(graph, 0);
    printf("\n");

    getchar();
    return 0;
}