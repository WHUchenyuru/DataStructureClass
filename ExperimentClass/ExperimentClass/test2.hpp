//栈的定义
#ifndef test2_hpp
#define test2_hpp

#include <stdio.h>
#define Maxsize 100
typedef struct
{
    int top;
    char data[Maxsize];
}SqStack;
void InitSqStack(SqStack *& sq);
bool StackEmpty(SqStack * sq);
void Push(SqStack *& sq, char e);
bool Pop(SqStack *& sq, char & e);
bool Match(char s[], int n);
#endif /* test2_hpp */
