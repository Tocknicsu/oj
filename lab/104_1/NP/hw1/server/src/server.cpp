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
    std::cout << "Waiting connect..." << std::endl;
	int submission_update = 0;

	struct timeval timeout={0, 0};

    while(1){
        int m_socket = accept(m_server_socket, (sockaddr*)&m_server, (socklen_t*)&m_server_len);
        if(fork()){
            close(m_socket);
        } else {
            dup2(m_socket, STDIN_FILENO);
            dup2(m_socket, STDOUT_FILENO);
            dup2(m_socket, STDERR_FILENO);
            close(m_socket);
            std::string str;
            while(std::cin >> str){
                std::cout << "XD: " << str << std::endl;
            }
            exit(0);
        }
    }
}

