//链栈的基本操作
#include<iostream>
#include<stdio.h>
#include "LinkedStack.hpp"

//初始化栈
void InitLinkedStack(LinkStNode *& s)
{
    s = (LinkStNode *)malloc(sizeof(LinkStNode));
    s->next = NULL;
}

//销毁栈
void DestroyLinkedStack(LinkStNode *& s)
{
    LinkStNode * pre = s , *p = s->next; //pre指向头结点，p指向首结点
    while(p != NULL)    //循环到p为空
    {
        free(pre);      //释放pre结点
        pre = p;        //pre、p同步后移
        p = p->next;
    }
    free(pre);          //此时pre指向尾结点，释放其空间
}

//判断栈是否为空
bool LinkedStackEmpty(LinkStNode *s)
{
    return(s->next == NULL);
}

//进栈
void Push(LinkStNode *& s , char e)
{
    LinkStNode * p;
    p = (LinkStNode *)malloc(sizeof(LinkStNode));   //新建结点p
    p->data = e;
    p->next = s->next;
    s->next = p;
}

//出栈
bool Pop(LinkStNode *& s , char & e)
{
    LinkStNode * p;
    if(s->next == NULL)
        return false;
    p = s->next;        //p指向首结点
    e = p->data;        //提取首结点值
    s->next = p->next;  //删除首结点
    free(p);            //释放被删结点的储存空间
    return true;
}

//取栈顶元素
bool GetTop(LinkStNode * s , char e)
{
    if(s->next == NULL)
        return false;
    e = s->next->data;
    return true;
}
