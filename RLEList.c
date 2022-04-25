#include "RLEList.h"
#include <stdlib.h>
#include "string.h"
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
    if ((!(list->next) && index >= list->len) || index < 0){
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
        list ->val = map_function(list ->val);
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
static char DigitToChar(int dig)
{
    return (char)('0' + dig);
}
static char* IntToString(int num)
{
    char* out = malloc(sizeof (char) * 2);
    int index = 0;
    while(num > 0)
    {
        if(index > 0)
            realloc(out,sizeof (char) * (index+2));
        out[index++] = DigitToChar(num%10);
        out[index] = '\0';
        num /= 10;
    }
    return out;
}
static char* ReverseString(char* str)
{
    int len = (int)strlen(str);
    for (int i = 0; i < len / 2; ++i) {
        char temp = str[i];
        str[i] = str[len-(i+1)];
        str[len - (i+1)] = temp;
    }
    return str;
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
    if (!list) {
        UpdateResult(result,RLE_LIST_NULL_ARGUMENT);
        return 0;
    }

    if((!list->next && index >= list->len) || index < 0) {
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
    list = list->next;
    int size = RLEListSize(list);
    int nodes = RLENodes(list);
    char* appearances = ReverseString(IntToString(list->len));
    int appear_len = (int)strlen(appearances);
    char* out = malloc(sizeof (char) *(3 + appear_len));
    if(!out)
    {
        UpdateResult(result,RLE_LIST_ERROR);
        return NULL;
    }

    int index = 0, out_index = 0;
    while(index < size)
    {
        out[out_index++] = list->val;
        for (int i = 0; i < appear_len; ++i) {
            out[out_index++] = appearances[i];
        }
        out[out_index++] = '\n';
        out[out_index] = '\0';

        index += list->len;
        list = list->next;
    }

    UpdateResult(result,RLE_LIST_SUCCESS);

    return out;
}
