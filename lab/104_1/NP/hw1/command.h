#ifndef _COMMAND_H_
#define _COMMAND_H_
#include <unistd.h>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <signal.h>
#include <cstdlib>
#include <sstream>
using namespace std;

#define SINGLE_TEST
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef pair<string, PII> COMMAND;

map<int, PIP> PIPE;

#endif
