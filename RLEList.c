#include "RLEList.h"
#include <stdlib.h>
#include "string.h"
#define NEW_LEN 1


struct RLEList_t {
    int len;
    char val;
    struct RLEList_t* next;
};


//--------------------STATIC FUNCTIONS--------------------------------
static void updateResult(RLEListResult *result, RLEListResult val);
static int calcPower(int base, int power);
static int RLENodes(RLEList list);
static char digitToChar(int dig);
static char* intToString(int num);
static int appearancesArray(RLEList list, int* array);
static void mergeAdjacentNodes(RLEList first_node, RLEList second_node);

//-------------------STATIC IMPLEMENTATION---------------------------
static void updateResult(RLEListResult *result, RLEListResult val)
{
    if(result)
        *result = val;
}
static int calcPower(int base, int power)
{
    int out = 1;
    for (int i = 0; i < power; ++i) {
        out *= base;
    }
    return out;
}
static int RLENodes(RLEList list)
{
    if(!list)
        return 0;
    return RLENodes(list->next) + 1;
}
static char digitToChar(int dig)
{
    return (char)('0' + dig);
}
static char* intToString(int num)
{
    int tempNum = num;
    int digits = 0;
    while(tempNum > 0)
    {
        digits++;
        tempNum /= 10;
    }
    char* out = malloc(sizeof (char) * (digits+1));
    for (int i = 0; i < digits; ++i) {
        int digit_index = calcPower(10,digits-1-i);
        out[i] = digitToChar(num/digit_index);
        num %= digit_index;
    }
    out[digits] = '\0';
    return out;
}
static int appearancesArray(RLEList list, int* array)
{
    int index = 0, sum = 0;
    while (list)
    {
        if(list->len > 0)
            array[index] = (int)strlen(intToString(list->len));
        else
            array[index] = 0;
        sum += array[index];
        list = list->next;
        index++;
    }
    return sum;
}
static void mergeAdjacentNodes(RLEList firstNode, RLEList secondNode)
{
    firstNode->len += secondNode->len;
    firstNode->next = secondNode->next;
    free(secondNode);
}

//------------------RLEList Functions---------------------------------
RLEList RLEListCreate()
{
    RLEList list= malloc(sizeof(*list));
    if (!list){
        return NULL;
    }
    list->len = 0;
    list->val = 0;
    list->next = NULL;
    return list;
}

void RLEListDestroy(RLEList list)
{
    if(!list) {
        return;
    }
    RLEListDestroy(list->next);
    free(list);
}

RLEListResult RLEListAppend(RLEList list, char value)
{
    if (!list){
        return RLE_LIST_NULL_ARGUMENT;
    }
    if (!list->next){
        if (list->val == value){
            list->len++;
            return RLE_LIST_SUCCESS;
        }
        else {
            RLEList temp = malloc(sizeof(*temp));
            if (!temp) {
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

RLEListResult RLEListRemove(RLEList list, int index)
{
    if (list==NULL){
        return RLE_LIST_NULL_ARGUMENT;
    }
    if ((!(list->next) && index >= list->len) || index < 0){
        return RLE_LIST_INDEX_OUT_OF_BOUNDS;
    }

    int currNodeLen = list->len;
    int nextNodeLen = list->next->len;
    if (index < currNodeLen + nextNodeLen){
        if (nextNodeLen > NEW_LEN){
            list->next->len--;
            return RLE_LIST_SUCCESS;
        }
        RLEList temp = list->next;
        if(!temp->next)
            list->next = NULL;
        else
        {
            if(list->val == temp->next->val) {
                mergeAdjacentNodes(list,temp->next);
            }
            else
                list->next = list->next->next;
        }
        free(temp);
        return RLE_LIST_SUCCESS;
    }
    return RLEListRemove (list->next, index - (list->len));
}

char RLEListGet(RLEList list, int index, RLEListResult *result)
{
    if (!list) {
        updateResult(result,RLE_LIST_NULL_ARGUMENT);
        return 0;
    }

    if((!list->next && index >= list->len) || index < 0) {
        updateResult(result, RLE_LIST_INDEX_OUT_OF_BOUNDS);
        return 0;
    }

    if(index < list->next->len + list->len) {
        updateResult(result,RLE_LIST_SUCCESS);
        return list->next->val;
    }
    return RLEListGet(list->next,index - list->len,result);

}

char* RLEListExportToString(RLEList list, RLEListResult* result)
{
    if(!list){
        updateResult(result,RLE_LIST_NULL_ARGUMENT);
        return NULL;
    }

    int nodes = RLENodes(list), appearLenSum;
    int* appearLen = malloc(sizeof(int) * nodes);
    appearLenSum = appearancesArray(list,appearLen);

    char* out = malloc(sizeof (char) *((nodes-1)*2 + appearLenSum)+1);
    if(!out)
    {
        updateResult(result,RLE_LIST_ERROR);
        return NULL;
    }

    int outIndex = 0, linesIndex = 1;
    while(list->next)
    {
        list = list->next;
        char* appearances = intToString(list->len);
        out[outIndex++] = list->val;
        for (int i = 0; i < appearLen[linesIndex]; ++i) {
            out[outIndex++] = appearances[i];
        }
        out[outIndex++] = '\n';

        linesIndex++;
    }
    out[outIndex]='\0';
    free(appearLen);
    updateResult(result,RLE_LIST_SUCCESS);

    return out;
}

RLEListResult RLEListMap(RLEList list, MapFunction mapFunction){
    if (!mapFunction){
        return RLE_LIST_NULL_ARGUMENT;
    }
    if (!list){
        return RLE_LIST_NULL_ARGUMENT;
    }
    if (!(list ->next)){
        list->val = mapFunction(list->val);
        return RLE_LIST_SUCCESS;
    }
    RLEListMap (list ->next, mapFunction);
    list->val = mapFunction(list->val);
    return RLE_LIST_SUCCESS;
}