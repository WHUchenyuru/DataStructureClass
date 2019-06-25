//链队
#include "LinkedQueue.hpp"
#include <iostream>
#include <stdio.h>

//初始化队列
void InitLinkedQueue(LinkQuNode *& q)
{
    q = (LinkQuNode *)malloc(sizeof(LinkQuNode));
    q->front = q->rear = NULL;
}

//销毁队列
void DestroyLinkedQueue(LinkQuNode *& q)
{
    DataNode * pre = q->front , *p;     //pre指向队首结点
    if(pre != NULL)
    {
        p = pre->next;          //p指向结点pre的后继结点
        while(p != NULL)        //p不空循环
        {
            free(pre);          //释放pre结点
            pre = p;            //pre、p同步后移
            p = p->next;
        }
        free(pre);
    }
    free(q);                    //释放链队结点
}

//判断队列是否为空
bool LinkedQueueEmpty(LinkQuNode * q)
{
    return(q->rear == NULL);    //也可以由front为空判断
}

//进队列
void InLinkedQueue(LinkQuNode *& q , int e)
{
    DataNode * p;
    p = (DataNode *)malloc(sizeof(DataNode));   //创建新结点
    p->data = e;
    p->next = NULL;
    if(q->rear == NULL)     //若队列为空，则新结点既是头结点也是尾结点
    {
        q->front = q->rear = p;
    }
    else                    //若队列非空
    {
        q->rear->next = p;  //将结点p链到队尾，并将rear指向它
        q -> rear = p;
    }
}

//出队列
bool deLinkedQueue(LinkQuNode *& q , int & e)
{
    DataNode * t;
    if(q->rear == NULL)
        return false;       //原来队列为空
    t = q->front;           //t指向首结点
    if(q->front == q->rear) //原来队列中只有一个数据结点
        q->front = q->rear = NULL;
    else                    //原来队列中有两个或两个以上数据结点
        q->front = q->front->next;
    e = t->data;
    free(t);
    return true;
}
