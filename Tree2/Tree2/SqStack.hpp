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
#include"BTree.hpp"

//顺序栈的定义
typedef struct
{
    BTNode *data[MaxSize];  //存放栈中的数据元素
    int top;            //栈顶指针，即存放栈顶元素在data数组中的下标
}SqStack;               //顺序栈类型

void InitSqStack(SqStack *& s);
void DestroySqStack(SqStack *& s);
bool SqStackEmpty(SqStack * s);
bool Push(SqStack *& s , BTNode *e);
bool Pop(SqStack *& s , BTNode *& e);
bool GetTop(SqStack * s , BTNode *& e);


#endif /* SqStack_hpp */
