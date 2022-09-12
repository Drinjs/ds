//
// Created by J Z on 2022/9/12.
//

#include "index.h"
#include "iostream"

using namespace std;

void initStack(SqStack &stack) {
    stack.top = -1;
}

bool isEmpty(SqStack stack) {
    return (stack.top == -1);
}

bool isFull(SqStack stack) {
    return (stack.top == MaxSize - 1);
}

bool push(SqStack &stack, char c) {
    if (isFull(stack)) {
        return false;
    }
    stack.data[++stack.top] = c;
    return true;
}

bool pop(SqStack &stack, char &item) {
    if (isEmpty(stack)) {
        return false;
    }
    item = stack.data[stack.top--];
    return true;
}

bool bracketCheck(char str[], int length) {
    SqStack stack;
    initStack(stack);
    for (int i = 0; i < length; i++) {
        if (str[i] == '{' || str[i] == '[' || str[i] == '(') {
            push(stack, str[i]);
        } else {
            if (isEmpty(stack)) { // 匹配到右括号但是当前栈为空
                return false;
            }

            char popItem;
            pop(stack, popItem);

            if (str[i] == '}' && popItem != '{') {
                return false;
            }
            if (str[i] == ']' && popItem != '[') {
                return false;
            }
            if (str[i] == ')' && popItem != '(') {
                return false;
            }
        }
    }

    return isEmpty(stack);
}

int main() {
    char str[20];
    int len = 0;
    cin >> str;
    for (int i = 0; str[i] != '\0'; i++) {
        len++;
    }
    if (bracketCheck(str, len)) {
        cout << "合格的括号" << endl;
    } else {
        cout << "括号匹配失败" << endl;
    }

    return 0;
}