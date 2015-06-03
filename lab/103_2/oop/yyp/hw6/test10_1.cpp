#include <iostream>
#include "stable_vector.hpp"
void print(stable_vector<int>& vec){
    for(int i = 0 ; i < (int)vec.size() ; ++i)
        cout << vec[i] << ' ';
    cout << endl;
}
int main(){
    cout << "Test all constuctor" << endl;
    stable_vector<int> v1;
    cout << "Should be a blank line." << endl;
    print(v1);

    stable_vector<int> v2(5, 3);
    cout << "Should be 3 3 3 3 3" << endl;
    print(v2);
    
    vector<int> vec;
    for(int i = 0 ; i < 5 ; i++)
        vec.push_back(i);
    stable_vector<int> v3(vec.begin(), vec.end());
    cout << "Should be 0 1 2 3 4" << endl;
    print(v3);

    stable_vector<int> v4(v3);
    cout << "Should be 0 1 2 3 4" << endl;
    print(v4);

    stable_vector<int> v5 = v3;
    cout << "Should be 0 1 2 3 4" << endl;
    print(v5);

    v5 = v2;
    cout << "Should be 3 3 3 3 3" << endl;
    print(v5);

    
}
