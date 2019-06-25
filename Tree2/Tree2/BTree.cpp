#include <stdio.h>
#include "BTree.hpp"
#include <iostream>
#include"SqStack.hpp"

//转换为二叉链
void CreateBTree(BTNode *& b , char * str)
{
    BTNode * ST[MaxSize] , *p = nullptr;      //ST数组作为顺序栈
    int top = -1 ,k ,j = 0;         //top作为栈顶指针
    char ch;
    b = NULL;                       //初始时二叉琏为空
    ch = str[j];
    while(ch != '\0')               //循环扫描str中的每个字符
    {
        switch(ch)
        {
            case '(' : top++; ST[top] = p; k = 1; break;
            case ')' : top--; break;
            case ',' : k = 2; break;
            default : p = (BTNode *)malloc(sizeof(BTNode));
                p->data = ch;
                p->lchild = p->rchild = NULL;
                if(b == NULL)
                    b = p;
                else
                {
                    switch(k)
                    {
                        case 1: ST[top]->lchild = p;break;
                        case 2: ST[top]->rchild = p;break;
                    }
                }
        }
        j++;
        ch = str[j];
    }
}

//前序遍历
void PreOrder(BTNode * b , char * pre)
{
    int n = 0;
    BTNode * p = nullptr;
    SqStack * st;
    InitSqStack(st);
    if(b != NULL)
    {
        Push(st, b);               //根结点进栈
        while(!SqStackEmpty(st))
        {
            Pop(st, p);            //退栈结点p并访问它
            pre[n] = p->data;
            n++;
            printf("%c" , p->data);
            if(p->rchild != NULL)       //有右孩子时将其进栈
                Push(st, p->rchild);
            if(p->lchild != NULL)
                Push(st, p->lchild);   //有左孩子时将其进栈
        }
        printf("\n");
    }
    DestroySqStack(st);
}

//中序遍历
void InOrder(BTNode * b , char * in)
{
    int n = 0;
    BTNode * p;
    SqStack * st;
    InitSqStack(st);
    p = b;
    while(!SqStackEmpty(st) || p != NULL)
    {
        while(p != NULL)        //扫描结点p的所有左下结点并进栈
        {
            Push(st , p);      //结点p进栈
            p = p->lchild;          //移动到左孩子
        }
        if(!SqStackEmpty(st))
        {
            Pop(st, p);            //出栈结点p
            in[n] = p->data;
            n++;
            printf("%c" , p->data); //访问结点p
            p = p->rchild;          //转向处理其右子树
        }
    }
    printf("\n");
    DestroySqStack(st);
}

//后序遍历
void PostOrder(BTNode * b)
{
    BTNode * p , *r;
    bool flag;
    SqStack * st;
    InitSqStack(st);
    p = b;
    do
    {
        while(p != NULL)    //扫描结点p的所有左下结点并进栈
        {
            Push(st, p);
            p = p->lchild;
        }
        r = NULL;       //r指向刚访问的结点，初始时为空
        flag = true;    //flag为真表示正在处理栈顶结点
        while(!SqStackEmpty(st) && flag)
        {
            GetTop(st, p);         //取出当前的栈顶结点p
            if(p->rchild == r)      //若结点p的右孩子为空或为刚刚访问过的结点
            {
                printf("%c" , p->data); //访问结点p
                Pop(st, p);
                r = p;          //r为刚访问的结点
            }
            else
            {
                p = p->rchild;      //转向处理其右子树
                flag = false;       //表示当前不是处理栈顶结点
            }
        }
    }while(!SqStackEmpty(st));
    printf("\n");
    DestroySqStack(st);
}

//由先序和中序构造二叉链
BTNode * CreateBT1(char * pre , char * in , int n)
{
    BTNode * b;
    char * p;
    int k;
    if(n <= 0) return NULL;
    b = (BTNode *)malloc(sizeof(BTNode));
    b->data = *pre;
    for(p = in ; p < in + n ;p++)       //在中序序列中找等于*pre字符的位置k
        if(*p == *pre)                  //pre指向根结点
            break;                      //找到后退出循环
    k = p - in;                         //确定根结点在in中的位置
    b->lchild = CreateBT1(pre + 1, in, k);  //递归构造左子树
    b->rchild = CreateBT1(pre + k + 1, p + 1, n - k - 1);   //递归构造右子树
    return b;
}

void PrintBTree(BTNode* root)//根据根节点，输出二叉树的括号表达式
{
    if(root!=NULL)
    {
        printf("%c",root->data);//打印当前节点
        if(root->lchild!=NULL || root->rchild!=NULL)//如果当前节点有孩子
        {
            printf("(") ;//有孩子必定有左括号
            if(root->lchild!=NULL) //如果左孩子不为空，打印左孩子
            {
                PrintBTree(root->lchild);
            }
            if(root->rchild!=NULL)//如果右孩子不为空，打印右孩子
            {
                printf(",");//有右孩子必定有','
                PrintBTree(root->rchild);
            }
            printf(")") ;////有孩子必定有右括号
        }
    }
}
