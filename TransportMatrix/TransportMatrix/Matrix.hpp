//头文件

#ifndef Matrix_hpp
#define Matrix_hpp

#include <stdio.h>
#define MaxSize 8
#define M 6
#define N 7
typedef struct
{
    int i;      //行号
    int j;      //列号
    int d;      //t元素值
}TupNode;       //三元组定义

typedef struct
{
    int row;                //行数值
    int col;                //列数值
    int num;                //非零元素总数
    TupNode data [MaxSize];
}TSMatrix;                  //三元顺序表定义

void TranTat(TSMatrix A , TSMatrix & B);
void DispMat(TSMatrix A);
void CreateMat(TSMatrix & A , int Mat[M][N]);
#endif /* Matrix_hpp */
