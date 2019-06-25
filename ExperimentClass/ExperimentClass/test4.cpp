#include "test4.hpp"
#include <stdio.h>

void CreateHT(HTNode ht[], int n0)
{
    int i, k, lnode, rnode;
    double min1, min2;
    for(i=0; i<2*n0-1; i++)
        ht[i].parent = ht[i].lchild = ht[i].rchild =-1;     //所有结点的相关域置初值为-1
    for(i=n0; i<2*n0-2; i++)
    {
        min1=min2=32767;
        lnode = rnode = -1;
        for(k=0; k<=i-1; k++)
            if(ht[k].parent == -1)
            {
                if(ht[k].weight<min1)
                {
                    min2 = min1; rnode = lnode;
                    min1 = ht[k].weight; lnode = k;
                }
                else if(ht[k].weight < min2)
                {
                    min2 = ht[k].weight; rnode = k;
                }
            }
        ht[i].weight = ht[lnode].weight + ht[rnode].weight;
        ht[i].lchild = lnode; ht[i].rchild = rnode;
        ht[lnode].parent = i; ht[rnode].parent = i;
    }
}

void CreateHCode(HTNode ht[], HCode hcd[], int n)
{
    int i, f, c;
    HCode hc;
    for(i = 0; i<n; i++)
    {
        hc.start = n; c = i;
        f = ht[i].parent;
        while(f != -1)
        {
            if(ht[f].lchild == c)
                hc.cd[hc.start--] = '0';
            else
                hc.cd[hc.start--] = '1';
            c = f; f = ht[f].parent;
        }
        hc.start++;
        hcd[i] = hc;
    }
}


void DispHcode(HTNode ht[], HCode hcd[], int n)
{
    int i , k; int sum = 0, m = 0, j;
    printf("输出哈夫曼编码：\n");
    for(i = 0; i<n; i++)
    {
        j = 0;
        printf("    %g:\t", ht[i].weight);
        for(k = hcd[i].start; k<=n; k++)
        {
            printf("%c", hcd[i].cd[k]);
            j++;
        }
        printf("\n");
        m += ht[i].weight;
        sum += ht[i].weight * j;
    }
    printf("\n平均长度 = %g\n", 1.0 * sum/m);

}
