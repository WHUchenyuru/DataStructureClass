//迷宫问题
#include <stdio.h>
#include <iostream>
#define M 4             //行数
#define N 4             //列数
#define Maxsize 100     //栈最多元素个数
int mg[M+2][N+2] =      //迷宫
{
    {1,1,1,1,1,1} , {1,0,0,0,1,1} , {1,0,1,0,0,1} ,
    {1,0,0,0,1,1} , {1,1,0,0,0,1} , {1,1,1,1,1,1}
};

struct
{
    int i , j;
    int di;
}St[Maxsize] , Path[Maxsize];   //定义栈d和存放最短路径的数组
int top = -1;                   //栈顶指针
int count = 1;                  //路径数计数
int minlen = Maxsize;           //最短路径长度

void dispapath()                //输出一条路径并求最短路径
{
    int k;
    printf("%5d:" , count++);   //输出第count条路径
    for(k = 0 ; k <= top ; k++)
        printf("(%d , %d)" , St[k].i , St[k].j);
    printf("\n");
    if(top + 1 < minlen)        //比较找到最短路径
    {
        for(k = 0 ; k <= top ; k++) //将最短路径存放在path中
        {
            Path[k] = St[k];
        }
        minlen = top + 1;           //将最短路径长度存放在minlen中
    }
}

void dispminpath()           //输出第一条最短路径
{
    printf("最短路径如下：\n");
    printf("长度：%d\n" , minlen);
    printf("路径：");
    for(int k = 0 ; k < minlen ; k++)
        printf("(%d , %d)" , Path[k].i , Path[k].j);
    printf("\n");
}

void mgpath(int xi , int yi , int xe , int ye)
{
    int i,j,di,i1,j1;
    bool find;
    top++;
    St[top].i = xi;
    St[top].j = yi;
    St[top].di = -1;
    mg[xi][yi] = -1;                //将入口的迷宫值置为-1，避免重复走到该方块
    while(top > -1)        //栈不空时循环
    {
        i = St[top].i; j = St[top].j; di = St[top].di;
        if(i == xe && j == ye)      //找到了出口，x输出该路径
        {
            dispapath();
            mg[i][j] = 0;
            top--;
            i = St[top].i;
            j = St[top].j;
            di = St[top].di;
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
            St[top].di = di;
            top++;
            St[top].i = i1;
            St[top].j = j1;
            St[top].di = -1;
            mg[i1][j1] = -1;                    //将(i1,j1)迷宫值置为-1，避免重复
        }
        else                                    //没有路径可走，则退栈
        {
            mg[i][j] = 0;                        //将栈顶方块退栈
            top--;                   //让退栈方块的位置变成其他路径可走的方块
        }
    }
    dispminpath();
}
int main() {
    printf("迷宫所有路径为下：\n");
    mgpath(1,1,M,N);
    return 1;
}
