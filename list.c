#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    char *p1 = NULL;
    char *p2 = NULL;
    p1 = test1();
    printf("test1 res: %p\n", p1);
    test2(p2);
    printf("test2 res: %p\n", p2);
    return 0;
}