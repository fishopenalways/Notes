#include <stdio.h>

typedef unsigned int u32;

void test1()
{
    u32 a = 0xffffffff;
    printf("num: %d\n", a);
    printf("num: %u\n", a);
    return;
}

int main()
{
    test1();
    return 0;
}