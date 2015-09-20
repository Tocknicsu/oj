#include <bits/stdc++.h>
using namespace std;
const int MAX = 501234 * 10;
typedef long long ll;
int L[MAX], R[MAX];
ll v[MAX], sum[MAX];

int next(){
    static int x = 1;
    return x++;
}

int build(int l, int r){
    if(l+1 == r)
        return next();
    int x = next();
    int mid = (l+r) / 2;
    L[x] = build(l, mid);
    R[x] = build(mid, r);
    return x;
}
int update(int now, int l, int r, int nv, int k){
    int x = next();
    if(r-l == 1){
        v[x] = nv;
    } else {
        int mid = (l + r) / 2;
        if(k < mid){
            L[x] = update(L[now], l, mid, nv, k);
            R[x] = R[now];
        } else {
            L[x] = L[now];
            R[x] = update(R[now], mid, r, nv, k);
        }
        v[x] = v[L[x]] + v[R[x]];
    }
    return x;
}

void print(int now, int l, int r){
    if(r-l == 1){
        printf("%lld ", v[now]);
    } else {
        int mid = (l + r) / 2;
        print(L[now], l, mid);
        print(R[now], mid, r);
    }
}
ll query(int now, int l, int r, int ql, int qr){
    if(r <= ql || qr <= l) return 0;
    if(ql <= l && r <= qr) return v[now];
    int mid = (l+r) / 2;
    return query(L[now], l, mid, ql, qr) + query(R[now], mid, r, ql, qr);
}

int main(){
    int n, t;
    scanf("%d%d", &n, &t);
    vector<int> root;
    root.push_back(build(1, n+1));
    for(int i = 0 ; i < t ; i++){
        int a, b, c;
        scanf("%d", &a);
        if(a == 1){
            scanf("%d%d", &b, &c);
            root.push_back(update(root.back(), 1, n+1, c, b));
        } else if(a == 2) {
            scanf("%d%d", &b, &c);
            printf("%lld\n", query(root.back(), 1, n+1, b, c+1));
            root.push_back(root.back());
        } else {
            scanf("%d", &b);
            root.push_back(root[root.size()-b-1]);
        }
//        print(root.back(), 1, n+1);
    }
}
