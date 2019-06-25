#include<stdio.h>
#include <iostream>
#include"mgPath.hpp"

int main() {
    if(!mgPath(1, 1, 8, 8))
        printf("该迷宫问题没有解！");
    return 1;
}
