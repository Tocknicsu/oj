#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 1000000000
//#define MAX 20

int main(){
    set<ll> tri;
    vector<ll> ans;
    int x = 1, step = 2;
    for( ; x <= MAX ; x += step, step++){
        tri.insert(x);
    }
    for(int i = 1 ; i * i <= MAX ; i++){
        int y = i * i;
        if(tri.count(y-1)){
            ans.push_back(y-1);
        }
    }
    int a, b, n = 1;
    while(scanf("%d%d", &a, &b), a || b){
        b--;
        printf("Case %d: %d\n", n++, (int)(lower_bound(ans.begin(), ans.end(), b) - lower_bound(ans.begin(), ans.end(), a)));
    }
    return 0;
}
