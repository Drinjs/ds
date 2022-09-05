//
// Created by J Z on 2022/9/6.
//
#include "index.h"
#include "iostream"

using namespace std;

bool isEmpty(LinkQueue queue) {
    return (queue.front == queue.rear);
}

bool initQueue(LinkQueue &queue) {
    try {
        LinkNode *fp = (LinkNode *) new LinkNode;
        fp->next = nullptr;
        queue.front = queue.rear = fp;
        return true;
    } catch (...) {
        return false;
    }
}

bool push(LinkQueue &queue, int data) {
    try {
        LinkNode *tp = (LinkNode *) new LinkNode;
        tp->data = data;
        tp->next = nullptr;
        queue.rear->next = tp;
        queue.rear = tp;
        return true;
    } catch (...) {
        return false;
    }
}

bool pop(LinkQueue &queue, int &data) {
    if (isEmpty(queue)) {
        return false;
    }
    try {
        LinkNode *node = queue.front->next;
        data = node->data;
        queue.front->next = node->next;
        if (node->next == nullptr) {
            queue.rear = queue.front;
        }
        delete node;
        return true;
    } catch (...) {
        return false;
    }
}

bool getFront(LinkQueue queue, int &data) {
    if (isEmpty(queue)) {
        return false;
    }
    data = queue.front->next->data;
    return true;
}

int length(LinkQueue queue) {
    LinkNode *node = queue.front->next;
    int len = 0;
    while (node != nullptr) {
        len++;
        node = node->next;
    }
    return len;
}

int main() {
    LinkQueue queue;
    initQueue(queue);
    if (isEmpty(queue)) {
        cout << "快来看，这个空队列～" << endl;
    }

    int pushData = -1;
    cout << "进去吧你， " << endl;
    cin >> pushData;
    while (pushData != 999) {
        push(queue, pushData);
        cout << "进去吧你， " << endl;
        cin >> pushData;
    }

    cout << "队列长度为：" << length(queue) << endl;

    int popData = -1;
    cout << "出来吧你， ";
    while (!isEmpty(queue)) {
        pop(queue, popData);
        cout << popData << " ";
    }
    cout << endl;

    if (!pop(queue, popData)) {
        cout << "空队列无法出队！" << endl;
    }
    return 0;
}
