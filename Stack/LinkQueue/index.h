//
// Created by J Z on 2022/9/6.
//
typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} LinkNode;

typedef struct {
    LinkNode *rear, *front;
} LinkQueue;

bool isEmpty(LinkQueue queue);

bool initQueue(LinkQueue &queue);

bool pop(LinkQueue &queue, int &data);

bool push(LinkQueue &queue, int data);

bool getFront(LinkQueue queue, int &data);

int length(LinkQueue queue);