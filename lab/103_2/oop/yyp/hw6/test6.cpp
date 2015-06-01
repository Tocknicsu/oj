#include "stable_vector.hpp"
#include <iostream>
using namespace std;

int main(){
    stable_vector<int> vec;
    for(int i = 0 ; i < 10 ; i++)
        vec.push_back(i);

    vec.erase(vec.begin());
    
    cout << "Output 1~9:" << endl;
    for(int i = 0 ; i < (int)vec.size() ; i++)
        cout << vec[i] << ' ';
    cout << endl << endl;


    cout << "Output 1~5:" << endl;
    for(int i = 0 ; i < 4 ; i++)
        vec.pop_back();
    for(int i = 0 ; i < (int)vec.size() ; i++)
        cout << vec[i] << ' ';
    cout << endl << endl;
    return 0;
}
