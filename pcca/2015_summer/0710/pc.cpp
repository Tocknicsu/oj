#include <bits/stdc++.h>
using namespace std;

int Solve(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    int ans = 0;
    for(int i = 0 ; i < (int)str.size() ; i++){
        if(str[i] == '.')
            ans++, i+=2;
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    for(int i = 0 ; i < t ; i++)
        cout << "Case " << i+1 << ": " << Solve() << endl;
    return 0;
}
