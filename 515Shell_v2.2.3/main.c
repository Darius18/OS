#include "type_prompt.h"
#include "Get_StartCommands.h"

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
        int result = exec_command(input_string);
        if (!result) //结果为0的时候退出！
            break;
    }
    return 0;
}
