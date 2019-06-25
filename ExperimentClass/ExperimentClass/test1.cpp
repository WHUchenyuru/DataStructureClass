//单向链表
#include <stdio.h>
#include <iostream>
#include "test1.hpp"

//创建递增单向链表
void CreateOrderList(LNode *& L, int A[], int n)
{
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
    LNode * pre, *p;
    for(int i = 0; i < n; i++)
    {
        pre = L;
        p = (LNode *)malloc(sizeof(LNode));
        p->data = A[i];
        while(pre->next != NULL && pre->next->data < p->data)
            pre = pre->next;
        p->next = pre->next;
        pre->next = p;
    }
    
}

//两个链表的合并(按递增顺序)
void LinkTable(LNode *& h1, LNode * h2)
{
    LNode *q, *p=h2->next, *r;
    while(p!=NULL)
    {
        q = h1;
        r = p->next;
        while(q->next != NULL && q->next->data < p->data)
            q = q->next;
        p->next = q->next;
        q->next = p;
        p = r;
    }
}

//链表的显示
void display(LNode * h)
{
    LNode *q = h->next;
    while(q!=NULL){
        printf("%4d",q->data);
        q=q->next;
    }
}
