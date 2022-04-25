#include "RLEList.h"
#include <stdlib.h>
#include "string.h"
#include "math.h"
#define NEW_LEN 1


typedef struct RLEList_t {
    int len;
    char val;
    struct RLEList_t* next;
}*RLEList;


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
    int temp_num = num;
    int digits = 0;
    while(temp_num > 0)
    {
        digits++;
        temp_num /= 10;
    }
    char* out = malloc(sizeof (char) * (digits+1));
    for (int i = 0; i < digits; ++i) {
        int digit_index = (int)(pow(10,digits-1-i));
        out[i] = DigitToChar(num/digit_index);
        num %= digit_index;
    }
    out[digits] = '\0';
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
static void AppearancesArray(RLEList list, int* array)
{
    int index = 0;
    while (list)
    {
        if(list->len > 0)
            array[index] = (int)strlen(IntToString(list->len));
        list = list->next;
        index++;
    }
}
static void MergeAdjacentNodes(RLEList first_node, RLEList second_node)
{
    first_node->len += second_node->len;
    first_node->next = second_node->next;
    free(second_node);
}

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
        if(!temp->next)
            list->next = NULL;
        else
        {
            if(list->val == temp->next->val) {
                MergeAdjacentNodes(list,temp->next);
            }
            else
                list->next = list->next->next;
        }
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

    int size = RLEListSize(list);
    int nodes = RLENodes(list);
    int* appear_len = malloc(sizeof(int) * nodes);
    for (int i = 0; i < nodes; ++i) {
        appear_len[i] = 0;
    }
    AppearancesArray(list,appear_len);
    int appear_len_sum = 0;
    for (int i = 0; i < nodes; ++i) {
        appear_len_sum += appear_len[i];
    }

    char* out = malloc(sizeof (char) *((nodes-1)*2 + appear_len_sum)+1);
    if(!out)
    {
        UpdateResult(result,RLE_LIST_ERROR);
        return NULL;
    }

    int index = 0, out_index = 0, lines_index = 1;
    while(index < size)
    {
        list = list->next;
        char* appearances = IntToString(list->len);
        out[out_index++] = list->val;
        for (int i = 0; i < appear_len[lines_index]; ++i) {
            out[out_index++] = appearances[i];
        }
        out[out_index++] = '\n';

        index += list->len;
        lines_index++;
    }
    out[out_index]='\0';
    free(appear_len);
    UpdateResult(result,RLE_LIST_SUCCESS);

    return out;
}
