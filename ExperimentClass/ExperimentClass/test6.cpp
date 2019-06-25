//排序算法
#include <stdio.h>
#include "test6.hpp"
#include <iostream>

//折半插入排序
void BinInsertSort(int R[], int n)
{
    int i, j, low, high, mid;
    int tmp;
    for(i=1; i<n; i++)
    {
        if(R[i] < R[i-1])
        {
            tmp = R[i];
            low = 0; high = i-1;
            while(low <= high)
            {
                mid = (low + high)/2;
                if(tmp < R[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            for(j = i-1; j >= high+1; j--)
                R[j+1] = R[j];
            R[high + 1] = tmp;
        }
    }
}

//希尔排序
void ShellSort(int R[], int n)
{
    int i, j, d;
    int tmp;
    d = n/2;
    while(d > 0)
    {
        for(i = d; i < n; i++)
        {
            tmp = R[i];
            j = i - d;
            while(j >= 0 && tmp < R[j])
            {
                R[j+d] = R[j];
                j = j-d;
            }
            R[j+d] = tmp;
        }
        d = d/2;
    }
}

//快速排序
int partition(int R[], int s, int t)
{
    int i = s, j = t;
    int tmp = R[i];
    while(i < j)
    {
        while(j > i && R[j] >= tmp)
            j--;
        R[i] = R[j];
        while(i < j && R[i] <= tmp)
            i++;
        R[j] = R[i];
    }
    R[i] = tmp;
    return i;
}

void QuickSort(int R[], int s, int t)
{
    int i;
    if(s<t)
    {
        i = partition(R, s, t);
        QuickSort(R, s, i-1);
        QuickSort(R, i+1, t);
    }
}
