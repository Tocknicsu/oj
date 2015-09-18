#include <bits/stdc++.h>
using namespace std;
queue<int> q[1024];
queue<int> order;
map<int, int> m;

void Solve(int n){
    while(order.size()) order.pop();
    for(int i = 0 ; i < 1024 ; i++)
        while(q[i].size()) q[i].pop();
    m.clear();
    bool in[1024] = {};
    fill(in, in+1024, 0);
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
            if(!in[g]){
                order.push(g);
                in[g] = true;
            }
            q[g].push(x);
        } else if(str[0]=='D'){
            int g = order.front();
            cout << q[g].front() << endl;
            q[g].pop();
            if(q[g].empty()){
                in[g] = 0;
                order.pop();
            }
        }

    }
}

int main(){
    freopen("pb.in", "r", stdin);
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    int cases = 0;
    while(cin >> n, n){
        cout << "Scenario #" << ++cases << endl;
        Solve(n);
        cout << endl;
    }
}
