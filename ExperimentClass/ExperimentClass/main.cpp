#include <stdio.h>
#include <iostream>
#include <time.h>
#include "test1.hpp"
#include "test2.hpp"
#include "test3.hpp"
#include "test4.hpp"
#include "test5.hpp"
#include "test6.hpp"
using namespace std;

//第一题
void test1()
{
    int A[100],B[100];
    int i=0,j=0;
    printf("请输入数组A：");
    while(cin>>A[i]){
        if(getchar()=='\n')
            break;
        i++;
    }
    printf("请输入数组B：");
    while(cin>>B[j]){
        if(getchar()=='\n')
            break;
        j++;
    }
    LNode * h1, * h2;
    CreateOrderList(h1, A, i+1);
    CreateOrderList(h2, B, j+1);
    printf("有序链表A为：");
    display(h1);
    printf("\n有序链表B为：");
    display(h2);
    LinkTable(h1, h2);
    printf("\n合成的链表为：");
    display(h1);
}

//第二题
void test2(){
    char s[Maxsize];
    int i=0;
    printf("请输入一个字符串：");
    while(cin>>s[i]){
        if(getchar()=='\n')
            break;
        i++;
    }
    bool test2 = Match(s, i+1);
    cout<<test2<<endl;
}

//第三题
void test3(){
//    if(!maPathbyStack(1, 1, 8, 8))
//        printf("该迷宫问题没有解！");
    if(!mgPathByQueue(1, 1, 8, 8))
        printf("该迷宫问题没有解！");
}

//第四题
void test4()
{
    int num4[]={12, 1, 23, 35, 21, 60, 90, 60, 10, 15, 25, 56};
    HTNode ht[M];
    HCode hcd[N];
    for(int i = 0; i < 12; i++)
    {
        ht[i].weight = num4[i];
    }
    CreateHT(ht, 12);
    CreateHCode(ht, hcd, 12);
    DispHcode(ht, hcd, 12);
}

//第五题
void test5()
{
    BTNode *b;
    char str[]="A(B(D(,G)),C(E,F))";
    CreateBTree(b, str);
    printf("递归算法：\n");
    PreOrder(b);
    printf("\n非递归算法：\n");
    PreOrder1(b);
}

//第六题
void test6()
{
    int R[100];
    int R1[10000];
    for(int i = 0; i < 100; i++)
    {
        R[i] = rand()%100;
    }
    ShellSort(R, 100);
    BinInsertSort(R, 100);
    QuickSort(R, 0, 99);
    printf("排序的结果：\n");
    for(int i = 0; i < 100; i++)
        printf("%d\t", R[i]);
    for(int i = 0; i < 10000; i++)
    {
        R1[i] = rand()%100;
    }
    clock_t start, end;
    start = clock();
    ShellSort(R1, 10000);
    end = clock();
    printf("\n希尔排序需要的时间为：%f seconds\n", (double)end-start);
    start = clock();
    BinInsertSort(R1, 10000);
    end = clock();
    printf("折半插入排序需要的时间为：%f seconds\n", (double)end-start);
    start = clock();
    QuickSort(R1, 0, 9999);
    end = clock();
    printf("快速排序需要的时间为：%f seconds\n", (double)end-start);
}

int main(int argc, const char * argv[]) {
    //test1();
    //test2();
    //test3();
    //test4();
    //test5();
    test6();
    return 1;
}
