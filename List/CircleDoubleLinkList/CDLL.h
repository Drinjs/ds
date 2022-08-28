typedef struct CircleDoubleLinkNode {
    int data;
    struct CircleDoubleLinkNode *next;
    struct CircleDoubleLinkNode *prior;
} CDNode, *CDList;

bool initLinkList(CDList &CL);  // 初始化

bool isEmpty(CDList CL); // 判断空链表

CDNode *getItem(CDList CL, int i); // 按位查找

int length(CDList CL); // 链表长度

CDList List_HeadInsert(CDList &CL); // 头插法

CDList List_TailInsert(CDList &CL); // 尾插法

void print(CDList CL); // 打印链表

CDNode *locateItem(CDList CL, int data); // 正序按值查找

bool insertBefore(CDList &CL, int i, int data); // 指定位置前添加数据项

bool insert(CDList &CL, int i, int data); // 指定位置后添加数据项

bool insertPrevNode(CDNode *p, int data); // 前插指定数据项

bool insertNextNode(CDNode *p, int data); // 后插指定数据项

bool remove(CDList &CL, int i, int &data); // 删除元素节点

bool deleteNode(CDList &CL, CDNode *p, int &data); // 黑魔法删除当前节点

bool revert(CDList &CL); // s链表反转