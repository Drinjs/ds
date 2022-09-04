//
// Created by J Z on 2022/8/30.
//

#include "index.h"
#include "iostream"

using namespace std;

bool isEmpty(SqStack stack) {
    return (stack.top == -1);
}

bool isFull(SqStack stack) {
    return (stack.top == MaxSize - 1);
}

bool initStack(SqStack &stack) {
    stack.top = -1;
}

bool pop(SqStack &stack, int &data) {
    if (isEmpty(stack)) {
        cout << "空栈，别搞事!" << endl;
        return false;
    }

    data = stack.data[stack.top--];
    return true;
}

bool push(SqStack &stack, int data) {
    if (isFull(stack)) {
        cout << "满栈，别搞事!" << endl;
        return false;
    }

    stack.data[++stack.top] = data;
    return true;
}

bool getTop(SqStack stack, int &data) {
    if (isEmpty(stack)) {
        cout << "空栈，别搞事!" << endl;
        return false;
    }
    data = stack.data[stack.top];
    return true;
}

int main() {
    SqStack stack;
    initStack(stack);
    if (isEmpty(stack)) {
        cout << "快来看，这个空栈～" << endl;
    }

    int pushData = -1;
    cout << "进去吧你， " << endl;
    cin >> pushData;
    while (!isFull(stack) && pushData != 999) {
        push(stack, pushData);
        cout << "进去吧你， " << endl;
        cin >> pushData;
    }
    push(stack, pushData);

    int popData = -1;
    cout << "出来吧你， ";
    while (!isEmpty(stack)) {
        pop(stack, popData);
        cout << popData << " ";
    }
    cout << endl;

    pop(stack, popData);
    cout << "栈顶指针为： " << stack.top << endl;
    return 0;
}