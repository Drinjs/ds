//
// Created by J Z on 2022/8/21.
//
#include "iostream"

using namespace std;

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
    int length;
}LinkNode, *LinkList;

bool isEmpty(LinkList &L) {
    if(L->next == NULL) {
        return true;
    }
    return false;
}

bool initLinkList(LinkList &L) {
    try {
        L = (LinkNode *) new LinkNode;
        L->next = NULL;
        L->length = 0;
        return true;
    } catch (...) {
        return false; // 内存不足
    }
}

/**
 * @desc 按位查找
 * @param L
 * @param i
 * @return
 */
LinkNode * getItem(LinkList L, int i) {
    if ( i < 0) {
        return NULL;
    }
    // 根据目标位置查找当前节点
    LinkNode *p;
    int j = 0;
    p = L;
    while(p != NULL && j < i) {
        p = p->next;
        j++;
    }
    return  p;
}

bool insertNextNode(LinkNode *p, int data) {
    if(p == NULL) {
        return false;
    }

    try {
        LinkNode *linkNode = (LinkNode *) new LinkNode; // 构建插入节点
        linkNode->data = data;
        linkNode->next = p->next;
        p->next = linkNode;
        return true;
    } catch (...) {
        return false;
    }
}

bool insertPrevNode(LinkNode *p, int data) {
    if(p == NULL) {
        return false;
    }
    try {
        LinkNode *linkNode = (LinkNode *) new LinkNode; // 构建插入节点
        linkNode->next = p->next;
        p->next = linkNode;
        linkNode->data = p->data;
        p->data = data;
        return true;
    } catch (...) {
        return false;
    }
}

bool insert(LinkList &L, int i, int data) {
    LinkNode *p = getItem(L, i-1);
    if(p) {
        bool flag = insertNextNode(p, data);
        if(flag) {
            L->length++;
        }
        return flag;
    } else {
        return false;
    }
}

bool insertBefore(LinkList &L, int i, int data) {
    LinkNode *p = getItem(L, i-1);
    if(p) {
        bool flag = insertPrevNode(p, data);
        if(flag) {
            L->length++;
        }
        return flag;
    } else {
        return false;
    }
}

void print(LinkList L) {
    if(isEmpty(L)) {
        cout << "空链表" <<endl;
    } else {
        cout << "遍历链表： " <<endl;
        LinkNode *p = L->next;
        while(p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }

        cout << endl;
    }
}

bool deleteNode(LinkList &L, LinkNode *p, int &data) {
    if(p == NULL) {
        return false;
    }
    data = p->data;
    if(p->next == NULL) { // 如果是末尾节点时， 则需要遍历链表 时间复杂度为O(n)
        LinkNode *o = L;
        LinkNode *prevNode = L;
        bool flag = false;
        while(o != NULL) {
            prevNode = o;
            o = o->next;
            if(o == p) {
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

bool remove(LinkList &L, int i, int &data) {
    LinkNode *p = getItem(L, i);
    if(p) {
        bool flag = deleteNode(L, p, data);
        if(flag) {
            L->length--;
        }
        return flag;
    } else {
        return false;
    }
}

LinkNode * locateItem(LinkList L, int data) {
    LinkNode *p = L->next;
    while(p != NULL && p->data != data) {
        p = p->next;
    }
    return p;
}

int length(LinkList L) {
    return L->length;
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
        p->next = L->next;
        L->next = p;
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
    LinkNode *p = L->next;
    int data = -1;
    int len = 0;
    while(p != NULL && len != L->length) {
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

/**
 *@desc 尾插法创建单链表
 * @param L
 * @return
 */
LinkList List_TailInsert(LinkList &L) {
    int x;
    L = (LinkNode *) new LinkNode;
    LinkNode *s, *t = L;
    cout << "输入要添加的元素至尾部～" << endl;
    cin >> x;
    while(x != 999) {
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

LinkList List_HeadInsert(LinkList &L) {
    int x;
    L = (LinkNode *) new LinkNode;
    L->next = NULL;
    L->length = 0;
    LinkNode *p = L;
    cout << "输入要添加的元素至头部～" << endl;
    cin >> x;
    while(x != 999) {
        LinkNode *s = (LinkNode *) new LinkNode;
        s->data = x;
        s->next = p->next;
        p->next = s;
        L->length++;
        cout << "继续输入要添加的元素至头部～" << endl;
        cin >> x;
    }
    return L;
}

int main() {
    LinkList L;
    initLinkList(L);

//    List_TailInsert(L);
    List_HeadInsert(L);
    print(L);

    insertBefore(L, 2, 2);
    print(L);

    int removeItem = -1;
    remove(L, 3, removeItem);
    print(L);

    int searchItem = -1;
    cout << "输入要查询的链表元素值： ";
    cin >> searchItem;
    LinkNode *p = locateItem(L, searchItem);
    if(p == NULL) {
        cout << "未找到指定元素" << endl;
    } else {
        cout << "链表元素" << p->data << "的地址为： " << &p << endl;
    }
    cout << "当前表长： " << length(L) << endl;

    cout << "单向链表开始取反操作： " << endl;
    revert(L);
    print(L);
}
