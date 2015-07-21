#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<int ,int> PII;
typedef pair<int, PII> PIP;
int dis(PII a, PII b){
    return (a.f-b.f) * (a.f-b.f) + (a.s-b.s) * (a.s-b.s);
}
int main(){
//    freopen("pc.in", "r", stdin);
    int n, t = 0;
    while(cin >> n, n){
        vector<PII> p;
        for(int i = 0 ; i < n ; i++){
            int x, y;
            cin >> x >> y;
            p.push_back(PII(x, y));
        }
        int ed[256][256];
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++){
                if(i==j) ed[i][j] = 999999999;
                ed[i][j] = dis(p[i], p[j]);
            }
        for(int k = 0 ; k < n ; k++)
            for(int i = 0 ; i < n ; i++)
                for(int j = 0 ; j < n ; j++){
                    ed[i][j] = min(ed[i][j], max(ed[i][k], ed[k][j]));
                }
        cout << "Scenario #" << ++t << endl;
        cout << "Frog Distance = " << fixed << setprecision(3) << sqrt(ed[0][1]) << endl << endl;

    }
}
