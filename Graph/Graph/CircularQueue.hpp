//
//  CircularQueue.hpp
//  Chapter3
//
//  Created by 陈羽如 on 2018/10/12.
//  Copyright © 2018年 陈羽如. All rights reserved.
//

#ifndef CircularQueue_hpp
#define CircularQueue_hpp
#include <stdio.h>
#define MaxSize 10

typedef struct
{
    int data[MaxSize];     //存放队中元素
    int front , rear;       //队头和队尾指针
}CirQueue;                   //队列类型

void InitCirQueue( CirQueue *& q);
void DestroyCirQueue( CirQueue *& q);
bool CirQueueEmpty( CirQueue * q);
bool enCirQueue( CirQueue *& q , int e);
bool deCirQueue( CirQueue *& q , int & e);

#endif /* CircularQueue_hpp */
