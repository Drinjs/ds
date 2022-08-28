typedef struct CircleLinkNode {
    int data;
    struct CircleLinkNode *next;
} CNode, *CList;

void initLinkList(CList &CL);  // 初始化

bool isEmpty(CList CL); // 判断空链表

CNode *getItem(CList CL, int i); // 按位查找

int length(CList CL); // 链表长度

CList List_HeadInsert(CList &CL); // 头插法

CList List_TailInsert(CList &CL); // 尾插法

void print(CList CL); // 打印链表

CNode *locateItem(CList CL, int data); // 正序按值查找

bool insertBefore(CList &CL, int i, int data); // 指定位置前添加数据项

bool insert(CList &CL, int i, int data); // 指定位置后添加数据项

bool insertPrevNode(CNode *p, int data); // 前插指定数据项

bool insertNextNode(CNode *p, int data); // 后插指定数据项

bool remove(CList &CL, int i, int &data); // 删除元素节点

bool deleteNode(CList &CL, CNode *p, int &data); // 黑魔法删除当前节点

bool revert(CList &CL); // s链表反转