#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans[65536];
ll ary[] = {1, 5, 10, 20, 50, 100, 200, 500, 1000, 2000};
int main(){
    ans[0] = 1;
    for(int i = 0 ; i < 10 ; i++)
        for(int j = ary[i] ; j < 65536 ; j++){
            ans[j] += ans[j-ary[i]];
        }
    string str;
    while(getline(cin, str)){
        int n = 0, tmp;
        stringstream ss(str);
        while(ss >> tmp)
            n += tmp;
        if(!n) return 0;
        cout << ans[n] - 1 << endl;
    }
}
