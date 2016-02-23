#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<int, int> PII;
vector<PII> v;
bool check(int s){
    int remain[(int)v.size()];
    fill(remain, remain+v.size(), s);
    int id = 0, now = 0;
    priority_queue< PII, vector<PII>, greater<PII> > PQ;
    while(!(id == (int)v.size() && PQ.empty())){
        if(PQ.empty())
            now = v[id].f;
        for( ; id < (int)v.size() && v[id].f == now ; id++)
            PQ.push(PII(v[id].s, id));
        int next_now = min(PQ.top().f, id == (int)v.size() ? 0x3f3f3f3f : v[id].f);
        int quota = next_now - now;
        now = next_now;

        while(quota && PQ.size()){
            int u = PQ.top().s;
            int value = min(remain[u], quota);
            quota -= value;
            remain[u] -= value;
            if(remain[u] == 0) PQ.pop();
        }
        if(PQ.size() && PQ.top().f <= now){
            return false;
        }
    }
    return true;
}
bool cmp(const PII &a, const PII &b){
    return a.f < b.f;
}
int main(){
    int n, s = 0, step = 16384, l, r;
    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%d%d", &l, &r);
        v.push_back(PII(l, r));
        step = min(step, r -l);
    }
    sort(v.begin(), v.end(), cmp);
    while(step){
        if(check(s+step)){
            s += step;
        } else {
            step >>= 1;
        }
    }
    printf("%d\n", s * (int)v.size());
    return 0;
}
