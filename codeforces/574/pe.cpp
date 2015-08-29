#include <bits/stdc++.h>
using namespace std;
vector<int> ed[131072];
int main(){
    int n;
    cin >> n;
    int a, b;
    while(cin >> a >> b){
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
}
