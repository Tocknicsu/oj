/*
給定n個人走一條線
每個人有瞬間出現時間 起點 終點
問每個人會和幾個人碰面
*/

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
#define f first
#define s second

struct S{
    int ts, te, s, e, d;
    S(){}
    S(int _t, int _s, int _e) : ts(_t), te(_t+abs(_e-_s)), s(_s), e(_e), d(e > s ? 1 : -1) {}
    PII find(int start, int end){
        int x = s + d * (start - ts);
        int y = s + d * (end - ts);
        return PII(min(x, y), max(x, y));
    }
};


int main(){
    //freopen("pd.in", "r", stdin);
    int n;
    while(~scanf("%d", &n)){
        vector<S> v;
        for(int i = 0 ; i < n ; i++){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            v.push_back(S(a, b, c));
        }
        for(int i = 0 ; i < n ; i++){
            int ans = 0;
            for(int j = 0 ; j < n ; j++){
                if(i == j) continue;
                S &x = v[i];
                S &y = v[j];
                if(x.te < y.ts || y.te < x.ts) continue;
                int start = max(x.ts, y.ts);
                int end = min(x.te, y.te);
                PII a = x.find(start, end);
                PII b = y.find(start, end);
                /*
                printf("%d %d:\n", i, j);
                printf("\t%d %d\n", x.d, y.d);
                printf("\t%d %d %d %d\n", a.f, a.s, b.f, b.s);
                */
                if(x.d == y.d){
                    if(a.f == b.f) ans++;
                } else if(x.d == -1){
                    if(a.s >= b.f && a.f <= b.s) ans++;
                } else {
                    if(b.s >= a.f && b.f <= a.s) ans++;
                }
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}
