#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> num;
void build(){
    queue<string> Q;
    num.push_back(4);
    num.push_back(7);
    Q.push("44");
    Q.push("77");
    while(Q.size()){
        string now = Q.front();
        Q.pop();
        if(now.size() >= 19) continue;

        num.push_back(atoll(now.c_str()));
        if(now.size() & 1) continue;
        int sz = now.size() / 2;
        Q.push(now.substr(0, sz) + "4" + now.substr(sz, sz));
        Q.push(now.substr(0, sz) + "44" + now.substr(sz, sz));
        Q.push(now.substr(0, sz) + "7" + now.substr(sz, sz));
        Q.push(now.substr(0, sz) + "77" + now.substr(sz, sz));
    }
    sort(num.begin(), num.end());
}

int main(){
//    freopen("pc.in", "r", stdin);
    build();
    int n;
    scanf("%d", &n);
    while(n--){
        ll x, y;
        scanf("%lld%lld", &x, &y);
        printf("%d\n", (int)(upper_bound(num.begin(), num.end(), y) - lower_bound(num.begin(), num.end(), x)));
    }
    return 0;
}
