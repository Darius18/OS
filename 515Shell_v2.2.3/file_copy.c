#include "file_copy.h"

void file_copy(FILE *file1, FILE *file2)
{
    int c = 0;
    while ((c = getc(file1)) != EOF)
    {
        putc(c, file2);
    }
}
