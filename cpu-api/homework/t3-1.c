#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>//访问操作系统API
 
void * Pthreadfunc1()
{
    printf("HELLO!!!\n");
    
    pthread_exit((void*)1);  //线程退出
}
 
int main(int argc, char * argv [ ])
{
    int iRet = 0;
    void *rval = NULL;
    pthread_t pid1;
 
    iRet = pthread_create(&pid1, NULL, Pthreadfunc1, NULL);     //创建一个线程pthreadfunc1
    // if(0 != iRet)
    // {
    //     printf("pthread_create error, %s,%d\n", (char *)strerror(errno), errno);
    //     return -1;
    // }
 
    pthread_join(pid1, &rval);  //线程等待，线程退出的值存放在rval中
    // printf("rval= %d\n",(intptr_t)rval);
    printf("GOODBYE!!!\n");
    
    return 0;
}