/*
 * =====================================================================================
 *       Filename:  515shell.h
 *    Description:  Tributes to 515lab
 *        Version:  3.0
 *        Created:  2020.11.8
 *         Author:  C.JiangChao L.ZiYu Z.Chi
 *        Company:  HENU
 * =====================================================================================
 */
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ncurses.h>
#include <sys/stat.h>
#include <pwd.h>
#include <math.h>

#define TRUE 1
#define MAX_SIZE 1024

void file_copy(FILE *file1, FILE *file2);
struct passwd *pwd;

void print_prompt();
int exec_command(char *user_input);
int FOF_launch(char **args);
int FOF_num_builtins();
int read_input(char *str);

/*
  Function Declarations for builtin shell commands:
 */
int FOF_cd();
int FOF_help();
int FOF_exit();
int FOF_whoami();
int FOF_history();
int cat_command(char **args);
int cp_command(char **args);
int mkdir_command(char **args);
int mv_command(char **args);
int pwd_command(char **args);
int rm_command(char **args);

/*
  List of builtin commands, followed by their corresponding functions.
 */
// char *builtin_str[11];

// int (*builtin_func[])(char **);

//切割后的输入字符
char *inputs[MAX_SIZE];

//return 0 退出
//return 1 正常进行