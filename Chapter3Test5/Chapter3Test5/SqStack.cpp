//顺序栈的基本操作
#include <iostream>
#include "SqStack.hpp"
#include <stdio.h>

//初始化栈
void InitSqStack(SqStack *& s)
{
    s = (SqStack *)malloc(sizeof(SqStack)); //分配一个顺序栈空间，首地址存放在s中
    s->top = -1;                            //栈顶指针置为-1
}

//销毁栈
void DestroySqStack(SqStack *& s)
{
    free(s);
}

//判断栈是否为空
bool SqStackEmpty(SqStack * s)
{
    return (s->top == -1);
}

//进栈
bool Push(SqStack *& s , Box e)
{
    if(s->top == MaxSize - 1)   //栈满的情况，即栈上溢出
        return false;
    s->top++;                   //栈顶指针增一
    s->data[s->top] = e;        //元素ed放在栈顶指针处
    return true;
}

//出栈
bool Pop(SqStack *& s , Box & e)
{
    if(s->top == -1)    //栈为空
        return false;
    e = s->data[s->top];    //取栈顶元素
    s->top--;               //栈顶指针减一
    return true;
}

//取栈顶元素
bool GetTop(SqStack * s , Box & e)
{
    if(s->top == -1)
        return false;
    e = s->data[s->top];
    return true;
}

