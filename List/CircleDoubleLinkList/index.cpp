//
// Created by J Z on 2022/8/28.
//
#include "CDLL.h"
#include "iostream"

using namespace std;

bool isEmpty(CDList CDL) {
    return (CDL->next == CDL && CDL->prior == CDL);
}

bool initLinkList(CDList &CDL) {
    try {
        CDL = (CDNode *) new CDNode; // 分配一个头节点
        CDL->next = CDL;
        CDL->prior = CDL;
        return true;
    } catch (...) {
        return false; // 内存不足
    }
}

CDList List_HeadInsert(CDList &CDL) {
    int x;
    CDL = (CDNode *) new CDNode;
    CDL->next = CDL;
    CDL->prior = CDL;
    CDNode *p = CDL;
    cout << "输入要添加的元素至头部～" << endl;
    cin >> x;
    while (x != 999) {
        CDNode *s = (CDNode *) new CDNode;
        s->data = x;
        s->next = p->next;
        s->prior = p;
        p->next->prior = s;
        p->next = s;
        cout << "继续输入要添加的元素至头部～" << endl;
        cin >> x;
    }
    return CDL;
}

CDList List_TailInsert(CDList &CDL) {
    int x;
    CDL = (CDNode *) new CDNode;
    CDL->next = CDL;
    CDL->prior = CDL;
    CDNode *p, *t = CDL;
    cout << "输入要添加的元素至尾部～" << endl;
    cin >> x;
    while (x != 999) {
        p = (CDNode *) new CDNode;
        p->data = x;
        p->prior = t;
        p->next = t->next;
        t->next = p;
        CDL->prior = p;
        t = p;
        cout << "继续输入要添加的元素至尾部～" << endl;
        cin >> x;
    }
    return CDL;
}

void print(CDList CDL) {
    if (!isEmpty(CDL)) {
        CDNode *p = CDL->next;
        cout << "双向链表为： ";
        while (p != CDL) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    } else {
        cout << "空链表" << endl;
    }
}

CDNode *getItem(CDList CDL, int i) {
    if (i < 0 || i > length(CDL)) {
        return nullptr;
    }

    CDNode *p = CDL->next;
    int j = 0;
    while (p != CDL & j < i - 1) {
        p = p->next;
        j++;
    }
    return p;
}

bool insertNextNode(CDNode *p, int data) {
    if (p == nullptr) {
        return false;
    }

    try {
        CDNode *linkNode = (CDNode *) new CDNode; // 构建插入节点
        linkNode->data = data;
        linkNode->next = p->next;
        p->next->prior = linkNode;
        p->next = linkNode;
        linkNode->prior = p;
        return true;
    } catch (...) {
        return false;
    }
}

bool insertPrevNode(CDNode *p, int data) {
    if (p == nullptr) {
        return false;
    }
    try {
        CDNode *linkNode = (CDNode *) new CDNode; // 构建插入节点
        linkNode->data = data;
        linkNode->prior = p->prior;
        p->prior->next = linkNode;
        linkNode->next = p;
        p->prior = linkNode;
        return true;
    } catch (...) {
        return false;
    }
}

bool insert(CDList &CDL, int i, int data) {
    if (i < 0 || i > length(CDL)) {
        return false;
    }
    CDNode *p = getItem(CDL, i);
    if (p) {
        return insertNextNode(p, data);
    } else {
        return false;
    }
}

bool insertBefore(CDList &CDL, int i, int data) {
    if (i < 0 || i > length(CDL)) {
        return false;
    }
    CDNode *p = getItem(CDL, i);
    if (p) {
        return insertPrevNode(p, data);
    } else {
        return false;
    }
}

bool deleteNode(CDList &CDL, CDNode *p, int &data) {
    if (p == nullptr) {
        return false;
    }
    data = p->data;
    CDNode *q = p->prior;
    q->next = p->next;
    p->next->prior = q;
    return true;
}

bool remove(CDList &CDL, int i, int &data) {
    if (i < 0 || i > length(CDL)) {
        return false;
    }
    CDNode *p = getItem(CDL, i);
    if (p) {
        deleteNode(CDL, p, data);
        delete p;
        return true;
    } else {
        return false;
    }
}

CDNode *locateItem(CDList CDL, int data) {
    CDNode *p = CDL->next;
    while (p->data != data) {
        p = p->next;
        if (p == CDL && p->data != data) {
            p = nullptr;
            break;
        }
    }
    return p;
}

int length(CDList CDL) {
    CDNode *p = CDL->next;
    int len = 0;
    while (p != CDL) {
        len++;
        p = p->next;
    }
    return len;
}

/**
 * desc 向链表头部插入数据
 * @param L
 * @param data
 * @return
 */
bool headInsert(CDList &CDL, int data) {
    try {
        CDNode *p = (CDNode *) new CDNode;
        p->data = data;
        CDL->next->prior = p;
        p->next = CDL->next;
        p->prior = CDL;
        CDL->next = p;
        return true;
    } catch (...) {
        throw false;
    }
}

/**
 * @desc 链表倒序（自倒序）
 * @param L
 * @return
 */
bool revert(CDList &CDL) {
    CDNode *p = CDL->next->next;
    int data = -1;
    int len = 1;
    while (p != nullptr && len != length(CDL)) {
        try {
            bool flag = deleteNode(CDL, p, data);
            cout << "删除的数据为" << data << endl;
            if (!flag) {
                return false;
            }
            len++;
            headInsert(CDL, data);
            p = p->next;
        } catch (...) {
            return false;
        }
    }
    return true;
}

int main() {
    CDList CDL;
    initLinkList(CDL);
    if (isEmpty(CDL)) {
        cout << "空链表" << endl;
    } else {
        cout << "非空链表" << endl;
    }
    List_TailInsert(CDL);
    print(CDL);

    cout << "链表第二位： " << getItem(CDL, 2)->data << endl;

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
    int searchItem = -1;
    cout << "输入要查询的链表元素值： ";
    cin >> searchItem;
    CDNode *p = locateItem(CDL, searchItem);
    if (p == nullptr) {
        cout << "未找到指定元素" << endl;
    } else {
        cout << "链表元素首个数据项等于" << p->data << "的地址为： " << &p << endl;
    }

    cout << " ========================================== " << endl;
    cout << "双向链表开始取反操作： " << endl;
    revert(CDL);
    print(CDL);

    return 0;
};