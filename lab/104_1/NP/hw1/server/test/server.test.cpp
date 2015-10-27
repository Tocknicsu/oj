#include "server.h"
#include <unistd.h>
#include <csignal>
#include <sys/wait.h>

void signal_handler_SIGCHLD(int sig){
    int status;
    int pid = waitpid(-getpid(), &status, WNOHANG);
}

int main(){
    signal(SIGCHLD, &signal_handler_SIGCHLD); 
    SERVER server;
    server.start();
    for(auto x : clients){
        kill(x, SIGINT);
        waitpid(x, NULL, 0);
    }
}
