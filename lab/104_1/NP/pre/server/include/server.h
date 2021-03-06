#ifndef SERVER_H
#define SERVER_H
#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <iostream>
#include <list>
#include <cstring>
#include "log.h"
#include "config.h"
#include "function.h"

const int BUFFER_SIZE = 1024;
class SERVER{
    struct CLIENT{
        int         socket;
        sockaddr_in addr;
        socklen_t   addr_len;
        std::string ip;
        std::string nick_name;
    };
    private:
		sockaddr_in m_server;
		int m_server_socket;
		int m_server_len;

        CONFIG m_config;
        
        std::list<CLIENT> m_client_list;

        LOG m_log;

		fd_set readfd;
        
        void Set_FD();
        void Server();
        void Client();
        int Command_Line();
    public:
        SERVER();
        ~SERVER();
        void start();
        void stop();
};

#endif
