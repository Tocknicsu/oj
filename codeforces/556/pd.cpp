#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<long long, long long> PII;
typedef pair<long long, PII> PIP;
bool cmp(PIP a, PIP b){
    return a.s.f < b.s.f || (a.s.f == b.s.f && a.s.s < b.s.s);
}
bool cmp2(PII a, PII b){
    return a.s < b.s;
}
bool cmp3(PII a, PII b){
    return a.f < b.f;
}
int main(){
    long long n, m;
    cin >> n >> m;
    vector<PII> point;
    for(long long i = 0 ; i < n ; i++){
        long long l, r;
        cin >> l >> r;
        point.push_back(PII(l, r));
    }
    
    vector<PIP> dis;
    for(long long i = 0 ; i < n - 1 ; i++){
        dis.push_back(PIP(i, PII(point[i+1].f-point[i].s, point[i+1].s-point[i].f)));
    }
    sort(dis.begin(), dis.end(), cmp);
    vector<PII> bri;
    for(long long i = 0 ; i < m ; i++){
        long long len;
        cin >> len;
        bri.push_back(PII(i, len));
    }
    long long last = 0;
    sort(bri.begin(), bri.end(), cmp2);
    vector<PII> ans;
    for(long long i = 0 ; i < (long long)dis.size() ; i++){
        for( ; last < (long long)bri.size() ; last++){
            if(dis[i].s.f <= bri[last].s && bri[last].s <= dis[i].s.s){
                ans.push_back(PII(dis[i].f, bri[last].f));
                last++;
                break;
            }
        }
    }
    if(ans.size() != dis.size()){
        cout << "No" << endl;
        return 0;
    }
 //   sort(ans.begin(), ans.end(), cmp3);
    sort(ans.begin(), ans.end());
    cout << "Yes" << endl;
    for(long long i = 0 ; i < (long long)ans.size() ; i++)
        cout << ans[i].s + 1 << ' ';
    return 0;
}
