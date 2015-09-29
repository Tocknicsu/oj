#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

void Solve(){
    int n;
    scanf("%d", &n);
    map<int, int> m;
    int t;
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &t);
        m[t] = i+1;
    }
    scanf("%d", &t);
    vector<int> vec;
    vec.push_back(m[t]);
    vector<PII> ans;
    ans.push_back(PII(t, 0));
    for(int i = 1 ; i < n ; i++){
        scanf("%d", &t);
        if(m[t] == 0)
            continue;
        if(m[t] > vec.back())
            vec.push_back(m[t]);
        else
            *lower_bound(vec.begin(), vec.end(), m[t]) = m[t];
        ans.push_back(PII(t, lower_bound(vec.begin(), vec.end(), m[t])-vec.begin()));
    }
    vector<int> f;
    int now = vec.size() - 1;
    for(int i = ans.size() - 1 ; i >= 0 ; i--){
        if(ans[i].second == now){
            now--;
            f.push_back(ans[i].first);
        }
    }
    while(f.size()){
        printf("%d ", f.back());
        f.pop_back();
    }
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        Solve();
    return 0;
}
