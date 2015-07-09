#include <bits/stdc++.h>
using namespace std;

void Solve(int n){
    string str;
    vector<int> len;
    set<int> s;
    len.push_back(0);
    for(int i = 0 ; i < n ; i++){
        cin >> str;
        len.push_back(len.back()+str.size());
        s.insert(len.back());
    }
    for(int i = 0 ; i < (int)len.size() ; i++){
        int x = len[i];
        if(s.count(x+5)+s.count(x+12)+s.count(x+17)+s.count(x+24)+s.count(x+31) == 5){
            cout << i + 1 << endl;
            return;
        }
    }
}

int main(){
    int n;
    while(cin >> n)
        Solve(n);
    return 0;
}
