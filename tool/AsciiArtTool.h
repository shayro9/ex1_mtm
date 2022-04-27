//
// Created by michalmaya on 25/04/2022.
//

#ifndef EX1_MTM_ASCIIARTTOOL_H
#define EX1_MTM_ASCIIARTTOOL_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <RLEList.h>

//asciiArtRead reads the given file and makes it into a compressed RLEList
RLEList asciiArtRead(FILE* in_stream);

//asciiArtPrint prints the asciiArt RLEList into the given file
RLEListResult asciiArtPrint(RLEList list, FILE *out_stream);

//asciiArtPrintEncoded prints the compressed asciiArt RLEList into the given file
RLEListResult asciiArtPrintEncoded(RLEList list, FILE *out_stream);

#endif //EX1_MTM_ASCIIARTTOOL_H