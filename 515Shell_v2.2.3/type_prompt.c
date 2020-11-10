#include "type_prompt.h"

void print_prompt()
{
    const int max_name_len = 256;
    char hostname[max_name_len];
    char cwd[MAX_SIZE];
    pwd = getpwuid(getuid());
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        if (gethostname(hostname, max_name_len) == 0){//返回主机名
            printf("😺 515SHELL😺  %s @ %s :\033[0;34m%s\033[0m💲 ", pwd->pw_name,hostname,cwd);
        }else{
            printf("😺 515SHELL😺 @ unknown :\033[0;34m%s\033[0m💲 ", cwd);
        }
    }else{
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