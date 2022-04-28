#include "AsciiArtTool.h"

struct RLEList_t {
    int len;
    char val;
    struct RLEList_t* next;
};

RLEList asciiArtRead(FILE* in_stream){
    RLEList out = RLEListCreate();
    char* input = malloc(sizeof (char)*2);
    char* read = fgets(input,2,in_stream);
    while (read != NULL)
    {
        RLEListAppend(out,read[0]);
        read = fgets(input,2,in_stream);
    }
    free(input);
    free(read);
    return out;
}

RLEListResult asciiArtPrint(RLEList list, FILE *out_stream)
{
    RLEListResult result = RLE_LIST_SUCCESS;
    if(!list)
        return RLE_LIST_NULL_ARGUMENT;
    char* temp = malloc(sizeof (char) * (RLEListSize(list)+1));
    int index = 0;
    while (list->next && result == RLE_LIST_SUCCESS)
    {
        temp[index++] = list->next->val;
        result = RLEListRemove(list, 0);
    }
    temp[index]='\0';
    fputs(temp, out_stream);
    free (temp);
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
    return result;
}