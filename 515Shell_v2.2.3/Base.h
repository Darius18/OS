#ifndef BASE_H_INCLUDED
#define BASE_H_INCLUDED
/*
 * =====================================================================================
 *       Filename:  515shell.h
 *    Description:  Tributes to 515lab
 *        Version:  3.1
 *        Created:  2020.11.9
 *         Author:  C.JiangChao L.ZiYu Z.Chi
 *        Company:  HENU
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <pwd.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 1024
struct passwd *pwd;

//切割后的输入字符
char *inputs[MAX_SIZE];

int num_builtins();

#endif // BASE_H_INCLUDED
