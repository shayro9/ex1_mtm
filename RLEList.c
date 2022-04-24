#include "RLEList.h"
#include <stdlib.h>
#define NEW_LEN 1


typedef struct RLEList_t {
    int len;
    char val;
    struct RLEList_t* next;
}*RLEList;

RLEList RLEListCreate(){
    RLEList list= malloc(sizeof(*list));
    if (list==NULL){
        return NULL;
    }
    list ->len =0;
    list ->val= 0;
    list ->next= NULL;
    return list;
}

RLEListResult RLEListAppend(RLEList list, char value){
    if (list== NULL){
        return RLE_LIST_NULL_ARGUMENT;
    }
    if (list ->next== NULL){
        if (list ->val==value){
            list ->len++;
            return RLE_LIST_SUCCESS;
        }
        else {
            RLEList temp = malloc(sizeof(*temp));
            if (temp == NULL) {
                return RLE_LIST_OUT_OF_MEMORY;
            }
            temp->val = value;
            temp->len = NEW_LEN;
            temp->next = NULL;
            list->next = temp;
            return RLE_LIST_SUCCESS;
        }
    }
    return RLEListAppend(list->next, value);
}

RLEListResult RLEListRemove(RLEList list, int index){
    if (list==NULL){
        return RLE_LIST_NULL_ARGUMENT;
    }
    if (index > RLEListSize(list)){
        return RLE_LIST_INDEX_OUT_OF_BOUNDS;
    }
    int curr_node_len = list->len;
    int next_node_len = list->next->len;
    if (index < curr_node_len + next_node_len){
        if (next_node_len > NEW_LEN){
            list->next ->len--;
            return RLE_LIST_SUCCESS;
        }
        RLEList temp = list->next;
        list->next = list->next->next;
        free(temp);
        return RLE_LIST_SUCCESS;
    }
    return RLEListRemove (list ->next, index- (list ->len));
}

RLEListResult RLEListMap(RLEList list, MapFunction map_function){
    if (map_function== NULL){
        return RLE_LIST_NULL_ARGUMENT;
    }
    if (list== NULL){
        return RLE_LIST_NULL_ARGUMENT;
    }
    if ((list ->next)==NULL){
        list ->next ->val = map_function(list ->next ->val);
        return RLE_LIST_SUCCESS;
    }
    RLEListMap (list ->next, map_function);
    list ->val = map_function(list ->val);
    return RLE_LIST_SUCCESS;
}

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

    if(index < list-> next->len + list->len) {
        UpdateResult(result,RLE_LIST_SUCCESS);
        return list->next->val;
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
