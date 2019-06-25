//顺序队列的基本操作

#include "SequentialQueue.hpp"
#include <iostream>
#include <stdio.h>

//初始化队列
void InitQueue(SqQueue *& q)
{
    q = (SqQueue *)malloc(sizeof(SqQueue));
    q->front = q->rear = -1;
}

//销毁队列
void DestroyQueue(SqQueue *& q)
{
    free(q);
}

//判断队列是否为空
bool QueueEmpty(SqQueue * q)
{
    return(q->front == q->rear);
}

//进队列
bool enQueue(SqQueue *& q , int e)
{
    if(q->rear == MaxSize - 1)  //满队上溢出
        return false;           //返回假
    q->rear++;                  //队尾增1
    q->data[q->rear] = e;       //rear位置插入元素e
    return true;                //返回真
}

//出队列
bool outQueue(SqQueue *& q , int & e)
{
    if(q->front == q->rear)     //队空下溢出
        return false;
    q->front++;
    e = q->data[q->front];
    return true;
}
