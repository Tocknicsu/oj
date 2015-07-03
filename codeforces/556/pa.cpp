#include <bits/stdc++.h>
using namespace std;

int main(){
    int x;
    cin >> x;
    string str;
    cin >> str;
    int ans = 0;
    for(int i = 0 ; i < (int)str.size() ; i++)
        ans += str[i] == '0' ? 1 : -1;
    cout << abs(ans) << endl;
}
