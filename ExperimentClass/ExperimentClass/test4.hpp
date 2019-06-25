//
//  test4.hpp
//  ExperimentClass
//
//  Created by 陈羽如 on 2018/12/25.
//  Copyright © 2018 陈羽如. All rights reserved.
//

#ifndef test4_hpp
#define test4_hpp

#include <stdio.h>
#define N 50
#define M 2*N-1

typedef struct
{
    double weight;  //权重
    int parent;     //双亲结点
    int lchild;     //左孩子结点
    int rchild;
}HTNode;            //哈夫曼树中的结点类型

typedef struct
{
    char cd[N];     //存放哈夫曼编码
    int start;      //ch[start...n]存放哈夫曼编码
}HCode;

void CreateHT(HTNode ht[], int n0);
void CreateHCode(HTNode ht[], HCode hcd[], int n);
void DispHcode(HTNode ht[], HCode hcd[], int n);
#endif /* test4_hpp */
