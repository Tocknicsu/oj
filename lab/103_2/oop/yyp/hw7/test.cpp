#include "msgpack.hpp"
#include <stdio.h>

#include <cassert>
#include <cstdint>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <time.h>
#include <iomanip>
using namespace std;
void print(value &v){
    stringstream ss;
    v.serialize(ss);
    string str;
    getline(ss, str);
    for(int i = 0 ; i < (int)str.size() ; i++)
        cout << setw(2) << setfill('0') << hex << (((int)str[i])&255) << ' ';
    cout << endl;
}

void print(const value &v){
    stringstream ss;
    v.serialize(ss);
    string str;
    getline(ss, str);
    for(int i = 0 ; i < (int)str.size() ; i++)
        cout << setw(2) << setfill('0') << hex << (((int)str[i])&255) << ' ';
    cout << endl;
}
int main() {
    using std::int64_t;
    value v(int64_t(123));
    print(v);
    print(v);
    return 0;
}
