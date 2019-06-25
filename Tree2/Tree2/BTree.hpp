//

#ifndef BTree_hpp
#define BTree_hpp

#include <stdio.h>
#define MaxSize 10

typedef struct node
{
    char data;
    node * lchild;
    node * rchild;
}BTNode;                  //顺序栈类型
void CreateBTree(BTNode *& b , char * str);
void PreOrder(BTNode * b , char * pre);
void InOrder(BTNode * b , char * in);
void PostOrder(BTNode * b);
BTNode * CreateBT1(char * pre , char * in , int n);
void PrintBTree(BTNode* root);

#endif /* BTree_hpp */
