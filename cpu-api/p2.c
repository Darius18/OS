#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    printf("hello darius (pid:%d)\n",(int) getpid());
    int rc = fork();
    if(rc<0){
        fprintf(stderr,"fork failed\n");
        exit(1);
    }else if(rc==0){
        printf("im baby (pic:%d)\n",(int) getpid());
    }else {
        int wc = wait(NULL);
        printf("im dad of %d (wc:%d) (pid:%d)\n",rc,wc,(int)getpid());
    }
    return 0;
}