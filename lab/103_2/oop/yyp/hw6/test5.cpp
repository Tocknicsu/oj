#include "stable_vector.hpp"
#include <iostream>
using namespace std;

int main(){
    cout << "Before you start this test, you should remove redundant node in your constructor scope." << endl;
    stable_vector<int> v1;
    for(int i = 0 ; i < 100 ; i++)
        v1.push_back(i);

    cout << "Output 0 ~ 99" << endl;
    for(int i = 0 ; i < (int)v1.size() ; i++)
        cout << v1[i] << ' ';
    cout << endl << endl;

    for(int i = 0 ; i < 100 ; i++)
        v1.insert(v1.end(), i);

    cout << "Output 0 ~ 99 twice" << endl;
    for(int i = 0 ; i < (int)v1.size() ; i++)
        cout << v1[i] << ' ';
    cout << endl;
    
    return 0;
}
