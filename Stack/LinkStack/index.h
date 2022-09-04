//
// Created by J Z on 2022/8/31.
//
#define MaxSize 5
typedef struct LinkStack {
    int data;
    struct LinkStack *next;
} *LStack;

int length(LStack stack);

void initStack(LStack &stack);

bool pop(LStack &stack, int &data);

bool push(LStack &stacks, int &data);

void getTop(LStack stack, int &data);

bool isEmpty(LStack stack);

bool isFull(LStack stack);