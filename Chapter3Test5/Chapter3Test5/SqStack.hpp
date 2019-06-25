//

#ifndef mgPath_hpp
#define mgPath_hpp
#define MaxSize 100
#include <stdio.h>

typedef struct
{
    int i;  //当前方块的行号
    int j;  //当前方块的列号
    int di; //下一相邻可走方块的方位号
}Box;       //方块类型

//顺序栈的定义
typedef struct
{
    Box data[MaxSize];  //存放栈中的数据元素
    int top;            //栈顶指针，即存放栈顶元素在data数组中的下标
}SqStack;               //顺序栈类型

void InitSqStack(SqStack *& s);
void DestroySqStack(SqStack *& s);
bool SqStackEmpty(SqStack * s);
bool Push(SqStack *& s , Box e);
bool Pop(SqStack *& s , Box & e);
bool GetTop(SqStack * s , Box & e);


#endif /* SqStack_hpp */
