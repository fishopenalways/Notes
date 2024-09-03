#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * test1()
{
    char * p = NULL;
    p = (char *)malloc(10);
    return p;
}

void test2(char *p)
{
    p = (char *)malloc(10);
    return;
}

//指针作为出参，需要提前分配好内存（因为一般都是修改指向内存块的内容），
//不管是堆内存还是栈空间，malloc和局部变量声明都可以
void test3(char *p)
{
    char sz1[10] = "Hello";
    strncpy(p, sz1, 10);
    return;
}

int main()
{
    char *p1 = NULL;
    char *p2 = NULL;
    char sz3[10];
    p1 = test1();
    printf("test1 res: %p\n", p1);
    test2(p2);
    printf("test2 res: %p\n", p2);
    test3(sz3);
    printf("test3 res: %s\n", sz3);
    return 0;
}