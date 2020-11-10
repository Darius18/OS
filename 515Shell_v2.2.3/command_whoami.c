#include "command_whoami.h"

int whoami_command()
{
    printf("The UID is %d \n", getuid());
    printf("The login name is %s\n", getlogin());
    return 1;
}
