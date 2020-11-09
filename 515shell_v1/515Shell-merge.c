#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ncurses.h>
#include <sys/stat.h>
#include <pwd.h>

#define TRUE 1
#define MAX_SIZE 1024

void file_copy(FILE *file1, FILE *file2);
int cat_command(char *filename);
int cp_command(char *source, char *dest);
int mv_command(char *oldname, char *newname);
int mkdir_command(char *dir);
int pwd_command();
int rm_command(char *path);
struct passwd *pwd;

void print_prompt()
{
    const int max_name_len = 256;
    char hostname[max_name_len];
    char cwd[MAX_SIZE];
    pwd = getpwuid(getuid());
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        if (gethostname(hostname, max_name_len) == 0)
        { //返回主机名
            printf("😺 515SHELL😺  %s @ %s :\033[0;34m%s\033[0m💲 ", pwd->pw_name, hostname, cwd);
        }
        else
        {
            printf("😺 515SHELL😺 @ unknown :\033[0;34m%s\033[0m💲 ", cwd);
        }
    }
    else
    {
        printf("🙀515SHELL🙀 : something went wrong...");
    }
}

int read_input(char *str)
{
    char buf[MAX_SIZE];
    fgets(buf, MAX_SIZE, stdin); //从指定的流中读取数据，每次读取一行
    if (strlen(buf) != 1)
    {
        strcpy(str, buf);
        return 1;
    }
    else
    {
        return 0;
    }
}

int command_whoami()
{
    printf("The UID is %d \n", getuid());
    printf("The login name is %s\n", getlogin());
    return 0;
}

int exec_command(char *user_input)
{
    char *inputs[MAX_SIZE];
    bzero(inputs, MAX_SIZE);               // 置字节字符串s的前n个字节为零
    char *token = strtok(user_input, " "); //按空格分解字符串user_input
    //首次调用时，第一个参数指向要分解的字符串，返回的是空格前面的字符
    //之后再次调用要把s设成NULL
    //这个函数会破坏字符串的完整性
    int i = 0;
    while (token != NULL)
    {
        inputs[i] = token;
        // printf("input[%d]: %s", i, inputs[i]);
        i++;
        token = strtok(NULL, " ");
    }

    if (strcmp(inputs[0], "exit") == 0)
    { //字符串比较
        printf("Bye~\n");
        return 1;
    }

    if (strcmp(inputs[0], "whoami") == 0)
    { //字符串比较
        if (command_whoami() != 0)
        {
            fprintf(stderr, "🙀🙀🙀❌error:I DONT KNOW WHO YOU R!\n"); //把格式字符串输出到指定文件设备中
        }
        return 0;
    }

    if (strcmp(inputs[0], "history") == 0)
    { //字符串比较
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
        return 0;
    }

    if (strcmp(inputs[0], "cd") == 0)
    { //内建命令(built-in command)
        //内建命令并非可以调用的可执行程序，它们被直接写在shell中，打开shell的时候就会预加载，在自己的shell中需要自己实现，cd、quit、history都是内建命令
        int chas = chdir(inputs[1]);
        if (chas == -1)
        {
            fprintf(stderr, "🙀🙀🙀❌error:NO SUCH FILE OR DIRECTORY!\n"); //把格式字符串输出到指定文件设备中
        }
        //chdir 是C语言中的一个系统调用函数（同cd），用于改变当前工作目录，其参数为Path 目标目录，可以是绝对目录或相对目录。
        return 0;
    }

    if (strcmp(inputs[0], "cat") == 0)
    {
        cat_command(inputs[1]);
        return 0;
    }

    if (strcmp(inputs[0], "cp") == 0)
    {
        cp_command(inputs[1], inputs[2]);
        return 0;
    }

    if (strcmp(inputs[0], "mkdir") == 0)
    {
        mkdir_command(inputs[1]);
        return 1;
    }

    if (strcmp(inputs[0], "mv") == 0)
    {
        mv_command(inputs[1], inputs[2]);
        return 0;
    }

    if (strcmp(inputs[0], "pwd") == 0)
    {
        pwd_command();
        return 0;
    }

    if (strcmp(inputs[0], "rm") == 0)
    {
        rm_command(inputs[1]);
        return 0;
    }

    char path[100];
    bzero(path, 100);
    strcat(path, "/bin/"); //将两个char类型连接
    ///bin: /usr/bin: 可执行二进制文件的目录，如常用的命令ls、tar、mv、cat等。
    strcat(path, inputs[0]);
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
        execve(path, inputs, 0);
    }
    else
    {                                                //创建失败
        fprintf(stderr, "🙀🙀🙀❌error:fork failed!\n"); //把格式字符串输出到指定文件设备中
        //在这里是输出到标准错误输出设备，默认输出到屏幕
        return 1;
    }
    return 0;
}

int main()
{
    while (TRUE)
    {
        char input_string[MAX_SIZE];
        print_prompt();
        if (!read_input(input_string))
            continue;

        int len = strlen(input_string);
        input_string[len - 1] = '\0';
        //因为所有的C中的字串操作函数都是以'\0'作为结束标志的
        //前面的fgets是以\n结尾的，需要将其替换成\0
        if (exec_command(input_string)) //结果为1的时候退出！
            break;
    }
    return 0;
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
 * If cat sucessfully, return 0; else return 1.
 **/
int cat_command(char *filename)
{
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

/**
 * If cp successfully, return 0; else return 1.
 **/
int cp_command(char *source, char *dest)
{
    // firstly, judge the file of source and dest whether exit
    FILE *fp1 = NULL;
    FILE *fp2 = NULL;
    if ((fp1 = fopen(source, "r")) == NULL)
    {
        printf("no such file %s.\n", source);
        return 1;
    }
    // If dest is not exit, create it
    if ((fp2 = fopen(dest, "w")) == NULL)
    {
        return 1;
    }

    file_copy(fp1, fp2);
    fclose(fp1);
    fclose(fp2);
    return 0;
}

/**
 * create a direction
 * If success return 0, else return 1.
 **/
int mkdir_command(char *dir)
{
    /**
     * make a direction
     * S_IRWXU: Read, write, and execute by owner.
     * S_IRGRP: Read by group.
     * S_IWGRP: Write by group.
     * S_IROTH: Read by others.
     **/
    int result = mkdir(dir, S_IRWXU | S_IRGRP | S_IWGRP | S_IROTH);
    if (result == 0)
    {
        printf("mkdir %s successfully!\n", dir);
        return 0;
    }
    else
    {
        perror("mkdir");
        return 1;
    }
}

int mv_command(char *oldname, char *newname)
{
    if (rename(oldname, newname) == 0)
    {
        printf("Rename %s to %s.\n", oldname, newname);
        return 1;
    }
    else
    {
        perror("rename error");
        return 0;
    }
}

int pwd_command()
{
    // 获取当前路径
    char buffer[1024];
    char *p = getcwd(buffer, 40);
    printf("p:%s\n", p);
    return 1;
}

/**
 * according path to remove a file or direction
**/
int rm_command(char *filename)
{
    // printf("rm_command, filename: %s\n", filename);
    if (remove(filename) == 0)
    {
        printf("Remove %s successfully!\n", filename);
        return 1;
    }
    else
    {
        perror("Remove:");
        return 0;
    }
}
