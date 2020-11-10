#include "command_cat.h"

int cat_command(char **args)
{
    char *filename = args[1];
    FILE *fp = NULL;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("no such file %s", filename);
        return 1;
    }
    else
    {
        file_copy(fp, stdout);
        fclose(fp);
        return 1;
    }
}
