//
//  LinkedQueue.hpp
//  Chapter3
//
//  Created by 陈羽如 on 2018/10/10.
//  Copyright © 2018年 陈羽如. All rights reserved.
//

#ifndef LinkedQueue_hpp
#define LinkedQueue_hpp

#include <stdio.h>
//链队中数据节点的声明
typedef struct qnode
{
    int data;               //存放元素
    struct qnode * next;    //下一个节点指针
}DataNode;                  //链队数据节点的类型

//链队节点的声明
typedef struct
{
    DataNode * front;       //指向队首节点
    DataNode * rear;        //指向队尾节点
}LinkQuNode;                //链队节点的类型

void InitLinkedQueue(LinkQuNode *& q);
void DestroyLinkedQueue(LinkQuNode *& q);
bool LinkedQueueEmpty(LinkQuNode * q);
void InLinkedQueue(LinkQuNode *& q , int e);
bool deLinkedQueue(LinkQuNode *& q , int & e);


#endif /* LinkedQueue_hpp */
