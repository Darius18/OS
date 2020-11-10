#include "command_cd.h"

int cd_command(char **args)
{
    int chas = chdir(args[1]);
    if (chas == -1)
    {
        fprintf(stderr, "error:NO SUCH FILE OR DIRECTORY!\n"); //把格式字符串输出到指定文件设备中
        return 1;
    }
    return 1;
}
