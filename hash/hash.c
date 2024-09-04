#include <stdlib.h>
#include <stdio.h>
#include "hash.h"

#define ok 0
#define error 1
#define ignore_param(x) ((x) = (x))

static int *g_u32pHashArr;

u32 hash_init(u32 len)
{
    u32 res = ok;
    int *hash_arr = (int *)calloc(len, sizeof(u32));
    if(NULL == hash_arr)
    {
        fprintf(stderr, "mem not enough!\n");
        return error;
    }
    g_u32pHashArr = hash_arr;
    return ok;
}

void hash_fini()
{
    if(NULL == g_u32pHashArr)
    {
        fprintf(stdout, "no need to fini\n");
        return;
    }

    free(g_u32pHashArr);
    g_u32pHashArr = NULL;
    return;
}

void hash_add_item(u32 num)
{
    //todo
    ignore_param(num);
    return;
}

void hash_del_item(u32 num)
{
    //todo
    ignore_param(num);
    return;
}

u32 hash_get_item(u32 num)
{
    //todo
    u32 res = num;
    return res;
}