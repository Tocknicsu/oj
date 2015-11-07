#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000003;
ll f[1024], rf[1024];
ll RF(ll x){
    int n = MOD - 2;
    ll re = 1;
    while(n){
        if(n & 1)
            re = (re * x) % MOD;
        x = (x * x) % MOD;
        n >>= 1;
    }
    return re;
}
struct Node{
    int v;
    Node *l, *r;
    ll cnt, s;
    Node(int _v) : v(_v), l(NULL), r(NULL), cnt(1), s(1){}
};
Node* insert(Node *now, int t){
    if(now == NULL){
        return new Node(t);
    }
    if(t > now->v){
        now->r = insert(now->r, t);
    } else {
        now->l = insert(now->l, t);
    }
    return now;
}
void destruct(Node *now){
    if(now == NULL)
        return;
    destruct(now->l);
    destruct(now->r);
    delete now;
}
void dfs(Node* now){
    if(now->l && now->r){
        dfs(now->l), dfs(now->r);
        now->s = (now->l->s * now->r->s) % MOD;
        now->s = (now->s * f[now->l->cnt + now->r->cnt]) % MOD;
        now->s = (now->s * rf[now->l->cnt]) % MOD;
        now->s = (now->s * rf[now->r->cnt]) % MOD;
        now->cnt = now->l->cnt + now->r->cnt + 1;
    } else if(now->l || now-> r){
        if(now->l) dfs(now->l);
        else dfs(now->r);
        now->s = (now->l ? now->l->s : now->r->s);
        now->cnt = (now->l ? now->l->cnt : now->r->cnt) + 1;
    }
}

void Solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    int t;

    Node *root = NULL;
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &t);
        root = insert(root, t);
    }
    dfs(root);
    ll ans = ( ((root->s * f[m])%MOD) * ((rf[m-n] * rf[n])%MOD) ) %MOD;
    printf("%lld\n", ans);
    destruct(root);
}

int main(){
    f[0] = rf[0] = 1;
    for(int i = 1 ; i <= 1000 ; i++){
        f[i] = (f[i-1] * i) % MOD;
        rf[i] = RF(f[i]);
    }
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
    return 0;
}
