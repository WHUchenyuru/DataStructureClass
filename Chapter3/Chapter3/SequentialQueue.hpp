//
//  Queue.hpp
//  Chapter3
//
//  Created by 陈羽如 on 2018/10/10.
//  Copyright © 2018年 陈羽如. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp
#define MaxSize 10

//顺序队的声明
typedef struct
{
    int data[MaxSize];     //存放队中元素
    int front , rear;       //队头和队尾指针
}SqQueue;                   //顺序队类型

void InitQueue(SqQueue *& q);
void DestroyQueue(SqQueue *& q);
bool QueueEmpty(SqQueue * q);
bool enQueue(SqQueue *& q , int e);
bool outQueue(SqQueue *& q , int & e);


#include <stdio.h>

#endif /* Queue_hpp */
