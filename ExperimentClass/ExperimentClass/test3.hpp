#ifndef test3_hpp
#define test3_hpp

#include <stdio.h>
#define MaxSize 100

typedef struct{
    int i, j;       //方块的位置
    int di;         //顺序栈中表示方块的下一可走位置，顺序队中表示上一个方块在队列中的下标
}Box;               //方块类型

typedef struct{
    Box data[MaxSize];
    int top;        //栈顶指针
}StType;            //顺序栈类型

typedef struct{
    Box data[MaxSize];
    int front, rear;    //队头指针和队尾指针
}QuType;                //顺序队类型

void initStack(StType *& s);
void PushStack(StType *& s, Box e);
void PopStack(StType *& s, Box & e);
void DestroyStack(StType *& s);
bool maPathbyStack(int xi, int yi, int xe, int ye);
bool mgPathByQueue(int xi, int yi, int xe, int ye);
void print(QuType * qu, int front);
#endif /* test3_hpp */
