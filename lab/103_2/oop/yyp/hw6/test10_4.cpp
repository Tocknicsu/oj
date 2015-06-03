#include <iostream>
#include "stable_vector.hpp"
using namespace std;

int main(){

    stable_vector<int> v1;
    for(int i = 0 ; i < 10 ; i++)
        v1.push_back(i);
    v1.insert(v1.begin()+5, v1.begin(), v1.end());
    cout << "You should see 0 1 2 3 4 0 1 2 3 4 5 6 7 8 9 5 6 7 8 9 " << endl;
    for(int i = 0 ; i < (int)v1.size() ; i++)
        cout << v1[i] << ' ';
    cout << endl;

    cout << "You should see 4 times of done and exec time between each other within 1 sec. Number: 1000000 -> 2000000 -> 1000000 -> 0" << endl;
    stable_vector<int> vec;
    for(int i = 0 ; i < 1000000 ; i++)
        vec.push_back(i);
    cout << "done. " << vec.end() - vec.begin() << endl;
    auto it = vec.insert(vec.begin(), vec.begin(), vec.end());
    cout << "done. " << vec.end() - vec.begin() << endl;

    for(int i = 0 ; i < 1000000 ; i++)
        vec.pop_back();
    cout << "done. " << vec.end() - vec.begin() << endl;

    vec.erase(vec.begin(), vec.end());
    cout << "done. " << vec.end() - vec.begin() << endl;


    return 0;
}
