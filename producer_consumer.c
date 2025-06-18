#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5  // 缓冲区大小

// 全局变量
int buffer[BUFFER_SIZE];  // 缓冲区
int in = 0;   // 生产者指针
int out = 0;  // 消费者指针

// 信号量声明
sem_t mutex;  // 互斥信号量，保护缓冲区
sem_t empty;  // 空位信号量
sem_t full;   // 产品信号量

// 生产者线程函数
void* producer(void* arg) {
    int producer_id = *(int*)arg;
    int item;
    
    for(int i = 0; i < 5; i++) {  // 每个生产者生产5个产品
        // 生产产品
        item = rand() % 100 + 1;  // 生产1-100的随机数作为产品
        
        // 等待空位
        sem_wait(&empty);
        // 进入临界区前获取互斥锁
        sem_wait(&mutex);
        
        // 临界区：放入产品
        buffer[in] = item;
        printf("生产者%d生产了产品%d，放入位置%d\n", producer_id, item, in);
        in = (in + 1) % BUFFER_SIZE;  // 循环缓冲区
        
        // 离开临界区，释放互斥锁
        sem_post(&mutex);
        // 增加产品数量信号量
        sem_post(&full);
        
        // 模拟生产时间
        sleep(1);
    }
    
    return NULL;
}

// 消费者线程函数
void* consumer(void* arg) {
    int consumer_id = *(int*)arg;
    int item;
    
    for(int i = 0; i < 5; i++) {  // 每个消费者消费5个产品
        // 等待产品
        sem_wait(&full);
        // 进入临界区前获取互斥锁
        sem_wait(&mutex);
        
        // 临界区：取出产品
        item = buffer[out];
        printf("消费者%d消费了产品%d，从位置%d取出\n", consumer_id, item, out);
        out = (out + 1) % BUFFER_SIZE;  // 循环缓冲区
        
        // 离开临界区，释放互斥锁
        sem_post(&mutex);
        // 增加空位数量信号量
        sem_post(&empty);
        
        // 模拟消费时间
        sleep(2);  // 消费比生产慢，观察效果
    }
    
    return NULL;
}

int main() {
    // 线程标识符
    pthread_t producers[2];  // 2个生产者线程
    pthread_t consumers[2];  // 2个消费者线程
    
    // 生产者和消费者ID
    int producer_ids[2] = {1, 2};
    int consumer_ids[2] = {1, 2};
    
    printf("=== 生产者-消费者问题模拟开始 ===\n");
    printf("缓冲区大小: %d\n", BUFFER_SIZE);
    printf("生产者数量: 2，消费者数量: 2\n\n");
    
    // 初始化信号量
    sem_init(&mutex, 0, 1);           // 互斥信号量，初值为1
    sem_init(&empty, 0, BUFFER_SIZE); // 空位信号量，初值为缓冲区大小
    sem_init(&full, 0, 0);            // 产品信号量，初值为0
    
    // 创建生产者线程
    for(int i = 0; i < 2; i++) {
        if(pthread_create(&producers[i], NULL, producer, &producer_ids[i]) != 0) {
            printf("创建生产者线程%d失败\n", i+1);
            exit(1);
        }
    }
    
    // 创建消费者线程
    for(int i = 0; i < 2; i++) {
        if(pthread_create(&consumers[i], NULL, consumer, &consumer_ids[i]) != 0) {
            printf("创建消费者线程%d失败\n", i+1);
            exit(1);
        }
    }
    
    // 等待所有生产者线程结束
    for(int i = 0; i < 2; i++) {
        pthread_join(producers[i], NULL);
        printf("生产者%d线程结束\n", i+1);
    }
    
    // 等待所有消费者线程结束
    for(int i = 0; i < 2; i++) {
        pthread_join(consumers[i], NULL);
        printf("消费者%d线程结束\n", i+1);
    }
    
    // 销毁信号量
    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    
    printf("\n=== 所有线程执行完毕，程序结束 ===\n");
    
    return 0;
}