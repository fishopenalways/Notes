#include <stdio.h>
#include "hash.h"

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
    unsigned int res = error;
    res = hash_init(100);
    printf("res: %u\n", res);
    return 0;
}