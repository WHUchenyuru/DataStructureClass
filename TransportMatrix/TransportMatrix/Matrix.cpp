//矩阵的转置
#include "Matrix.hpp"
#include<stdio.h>
void TranTat(TSMatrix A , TSMatrix & B)
{
    B.num = A.num;
    B.col = A.row;
    B.row = A.col;
    for(int k = 0 ; k < B.num ; k++)
        B.data[k].d = 0;
    int rpos[A.col];    //记录每一列首个非零元素在B中位置的数组
    int nC[A.col];      //记录每一列元素个数的数组
    for(int k = 0 ; k < A.num ; k++)    //遍历A
    {
        nC[A.data[k].j]++;
    }
    
    for(int k = 0 ; k < A.col ; k++)
    {
        if(k == 0)
            rpos[k] = 0;
        else
            rpos[k] = rpos[k - 1] + nC[k - 1];
    }
    
    for(int k = 0 ; k < A.num ; k++)
    {
        int n = rpos[A.data[k].j];
        if(B.data[n].d != 0)
            n++;
        B.data[n].i = A.data[k].j;
        B.data[n].j = A.data[k].i;
        B.data[n].d = A.data[k].d;
    }
}
               
void DispMat(TSMatrix A)
{
    if (A.num <= 0) return;
    printf("\t%d\t%d\t%d\n" , A.row , A.col, A.num);
    printf("--------------------------\n");
    for(int k = 0 ; k < A.num ; k++)
    {
           printf("\t%d\t%d\t%d\n" , A.data[k].i,A.data[k].j,A.data[k].d);
    }
}

void CreateMat(TSMatrix & A , int Mat[M][N])
{
    int i , j;
    A.row = M; A.col = N; A.num = 0;
    for(i = 0 ; i < M ; i++)
    {
        for(j = 0 ; j < N ; j++)
        {
            if(Mat[i][j] != 0)
            {
                A.data[A.num].i = i;
                A.data[A.num].j = j;
                A.data[A.num].d = Mat[i][j];
                A.num++;
            }
        }
    }
}
