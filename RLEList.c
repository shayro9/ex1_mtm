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

int RLEListSize(RLEList list)
{
    if(!list){
        return -1;
    }
    if(!list->next){
        return list->len;
    }
    return list->len + RLEListSize(list->next);
}

char RLEListGet(RLEList list, int index, RLEListResult *result)
{
    int size = RLEListSize(list);
    if(!list)
        *result = RLE_LIST_NULL_ARGUMENT;
    if(index >= size)
        *result = RLE_LIST_INDEX_OUT_OF_BOUNDS;
    if(*result != RLE_LIST_SUCCESS)
        return 0;

    if(index <= list->len) {
        *result = RLE_LIST_SUCCESS;
        return list->val;
    }
    return RLEListGet(list->next,index - list->len,result);

}

char* RLEListExportToString(RLEList list, RLEListResult* result)
{
    if(!list){
        *result = RLE_LIST_NULL_ARGUMENT;
        return NULL;
    }
    int size = RLEListSize(list);
    char* out = malloc(size-1);
    for (int i = 0; i < size; ++i) {
        char curr = RLEListGet(list,i,result);
        out[i] = curr;
    }
    *result = RLE_LIST_SUCCESS;
    return out;
}
