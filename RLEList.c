#include "RLEList.h"
#include "stdlib.h"

struct RLEList_t{
    int len;
    char val;
    struct RLEList_t* next;
};

void RLEListDestroy(RLEList list)
{
    if(!list) {
        return;
    }
    RLEListDestroy(list->next);
    free(list);
}