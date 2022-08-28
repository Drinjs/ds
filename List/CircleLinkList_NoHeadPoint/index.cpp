//
// Created by J Z on 2022/8/28.
//

#include "CircleLinkList.h"
#include "iostream"

using namespace std;

void initLinkList(CList &CL) {
    CL = nullptr;
}

bool isEmpty(CList CL) {
    return (CL == nullptr);
}

CNode *getItem(CList CL, int i) {
    if (i < 0 || i > length(CL) - 1) {
        return nullptr;
    }

    CNode *p = CL;
    int j = 0;
    while (j < i - 1) {
        j++;
        p = p->next;
    }

    return p;
}

int length(CList CL) {
    int len = 1;
    CNode *p = CL->next;
    while (p != CL) {
        len++;
        p = p->next;
    }
    return len;
}

CList List_HeadInsert(CList &CL) {
    int x;
    CL = (CNode *) new CNode;
    cout << "输入要添加的元素至头部～" << endl;
    cin >> x;
    CL->data = x;
    CL->next = CL;
    cout << "继续输入要添加的元素至头部～" << endl;
    cin >> x;
    CNode *t = &*CL; // 尾指针固定指向尾节点 头插法过程中尾指针地址不会被删除
    while (x != 999) {
        CNode *s = (CNode *) new CNode;
        s->data = x;
        s->next = CL;
        t->next = s;
        CL = s;
        cout << "继续输入要添加的元素至头部～" << endl;
        cin >> x;
    }
    return CL;
}

CList List_TailInsert(CList &CL) {
    int x;
    CL = (CNode *) new CNode;
    CNode *p, *t = CL; // t尾指针
    cout << "输入要添加的元素至尾部～" << endl;
    cin >> x;
    CL->data = x;
    CL->next = CL;
    cout << "继续输入要添加的元素至尾部～" << endl;
    cin >> x;
    while (x != 999) {
        p = (CNode *) new CNode;
        p->data = x;
        t->next = p;
        p->next = CL;
        t = p;
        cout << "继续输入要添加的元素至尾部～" << endl;
        cin >> x;
    }
    return CL;
}

void print(CList CL) {
    CNode *p = CL;
    cout << "输出循环单向链表：" << endl;
    while (p->next != CL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << p->data << endl;
}

CNode *locateItem(CList CL, int data) {
    CNode *p = CL;
    int len = 0;
    while (p->data != data && len < length(CL)) {
        if (len == length(CL) - 1 && p->data != data) {
            p = nullptr;
            break;
        }
        len++;
        p = p->next;
    }
    return p;
}

bool insertBefore(CList &CL, int i, int data) {
    if (i < 1 || i > length(CL)) { // 非法区间
        return false;
    }

    CNode *p = getItem(CL, i); // 获取指定节点 另一种思路：i前插等于在i-1的节点后插操作

    if (p) {
        return insertPrevNode(p, data);
    } else {
        return false;
    }
}

bool insert(CList &CL, int i, int data) {
    if (i < 0 || i > length(CL) - 1) { // 非法区间
        return false;
    }

    CNode *p = getItem(CL, i); // 获取指定节点
    if (p) {
        return insertNextNode(p, data);
    } else {
        return false;
    }
}

bool insertPrevNode(CNode *p, int data) {
    try {
        CNode *t = (CNode *) new CNode;
        t->data = p->data;
        p->data = data;
        t->next = p->next;
        p->next = t;
        return true;
    } catch (...) {
        return false;
    }
}

bool insertNextNode(CNode *p, int data) {
    try {
        CNode *t = (CNode *) new CNode;
        t->data = data;
        t->next = p->next;
        p->next = t;
        return true;
    } catch (...) {
        return false;
    }
}

bool remove(CList &CL, int i, int &data) {
    CNode *p = getItem(CL, i);
    if (p) {
        return deleteNode(CL, p, data);
    } else {
        return false;
    }
}

bool deleteNode(CList &CL, CNode *p, int &data) {
    try {
        data = p->data;
        CNode *q;
        if (p->next == CL) { // 尾节点 遍历一次 前置节点
            q = getItem(CL, length(CL) - 1);
            q->next = CL;
            delete p;
        } else {
            q = p->next;
            p->data = q->data;
            p->next = q->next;
            delete q;
        }
        return true;
    } catch (...) {
        return false;
    }
}

bool revert(CList &CL) {
    CNode *p = CL->next; // 从位序第二个节点开始（下标1的节点）
    int data = -1;
    int len = 1;
    while (len < length(CL)) {
        try {
            deleteNode(CL, p, data);
            len++;
            insertBefore(CL, 1, data);
        } catch (...) {
            return false;
        }
    }
    return true;
}

int main() {
    CList CL;
    initLinkList(CL);

    if (isEmpty(CL)) {
        cout << "空链表哦" << endl;
    }

    List_TailInsert(CL);
    print(CL);

    cout << " ========================================== " << endl;
    cout << "当前链表长度为： " << length(CL) << endl;

    cout << " ========================================== " << endl;
    cout << "即将在位序2的元素前插数据项为2的节点～ " << endl;
    insertBefore(CL, 2, 2);
    print(CL);


    cout << " ========================================== " << endl;
    cout << "即将在位序3的元素后插数据项为3的节点～ " << endl;
    insert(CL, 3, 3);
    print(CL);

    cout << " ========================================== " << endl;
    cout << "即将删除位序1的元素: ";
    int removeItem = -1;
    remove(CL, 1, removeItem);
    cout << removeItem << endl;
    print(CL);

    cout << " ========================================== " << endl;
    cout << "单向链表开始取反操作： " << endl;
    revert(CL);
    print(CL);

    cout << " ========================================== " << endl;
    int searchItem = -1;
    cout << "输入要查询的链表元素值： ";
    cin >> searchItem;
    CNode *p = locateItem(CL, searchItem);
    if (p == nullptr) {
        cout << "未找到指定元素" << endl;
    } else {
        cout << "链表元素" << p->data << "的地址为： " << &p << endl;
    }

    return 0;
}