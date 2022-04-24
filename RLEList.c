#include "RLEList.h"
#include "stdlib.h"

struct RLEList_t{
    int len;
    char val;
    struct RLEList_t* next;
};

static void UpdateResult(RLEListResult *result, RLEListResult val)
{
    if(result)
        *result = val;
}
static int RLENodes(RLEList list)
{
    if(!list)
        return 0;
    return RLENodes(list->next) + 1;
}

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
    if (!list) {
        UpdateResult(result,RLE_LIST_NULL_ARGUMENT);
        return 0;
    }
    if (index >= size) {
        UpdateResult(result, RLE_LIST_INDEX_OUT_OF_BOUNDS);
        return 0;
    }

    if(index <= list->len) {
        UpdateResult(result,RLE_LIST_SUCCESS);
        return list->val;
    }
    return RLEListGet(list->next,index - list->len,result);

}

char* RLEListExportToString(RLEList list, RLEListResult* result)
{
    if(!list){
        UpdateResult(result,RLE_LIST_NULL_ARGUMENT);
        return NULL;
    }

    int size = RLEListSize(list);
    int nodes = RLENodes(list);
    char* out = malloc(nodes * 3);
    if(!out)
    {
        UpdateResult(result,RLE_LIST_ERROR);
        return NULL;
    }

    int index = 0, out_index = 0;
    while(index < size)
    {
        out[out_index] = list->val;
        out[out_index + 1] = (char) list->len;
        out[out_index + 2] = '\n';
        index += list->len;
        out_index += 3;
        list = list->next;
    }

    UpdateResult(result,RLE_LIST_SUCCESS);

    return out;
}
