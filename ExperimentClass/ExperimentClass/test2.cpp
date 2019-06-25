//输入一个字符串，判断字符串中左右括号是否匹配
#include <stdio.h>
#include <iostream>
#include "test2.hpp"

//初始化栈
void InitSqStack(SqStack *& sq){
    sq=(SqStack *)malloc(sizeof(SqStack));
    sq->top=-1;
}

//判断栈是否为空
bool StackEmpty(SqStack * sq){
    return (sq->top==-1);
}

//进栈
void Push(SqStack *& sq, char e){
    sq->top++;
    sq->data[sq->top]=e;
}

//出栈
bool Pop(SqStack *& sq, char & e){
    if(sq->top==-1)
        return false;
    e=sq->data[sq->top];
    sq->top--;
    return true;
}

//销毁栈
void DestroyStack(SqStack *& sq){
    free(sq);
}

//判断是否匹配
bool Match(char s[], int n){
    int i=0;
    SqStack *sq;
    InitSqStack(sq);
    char e;
    bool flag=true;
    while(i<n && flag){
        char k=s[i];
        switch(k){
            case '(':
                Push(sq, s[i]);break;
            case ')':
                if(Pop(sq, e)==true){
                    if(e != '(') flag=false;
                }
                else flag=false;
        }
        i++;
    }
    if(!StackEmpty(sq)) flag=false;
    DestroyStack(sq);
    return flag;
}
