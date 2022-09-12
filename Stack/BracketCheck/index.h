//
// Created by J Z on 2022/9/12.
//
#define MaxSize 10
typedef struct {
    char data[MaxSize];
    int top; // 栈顶指针
} SqStack;

void initStack(SqStack &stack); // 初始化栈

bool isEmpty(SqStack stack);

bool isFull(SqStack stack);

bool push(SqStack &stack, char s);

bool pop(SqStack &stack, char &o);