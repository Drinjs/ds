//
// Created by J Z on 2022/8/21.
//

#include "iostream"

using namespace std;

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
    int length;
} LinkNode, *LinkList;

bool isEmpty(LinkList &L) {
    return (L == NULL);
}

void initLinkList(LinkList &L) {
    L = NULL;
}

/**
 *@desc 尾插法创建单链表
 * @param L
 * @return
 */
LinkList List_TailInsert(LinkList &L) {
    int x;
    L = (LinkNode *) new LinkNode;
    LinkNode *s, *t = L; // t为尾指针 s插入节点
    cout << "输入要添加的元素至尾部～" << endl;
    cin >> x;
    L->data = x;
    L->next = NULL;
    L->length = 1;
//    t = L;
    cout << "继续输入要添加的元素至尾部～" << endl;
    cin >> x;
    while (x != 999) {
        s = (LinkNode *) new LinkNode;
        s->data = x;
        t->next = s;
        t = s;
        L->length++;
        cout << "继续输入要添加的元素至尾部～" << endl;
        cin >> x;
    }

    t->next = NULL;
    return L;
}

/**
 *@desc 头插法创建单链表
 * @param L
 * @return
 */
LinkList List_HeadInsert(LinkList &L) {
    int x;
    L = (LinkNode *) new LinkNode;
    cout << "输入要添加的元素至头部～" << endl;
    cin >> x;
    L->data = x;
    L->next = NULL;
    L->length = 1;
    cout << "继续输入要添加的元素至头部s～" << endl;
    cin >> x;
    while (x != 999) {
        LinkNode *s = (LinkNode *) new LinkNode;
        s->data = x;
        s->next = L;
        L = s;
        L->length++;
        cout << "继续输入要添加的元素至头部～" << endl;
        cin >> x;
    }
    return L;
}

void print(LinkList L) {
    if (isEmpty(L)) {
        cout << "空链表" << endl;
    } else {
        cout << "遍历链表： " << endl;
        LinkNode *p = L;
        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }

        cout << endl;
    }
}

/**
 * @desc 获取链表长度
 * @param L
 * @return
 */
int length(LinkList L) {
    return L->length;
}

/**
 * @desc 按位查找
 * @param L
 * @param i
 * @return
 */
LinkNode *getItem(LinkList L, int i) {
    if (i < 0 || L == NULL || i > L->length) {
        return NULL;
    }

    // 根据目标位置查找当前节点
    LinkNode *p;
    int j = 1;
    p = L;
    while (p != NULL && j < i) { // 确保获得当前节点指针的方案： j = 1 & j < i 或者 j = 0 & j < i-1
        p = p->next;
        j++;
    }
    return p;
}

/**
 * @desc 后插节点
 * @param p
 * @param data
 * @return
 */
bool insertNextNode(LinkNode *p, int data) {
    if (p == NULL) {
        return false;
    }

    try {
        LinkNode *s = (LinkNode *) new LinkNode; // 构建插入节点
        s->data = data;
        s->next = p->next;
        p->next = s;
        return true;
    } catch (...) {
        return false;
    }
}

/**
 * @desc 前插节点
 * @param p
 * @param data
 * @return
 */
bool insertPrevNode(LinkNode *p, int data) {
    if (p == NULL) {
        return false;
    }
    try {
        LinkNode *s = (LinkNode *) new LinkNode; // 构建插入节点
        s->next = p->next;
        p->next = s; // 构建数据链

        s->data = p->data;
        p->data = data; // 交换数据项
        return true;
    } catch (...) {
        return false;
    }
}

/**
 * @desc 在i位后插数据项
 * @param L
 * @param i 表示在指定位序之后添加数据项
 * @param data
 * @return
 */
