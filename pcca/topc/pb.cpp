#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<char> v;
        for(int i = 0 ; i < 26 ; i++)
            v.push_back(i+'a');
        for(int i = 0 ; i < n ; i++){
            int y;
            cin >> y;
            char x = v[y];
            v.erase(v.begin()+y);
            v.insert(v.begin(), x);
            cout << x;
        }
        cout << endl;

    }
    return 0;
}
