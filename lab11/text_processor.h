#ifndef LAB11_TEXT_PROCESSOR_H
#define LAB11_TEXT_PROCESSOR_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int CountUniqueLetters(const char *word);
void RemoveMaxUniqueWord(char *line);
void GenerateHTML(const char *inputFile, const char *outputFile);

#endif //LAB11_TEXT_PROCESSOR_H