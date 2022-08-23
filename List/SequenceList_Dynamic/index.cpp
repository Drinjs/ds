//
// Created by J Z on 2022/8/20.
//
#include "iostream"

using namespace std;

#define MaxSize 5

typedef struct {
    int *data;
    int maxSize;
    int length;
} DynamicSequenceList;

void init(DynamicSequenceList &L) {
    L.data = (int *) new int [MaxSize]();
    L.length = 0;
    L.maxSize = MaxSize;
}

void increaseSize(DynamicSequenceList &L, int len) {
    cout << "正在扩容中..." << endl;
    try{
        int *p = L.data;
        L.data = (int *) new int [L.maxSize + len]();
        for(int i = 0; i < L.length; i++) {
            L.data[i] = p[i];
        }
        L.maxSize += len;
        delete []p;
        p = NULL;
    } catch(...){
        // new申请内存空间失败时抛出异常，所以要有捕获异常处理程序
        cout << "捕获错误" <<endl;
    }
}

int get(DynamicSequenceList L, int i) {
    if (i < 1 || i > L.length + 1) { // 非法插入 无效插入位置
        return false;
    }
    return L.data[i - 1];
}

void set(DynamicSequenceList &L, int n) {
    if (n > L.maxSize) {
        increaseSize(L, n);
    }
    for (int i = 0; i < n; i++) {
        cout<<"请输入第"<<i+1<<"个数据:";
        cin>>L.data[i];
    }
    L.length = n;
}

// 插入操作
bool insert(DynamicSequenceList &L, int i, int data) {
    if (i < 1 || i > L.length + 1) { // 非法插入 无效插入位置
        return false;
    }

    if (L.length == L.maxSize) { // 但存储空间已满 自动扩容
        increaseSize(L, i);
    }
    for(int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i-1] = data;
    ++L.length;
    return true;
}

bool remove(DynamicSequenceList &L, int i, int &item) {
    if (i < 1 || i > L.length + 1) { // 非法插入 无效插入位置
        return false;
    }
    item = L.data[i-1];
    for(int j = i; j < L.length; j++) {
        L.data[j-1] = L.data[j];
    }
    --L.length;
    return true;
}

int listLength(DynamicSequenceList L) {
    return L.length;
}

void print(DynamicSequenceList L) {
    cout << "顺序表为：";
    for(int i = 0; i < L.length; i++) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}

int main() {
    DynamicSequenceList dsqList;
    init(dsqList);

    set(dsqList, 5);
    cout << "动态顺序表长度为：" << listLength(dsqList) << endl;
    print(dsqList);

    int index = -1;
    cout << "查询顺序表，位号：";
    cin >> index;
    if(get(dsqList, index)) {
        cout << "动态顺序表第" << index << "位为：" << get(dsqList, index) << endl;
    } else {
        cout << "无效位置: " << index << endl;
    }

    int insertIndex = -1, insertItem = -1;
    cout << "插入顺序表，位号+值（以空格隔开）：";
    cin >> insertIndex >> insertItem;
    if(insert(dsqList, insertIndex, insertItem)) {
        cout << "插入第" << insertIndex << "位：" << insertItem << endl;
    } else {
        cout << "无效位置: " << insertIndex << endl;
    }
    print(dsqList);

    int removeItem = - 1;
    int removeIndex = -1;
    cout << "删除顺序表，位号：";
    cin >> removeIndex;
    if(remove(dsqList, removeIndex, removeItem))  {
        cout << "删除第" << removeIndex << "位：" << removeItem << endl;
    } else {
        cout << "无效位置: " << removeIndex << endl;
    }
    print(dsqList);
    return 0;
}
