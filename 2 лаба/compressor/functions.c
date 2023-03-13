#include "functions.h"

char* transfer(char* text)
{
    FILE* f;

    f = fopen("C:/Users/bukat/Desktop/~/ОАиП/2sem/2 лаба/compressor/text.txt", "rt+");
    if (f == NULL)
    {
        printf("Error opening file");
        return 0;
    }

    fseek(f, 0, SEEK_END);
    long length = ftell(f);
    fseek(f, 0, SEEK_SET);
}