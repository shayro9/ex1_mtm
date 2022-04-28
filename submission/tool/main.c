#include "AsciiArtTool.h"
#define FLAG_ARG 1
#define SOURCE_ARG 2
#define TARGET_ARG 3

struct RLEList_t {
    int len;
    char val;
    struct RLEList_t* next;
};

char mapFunction(char c) //turns a given characters from a ' ' to a '@' and the other way around.
{
    if (c==' '){
        c= '@';
    } else if(c=='@'){
        c= ' ';
    }
    return c;
}

int main(int argc, char** argv)
{
    char* flag= argv[FLAG_ARG];
    FILE* source= fopen(argv[SOURCE_ARG], "r");
    if (!source){
        return 0;
    }
    FILE* target= fopen(argv[TARGET_ARG], "w");
    if (!target){
        fclose(source);
        return 0;
    }
    RLEList list = asciiArtRead(source);
    if (flag[1] =='e'){
        asciiArtPrintEncoded(list, target);
    }
    if (flag[1] == 'i'){
        RLEListMap(list, mapFunction);
        asciiArtPrint (list, target);
    }
    RLEListDestroy(list);
    fclose(source);
    fclose(target);
    return 0;
}