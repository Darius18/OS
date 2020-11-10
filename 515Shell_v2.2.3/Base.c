#include "Base.h"
#include "property.h"

int num_builtins()
{
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
    return sizeof(builtin_str) / sizeof(char *);
}
