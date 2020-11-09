#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ncurses.h>
#define TRUE 1
#define MAX_SIZE 1024

void print_prompt()
{
    char cwd[MAX_SIZE];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        printf("GAGASHELL @ 😺😺😺 :\033[0;34m%s\033[0m💲 ", cwd);
    }
    //getcwd会将当前工作目录的绝对路径复制到参数buffer所指的内存空间中，头文件unistd.h
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
            exit(1);
        }
        else if (rc == 0)
        {
            // child (new process)
            // printf("hello, I am child (pid:%d)\n", (int)getpid());
            printf("son\n");
            char *arglist[3];
            
            arglist[0] = strdup("cat");
            arglist[1] = strdup("~/.bash_history");
            arglist[2] = NULL; 
            printf(arglist[2]);
            execvp('cat', arglist);
        }
        else
        {
            printf("father\n");
            // int *status;
            // waitpid(-1, status, 0);
            int wc = wait(NULL);
            //pid=-1 等待任何子进程,相当于 wait()。
            //任意子进程结束，返回子进程结束状态值。
            //options设为0表示不使用这个参数
        }
        return 0;
    }

    if (strcmp(inputs[0], "cd") == 0)
    {   //内建命令(built-in command)
        //内建命令并非可以调用的可执行程序，它们被直接写在shell中，打开shell的时候就会预加载，在自己的shell中需要自己实现，cd、quit、history都是内建命令
        int chas = chdir(inputs[1]);
        if (chas == -1)
        {
            fprintf(stderr, "🙀🙀🙀❌error:NO SUCH FILE OR DIRECTORY!\n"); //把格式字符串输出到指定文件设备中
        }
        //chdir 是C语言中的一个系统调用函数（同cd），用于改变当前工作目录，其参数为Path 目标目录，可以是绝对目录或相对目录。
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
        int *status;
        waitpid(-1, status, 0); //pid=-1 等待任何子进程,相当于 wait()。
        //任意子进程结束，返回子进程结束状态值。
        //options设为0表示不使用这个参数
    }
    else if (rc == 0)
    { //子进程
        execve(path, inputs, 0);
    }
    else
    {                                                //创建失败
        fprintf(stderr, "🙀🙀🙀❌error:fork failed!\n"); //把格式字符串输出到指定文件设备中
        // 在这里是输出到标准错误输出设备，默认输出到屏幕
        return 1;
    }
    return 0;
}

void main()
{
    while (TRUE)
    {
        char input_string[MAX_SIZE];
        print_prompt();

        // int ch;
        // initscr(); //initialize the ncurses data structures

        // keypad(stdscr, TRUE); //enable special keys capturing

        // ch = getch();
        // if (ch == KEY_UP)
        // {
        //     printf("Key up pressed!");
        //     continue;
        // }

        if (!read_input(input_string))
            continue;

        int len = strlen(input_string);
        input_string[len - 1] = '\0';
        //因为所有的C中的字串操作函数都是以'\0'作为结束标志的
        //前面的fgets是以\n结尾的，需要将其替换成\0
        if (exec_command(input_string))
            break;
    }
}