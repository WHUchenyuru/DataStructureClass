//练习题二
#include"BTree.hpp"
#include"SqStack.hpp"
#include <iostream>
#include<stdio.h>
int main() {
    char str[] = "A(B(D(,G)),C(E,F))";
    char pre[7] = "";
    char in[7] = "";
    BTNode * b = (BTNode*)malloc(sizeof(BTNode));
    CreateBTree(b, str);
    //PrintBTree(b);
    printf("前序遍历：\n");
    PreOrder(b , pre);
    printf("中序遍历：\n");
    InOrder(b , in);
    printf("后序遍历：\n");
    PostOrder(b);
    printf("括号表示法：\n");
    PrintBTree(CreateBT1(pre, in, 7));
    return 0;
}
