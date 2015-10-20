#include "server.h"

SERVER::SERVER(){
}
SERVER::~SERVER(){
    m_log.write("=====Server End=====");
}
void SERVER::start(){
    m_log = LOG("server.log", "server");
    m_config = CONFIG();
    m_log.write("=====Server Start=====");
	if( (m_server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        m_log.write("Error: create server socket.");
	    return;
	}
    m_log.write("Succ: Server socket create.");
    int m_opt = 1;  //re use addr
    if( setsockopt(m_server_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&m_opt, sizeof(m_opt)) < 0){
        m_log.write("Error: occur at set socket opt.");
        return;
    }
    m_log.write("Succ: Set socket option.");
	int port = m_config.port();
	int max_wait_listen = m_config.max_wait_listen();
	m_server.sin_family = AF_INET;
	m_server.sin_addr.s_addr = INADDR_ANY;
	m_server.sin_port = htons( port );
	if( bind(m_server_socket, (sockaddr *)&m_server, sizeof(m_server)) < 0){
        m_log.write("Error: occur bind.");
		return;
	}

	if( listen(m_server_socket, max_wait_listen) < 0){
        m_log.write("Error: occur listen.");
		return;
	}

	m_server_len = sizeof(m_server);
    m_log.write("Waiting connect...");

	struct timeval timeout={0, 0};

    while(1){
        int now_socket = accept(m_server_socket, (sockaddr*)&m_server, (socklen_t*)&m_server_len);
        m_log.write("have connection");
        if(fork()){
            close(now_socket);
        } else {
            m_log.write("dup socket");
            dup2(now_socket, STDIN_FILENO);
            dup2(now_socket, STDOUT_FILENO);
            dup2(now_socket, STDERR_FILENO);
            std::string str;
            while(std::cin >> str){
                std::cout << str << std::endl;
                if(str == "exit")
                    break;
                m_log.write(str);
            }
            m_log.write("End");
            exit(0);
        }
    }

    /*
    while(1){
        Set_FD();
        int max_sd = m_server_socket;
        for(auto it : m_client_list)
            max_sd = max_sd > it.socket ? max_sd : it.socket;
        int result = select(max_sd + 1, &readfd, NULL, NULL, &timeout);
        if(result == 0){
            usleep(1000);
            continue;
        }
        {
            int com_result = Command_Line();
            if(com_result == -1)
                return;
        }
        Server();
        Client();
    }
    */
}

void SERVER::Set_FD(){
    FD_ZERO(&readfd);
    FD_SET(0, &readfd); //stdin
    FD_SET(m_server_socket, &readfd);
    for(auto it : m_client_list)
        FD_SET(it.socket, &readfd);
}
int SERVER::Command_Line(){
    if(FD_ISSET(0, &readfd)){
        int result;
        char buffer[BUFFER_SIZE+1];
        if( (result = read(0, buffer, BUFFER_SIZE)) ){
            buffer[result-1] = '\0';
            std::stringstream ss(buffer);
            std::string command;
            ss >> command;

            std::cout << "Input: " << command << std::endl;
            m_log.write("[Stdin]" + command);
            if(command == std::string("exit")){
                return -1;
            }
        }
    }
    return 0;
}
void SERVER::Server(){
    if(FD_ISSET(m_server_socket, &readfd)){
        CLIENT new_client;
        new_client.socket = accept(m_server_socket, (sockaddr*)&m_server, (socklen_t*)&m_server_len);
        new_client.addr_len = sizeof(new_client.addr);
        getpeername(new_client.socket, (sockaddr*)&new_client.addr, &new_client.addr_len);
        char t_ip[32];
        inet_ntop(AF_INET, &new_client.addr.sin_addr, t_ip, sizeof(t_ip));
        new_client.ip = std::string(t_ip);
        m_client_list.push_back(new_client);
        m_log.write(std::string("Connected: ") + new_client.ip);
    }
}
void SERVER::Client(){
    char buffer[BUFFER_SIZE+1];
    for(std::list<CLIENT>::iterator it = m_client_list.begin() ; it != m_client_list.end() ;){
        if(FD_ISSET(it->socket, &readfd)){
            int re;
            int result = read(it->socket, buffer, BUFFER_SIZE);
            if( result == 0){
                m_log.write(std::string("Closed ") + it->ip);
                std::list<CLIENT>::iterator tmp = it;
                it = ++it;
                m_client_list.erase(tmp);
                continue;
            } else {
                buffer[result] = 0;
                m_log.write(
                    std::string("from:[")+it->ip+std::string("] ")+
                    std::string("msg:[")+std::string(buffer)+std::string("]")
                );

            }
        }

        ++it;
    }
}
