#include <bits/stdc++.h>
using namespace std;
const int MAX = 131072;
int power[MAX];
int from[MAX];

void Solve(){
    int n, k;
    scanf("%d%d", &n, &k);
    int r = 1 << n;
    for(int i = 0 ; i < r ; i++){
        scanf("%d", &power[i+r]);
        from[i+r] = i+1;
    }
    for(int i = r - 1 ; i > 0 ; i--){
        int win = power[2*i+1] > power[2*i] ? 2*i+1 : 2 * i;
        int lose = win ^ 1;
        from[i] = from[win];
        power[i] = min(power[win] - power[lose] + k, power[r+from[win]-1]);
    }
    int now = 1;
    printf("%d\n", from[1]);
    /*
    for(int i = r - 1 ; i > 0 ; i--){
        int win = power[2*i+1] > power[2*i] ? 2*i+1 : 2 * i;
        int lose = win ^ 1;
        if(from[win] == from[1])
            printf("%d ", from[lose]);
        from[i] = from[win];
        power[i] = min(power[win] - power[lose] + k, power[r+from[win]-1]);
    }
    */
    vector<int> ans;
    while(now <  r){
        //printf("%d\n", now);
        int _l = now * 2;
        int _r = now * 2 + 1;
        if(from[_l] == from[1]){
            ans.push_back(from[_r]);
            now = _l;
        } else {
            ans.push_back(from[_l]);
            now = _r;
        }
    }
    for(int i = (int)ans.size() - 1 ; i >= 0 ; i--){
        printf("%d", ans[i]);
        if(i)
            printf(" ");
    }
    printf("\n");
}

int main(){
    //freopen("pd.in", "r", stdin);
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
    return 0;
}
