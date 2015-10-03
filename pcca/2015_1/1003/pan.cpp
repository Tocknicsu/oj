#include <bits/stdc++.h>
using namespace std;
int Solve(int x){
    unordered_set<int> s;
    for(int i = 1 ; i <= x ; i++)
        for(int j = 1 ; j <= x ; j++)
            s.insert(i*j);
    return s.size();
}
int ans[32768];
int main(){
    unordered_set<int> s;
    for(int i = 1 ; i < 1001 ; i++){
        int t = 1;
        for(int j = 2 ; j * j <= i ; j++){
            if(i % j == 0){
                t = j;
            }
        }
        if(t != 1){
            int x = ( i / t ) * ( i / t) / i;
            for(int j = x ; j <= i ; j++)
                s.insert(i*j);
        } else {
            for(int j = 1 ; j <= i ; j++)
                s.insert(i*j);
        }
        ans[i] = s.size();
    }
    for(int i = 1 ; i < 100 ; i++)
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
