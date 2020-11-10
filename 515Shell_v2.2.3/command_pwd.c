#include "command_pwd.h"

int pwd_command(char **args)
{
    // 获取当前路径
    char buffer[1024];
    char *p = getcwd(buffer, 40);
    printf("%s\n", p);
    return 1;
}
