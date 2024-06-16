#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MaxSize 100
typedef char ElemType;
typedef struct {
    ElemType data[MaxSize];
    int front, rear; // 队首和队尾指针应该在同一行
} SqQueue; // 结构体定义后应该有分号

// 声明环形队列类型
void InitQueue(SqQueue *&q) {
    q = (SqQueue *)malloc(sizeof(SqQueue));
    q->front = q->rear = 0;
}

// 销毁队列q
void DestroyQueue(SqQueue *&q) {
    free(q);
}

// 判断队列q是否空
bool QueueEmpty(SqQueue *q) {
    return (q->front == q->rear);
}

// 进队
bool enQueue(SqQueue *&q, ElemType e) {
    if ((q->rear + 1) % MaxSize == q->front)
        return false;
    q->rear = (q->rear + 1) % MaxSize;
    q->data[q->rear] = e;
    return true;
}

// 出队
bool deQueue(SqQueue *&q, ElemType &e) {
    if (q->front == q->rear)
        return false;
    q->front = (q->front + 1) % MaxSize;
    e = q->data[q->front];
    return true;
}

