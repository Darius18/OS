#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fd = open("test", O_RDWR);//以读写方式打开文件

    if (fd < 0){
            perror("Opening of the file is failed\n");
    }
    else {
            printf("file sucessfully opened\n");
    }
    
    printf("hello darius (pid:%d)\n",(int) getpid());
    int rc = fork();
    if(rc<0){
        fprintf(stderr,"fork failed\n");
        exit(1);
    }else if(rc==0){
        int wc = write(fd,"im baby\n",strlen("im baby\n"));
        if(wc==-1){
            printf("write failed");
        }else{
            printf("write successful!");
        }
        printf("im baby (pic:%d) fd=%d \n",(int)getpid(),fd);
    }else {
        int wc = write(fd,"im dad\n",strlen("im dad\n"));
        if(wc==-1){
            printf("write failed");
        }else{
            printf("write successful!");
        }
        printf("im dad of %d (pid:%d) fd=%d \n",rc,(int)getpid(),fd);
    }
    close(fd); 
    return 0;
}

