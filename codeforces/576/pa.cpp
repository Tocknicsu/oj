#include <bits/stdc++.h>
using namespace std;
#define MAX 1024
bool tmp[MAX];
vector<int> p;
void build(){
    for(int i = 4 ; i < MAX ; i+=2)
        tmp[i] = 1;
    for(int i = 3 ; i * i < MAX ; i+=2)
        if(!tmp[i])
        for(int j = i*i ; j < MAX ; j+=2*i)
            tmp[j] = 1;
    for(int i = 2 ; i < MAX ; i++)
        if(!tmp[i])
            p.push_back(i);

}
int main(){
    build();
    int n;
    cin >> n;
    vector<int> ans;
    for(int i = 0 ; i < (int)p.size() && p[i] <= n ; i++){
        int t = p[i];
        while( t <= n){
            ans.push_back(t);
            t *= p[i];
        }
    }
    cout << ans.size() << endl;
    for(int i = 0 ; i < (int)ans.size() ; i++)
        cout << ans[i] << ' ';
    cout << endl;

    return 0;
}
