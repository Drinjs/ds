//
// Created by J Z on 2022/9/4.
//

#include "index.h"
#include "iostream"

using namespace std;

bool isEmpty(SqQueue SQ) {
    return (SQ.front == SQ.rear);
}

bool isFull(SqQueue SQ) {
    return ((SQ.rear + 1) % MaxSize == SQ.front);
}

bool initQueue(SqQueue &queue) {
    queue.front = queue.rear = 0;
}

bool push(SqQueue &queue, int data) {
    if (isFull(queue)) {
        return false;
    }
    queue.data[queue.rear++] = data;
    queue.rear %= MaxSize;
    return true;
}

bool pop(SqQueue &queue, int &data) {
    if (isEmpty(queue)) {
        return false;
    }

    data = queue.data[queue.front++];
    queue.front %= MaxSize;
    return true;
}

bool getFront(SqQueue queue, int &data) {
    if (isEmpty(queue)) {
        return false;
    }
    data = queue.data[queue.front];
    return true;
}

int main() {
    SqQueue queue;
    initQueue(queue);
    if (isEmpty(queue)) {
        cout << "快来看，这个空队列～" << endl;
    }

    int pushData = -1;
    cout << "进去吧你， " << endl;
    cin >> pushData;
    while (!isFull(queue) && pushData != 999) {
        push(queue, pushData);
        cout << "进去吧你， " << endl;
        cin >> pushData;
    }
    if (!push(queue, pushData)) {
        cout << "满队列无法入队！" << endl;
    }

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
