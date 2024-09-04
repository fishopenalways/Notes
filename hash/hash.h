#ifndef _HASH_H_
#define _HASH_H_

#include "base.h"

u32 hash_init(u32 len);
void hash_add_item(u32 num);
void hash_del_item(u32 num);
u32 hash_get_item(u32 num);
void hash_fini();

#endif //end of _HASH_H_