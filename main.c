#include "RLEList.h"
#include "AsciiArtTool.h"
//-----------!!!!!!!!FOR BASIC TESTING!!!!!!!----------------
int main()
{
    FILE* file = fopen("../tests/dog.txt","r");
    if(!file)
    {
        printf("XXX");
        return 0;
    }
    RLEList list = RLEListCreate();
    list = asciiArtRead(file);
    FILE* out = fopen("../tests/test.txt","w");
    if(out)
        asciiArtPrintEncoded(list,out);
    return 0;
}
