//
// Created by J Z on 2022/8/31.
//

#include "index.h"
#include "iostream"

using namespace std;

void initStack(LStack &LS) {
    LS = nullptr;
}

int length(LStack LS) {
    int len = 0;
    if (LS == nullptr) {
        return len;
    }

    LinkStack *p = LS;
    while (p != nullptr) {
        len++;
        p = p->next;
    }
    return len;
}

bool isFull(LStack LS) {
    return (length(LS) == MaxSize);
    s
}

bool push(LStack &LS, int &data) {
    try {
        LinkStack *p = (LinkStack *) new LinkStack;
        p->data = data;
        p->next = LS;
        LS = p;
        return true;
    } catch (...) {
        return false;
    }
}

bool pop(LStack &LS, int &data) {
    try {
        data = LS->data;
        LinkStack *p = LS;
        LS = p->next;
        p = nullptr;
        return true;
    } catch (...) {
        return false;
    }
}

void getTop(LStack LS, int &data) {
    data = LS->data;
}

bool isEmpty(LStack stack) {
    return (stack == nullptr);
}

int main() {
    LStack stack;
    initStack(stack);
    if (isEmpty(stack)) {
        cout << "快来看，这个空栈～" << endl;
    }
    int pushData = -1;
    cout << "进去吧你， " << endl;
    cin >> pushData;
    while (pushData != 999 && length(stack) < MaxSize) {
        push(stack, pushData);
        cout << "进去吧你， " << endl;
        cin >> pushData;
    }

    int topData = -1;
    getTop(stack, topData);
    if (topData != -1) {
        cout << "栈顶元素为： " << topData << endl;
    }

    int popData = -1;
    cout << "出来吧你， ";
    while (stack != nullptr) {
        pop(stack, popData);
        cout << popData << " ";
    }
    cout << endl;

    return 0;
}