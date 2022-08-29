//
// Created by J Z on 2022/8/29.
//

#include "index.h"
#include "iostream"

using namespace std;

void initLinkList(CDNHPList &CDL) {
    CDL = nullptr;
}

bool isEmpty(CDNHPList CDL) {
    return (CDL == nullptr);
}

int length(CDNHPList CDL) {
    CDNHPNode *p = CDL;
    int len = 1;
    while (p->next != CDL) {
        len++;
        p = p->next;
    }
    return len;
}

CDNHPList List_HeadInsert(CDNHPList &CDL) {
    int x;
    CDL = (CDNHPNode *) new CDNHPNode;
    cout << "输入要添加的元素至头部～" << endl;
    cin >> x;
    CDL->data = x;
    CDL->next = CDL;
    CDL->prior = CDL;
    cout << "输入要添加的元素至头部～" << endl;
    cin >> x;
    while (x != 999) {
        CDNHPNode *q = (CDNHPNode *) new CDNHPNode;
        q->data = x;
        q->next = CDL;
        q->prior = CDL->prior;
        CDL->prior->next = q;
        CDL->prior = q;
        CDL = q;
        cout << "继续输入要添加的元素至头部～" << endl;
        cin >> x;
    }
}

CDNHPList List_TailInsert(CDNHPList &CDL) {
    int x;
    CDL = (CDNHPNode *) new CDNHPNode;
    cout << "输入要添加的元素至尾部～" << endl;
    cin >> x;
    CDL->data = x;
    CDL->next = CDL;
    CDL->prior = CDL;
    cout << "输入要添加的元素至尾部～" << endl;
    cin >> x;
    while (x != 999) {
        CDNHPNode *q = (CDNHPNode *) new CDNHPNode;
        q->data = x;
        q->prior = CDL->prior;
        CDL->prior->next = q;
        q->next = CDL;
        CDL->prior = q;
        cout << "继续输入要添加的元素至尾部～" << endl;
        cin >> x;
    }
}

void print(CDNHPList CDL) {
    if (!isEmpty(CDL)) {
        CDNHPNode *p = CDL;
        cout << "双向链表为： ";
        while (p->next != CDL) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << p->data << " ";
        cout << endl;
    } else {
        cout << "空链表" << endl;
    }
}

CDNHPNode *getItem(CDNHPList CDL, int i) {
    if (i < 1 || i > length(CDL) || CDL == nullptr) {
        return nullptr;
    }

    CDNHPNode *p = CDL;
    int j = 1;
    while (j < i) {
        j++;
        p = p->next;
    }
    return p;
}

CDNHPNode *locateItem(CDNHPList CDL, int data) {
    if (CDL == nullptr) {
        return nullptr;
    }

    CDNHPNode *p = CDL;
    while (p->data != data && p->next != CDL) {
        p = p->next;
        if (p->next == CDL && p->data != data) {
            p = nullptr;
        }
    }
    return p;
}

bool insertBefore(CDNHPList &CDL, int i, int data) {
    if (i < 1 || i > length(CDL)) {
        return false;
    }

    CDNHPNode *p = getItem(CDL, i);
    if (p) {
        return insertPrevNode(p, data);
    } else {
        return false;
    }
}

bool insert(CDNHPList &CDL, int i, int data) {
    if (i < 1 || i > length(CDL)) {
        return false;
    }


    CDNHPNode *p = getItem(CDL, i);
    if (p) {
        return insertNextNode(p, data);
    } else {
        return false;
    }
}

bool insertPrevNode(CDNHPNode *p, int data) {
    if (p == nullptr) {
        return false;
    }

    try {
        CDNHPNode *node = (CDNHPNode *) new CDNHPNode;
        node->data = data;
        p->prior->next = node;
        node->prior = p->prior;
        node->next = p;
        p->prior = node;
        return true;
    } catch (...) {
        return false;
    }
}

bool insertNextNode(CDNHPNode *p, int data) {
    if (p == nullptr) {
        return false;
    }

    try {
        CDNHPNode *node = (CDNHPNode *) new CDNHPNode;
        node->data = data;
        node->next = p->next;
        p->next->prior = node;
        p->next = node;
        node->prior = p;
        return true;
    } catch (...) {
        return false;
    }
}

bool remove(CDNHPList &CDL, int i, int &data) {
    if (i < 1 || i > length(CDL)) {
        return false;
    }
    CDNHPNode *p = getItem(CDL, i);
    if (p) {
        data = p->data;
        deleteNode(CDL, p);
        delete p;
        return true;
    } else {
        return false;
    }
}

bool deleteNode(CDNHPList &CDL, CDNHPNode *p) {
    if (p == nullptr) {
        return false;
    }
    p->next->prior = p->prior;
    p->prior->next = p->next;
    return true;
}

bool headInsert(CDNHPList &CDL, int data) {
    try {
        CDNHPNode *p = (CDNHPNode *) new CDNHPNode;
        p->data = data;
        CDL->prior->next = p;
        p->next = CDL;
        p->prior = CDL->prior;
        CDL->prior = p;
        CDL = p;
        return true;
    } catch (...) {
        throw false;
    }
}

bool revert(CDNHPList &CDL) {
    CDNHPNode *p = CDL->next;
    int len = 0;
    while (p != nullptr && len != length(CDL)) {
        try {
            bool flag = deleteNode(CDL, p);
            CDNHPNode *t = p;
            if (!flag) {
                return false;
            }
            len++;
            headInsert(CDL, p->data);
            p = p->next;
            delete t;
        } catch (...) {
            return false;
        }
    }
    return true;
}

int main() {
    CDNHPList CDL;
    initLinkList(CDL);

    if (isEmpty(CDL)) {
        cout << "空链表" << endl;
    } else {
        cout << "非空链表" << endl;
    }
    List_TailInsert(CDL);
    print(CDL);

    cout << "链表长度为： " << length(CDL) << endl;

    cout << "链表第二位： " << getItem(CDL, 2)->data << endl;

    cout << " ========================================== " << endl;
    int searchItem = -1;
    cout << "输入要查询的链表元素值： ";
    cin >> searchItem;
    CDNHPNode *p = locateItem(CDL, searchItem);
    if (p == nullptr) {
        cout << "未找到指定元素" << endl;
    } else {
        cout << "链表元素首个数据项等于" << p->data << "的地址为： " << &p << endl;
    }

    cout << " ========================================== " << endl;
    cout << "即将在位序2的元素后插插数据项为2的节点～ " << endl;
    insert(CDL, 2, 2);
    print(CDL);

    cout << " ========================================== " << endl;
    cout << "即将在位序3的元素前插数据项为3的节点～ " << endl;
    insertBefore(CDL, 3, 3);
    print(CDL);

    cout << " ========================================== " << endl;
    int data = -1;
    cout << "开始删除第5位节点:" << endl;
    if (remove(CDL, 5, data)) {
        cout << "删除的元素为： " << data << endl;
    } else {
        cout << "未找到指定元素" << endl;
    }
    cout << "当前表长： " << length(CDL) << endl;
    print(CDL);

    cout << " ========================================== " << endl;
    cout << "双向链表开始取反操作： " << endl;
    revert(CDL);
    print(CDL);

    return 0;
}