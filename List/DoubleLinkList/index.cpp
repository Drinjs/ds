//
// Created by J Z on 2022/8/23.
//
//#include "iostream"
//
//using namespace std;
//
//typedef struct DoubleLinkNode{
//    int data;
//    int length;
//    struct DoubleLinkNode *next;
//    struct DoubleLinkNode *prior;
//} DoubleLinkNode, *DoubleLinkList;
//
//bool isEmpty(DoubleLinkList &DL) {
//    if(DL->next == NULL) {
//        return true;
//    }
//    return false;
//}
//
//bool initLinkList(DoubleLinkList &DL) {
//    try {
//        DL = (DoubleLinkNode *) new DoubleLinkNode; // 分配一个头节点
//        DL->next = NULL;
//        DL->prior = NULL;
//        DL->length = 0;
//        return true;
//    } catch (...) {
//        return false; // 内存不足
//    }
//}
//
//DoubleLinkList List_HeadInsert(DoubleLinkList &DL) {
//    int x;
//    DL = (DoubleLinkNode *) new DoubleLinkNode ;
//    DL->next = NULL;
//    DL->length = 0;
//    DoubleLinkNode *p = DL;
//    cout << "输入要添加的元素至头部～" << endl;
//    cin >> x;
//    while(x != 999) {
//        DoubleLinkNode *s = (DoubleLinkNode *) new DoubleLinkNode;
//        s->data = x;
//        s->next = p->next;
//        p->next = s;
//        DL->length++;
//        cout << "继续输入要添加的元素至头部～" << endl;
//        cin >> x;
//    }
//    return DL;
//}
//
//int main() {
//    DoubleLinkList DL;
//    isEmpty(DL);
//    initLinkList(DL);
//    return 0;
//};