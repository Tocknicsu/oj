#include <cassert>
#include <algorithm>
#include <iostream>
#include <string>

#include "stable_vector.hpp"
using namespace std;
int main() {
    std::string s = "able was I ere I saw elba";
    stable_vector<int> v1;
    const stable_vector<int> v2(5, 42); // v2 = {42, 42, 42, 42, 42}
    stable_vector<char> v3(s.begin(), s.end());
    stable_vector<char> v4;
    
    assert(v1.empty());
    assert(v1.size() == 0);
    assert(v1.begin() == v1.end());

    assert(v2.begin() + v2.size() == v2.end());
    for (stable_vector<int>::const_iterator it = v2.begin(); it < v2.end(); ++it)
        assert(*it == 42);

    v4.assign(v3.begin(), v3.end());
    std::reverse(v4.begin(), v4.end());
    assert(v3 == v4);
    std::sort(v3.begin(), v3.end());
    for (stable_vector<char>::const_iterator it = v3.begin(); it != v3.end(); ++it)
        std::cout << *it; // "      IIaaaabbeeeellrssww"
    std::cout << std::endl;

    stable_vector<int> u1(v2); // u1 = {42, 42, 42, 42, 42}
    stable_vector<int> u2; u2 = u1;
    stable_vector<int>::iterator it = --u2.end();
    *it = 1; // u2 = {42, 42, 42, 42, 1}
    assert(u1 > u2); //               ^it
    for (int i = 0; i < 10000; ++i)
        u2.push_back(i); // u2 = {42, 42, 42, 42, 1, 0, 1, 2, 3, ...}
    std::cout << *it << std::endl; // 1           ^it
    u2.erase(u2.begin(), u2.begin() + 4); // u2 = {1, 0, 1, 2, 3, ...}
    std::cout << it[4] << std::endl; // 3          ^it         ^(it + 4)

    u1.swap(u2);                   // u1 = {1, 0, 1, 2, 3, ...}
    std::cout << *it << std::endl; // 1     ^it
    return 0;
}
