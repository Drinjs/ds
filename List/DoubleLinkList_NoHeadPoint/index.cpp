//
// Created by J Z on 2022/8/26.
//
#include "iostream"

using namespace std;

typedef struct DoubleLinkNode {
    int data;
    int length;
    struct DoubleLinkNode *next;
    struct DoubleLinkNode *prior;
} DoubleLinkNode, *DoubleLinkList;

bool isEmpty(DoubleLinkList &DL) {
    return (DL == NULL);
}

void initLinkList(DoubleLinkList &DL) {
    DL = NULL;
}

DoubleLinkList List_HeadInsert(DoubleLinkList &DL) {
    int x;
    DL = (DoubleLinkNode *) new DoubleLinkNode;
    cout << "输入要添加的元素至头部～" << endl;
    cin >> x;
    DL->data = x;
    DL->next = NULL;
    DL->length = 1;
    cout << "输入要添加的元素至头部～" << endl;
    cin >> x;
    while (x != 999) {
        DoubleLinkNode *s = (DoubleLinkNode *) new DoubleLinkNode;
        s->data = x;
        s->next = DL;
        DL->prior = s;
        DL = s;
        DL->length++;
        cout << "继续输入要添加的元素至头部～" << endl;
        cin >> x;
    }
    return DL;
}

DoubleLinkList List_TailInsert(DoubleLinkList &DL) {
    int x;
    DL = (DoubleLinkNode *) new DoubleLinkNode;
    cout << "输入要添加的元素至头部～" << endl;
    cin >> x;
    DL->data = x;
    DL->next = NULL;
    DL->length = 1;
    DoubleLinkNode *p, *t = DL;
    cout << "输入要添加的元素至尾部～" << endl;
    cin >> x;
    while (x != 999) {
        p = (DoubleLinkNode *) new DoubleLinkNode;
        p->data = x;
        p->prior = t;
        t->next = p;
        t = p;
        DL->length++;
        cout << "继续输入要添加的元素至尾部～" << endl;
        cin >> x;
    }
    t->next = NULL;
    return DL;
}

void print(DoubleLinkList DL) {
    if (isEmpty(DL)) {
        cout << "空链表" << endl;
    } else {
        DoubleLinkNode *p = DL;
        cout << "双向链表为： ";
        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
}

DoubleLinkNode *getItem(DoubleLinkList DL, int i) {
    if (i < 1 || i > DL->length) {
        return NULL;
    }

    DoubleLinkNode *p;
    int j = 1;
    p = DL;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

bool insertNextNode(DoubleLinkNode *p, int data) {
    if (p == NULL) {
        return false;
    }

    try {
        DoubleLinkNode *linkNode = (DoubleLinkNode *) new DoubleLinkNode; // 构建插入节点
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

bool insertPrevNode(DoubleLinkNode *p, int data) {
    if (p == NULL) {
        return false;
    }
    try {
        DoubleLinkNode *linkNode = (DoubleLinkNode *) new DoubleLinkNode; // 构建插入节点
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

bool insert(DoubleLinkList &DL, int i, int data) {
    if (i < 0 || i > DL->length) {
        return false;
    }
    // 表头直接插入数据项
    if (i == 0) {
        DoubleLinkNode *s = (DoubleLinkNode *) new DoubleLinkNode;
        s->data = data;
        DL->prior = s;
        s->next = DL;
        DL->length++;
        s->length = DL->length;
        DL = s;
        return true;
    }
    DoubleLinkNode *p = getItem(DL, i);
    if (p) {
        bool flag = insertNextNode(p, data);
        if (flag) {
            DL->length++;
        }
        return flag;
    } else {
        return false;
    }
}

bool insertBefore(DoubleLinkList &DL, int i, int data) {
    if (i < 1 || i > DL->length) {
        return false;
    }
    // 表头直接插入数据项
    if (i == 1) {
        DoubleLinkNode *s = (DoubleLinkNode *) new DoubleLinkNode;
        s->data = data;
        DL->prior = s;
        s->next = DL;
        DL->length++;
        s->length = DL->length;
        DL = s;
        return true;
    }
    DoubleLinkNode *p = getItem(DL, i);
    if (p) {
        bool flag = insertPrevNode(p, data);
        if (flag) {
            DL->length++;
        }
        return flag;
    } else {
        return false;
    }
}

bool deleteNode(DoubleLinkList &DL, DoubleLinkNode *p, int &data) {
    if (p == NULL) {
        return false;
    }
    data = p->data;
    DoubleLinkNode *q = p->prior;
    q->next = p->next;
    if (p->next != NULL) {
        p->next->prior = q;
    }
    return true;
}

bool remove(DoubleLinkList &DL, int i, int &data) {
    if (i < 1 || i > DL->length) {
        return false;
    }

    // 删除表头 则重置头指针
    if (i == 1) {
        DoubleLinkNode *s = DL;
        data = DL->data;
        DL = DL->next;
        DL->length--;
        return true;
    }

    DoubleLinkNode *p = getItem(DL, i);
    if (p) {
        deleteNode(DL, p, data);
        DL->length--;
        delete p;
        return true;
    } else {
        return false;
    }
}

DoubleLinkNode *locateItem(DoubleLinkList DL, int data) {
    DoubleLinkNode *p = DL;
    while (p != NULL && p->data != data) {
        p = p->next;
    }
    return p;
}

int length(DoubleLinkList DL) {
    return DL->length;
}

/**
 * desc 向链表头部插入数据
 * @param L
 * @param data
 * @return
 */
bool headInsert(DoubleLinkList &L, int data) {
    try {
        DoubleLinkNode *p = (DoubleLinkNode *) new DoubleLinkNode;
        p->data = data;
        L->prior = p;
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
bool revert(DoubleLinkList &DL) {
    DoubleLinkNode *p = DL->next;
    int data = -1;
    int len = 0;
    while (p != NULL && len != DL->length) {
        try {
            bool flag = deleteNode(DL, p, data);
            cout << "删除的数据为" << data << endl;
            if (!flag) {
                return false;
            }
            len++;
            headInsert(DL, data);
            p = p->next;
        } catch (...) {
            return false;
        }
    }
    delete p;
    return true;
}


int main() {
    DoubleLinkList DL;
    initLinkList(DL);
    isEmpty(DL);
    if (isEmpty(DL)) {
        cout << "空链表" << endl;
    } else {
        cout << "非空链表" << endl;
    }
    initLinkList(DL);
    List_TailInsert(DL);
    print(DL);

    cout << "链表第二位： " << getItem(DL, 2)->data << endl;

    insert(DL, 1, 2);
    print(DL);
    insertBefore(DL, 2, 11);
    print(DL);

    int data = -1;
    cout << "开始删除第10位节点:" << endl;
    if (remove(DL, 10, data)) {
        cout << "删除的元素为： " << data << endl;
    } else {
        cout << "未找到指定元素" << endl;
    }
    print(DL);

    int searchItem = -1;
    cout << "输入要查询的链表元素值： ";
    cin >> searchItem;
    DoubleLinkNode *p = locateItem(DL, searchItem);
    if (p == NULL) {
        cout << "未找到指定元素" << endl;
    } else {
        cout << "链表元素首个数据项等于" << p->data << "的地址为： " << &p << endl;
    }
    cout << "当前表长： " << length(DL) << endl;

    cout << "单向链表开始取反操作： " << endl;
    revert(DL);
    print(DL);

    return 0;
};