//判断一棵二叉树的括号表示是否是合法的
#include <stdio.h>
#include <iostream>
#include"LinkedStack.hpp"

bool Tree(char exp[] , int n)
{
    int i = 0; char e;
    bool tree = true;
    LinkStNode * st;
    InitLinkedStack(st);
    while(i < n && tree)
    {
        if(exp[i] == '(')
            Push(st, exp[i]);
        if(exp[i] == ')')
        {
            if(GetTop(st, e) == true)
            {
                if(e != '(')
                    tree = false;
                else
                    Pop(st, e);
            }
            else tree = false;
        }
        i++;
    }
    if(!LinkedStackEmpty(st))
        tree = false;
    DestroyLinkedStack(st);
    return tree;
}
int main() {
    char str[] = "A(B(D(,G)),C(E,F))";
    printf("%s\n" , Tree(str, 7)? "true":"false");
    return 0;
}
