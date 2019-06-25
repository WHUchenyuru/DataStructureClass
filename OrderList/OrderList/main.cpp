//创建递增有序表
#include <stdio.h>
#include <iostream>

typedef struct Node
{
    int data;
    Node * next;
}LNode;     //结点定义

void CreateOrderList(LNode *& L, int A[], int n)
{
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
    LNode * pre, *p;
    for(int i = 0; i < n; i++)
    {
        pre = L;
        p = (LNode *)malloc(sizeof(LNode));
        p->data = A[i];
        while(pre->next != NULL && pre->next->data < p->data)
            pre = pre->next;
        p->next = pre->next;
        pre->next = p;
    }
    
}

int main(int argc, const char * argv[]) {
    int A[] = {23, 1, 14, 25, 42, 11};
    LNode * L;
    CreateOrderList(L, A, 6);
    while(L != NULL){
        std::cout<<L->data<<std::endl;
        L = L->next;
    }
    return 0;
}
