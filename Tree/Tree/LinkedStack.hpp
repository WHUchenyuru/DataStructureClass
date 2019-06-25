#ifndef LinkedStack_hpp
#define LinkedStack_hpp
#include<iostream>
#include <stdio.h>

typedef struct linknode
{
    int data;               //数据域
    struct linknode * next; //指针域
}LinkStNode;                //链栈结点类型

void InitLinkedStack(LinkStNode *& s);
void DestroyLinkedStack(LinkStNode *& s);
bool LinkedStackEmpty(LinkStNode *s);
void Push(LinkStNode *& s , char e);
bool Pop(LinkStNode *& s , char & e);
bool GetTop(LinkStNode * s , char e);

#endif /* LinkedStack_hpp */
