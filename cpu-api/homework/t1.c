#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int x;

int main(int argc, char *argv[])
{
    printf("hello darius (pid:%d)\n",(int) getpid());
    int rc = fork();
    if(rc<0){
        fprintf(stderr,"fork failed\n");
        exit(1);
    }else if(rc==0){
        // x=200;
        printf("im baby (pic:%d) x=%d \n",(int)getpid(),x);
    }else {
        x=100;
        printf("im dad of %d (pid:%d) x=%d \n",rc,(int)getpid(),x);
    }
    return 0;
}