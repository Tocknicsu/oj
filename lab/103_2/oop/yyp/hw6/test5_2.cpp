#include "stable_vector.hpp"
#include <iostream>
using namespace std;

int main(){
    cout << "Before you start this test, you should test test5.cpp and completely right." << endl;

    stable_vector<int> v1;
    for(int i = 0 ; i < 1000000 ; i++)
        v1.push_back(i);

    cout << "Should print 0 ~ 99" << endl;
    for(int i = 0 ; i < 100 ; i++)
        cout << v1[i] << ' ';
    cout << endl;

    cout << "Should print 999899 ~ 999999" << endl;
    for(int i = (int)v1.size() - 100 - 1 ; i < (int)v1.size() ; i++)
        cout << v1[i] << ' ';
    cout << endl;
    
    return 0;
}
