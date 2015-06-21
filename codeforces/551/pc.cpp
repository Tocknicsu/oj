#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
vector<ll> vec;
bool judge(ll x){
    vector<ll> tmp(vec);
    ll remain = m, now;
    for(int i = 0 ; i < (int)tmp.size() ; i++)
        if(tmp[i])
            now = i;
    while(remain--){
        ll power = x - (now+1);
        while(power > 0 && now >= 0){
            int r = min(tmp[now], power);
            power -= r;
            tmp[now] -= r;
            if(!tmp[now])
                now--;
        }
    }
    while(!tmp[now])now--;
    return now < 0;
}
int main(){
    cin >> n >> m;
    ll start = 0, step = n + 1, tmp;
    for(int i = 0 ; i < n ; i++){
        cin >> tmp;
        step += tmp;
        if(tmp)
            start = i;
        vec.push_back(tmp);
    }
    ++start;
    while(step){
        if(!judge(start+step))
            start += step;
        else
            step >>= 1;
    }
    cout << start + 1 << endl;
    return 0;
}
