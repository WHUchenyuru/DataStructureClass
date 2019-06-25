//第三章 栈和队列
#include <iostream>
#include <stdio.h>
#include "ApplicationOfQueue.hpp"

int main()
{
    int i = 1 , n = 8;
    printf("初始序列：");
    for(i = 1 ; i <= n ; i++)
        printf("%d" , i);
    printf("\n");
    number(n);
    return 1;
}