bool insert(LinkList &L, int i, int data) {
    if (i < 0) {
        return false;
    }
    // 表头直接插入数据项
    if (i == 0) {
        LinkNode *s = (LinkNode *) new LinkNode;
        s->data = data;
        s->next = L;
        L->length++;
        s->length = L->length;
        L = s;
        return true;
    }
    LinkNode *p = getItem(L, i); // 向位序i的位置之后插入数据项 则前驱节点为第i个数据项
    if (p) {
        bool flag = insertNextNode(p, data);
        if (flag) {
            L->length++;
        }
        return flag;
    } else {
        return false;
    }
}

/**
 * @desc 在i位前插数据项
 * @param L
 * @param i 表示在指定位序之前添加数据项
 * @param data
 * @return
 */
bool insertBefore(LinkList &L, int i, int data) {
    if (i < 1) {
        return false;
    }
    // 表头直接插入数据项
    if (i == 1) {
        LinkNode *s = (LinkNode *) new LinkNode;
        s->data = data;
        s->next = L;
        L->length++;
        s->length = L->length;
        L = s;
        return true;
    }

    LinkNode *p = getItem(L, i);
    if (p) {
        bool flag = insertPrevNode(p, data);
        if (flag) {
            L->length++;
        }
        return flag;
    } else {
        return false;
    }
}

/**
 * @desc 删除链表节点
 * @param L
 * @param p
 * @param data
 * @return
 */
bool deleteNode(LinkList &L, LinkNode *p, int &data) {
    if (p == NULL) {
        return false;
    }
    data = p->data;
    if (p->next == NULL) { // 如果是末尾节点时， 则需要遍历链表 时间复杂度为O(n)
        LinkNode *o = L;
        LinkNode *prevNode = L;
        bool flag = false;
        while (o != NULL) {
            prevNode = o;
            o = o->next;
            if (o == p) {
                prevNode->next = p->next;
                delete p;
                p = NULL;
                flag = true;
                break;
            }
        }
        return flag;
    }
    LinkNode *q = p->next;
    p->data = q->data;
    p->next = q->next;
    delete q;
    return true;
}

/**
 * @desc 删除指定位序的数据项
 * @param L
 * @param i
 * @param data
 * @return
 */
bool remove(LinkList &L, int i, int &data) {
    if (i < 1 || L == NULL) {
        return false;
    }
    // 删除表头 则重置头指针
    if (i == 1) {
        LinkNode *s = L;
        data = L->data;
        L = L->next;
        L->length--;
        delete s;
        return true;
    }

    LinkNode *p = getItem(L, i);
    if (p) {
        bool flag = deleteNode(L, p, data);
        if (flag) {
            L->length--;
        }
        return flag;
    } else {
        return false;
    }
}

/**
 * @desc 按值查找
 * @param L
 * @param data
 * @return
 */
LinkNode *locateItem(LinkList L, int data) {
    if (L == NULL) {
        return false;
    }
    LinkNode *p = L;
    while (p != NULL && p->data != data) {
        p = p->next;
    }
    return p;
}

/**
 * desc 向链表头部插入数据
 * @param L
 * @param data
 * @return
 */
bool headInsert(LinkList &L, int data) {
    try {
        LinkNode *p = (LinkNode *) new LinkNode;
        p->data = data;
        p->next = L;
        L = p;
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
bool revert(LinkList &L) {
    LinkNode *p = L;
    int data = -1;
    int len = 0;
    while (p != NULL && len != L->length) {
        try {
            bool flag = deleteNode(L, p, data);
            cout << "删除的数据为" << data << endl;
            if (!flag) {
                return false;
            }
            len++;
            headInsert(L, data);
        } catch (...) {
            return false;
        }
    }
    return true;
}

int main() {
    LinkList L;
    initLinkList(L);
    List_TailInsert(L);
    print(L);
    cout << getItem(L, 3)->data << endl;
    insert(L, 0, 11);
    print(L);
    insertBefore(L, 1, 10);
    print(L);
    cout << "当前链表长度为： " << L->length << endl;
    int removeData = -1;
    remove(L, 1, removeData);
    cout << "删除的数据为： " << removeData << endl;
    print(L);

    cout << "单向链表开始取反操作： " << endl;
    revert(L);
    print(L);
    return 0;
}