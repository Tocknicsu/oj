#include <iostream>
#include "stable_vector.hpp"
using namespace std;
void print(stable_vector<int>& vec){
    for(int i = 0 ; i < (int)vec.size() ; i++)
        cout << vec[i] << ' ';
    cout << endl;
}
int main(){
    stable_vector<int> v1, v2;
    for(int i = 0 ; i < 10 ; i++)
        v1.push_back(i), v2.insert(v2.begin(), i);
    cout << "Output 0~9 and 9~0" << endl;
    print(v1), print(v2);
    vector< stable_vector<int>::iterator > vec;
    for(auto x = v1.begin() ; x != v1.end() ; ++x)
        vec.push_back(x);

    
    v1.swap(v2);
    cout << "Output 1 for 10 times" << endl;
    for(int i = 0 ; i < (int)v2.size() ; i++)
        cout << (vec[i] == v2.begin()+i) << ' ';
    cout << endl;

    v1.resize(15, 3);
    v2.resize(5, 3);
    
    cout << "Output 9 ~ 0 and 3 for 5 times" << endl;
    print(v1);
    cout << "Output 0 ~ 4" << endl;
    print(v2);
    return 0;
}
