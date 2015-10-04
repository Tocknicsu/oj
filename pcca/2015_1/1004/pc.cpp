#include <bits/stdc++.h>
using namespace std;
struct S{
    int id;
    int a, b, c;
    S(){}
    S(int _id, int _a, int _b, int _c){
        id = _id;
        a = _a;
        b = _b;
        c = _c;
    }
    bool operator<(const S& o) const {
        if(a == o.a)
            return b > o.b;
        return a > o.a;
    }
    bool operator==(const S& o) const {
        return a == o.a && b == o.b && c == o.c;
    }
};
void Solve(){
    int n, s, k, m, a, b, t;
    vector<S> v;
    scanf("%d%d%d%d%d%d", &n, &s, &k, &m, &a, &b);
    for(int i = 0 ; i < n ; i++){
        int x, y, z;
        x = y = z = 0;
        for(int j = 0 ; j < k ; j++){
            scanf("%d", &t);
            if(t >= a) x++;
            else if(t >= b) y++;
            else z++;
        }
        v.push_back(S(i+1, x, y, z));
    }
    sort(v.begin(), v.end());
    int q;
    vector<int> ans(v.size()+1);
    ans[v[0].id] = 0;
    for(int i = 1 ; i < (int)v.size() ; i++){
        if(v[i] == v[i-1]){
            ans[v[i].id] = ans[v[i-1].id];
        } else {
            ans[v[i].id] = i;
        }
    }
    for(int i = 0 ; i < s ; i++){
        scanf("%d", &q);
        if(i)printf(" ");
        printf("%d", ans[q]);
    }
    printf("\n");
}

int main(){
//   freopen("pb.in", "r", stdin);
    int n;
    scanf("%d", &n);
    while(n--){
        Solve();
    }
    return 0;
}
