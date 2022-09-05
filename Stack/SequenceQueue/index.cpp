//
// Created by J Z on 2022/9/4.
//

#include "index.h"
#include "iostream"

using namespace std;

bool isEmpty(SqQueue SQ) {
    return (SQ.front == SQ.rear && SQ.tag == -1);
}

bool isFull(SqQueue SQ) {
    return (SQ.rear == SQ.front && SQ.tag == 1);
}

bool initQueue(SqQueue &queue) {
    queue.front = queue.rear = 0;
    queue.tag = -1;
}

bool push(SqQueue &queue, int data) {
    if (isFull(queue)) {
        return false;
    }
    queue.data[queue.rear++] = data;
    queue.rear %= MaxSize;
    queue.tag = 1;
    return true;
}

bool pop(SqQueue &queue, int &data) {
    if (isEmpty(queue)) {
        return false;
    }

    data = queue.data[queue.front++];
    queue.front %= MaxSize;
    queue.tag = -1;
    return true;
}

bool getFront(SqQueue queue, int &data) {
    if (isEmpty(queue)) {
        return false;
    }
    data = queue.data[queue.front];
    return true;
}

int length(SqQueue queue) {
    if (isFull(queue)) {
        return MaxSize;
    }
    return (queue.rear + MaxSize - queue.front) % MaxSize;
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
