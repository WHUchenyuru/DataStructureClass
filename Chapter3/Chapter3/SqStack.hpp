//
//  SqStack.hpp
//  Chapter3Test5
//
//  Created by 陈羽如 on 2018/10/14.
//  Copyright © 2018年 陈羽如. All rights reserved.
//

#ifndef SqStack_hpp
#define SqStack_hpp
#define MaxSize 10
#include <stdio.h>

//顺序栈的定义
typedef struct
{
    int data[MaxSize];  //存放栈中的数据元素
    int top;            //栈顶指针，即存放栈顶元素在data数组中的下标
}SqStack;               //顺序栈类型

void InitSqStack(SqStack *& s);
void DestroySqStack(SqStack *& s);
bool SqStackEmpty(SqStack * s);
bool Push(SqStack *& s , int e);
bool Pop(SqStack *& s , int & e);
bool GetTop(SqStack * s , int & e);


#endif /* SqStack_hpp */
