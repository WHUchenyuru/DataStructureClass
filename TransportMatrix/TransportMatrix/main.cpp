//主函数
#include <iostream>
#include"Matrix.hpp"

int Mat[M][N] = {{0,12,9,0,0,0,0} , {0,0,0,0,0,0,0} , {-3,0,0,0,0,14,0} ,
    {0,0,24,0,0,0,0} , {0,18,0,0,0,0,0} , {15,0,0,-7,0,0,0}
};
int main() {
    TSMatrix A , B;
    CreateMat(A, Mat);
    printf("原矩阵的三元顺序表：\n");
    DispMat(A);
    TranTat(A, B);
    printf("转置之后：\n");
    DispMat(B);
    
    return 0;
}
