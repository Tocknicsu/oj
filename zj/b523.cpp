#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    unordered_map<string, int> m;
    while(getline(cin, str)){
        cout << (m[str] ? "YES" : "NO") << endl;
        m[str]++;
    }
    return 0;
}
