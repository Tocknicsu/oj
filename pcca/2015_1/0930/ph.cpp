#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
map<PII, int> m;
vector<int> ans;
int cnt[6];
int d[6][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 0}, {-1, -1}, {0, -1}};
int dcnt[6] = {1, 0, 1, 1, 1, 1};

void build(){
    int nx = 0, ny = 0, dir = 0;
    ans.push_back(1);
    m[PII(0,0)] = 1;
    cnt[1] = 1;
    while((int)ans.size() <= 10000){
        for(int i = 0 ; i < dcnt[dir] ; i++){
            //cout << "now: " << ans.size() << endl;
            nx = nx + d[dir][0];
            ny = ny + d[dir][1];
            //cout << nx << ' ' << ny << endl;
            bool ok[6];
            fill(ok, ok+6, 1);
            for(int j = 0 ; j < 6 ; j++){
                int nnx = nx + d[j][0];
                int nny = ny + d[j][1];
                ok[m[PII(nnx, nny)]] = 0;
            }
            int fn = 0, times = 1029384756;
            for(int j = 1 ; j < 6 ; j++){
                if(ok[j]){
                    if(cnt[j] < times){
                        fn = j;
                        times = cnt[j];
                    }
                }
            }
            ans.push_back(fn);
            m[PII(nx, ny)] = fn;
            cnt[fn]++;
        }
        dcnt[dir]++;
        dir = (dir+1)%6;
    }
}

int main(){
    int t, n;
    build();
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("%d\n", ans[n-1]);
    }
}
