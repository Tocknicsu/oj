#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<int, int> PII;
typedef pair<int, PII> PPI;

namespace DS{
    int v[512];
    void init(int n){
        for(int i = 0 ; i < n ; i++)
            v[i] = i;
    }
    int find(int x){
        return x == v[x] ? v[x] : v[x] = find(v[x]);
    }
    int merge(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return 0;
        v[x] = y;
        return 1;
    }
};
int dis(string a, string b){
    int re = 0;
    for(int i = 0 ; i < 4 ; i++)
        re += min(10-abs(a[i]-b[i]), abs(a[i]-b[i]));
    return re;
}
void Solve(){
    int x;
    vector<string> l;
    vector<PPI> ed;
    cin >> x;
    for(int i = 0 ; i < x ; i++){
        string str;
        cin >> str;
        l.push_back(str);
    }
    for(int i = 0 ; i < (int)l.size() ; i++)
        for(int j = i+1 ; j < (int)l.size() ; j++)
            ed.push_back(PPI(dis(l[i], l[j]), PII(i, j)));

    sort(ed.begin(), ed.end());
    int ans = 0, min_add = 999;
    DS::init(x+1);
    for(int i = 0 ; i < (int)ed.size() ; i++)
        ans += DS::merge(ed[i].s.f, ed[i].s.s) * ed[i].f;
    for(int i = 0 ; i < (int)l.size() ; i++)
        min_add = min(min_add, dis(string("0000"), l[i]));
    cout << ans + min_add << endl;
}

int main(){
    int n;
    cin >> n;
    while(n--)
        Solve();
}
