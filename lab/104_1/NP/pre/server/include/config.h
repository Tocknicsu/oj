#ifndef CONFIG_H
#define CONFIG_H
#include <string>
#include <fstream>
#include "function.h"
class CONFIG{
    private:
        int m_port;
        int m_max_wait_listen;
    public:
        CONFIG();
        ~CONFIG();
        void init();
        int port();
        int max_wait_listen();
};
#endif
