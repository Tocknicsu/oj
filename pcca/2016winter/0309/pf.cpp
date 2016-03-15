#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAX 131072

inline ll squ(ll x){
    return x * x;
}

struct P{
    ll x, y, z;
    P(){}
    P(int _x, int _y, int _z){
        x = _x;
        y = _y;
        z = _z;
    }
    ll operator-(P b){
        return squ(b.x-x)+squ(b.y-y)+squ(b.z-z);
    }
    bool operator<(const P& b) const {
        if(x != b.x)
            return x < b.x;
        if(y != b.y)
            return y < b.y;
        return z < b.z;
    }
    P operator+(const P& b) const {
        P re;
        re.x = x + b.x;
        re.y = y + b.y;
        re.z = z + b.z;
        return re;
    }
    P operator/(const int &b) const {
        P re;
        re.x = x / b;
        re.y = y / b;
        re.z = z / b;
        return re;
    }

};
vector<P> bucket[MAX];
P g[MAX];
vector<P> p;

int main(){
    //freopen("pf.in", "r", stdin);
    int n, m;
    while(scanf("%d %d", &n, &m), n || m){
        P tmp;
        p.clear();
        for(int i = 0 ; i < MAX ; i++){
            bucket[i].clear();
            g[i] = P(0,0,0);
        }
        for(int i = 0 ; i < n ; i++){
            scanf("%lld%lld%lld", &tmp.x, &tmp.y, &tmp.z);
            p.push_back(tmp);
        }
        sort(p.begin(), p.end());
        int use = 0;
        for(int i = 0 ; i < n ; i++){
            bool flag = 0;
            for(int j = 0 ; j < use ; j++){
                if( ((g[j]/bucket[j].size()) - p[i]) / 300 <= squ(m)){
                    flag = 1;
                    g[j] = g[j] + p[i];
                    bucket[j].push_back(p[i]);
                    break;
                }
            }
            if(!flag){
                g[use] = p[i];
                bucket[use].push_back(p[i]);
                use++;
            }
        }
        int ans = 0;
        for(int i = 0 ; i < use ; i++){
            for(int j = 0 ; j < (int)bucket[i].size() ; j++){
                for(int k = j + 1 ; k < (int)bucket[i].size() ; k++){
                    if(bucket[i][j] - bucket[i][k] < squ(m)){
                        //printf("%lld %lld %lld, %lld %lld %lld\n", bucket[i][j].x, bucket[i][j].y, bucket[i][j].z, bucket[i][k].x, bucket[i][k].y, bucket[i][k].z);
                        ans++;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
