#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
namespace DS{
    int v[262144], sz[262144];
    void init(int n){
        for(int i = 0 ; i < n ; i++)
            v[i] = i, sz[i] = 1;
    }
    int find(int x){
        return v[x] == x ? v[x] : v[x] = find(v[x]);
    }
    int size(int x){
        return sz[find(x)];
    }
    void merge(int x, int y){
        x = find(x), y = find(y);
        v[x] = y;
        sz[y] += sz[x];
        sz[x] = 0;
    }
    
};
int len[262144];
bool ex[262144];
int main(){
    int n;
    cin >> n;
    vector<PII> v(n);
    for(int i = 0 ; i < n ; i++)
        cin >> v[i].first, v[i].second = i;
    sort(v.begin(), v.end());
    DS::init(n);
    for(int i = n - 1; i >= 0 ; i--){
        int value = v[i].first;
        int pos = v[i].second;
        ex[pos] = true;
        if(pos > 0 && ex[pos-1]) DS::merge(pos, pos-1);
        if(pos < n - 1 && ex[pos+1]) DS::merge(pos, pos+1);
        for(int i = DS::size(pos) ; i > 0 && !len[i] ; i--)
            len[i] = value;
    }
    for(int i = 1 ; i <= n ; i++)
        cout << len[i] << ' ';
    cout << endl;
    return 0;
}
