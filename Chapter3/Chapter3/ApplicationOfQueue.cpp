//队列的应用举例
#include<iostream>
#include<stdio.h>
#include "ApplicationOfQueue.hpp"
#include "CircularQueue.hpp"

//利用环形队列求解报数问题
void number(int n)
{
    int i; int e;
    CirQueue *q;  //环形队列指针q
    InitCirQueue(q);    //初始化队列q
    for(i = 1 ; i <= n ; i++)   //构建初始序列
    {
        enCirQueue(q, i);
    }
    printf("报数出列顺序：");
    while(!CirQueueEmpty(q))    //队列不空循环
    {
        deCirQueue(q , e);      //出队一个元素
        printf("%d" , e);       //输出元素编号
        if(!CirQueueEmpty(q))   //队列不空
        {
            deCirQueue(q , e);  //出队一个元素e
            enCirQueue(q , e);  //将刚出队的元素进队
        }
    }
    printf("\n");
    DestroyCirQueue(q);         //销毁队列q
}

