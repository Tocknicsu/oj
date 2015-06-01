#include "stable_vector.hpp"
#include <iostream>
using namespace std;

int main(){
    stable_vector<int> vec;
    for(int i = 0 ; i < 10 ; i++)
        vec.push_back(i);

    stable_vector<int>::iterator it1 = vec.begin(), it2 = vec.begin();
    cout << *(++it1) << ' ' << *(it2++) << "(Should be: 1 0)" << endl;
    cout << *it1 << ' ' << *it2 << "(Should be: 1 1)" << endl;
    cout << "Output 0 ~ 9: " << endl;
    for(stable_vector<int>::iterator it = vec.begin() ; it != vec.end() ; ++it)
        cout << *it << ' ';
    cout << endl;

    cout << *(vec.end() - 5) << "Should be: 5" << endl;
    return 0;
}
