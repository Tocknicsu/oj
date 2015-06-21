#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct matrix{
    int sz;
    ll v[220][220];
    matrix(int _sz, bool is_i = false){
        sz = _sz;
        for(int i = 0 ; i < sz ; i++)
            for(int j = 0 ; j < sz ; j++)
                v[i][j] = i == j ? is_i : 0;
    }
    matrix operator*(const matrix& b) const {
        matrix re(sz);
        for(int i = 0 ; i < sz ; i++){
            for(int j = 0 ; j < sz ; j++){
                for(int k = 0 ; k < sz ; k++)
                    if(v[i][k] && b.v[k][j])
                        re.v[i][j] = max(re.v[i][j], v[i][k] + b.v[k][j]);
            }
        }
        return re;
    }
    matrix operator^(const int &k) const {
        bool first = true;
        matrix re(sz);
        matrix tmp = (*this);
        int t = k;
        while(t){
            if(t&1){
                if(first)
                    re = tmp, first = false;
                else
                    re = re * tmp;
            }
            tmp = tmp * tmp;
            t >>= 1;
        }
        return re;
    }
};
void Solve(){
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    matrix basic(n);
    for(int i = 0 ; i < m ; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        basic.v[a][b] = max(basic.v[a][b], c);
    }
    matrix now(n);
    now = (basic ^ k);
    for(int i = 0 ; i < q ; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        cout << now.v[a][b] << endl;
    }
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    while(n--)
        Solve();
    return 0;
}
