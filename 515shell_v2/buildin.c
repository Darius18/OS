#include "515head.h"

//这个文件写shell内建函数，但是为了完成作业，把自己实现的不需要内建的函数也都写在了这个文件下，注意区分：带有FOF开头的函数为shell内建函数

char *builtin_str[] = {
    "cd",
    "help",
    "exit",
    "whoami",
    "history",
    "cat",
    "cp",
    "mkdir",
    "mv",
    "pwd",
    "rm"};

int FOF_num_builtins()
{

    return sizeof(builtin_str) / sizeof(char *);
}

/*
  Builtin function implementations.
*/
int FOF_cd()
{
    //内建命令(built-in command)
    //内建命令并非可以调用的可执行程序，它们被直接写在shell中，打开shell的时候就会预加载，在自己的shell中需要自己实现，cd、quit、history都是内建命令
    int chas = chdir(inputs[1]);
    if (chas == -1)
    {
        fprintf(stderr, "🙀🙀🙀❌error:NO SUCH FILE OR DIRECTORY!\n"); //把格式字符串输出到指定文件设备中
    }
    //chdir 是C语言中的一个系统调用函数（同cd），用于改变当前工作目录，其参数为Path 目标目录，可以是绝对目录或相对目录。
    return 1;
}

int FOF_help()
{
    printf("\n #######        #######                                   \n#         ##   #        ####  #    # ###### #      #      \n#        # #   #       #      #    # #      #      #      \n######     #   ######   ####  ###### #####  #      #      \n      #    #         #      # #    # #      #      #      \n#     #    #   #     # #    # #    # #      #      #      \n#####   #####  #####   ####  #    # ###### ###### ###### \n\n");
    int i;
    printf("Thanks for using the 515Shell\n");
    printf("Type program names and arguments, and hit enter.\n");
    printf("The following are built in:\n");

    for (i = 0; i < FOF_num_builtins(); i++)
    {
        printf("  %s\n", builtin_str[i]);
    }

    printf("Use the man command for information on other programs.\n");
    return 1;
}

int FOF_exit()
{
    printf("bye~");
    return 0;
}

int FOF_whoami()
{
    printf("The UID is %d \n", getuid());
    printf("The login name is %s\n", getlogin());
    return 1;
}

int FOF_history()
{
    printf("hello!!");

    int rc = fork();
    if (rc < 0)
    {
        // fork failed; exit
        fprintf(stderr, "🙀🙀🙀❌error:fork failed!\n");
        // exit(1);
        // return 0;
    }
    else if (rc == 0)
    {
        // 有问题
        printf("son\n");
        char *arglist[3];
        arglist[0] = "cat";
        arglist[1] = "/home/circle/.bash_history";
        arglist[2] = NULL;
        execvp("cat", arglist);
    }
    else
    {
        printf("father\n");
        // int *status;
        // waitpid(-1, status, 0);
        wait(NULL);
        //pid=-1 等待任何子进程,相当于 wait()。
        //任意子进程结束，返回子进程结束状态值。
        //options设为0表示不使用这个参数
    }
    return 1;
}

/**
 * 拷贝文件
 * copy file
 **/
void file_copy(FILE *file1, FILE *file2)
{
    int c = 0;
    while ((c = getc(file1)) != EOF)
    {
        putc(c, file2);
    }
}

/**
 * If cat sucessfully, return 1; else return 0.
 **/
int cat_command(char **args)
{
    char *filename = args[1];
    FILE *fp = NULL;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("no such file %s", filename);
        return 0;
    }
    else
    {
        file_copy(fp, stdout);
        fclose(fp);
        return 1;
    }
}

int cp_command(char **args)
{

    // firstly, judge the file of source and dest whether exit
    FILE *fp1 = NULL;
    FILE *fp2 = NULL;
    if ((fp1 = fopen(args[1], "r")) == NULL)
    {
        printf("no such file %s.\n", args[1]);
        return 0;
    }
    // If dest is not exit, create it
    if ((fp2 = fopen(args[2], "w")) == NULL)
    {
        return 0;
    }

    file_copy(fp1, fp2);
    fclose(fp1);
    fclose(fp2);
    return 1;
}

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
        return 0;
    }
}

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
        return 0;
    }
}

int pwd_command(char **args)
{
    // 获取当前路径
    char buffer[1024];
    char *p = getcwd(buffer, 40);
    printf("p:%s\n", p);
    return 1;
}

int rm_command(char **args)
{
    // printf("rm_command, filename: %s\n", filename);
    if (remove(args[1]) == 0)
    {
        printf("Remove %s successfully!\n", args[1]);
        return 1;
    }
    else
    {
        perror("Remove:");
        return 0;
    }
}