//环形队列
#include<iostream>
#include<stdio.h>
#include "CircularQueue.hpp"

//初始化队列
void InitCirQueue(CirQueue *& q)
{
    q = (CirQueue *)malloc(sizeof(CirQueue));
    q->front = q->rear = 0;
}

//销毁队列
void DestroyCirQueue(CirQueue *& q)
{
    free(q);
}

//判断队列是否为空
bool CirQueueEmpty(CirQueue * q)
{
    return(q->front == q->rear);
}

//进队列
bool enCirQueue(CirQueue *& q , int e)
{
    if((q->rear + 1) % MaxSize == q->front) //队满上溢出
        return false;
    q->rear = (q->rear + 1) % MaxSize;      //队尾指针增一
    q->data[q->rear] = e;
    return true;
}

//出队列
bool deCirQueue(CirQueue *& q , int & e)
{
    if(q->front == q->rear)     //队空下溢出
        return false;
    q->front = (q->front + 1) % MaxSize;
    e = q->data[q->front];
    return true;
}
