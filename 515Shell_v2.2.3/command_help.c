#include "command_help.h"

int help_command()
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
    printf("\n #######        #######                                   \n#         ##   #        ####  #    # ###### #      #      \n#        # #   #       #      #    # #      #      #      \n######     #   ######   ####  ###### #####  #      #      \n      #    #         #      # #    # #      #      #      \n#     #    #   #     # #    # #    # #      #      #      \n#####   #####  #####   ####  #    # ###### ###### ###### \n\n");
    int i;
    printf("Thanks for using the 515Shell\n");
    printf("Type program names and arguments, and hit enter.\n");
    printf("The following are built in:\n");

    for (i = 0; i < num_builtins(); i++)
    {
        printf("  %s\n", builtin_str[i]);
    }

    printf("Use the man command for information on other programs.\n");
    return 1;
}
