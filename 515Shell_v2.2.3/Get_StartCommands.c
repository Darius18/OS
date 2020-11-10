#include "Get_StartCommands.h"

int exec_command(char *user_input)
{
    extern char *builtin_str[];
    // char *builtin_str[] = {
    //     "cd",
    //     "help",
    //     "exit",
    //     "whoami",
    //     "history",
    //     "cat",
    //     "cp",
    //     "mkdir",
    //     "mv",
    //     "pwd",
    //     "rm"};
    int (*builtin_func[])(char **) = {
        &cd_command,
        &help_command,
        &exit_command,
        &whoami_command,
        &history_command,
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
    for (j = 0; j < num_builtins(); j++)
    {
        if (strcmp(inputs[0], builtin_str[j]) == 0)
        {
            int result = (*builtin_func[j])(inputs);
            return result;
        }
    }
    
    return launch(inputs);
}