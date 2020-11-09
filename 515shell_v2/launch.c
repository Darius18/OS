#include "515head.h"

//这个文件负责唤醒其他没有内建的功能，直接使用系统调用

int FOF_launch(char **args){

    char path[100];
    bzero(path, 100);
    strcat(path, "/bin/"); //将两个char类型连接
    ///bin: /usr/bin: 可执行二进制文件的目录，如常用的命令ls、tar、mv、cat等。
    strcat(path, args[0]);
    int rc = fork();
    if (rc > 0)
    { //父进程
        //int *status;
        //waitpid(-1, status, 0); //pid=-1 等待任何子进程,相当于 wait()。
        //任意子进程结束，返回子进程结束状态值。
        //options设为0表示不使用这个参数
        wait(NULL);
    }
    else if (rc == 0)
    { //子进程
        execve(path, args, 0);
    }
    else
    {                                                //创建失败
        fprintf(stderr, "🙀🙀🙀❌error:fork failed!\n"); //把格式字符串输出到指定文件设备中
        //在这里是输出到标准错误输出设备，默认输出到屏幕
        return 0;
    }
    return 1;
}