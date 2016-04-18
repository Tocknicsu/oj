#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> PDD;

bool cmp(const PDD &a, const PDD &b){
    if(a.first == b.first)
        return a.second > b.second;
    else
        return a.first < b.first;
}

int main(){
    int n, r, w, h;
    scanf("%d%d%d%d", &n, &r, &w, &h);
    vector<PDD> L;
    for(int i = 0 ; i < n ; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        double d = double(h - y) / double(r);
        double s = x - d;
        double e = x + d;
        L.push_back(PDD(s, e));
    }
    sort(L.begin(), L.end(), cmp);
    vector<double> LIS;
    LIS.push_back(-L[0].second);
    for(int i = 1 ; i < n ; i++){
        if(-L[i].second >= LIS.back())
            LIS.push_back(-L[i].second);
        else
            *lower_bound(LIS.begin(), LIS.end(), -L[i].second) = -L[i].second;
    }
    printf("%d\n", (int)LIS.size());
    return 0;
}
