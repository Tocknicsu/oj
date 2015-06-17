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
    cout.flags(ios::hex);
    for(int i = 0 ; i < (int)str.size() ; i++)
        cout << setw(2) << setfill('0') << (((int)str[i])&255) << ' ';
    cout.flags(ios::dec);
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
    value a(int64_t(123));
    print(a);
    cout <<  a.get_integer() << endl;
    return 0;
}
