#include "AsciiArtTool.h"

typedef struct RLEList_t {
    int len;
    char val;
    struct RLEList_t* next;
}*RLEList;

RLEList asciiArtRead(FILE* in_stream){
    RLEList out = RLEListCreate();
    char* read = fgets("",2,in_stream);
    while (read != NULL)
    {
        RLEListAppend(out,read[0]);
        read = fgets("",2,in_stream);
    }
    fclose(in_stream);
    return out;
}

RLEListResult asciiArtPrint(RLEList list, FILE *out_stream)
{
    RLEListResult result = RLE_LIST_SUCCESS;
    if(!list)
        return RLE_LIST_NULL_ARGUMENT;

    char* temp = malloc(sizeof (char) * RLEListSize(list));
    int index = 0;
    while (list->next && result == RLE_LIST_SUCCESS)
    {
        temp[index++] = list->next->val;
        result = RLEListRemove(list, 0);
    }
    temp[index]='\0';
    fputs(temp, out_stream);
    fclose(out_stream);
    return result;
}

RLEListResult asciiArtPrintEncoded(RLEList list, FILE *out_stream)
{
    RLEListResult result;
    if(!out_stream) {
        fclose(out_stream);
        return RLE_LIST_NULL_ARGUMENT;
    }
    char* out = RLEListExportToString(list, &result);
    fputs(out, out_stream);
    fclose(out_stream);
    return result;
}