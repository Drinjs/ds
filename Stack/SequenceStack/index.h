//
// Created by J Z on 2022/8/30.
//
#define MaxSize 10
typedef struct {
    int data[MaxSize];
    int top;
} SqStack;

bool isEmpty(SqStack stack);

bool isFull(SqStack stack);

bool initStack(SqStack &stack);

bool pop(SqStack &stack, int &data);

bool push(SqStack &stack, int data);

bool getTop(SqStack stack, int &data);