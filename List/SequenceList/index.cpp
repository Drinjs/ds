//
// Created by J Z on 2022/8/20.
//

#include "iostream"

using namespace std;

#define maxSize 5

typedef struct {
    int data[maxSize];
    int length;

} SequenceList;

void init(SequenceList &L) {
    for(int i = 0; i < maxSize; i++) {
        L.data[i] = 0;
    }
    L.length = 0;
}

int get(SequenceList L, int i) {
    if (i < 1 || i > L.length + 1) { // 非法插入 无效插入位置
        return false;
    }

    return L.data[i - 1];
}

void set(SequenceList &L, int n) {
    for (int i = 0; i < n; i++) {
        cout<<"请输入第"<<i+1<<"个数据:";
        cin>>L.data[i];
    }
    L.length = n;
}

// 插入操作
bool insert(SequenceList &L, int i, int data) {
    if (i < 1 || i > L.length + 1) { // 非法插入 无效插入位置
        return false;
    }

    if (L.length >= maxSize) { // 存储空间已满 无法插入
        return false;
    }

    for(int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i-1] = data;
    ++L.length;
    return true;
}

bool remove(SequenceList &L, int i, int &item) {
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

int listLength(SequenceList L) {
    return L.length;
}

void print(SequenceList L) {
    cout << "顺序表为：";
    for(int i = 0; i < L.length; i++) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}

int main() {
    SequenceList sqList;
    init(sqList);

    set(sqList, 5);
    cout << "顺序表长度为：" << listLength(sqList) << endl;
    print(sqList);

    int index = -1;
    cout << "查询顺序表，位号：";
    cin >> index;
    if(get(sqList, index)) {
        cout << "顺序表第" << index << "位为：" << get(sqList, index) << endl;
    } else {
        cout << "无效位置: " << index << endl;
    }

    int insertIndex = -1, insertItem = -1;
    cout << "插入顺序表，位号+值（以空格隔开）：";
    cin >> insertIndex >> insertItem;
    if(insert(sqList, insertIndex, insertItem)) {
        cout << "插入第" << insertIndex << "位：" << insertItem << endl;
    } else {
        cout << "无效位置（可能静态顺序表已满）: " << insertIndex << endl;
    }
    print(sqList);

    int removeItem = - 1;
    int removeIndex = -1;
    cout << "删除顺序表，位号：";
    cin >> removeIndex;
    if(remove(sqList, removeIndex, removeItem))  {
        cout << "删除第" << removeIndex << "位：" << removeItem << endl;
    } else {
        cout << "无效位置: " << removeIndex << endl;
    }
    print(sqList);
    return 0;
}
