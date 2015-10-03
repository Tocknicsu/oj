#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b){
    return a > b;
}

int main(){
    int n;
    scanf("%d", &n);
    int n2 = n * n;
    vector<int> v(n2);
    vector<int> ans;

    for(int i = 0 ; i < n2 ; i++){
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end(), cmp);
    map<int, int> skip;
    for(int i = 0 ; i < n * n ; i++){
        if(skip[v[i]]){
            skip[v[i]]--;
        } else {
            for(int j = 0 ; j < (int)ans.size() ; j++){
                skip[__gcd(v[i], ans[j])]+=2;
            }
            ans.push_back(v[i]);
        }
    }
    for(int i = 0 ; i < n ; i++)
        printf("%d ", ans[i]);
    return 0;
}
