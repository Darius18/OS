#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	int fd[2] = {0, 0};
	int sp = pipe(fd);
	if (sp != 0)
	{
		// 创建管道失败
		return 0;
	}
	// 创建两个子进程
	pid_t p1 = fork();
	if (p1 < 0)
	{
		fprintf(stderr, "fork filed p1\n");
	}
	else if (p1 == 0)
	{
		// p1子进程，写数据到管道
		// 关闭读端
		close(fd[0]);
		char *msg = "Hello world!\n";
		write(fd[1], msg, strlen(msg)); // 向管道写
		close(fd[1]); // 关闭写端
		printf("I am p1, I say \"hello world\" to p2.\n");
		return 0; // p1运行完直接退出；否则p1进程会运行pid_t p2 = fork()
	}

	pid_t p2 = fork();
	if (p2 < 0)
	{
		fprintf(stderr, "fork filed p2\n");
	}
	else if (p2 == 0)
	{
		// p2子进程
		// 等待p1进程完成写操作
		waitpid(p1, NULL, 0);
		close(fd[1]); // 关闭写端
		char buf[1024];
		int len = read(fd[0], buf, 1024); // 从管道中读数据
		if (len > 0)
		{
			buf[len] = '\0';
			printf("I am p2, p1 say: %s\n", buf);
		}
		return 0;
	}

	waitpid(p1, NULL, 0);
	waitpid(p2, NULL, 0);
	printf("I am father, everthing is over!\n");
	return 0;
}