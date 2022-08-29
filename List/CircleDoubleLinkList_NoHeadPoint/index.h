typedef struct CircleDoubleLinkNodeNoHeadPoint {
    int data;
    struct CircleDoubleLinkNodeNoHeadPoint *next;
    struct CircleDoubleLinkNodeNoHeadPoint *prior;
} CDNHPNode, *CDNHPList;

void initLinkList(CDNHPList &CDL);  // 初始化

bool isEmpty(CDNHPList CDL); // 判断空链表s

CDNHPNode *getItem(CDNHPList CDL, int i); // 按位查找

int length(CDNHPList CDL); // 链表长度

CDNHPList List_HeadInsert(CDNHPList &CDL); // 头插法

CDNHPList List_TailInsert(CDNHPList &CDL); // 尾插法

void print(CDNHPList CDL); // 打印链表

CDNHPNode *locateItem(CDNHPList CDL, int data); // 正序按值查找

bool insertBefore(CDNHPList &CDL, int i, int data); // 指定位置前添加数据项

bool insert(CDNHPList &CDL, int i, int data); // 指定位置后添加数据项

bool insertPrevNode(CDNHPNode *p, int data); // 前插指定数据项

bool insertNextNode(CDNHPNode *p, int data); // 后插指定数据项

bool remove(CDNHPList &CDL, int i, int &data); // 删除元素节点

bool deleteNode(CDNHPList &CDL, CDNHPNode *p); // 黑魔法删除当前节点

bool revert(CDNHPList &CDL); // 链表反转