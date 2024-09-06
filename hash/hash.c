#include <stdlib.h>
#include <stdio.h>
#include "hash.h"

#define ignore_param(x) ((x) = (x))

static u32 *g_u32pHashArr;
static u32 g_HashArrLen;
static u32 hashcode(u32 item);

u32 hash_init(u32 len)
{
    int *hash_arr = (int *)calloc(len, sizeof(u32));
    if(NULL == hash_arr)
    {
        fprintf(stderr, "mem not enough!\n");
        return error;
    }
    g_u32pHashArr = hash_arr;
    g_HashArrLen = len;
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
    u32 key = hashcode(num);
    
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
    return ;
}

static u32 hashcode(u32 item)
{
    u32 key = item % g_HashArrLen;
    return key;
}