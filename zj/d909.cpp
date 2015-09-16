#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<int, int> PII;
typedef pair<int, PII> PIP;
typedef long long ll;
vector<PIP> v;
namespace DS{
    int v[16384], sz;
    void init(int n){
        for(int i = 0 ; i < n ; i++)
            v[i] = i;
        sz = n;
    }
    int find(int x){
        return v[x] == x ? v[x] : v[x] = find(v[x]);
    }
    int merge(int a, int b, int c){
        a = find(a), b = find(b);
        if(a == b)
            return 0;
        v[a] = b;
        sz--;
        return c;
    }
};
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0 ; i < m ; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        v.push_back(PIP(c, PII(a,b)));
    }
    sort(v.begin(), v.end());
    DS::init(n);
    ll ans = 0;
    for(int i = 0 ; i < m && DS::sz != 1; i++){
        ans += DS::merge(v[i].s.f, v[i].s.s, v[i].f);
    }
    printf("%lld\n", ans);
    return 0;
}
