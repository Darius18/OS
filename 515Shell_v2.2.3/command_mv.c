#include "command_mv.h"

int mv_command(char **args)
{
    if (rename(args[1], args[2]) == 0)
    {
        printf("Rename %s to %s.\n", args[1], args[2]);
        return 1;
    }
    else
    {
        perror("rename error");
        return 1;
    }
}
