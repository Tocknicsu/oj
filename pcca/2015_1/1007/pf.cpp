/*
題目：砍龍需要兩把劍 問最少要準備幾把

*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 1048576
#define f first
#define s second
typedef pair<int, int> PII;
int d[MAX][3];
int ok[MAX];

bool cmp(const PII &a, const PII &b){
    if(a.f == b.f) return a.s < b.s;
    return a.f < b.f;
}

int Solve(){
    multiset<int> ms;
    set<int> s;
    int n, ans;
    memset(ok, 0, sizeof(ok));
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d%d%d", &d[i][0], &d[i][1], &d[i][2]);
        s.insert(d[i][0]);
        ms.insert(d[i][0]);
    }
    vector<PII> p;
    ans = s.size();
    for(int i = 0 ; i < n ; i++){
        ms.erase(d[i][0]);
        multiset<int>::iterator it = ms.lower_bound(d[i][1]);
        if(it != ms.end() && d[i][2] >= *it)
            ok[i] = true;
        ms.insert(d[i][0]);
    }
    for(int i = 0 ; i < n ; i++){
        if(ok[i]) continue;
        p.push_back(PII(d[i][1], d[i][2]));
    }
    sort(p.begin(), p.end(), cmp);
    int right = 0;
    for(int i = 0 ; i < (int)p.size() ; i++){
        right = min(right, p[i].s);
        if(right >= p[i].f) continue;
        ans++;
        right = p[i].s;
    }
    return ans;
}

int main(){
//    freopen("pf.in", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i = 1 ; i <= n ; i++){
        printf("Case #%d: %d\n", i, Solve());
    }
    return 0;
}
