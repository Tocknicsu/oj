#include <bits/stdc++.h>
using namespace std;

void Solve(int n){
    bool in[1024] = {};
    fill(in, in+1024, 0);
    queue<int> q[1024];
    queue<int> order;
    map<int, int> m;
    for(int i = 0 ; i < n ; i++){
        int t, x;
        cin >> t;
        while(t--){
            cin >> x;
            m[x] = i;
        }
    }
    string str;
    while(cin >> str, str[0] !='S'){
        if(str[0]=='E'){
            int x;
            cin >> x;
            int g = m[x];
            if(!in[g])
                order.push(g);
            q[g].push(x);
        } else if(str[0]=='D'){
            int g = order.front();
            cout << q[g].front() << endl;
            //q[g].pop();
            if(q[g].empty()){
                in[g] = 0;
                order.pop();
            }
        }

    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    int cases = 0;
    while(cin >> n, n){
        cout << "Scenario #" << ++cases << endl;
        Solve(n);
        cout << endl;
    }
}
