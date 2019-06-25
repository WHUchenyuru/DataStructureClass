//求解迷宫问题
#include "test3.hpp"
#include <stdio.h>
#include <iostream>

const int M = 8;
const int N = 8;
int mg[M + 2][N + 2]=
{
    {1,1,1,1,1,1,1,1,1,1} , {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,1,0,0,0,1,0,1} , {1,0,0,0,0,1,1,0,0,1},
    {1,0,1,1,1,0,0,0,0,1} , {1,0,0,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,1,0,0,1} , {1,0,1,1,1,0,1,1,0,1},
    {1,1,0,0,0,0,0,0,0,1} , {1,1,1,1,1,1,1,1,1,1},
};

//栈的初始化
void initStack(StType *& s)
{
    s=(StType *)malloc(sizeof(StType));
    s->top=-1;
}

void PushStack(StType *& s, Box e)     //进栈
{
    s->top++;
    s->data[s->top] = e;
}

void PopStack(StType *& s, Box & e)       //出栈
{
    e = s->data[s->top];
    s->top--;
}

void DestroyStack(StType *& s)          //销毁栈
{
    free(s);
}

//用栈方法解决迷宫问题
bool maPathbyStack(int xi, int yi, int xe, int ye)  //路径是由(xi,yi)到(xe,ye)
{
    StType * st;
    initStack(st);
    Box path[MaxSize], e;
    int i, j, di, i1 = 0, j1 = 0;
    e.i = xi; e.j = yi; e.di = -1;
    PushStack(st, e);           //将迷宫入口进栈
    mg[xi][yi] = -1;            //将入口的迷宫值置为-1
    while(st->top != -1)
    {
        i = st->data[st->top].i;
        j = st->data[st->top].j;
        di = st->data[st->top].di;
        if(i==xe && j==ye)      //如果找到了出口，输出路径
        {
            printf("迷宫的一条路径为：\n");
            int k = 0;
            while(st->top != -1)
            {
                PopStack(st, e);
                path[k++]=e;
            }
            while(k>0)
            {
                k--;
                printf("\t(%d, %d)" , path[k].i, path[k].j);
                if((k+2)%5 == 0)
                    printf("\n");
            }
            DestroyStack(st);
            return true;
        }
        bool find = false;
        while(di < 4 && !find)
        {
            di++;
            switch(di)
            {
                case 0:i1=i-1; j1=j; break;
                case 1:i1=i; j1=j+1; break;
                case 2:i1=i+1; j1=j; break;
                case 3:i1=i; j1=j-1; break;
            }
            if (mg[i1][j1] == 0) find = true;
        }
        if(find)
        {
            st->data[st->top].di=di;        //修改栈顶元素的di值
            e.i = i1; e.j = j1; e.di = -1;
            PushStack(st, e);               //将找到的相邻方块入栈
            mg[i1][j1] = -1;                //将迷宫值置为-1
        }
        else
        {
            PopStack(st, e);                //将栈顶方块推栈
            mg[e.i][e.j] = 0;               //将迷宫值还原
        }
    }
    DestroyStack(st);
    return false;
}

//用队列求解迷宫问题
bool mgPathByQueue(int xi, int yi, int xe, int ye)
{
    Box e;
    int i, j, i1 = 0, j1 = 0, di;
    QuType * qu;
    qu = (QuType *)malloc(sizeof(QuType));      //初始化队列
    qu->front = qu->rear = -1;
    e.i=xi; e.j=yi; e.di=-1;
    qu->rear++;                         //进队列
    qu->data[qu->rear] = e;
    mg[xi][yi] = -1;
    while(qu->front != qu->rear)
    {
        qu->front++;                    //出队列
        e = qu->data[qu->front];
        i=e.i; j=e.j;
        if(i==xe && j==ye)
        {
            print(qu, qu->front);
            free(qu);
            return true;
        }
        for(di=0; di<4; di++)
        {
            switch(di)
            {
                case 0:i1=i-1; j1=j;   break;
                case 1:i1=i;   j1=j+1; break;
                case 2:i1=i+1; j1=j;   break;
                case 3:i1=i;   j1=j-1; break;
            }
            if(mg[i1][j1]==0)
            {
                e.i=i1; e.j=j1;
                e.di=qu->front;
                qu->rear++; qu->data[qu->rear]=e;
                mg[i1][j1]=-1;
            }
        }
    }
    free(qu);
    return false;
}

//顺序队列显示路径
void print(QuType * qu, int front)
{
    int k=front, j, ns=0;
    printf("\n");
    do
    {
        j=k;
        k=qu->data[k].di;
        qu->data[j].di=-1;
    }while(k != 0);
    printf("一条迷宫路径如下：\n");
    k=0;
    while(k<MaxSize)
    {
        if(qu->data[k].di == -1)
        {
            ns++;
            printf("\t(%d, %d)", qu->data[k].i, qu->data[k].j);
            if(ns%5 == 0) printf("\n");
        }
        k++;
    }
    printf("\n");
}
