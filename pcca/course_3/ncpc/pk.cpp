#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

void Solve(){
    int a[2][6], ans[2];
    set<int> s[2];
    for(int i = 0 ; i < 2 ; i++){
        for(int j = 0 ; j < 6 ; j++)
            scanf("%d", &a[i][j]);
        sort(a[i], a[i]+6);
        do{
            int now = 0;
            for(int j = 0 ; j < 6 ; j++){
                now = now * 10 + a[i][j];
                s[i].insert(now);
            }
        }while(next_permutation(a[i], a[i]+6));
    }
    for(int i = 0 ; i < 2 ; i++){
        ans[i] = s[i].size();
        for(set<int>::iterator x = s[i].begin() ; x != s[i].end() ; ++x)
            if(s[i^1].count(*x))
                ans[i]--;
    }
    printf("%d %d\n", ans[0], ans[1]);

}

int main(){
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
    return 0;
}
