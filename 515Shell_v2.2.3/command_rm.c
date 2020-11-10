#include "command_rm.h"

int rm_command(char **args)
{
    if (remove(args[1]) == 0)
    {
        printf("Remove %s successfully!\n", args[1]);
        return 1;
    }
    else
    {
        perror("Remove:");
        return 1;
    }
}
