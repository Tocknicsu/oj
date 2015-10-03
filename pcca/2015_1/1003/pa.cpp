#include <bits/stdc++.h>
using namespace std;

int ans[32768];
unordered_set<int> s;
int main(){
    int t = 1;
    for(int i = 1 ; i < 1001 ; i++){
        if(s.count(i)){
            for( ; t <= i && s.count(i*t) ; t++);
            for(int j = t ; j <= i ; j++)
                s.insert(j*i);
        } else {
            for(int j = 1 ; j <= i ; j++)
                s.insert(i*j);
        }
        ans[i] = s.size();
    }
    freopen("pa.out.2", "w", stdout);
    for(int i = 1 ; i < 1001 ; i++)
        printf("%d\n", ans[i]);
    return 0;
    int n;
    scanf("%d", &n);
    while(n--){
        int x;
        scanf("%d", &x);
        printf("%d\n", ans[x]);
    }
}
