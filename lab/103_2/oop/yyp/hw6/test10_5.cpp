#include <cstdio>
#include <iostream>
#include <algorithm>
#include "stable_vector.hpp"
using namespace std;

int main(){
    stable_vector<int> v;
    for(int i = 0 ; i < 100 ; i++)
        v.push_back(rand() % 100);
    sort(v.begin(), v.end());
    for(auto x : v)
        cout << x << ' ';
    cout << endl;
    return 0;
}

