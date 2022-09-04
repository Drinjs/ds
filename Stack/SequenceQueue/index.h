//
// Created by J Z on 2022/9/4.
//
#define MaxSize 10

typedef struct {
    int data[MaxSize];
    int front, rear; // 队头指针 队尾指针
} SqQueue;

bool isEmpty(SqQueue queue);

bool isFull(SqQueue queue);

bool initQueue(SqQueue &queue);

bool pop(SqQueue &queue, int &data);

bool push(SqQueue &queue, int data);

bool getFront(SqQueue queue, int &data);