//多项式的相加
//作业版（不完整）

#include <iostream>
#include<stdio.h>

#define MaxCol 10
typedef struct Node1
{
    int data[MaxCol];
    struct Node1 * next;
}DList;

typedef struct Node2
{
    int Row;
    DList * next;
}HList;

void CreateTable(HList *& h)
{
    int i , j;
    DList *r , *s;
    h = (HList * )malloc(sizeof(HList));
    h->next = NULL;
    r = (DList*)malloc(sizeof(DList));
    printf("多项式的项数：");
    scanf("%d" , &h->Row);
    for(i = 0 ; i < h->Row ; i++)
    {
        printf("第%d项的系数和指数：" , i+1);
        s = (DList*)malloc(sizeof(DList));
        for(j = 0 ; j < 2 ; j++)
        {
            scanf("%d" , &s->data[j]);
        }
        if(h->next == NULL)
            h -> next = s;
        else
            r -> next = s;
        r = s;
    }
    r -> next = NULL;
}

void DestoryTable(HList *& h)
{
    DList * pre = h->next, *p = pre -> next;
    while(p!=NULL)
    {
        free(pre);
        pre = p ;
        p = p -> next;
    }
    free(pre);
    free(h);
}

void DispTable(HList *& h)
{
    int j;
    DList * p = h -> next;
    while(p != NULL && p->data[0] != 0)
    {
        for(j = 0 ; j < 2 ; j++)
        {
            printf("%4d" , p -> data[j]);
        }
        printf("\n");
        p = p -> next;
    }
}

void LinkTable(HList * h1 , HList * h2 , HList *& h)
{
    DList *p = h1 -> next , *q , *s , *r = nullptr;
    h = (HList *)malloc(sizeof(HList));
    r = (DList *)malloc(sizeof(DList));
    h -> Row = 0;
    h -> next = NULL;
    q = h2 -> next;
    while(p != NULL)
    {
        while(q != NULL)
        {
            s = (DList *)malloc(sizeof(DList));
            if(p->data[1] - q->data[1] > 0)
            {
                s -> data[0] = p -> data[0];
                s -> data[1] = p -> data[1];
                p = p -> next;
                if(h -> next == NULL)
                    h -> next = s;
                if(h -> next != NULL)
                    r -> next = s;
                r = s;
                h -> Row++;
                continue;
            }
            if(p->data[1] - q->data[1] < 0)
            {
                s -> data[0] = q -> data[0];
                s -> data[1] = q -> data[1];
                q = q -> next;
                if(h -> next == NULL)
                    h -> next = s;
                if(h -> next != NULL)
                    r -> next = s;
                r = s;
                h -> Row++;
                continue;
            }
            if(p->data[1] - q->data[1] == 0)
            {
                s -> data[0] =  q -> data[0] + p -> data[0];
                s -> data[1] = p ->data[1];
                p = p -> next;
                q = q -> next;
                if(h -> next == NULL)
                    h -> next = s;
                if(h -> next != NULL)
                    r -> next = s;
                r = s;
                h -> Row++;
                continue;
            }
        }
        if(p != NULL)
        {
            s = (DList *)malloc(sizeof(DList));
            s -> data[0] = p -> data[0];
            s -> data[1] = p -> data[1];
            p = p->next;
            if(h -> next == NULL)
                h -> next = s;
            if(h -> next != NULL)
                r -> next = s;
            r = s;
            h -> Row++;
        }
    }
    r -> next = NULL;
}

int main()
{
    HList *h1 , *h2 , *h;
    printf("多项式1:\n");
    CreateTable(h1);
    printf("多项式2:\n");
    CreateTable(h2);
    LinkTable(h1, h2, h);
    printf("相加多项式结果:\n");
    DispTable(h);
    DestoryTable(h1);
    DestoryTable(h2);
    DestoryTable(h);
    return 1;
}
