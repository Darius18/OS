#include "command_cp.h"

int cp_command(char **args)
{
    // firstly, judge the file of source and dest whether exit
    FILE *fp1 = NULL;
    FILE *fp2 = NULL;
    if ((fp1 = fopen(args[1], "r")) == NULL)
    {
        printf("no such file %s.\n", args[1]);
        return 1;
    }
    // If dest is not exit, create it
    if ((fp2 = fopen(args[2], "w")) == NULL)
    {
        return 1;
    }

    file_copy(fp1, fp2);
    fclose(fp1);
    fclose(fp2);
    return 1;
}
