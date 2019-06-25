//二叉树的先序遍历
#include "test5.hpp"
#include <stdio.h>
#include <iostream>
#define MaxSize 100

void CreateBTree(BTNode * & b, char * str)
{
    BTNode * St[MaxSize], *p = nullptr;
    int top = -1, j=0, k = 0;
    b = NULL;
    char ch = str[j];
    while(ch != '\0')
    {
        switch(ch)
        {
            case '(':top++; St[top]=p; k=1; break;
            case ')':top--; break;
            case ',':k=2; break;
            default:p=(BTNode *)malloc(sizeof(BTNode));
                p->data = ch;
                p->lchild = p->rchild = NULL;
                if(b == NULL)
                    b = p;
                else
                {
                    switch (k)
                    {
                        case 1: St[top]->lchild = p;break;
                        case 2: St[top]->rchild = p;break;
                    }
                }
        }
        j++;
        ch = str[j];
    }
}

//二叉树的先序遍历递归算法
void PreOrder(BTNode * b)
{
    if(b != NULL)
    {
        printf("%c", b->data);
        PreOrder(b->lchild);
        PreOrder(b->rchild);
    }
}

//二叉树的先序遍历非递归算法
void PreOrder1(BTNode *b)
{
    BTNode * st[MaxSize], *p;
    int top=-1;
    if(b != NULL)
    {
        st[++top] = b;
        while(top != -1)
        {
            p = st[top--];
            printf("%c", p->data);
            if(p->rchild != NULL)
                st[++top]=p->rchild;
            if(p->lchild != NULL)
                st[++top]=p->lchild;
        }
        printf("\n");
    }
}
