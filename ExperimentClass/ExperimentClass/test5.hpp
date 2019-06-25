//二叉树的定义

#ifndef test5_hpp
#define test5_hpp

#include <stdio.h>

typedef struct node
{
    char data;       //数据元素
    node * lchild;  //左孩子结点
    node * rchild;  //右孩子结点
}BTNode;

void CreateBTree(BTNode * & b, char * str);
void PreOrder(BTNode * b);
void PreOrder1(BTNode *b);
#endif /* test5_hpp */
