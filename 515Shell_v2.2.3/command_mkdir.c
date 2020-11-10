#include "command_mkdir.h"

int mkdir_command(char **args)
{
    /**
     * make a direction
     * S_IRWXU: Read, write, and execute by owner.
     * S_IRGRP: Read by group.
     * S_IWGRP: Write by group.
     * S_IROTH: Read by others.
     **/
    int result = mkdir(args[1], S_IRWXU | S_IRGRP | S_IWGRP | S_IROTH);
    if (result == 0)
    {
        printf("mkdir %s successfully!\n", args[1]);
        return 1;
    }
    else
    {
        perror("mkdir");
        return 1;
    }
}
