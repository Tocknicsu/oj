/*
給定一棵由字串組成的二元樹
將此樹壓縮後描述

先將字串改成數字處理
一個map (int)=>(string)

parse node

int dfs(int p){
    re = hash(self)
    if(not end){
        x = re_hash(dfs())
        y = re_hash(dfs())
        re = re + x + y;
        if(re not in hash)
            hash[re] = hash.size()
        return hash(re)
    }

}


*/


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PLL;
string str;
map<int, string> m;
#define MOD 1000000007
struct HASH{
    ll x, y;
    HASH(){}
    HASH(ll _x, ll _y){
        x = _x, y = _y;
    }
    HASH operator+(const HASH &a) const {
        HASH re;
        re.x = (x + a.x) % MOD;
        re.y = (y ^ a.y) % MOD;
        return re;
    }
    bool operator<(const HASH &a) const {
        return x == a.x ? y < a.y : x < a.x;
    }
};

vector<ll> go;

ll _hash(string str){
    ll x = 1024935;
    ll y = 131;
    ll mod = 1000000007;
    for(int i = 0 ; i < (int)str.size() ; i++){
        x += str[i];
        x *= y;
        x %= mod;
    }
    return x;
}
struct Node{
    ll v, l, r;
    Node(){}
};
map<HASH, int> hashmap;
int cnt;
int p;
int dfs(int p){
    HASH re(go[p], go[p]);
    p++;
    if(go[p] == -2 || go[p] == -3){
        p++;
        if(!hashmap[re])
            hashmap[re] = hashmap.size();
    }

    return hashmap[re];
}

void Solve(){
    go.clear();
    string str;
    cin >> str;
    hashmap.clear();
    p = 0;
    for(int i = 0 ; i < (int)str.size() ; i++){
        if(str[i] == '(')
            go.push_back(-1);
        else if(str[i] == ')')
            go.push_back(-2);
        else if(str[i] == ',')
            go.push_back(-3);
        else{
            string tmp;
            tmp.push_back(str[i]);
            for(;i+1<(int)str.size() && str[i+1] != '(' && str[i+1] != ')' && str[i+1] != ',' ; i++)
                tmp.push_back(str[i]);
            go.push_back(_hash(tmp));
            m[go.back()] = tmp;
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
    return 0;
}
