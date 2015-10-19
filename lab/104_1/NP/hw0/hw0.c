#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/file.h>
#define SEQFILE "seq.t"
int main(){
    fork();
    int pid = getpid();
    int fd;
    char buf[1024];
    if( (fd = open(SEQFILE, 2)) < 0 ){
        printf("OPEN FILE GG");
        exit(1);
    }
    for(int i = 0 ; i < 40 ; i++){

    }

    return 0;
}
