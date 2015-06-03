#include <iostream>
#include "stable_vector.hpp"
using namespace std;

int main(){
    stable_vector<int> vec;
    for(int i = 0 ; i < 10 ; i++)
        vec.push_back(i);

    cout << "Output 0 ~ 9:" << endl;
    const stable_vector<int> v1(vec);
    for(int i = 0 ; i < (int)v1.size() ; i++)
        cout << v1[i] << ' ';
    cout << endl;
    return 0;
}
