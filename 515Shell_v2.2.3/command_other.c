#include "command_other.h"

int launch(char **args)
{
    char path[100];
    bzero(path, 100);
    strcat(path, "/bin/"); //将两个char类型连接
    ///bin: /usr/bin: 可执行二进制文件的目录，如常用的命令ls、tar、mv、cat等。
    strcat(path, args[0]);
    int rc = fork();
    if (rc > 0)
    { //父进程
        waitpid(-1, 0, 0);
    }
    else if (rc == 0)
    { //子进程
        int result = execve(path, args, 0);
        if (result == -1)
        {
            printf("can not find %s\n", inputs[0]);
        }
        exit(0);
    }
    else
    {                                                //创建失败
        fprintf(stderr, "🙀🙀🙀❌error:fork failed!\n"); //把格式字符串输出到指定文件设备中
        //在这里是输出到标准错误输出设备，默认输出到屏幕
        return 0;
    }
    return 1;
}