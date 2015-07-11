#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<int, int> PII;
typedef pair<PII, int> PPI;
bool cmp(const PPI &a, const PPI &b){
    return a.f.f < b.f.f;
}
void Solve(){
    int n;
    cin >> n;
    vector<PPI> st;
    vector<PII> ans;
    int l, r;
    while(cin >> l >> r, l || r)
        st.push_back(PPI(PII(l, r), st.size()));
    sort(st.begin(), st.end(), cmp);
    int now = 0;
    int lastl = 0;
    while(now < n){
        priority_queue<PII> PQ;
        for( ; lastl < (int)st.size() && st[lastl].f.f <= now ; lastl++)
            PQ.push(PII(st[lastl].f.s, lastl));
        if(PQ.empty()){
            cout << 0 << endl;
            return;
        }
        PII tmp = PQ.top();
        now = tmp.first;
        ans.push_back(PII(st[tmp.s].f.f, st[tmp.s].f.s));
    }
    cout << ans.size() << endl;
    for(int i = 0 ; i < (int)ans.size() ; i++)
        cout << ans[i].f << ' ' << ans[i].s << endl;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        Solve();
        if(n) cout << endl;
    }
    return 0;
}
