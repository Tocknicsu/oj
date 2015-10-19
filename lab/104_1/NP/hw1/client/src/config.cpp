#include "config.h"

CONFIG::CONFIG(){
	std::string config_file_path = root_dir() + std::string("/config");
    std::ifstream ifs;
	ifs.open( config_file_path.c_str() );
    if(!(ifs >> m_ip)) m_ip = "127.0.0.1";
	if(!(ifs >> m_port)) m_port = 1736;
	ifs.close();
}
CONFIG::~CONFIG(){
}
std::string CONFIG::ip(){
    return m_ip;
}
int CONFIG::port(){
	return m_port;
}
