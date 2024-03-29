//
//  mgPath.cpp
//  Chapter3Test5
//
//  Created by 陈羽如 on 2018/10/14.
//  Copyright © 2018年 陈羽如. All rights reserved.
//
#include<iostream>
#include<stdio.h>
#include "SqStack.hpp"
#include "mgPath.hpp"

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

bool mgPath(int xi , int yi , int xe , int ye)  //求解路径为(xi,yi)->(xe,ye)
{
    Box path[MaxSize] , e;
    int i,j,di,i1 = 0 ,j1 = 0,k;
    bool find;
    SqStack *st;                    //定义栈dt
    InitSqStack(st);                //初始化栈顶指针
    e.i = xi; e.j = yi; e.di = -1;  //设置e为入口
    Push(st, e);                    //方块e进栈
    mg[xi][yi] = -1;                //将入口的迷宫值置为-1，避免重复走到该方块
    while(!SqStackEmpty(st))        //栈不空时循环
    {
        GetTop(st, e);              //取栈顶方块e
        i = e.i; j = e.j; di = e.di;
        if(i == xe && j == ye)      //找到了出口，x输出该路径
        {
            printf("一条迷宫路径为下：\n");
            k = 0;
            while(!SqStackEmpty(st))
            {
                Pop(st, e);         //出栈方块e
                path[k++] = e;      //将e添加到path数组中
            }
            while(k >= 1)
            {
                k--;
                printf("\t(%d , %d)" , path[k].i , path[k].j);
                if((k + 2) % 5 == 0)    //每输出5个方块后换一行
                    printf("\n");
            }
            printf("\n");
            DestroySqStack(st);     //销毁栈
            return true;            //输出一条迷宫路径后返回true
        }
        find = false;
        while(di < 4 && !find)      //找方块(i , j)的下一相邻可走方块
        {
            di++;
            switch (di)
            {
                case 0:i1 = i - 1; j1 = j;break;
                case 1:i1 = i; j1 = j + 1;break;
                case 2:i1 = i + 1; j1 = j;break;
                case 3:i1 = i; j1 = j - 1;break;
            }
            if(mg[i1][j1] == 0) find = true;     //找到了一个相邻可走方块，设置find为真
        }
        if(find)                                //找到了一个相邻可走方块(i1,j1)
        {
            st->data[st->top].di = di;          //修改原栈顶元素的di值
            e.i = i1; e.j = j1; e.di = -1;
            Push(st, e);                        //相邻可走方块进栈
            mg[i1][j1] = -1;                    //将(i1,j1)迷宫值置为-1，避免重复
        }
        else                                    //没有路径可走，则退栈
        {
            Pop(st , e);                        //将栈顶方块退栈
            mg[e.i][e.j] = 0;                   //让退栈方块的位置变成其他路径可走的方块
        }
    }
    DestroySqStack(st);
    return false;
}
