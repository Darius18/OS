#include "515head.h"

//这个文件负责两个功能：切割字符串，开启进程（内建和系统调用）
//

int exec_command(char *user_input)
{

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

    int (*builtin_func[])(char **) = {
        &FOF_cd,
        &FOF_help,
        &FOF_exit,
        &FOF_whoami,
        &FOF_history,
        &cat_command,
        &cp_command,
        &mkdir_command,
        &mv_command,
        &pwd_command,
        &rm_command,
    };

    //************************************切割字符串***********************************************
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

    //************************************开启进程***********************************************

    int j;

    if (inputs[0] == NULL)
    {
        // An empty command was entered.
        return 1;
    }

    for (j = 0; j < FOF_num_builtins(); j++)
    {
        if (strcmp(inputs[0], builtin_str[j]) == 0)
        {
            return (*builtin_func[j])(inputs);
        }
    }

    return FOF_launch(inputs);

    return 0;
}