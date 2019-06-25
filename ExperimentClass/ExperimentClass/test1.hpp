//单向链表的定义
//  LinkedTable.hpp
//  ExperimentClass
//
//  Created by 陈羽如 on 2018/12/12.
//  Copyright © 2018 陈羽如. All rights reserved.
//

#ifndef LinkedTable_hpp
#define LinkedTable_hpp

#include <stdio.h>
typedef struct Node
{
    int data;
    Node * next;
}LNode;     //结点定义

void CreateOrderList(LNode *& L, int A[], int n);
void LinkTable(LNode *& h1, LNode * h2);
void display(LNode * h);
#endif /* LinkedTable_hpp */
