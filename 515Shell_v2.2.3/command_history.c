#include "command_history.h"

int history_command()
{
    int rc = fork();
    if (rc < 0)
    {
        // fork failed; exit
        fprintf(stderr, "😺😺😺error:fork failed!\n");
    }
    else if (rc == 0)
    {
        char *arglist[3];
        arglist[0] = "cat";
        arglist[1] = "/home/circle/.bash_history";
        arglist[2] = NULL;
        execvp("cat", arglist);
    }
    else
    {
        wait(NULL);
        //pid=-1 等待任何子进程,相当于 wait()。
        //任意子进程结束，返回子进程结束状态值。
        //options设为0表示不使用这个参数
    }
    return 1;
}
