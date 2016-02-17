#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
ll f[36];
bool p[36];
void Solve(){
    int n;
    scanf("%d", &n);
    bool exist[36];
    fill(exist, exist+sizeof(exist), 1);
    vector<int> v;
    for(int i = 1 ; i <= n ; i++)
        v.push_back(i);
    int now = 1, remain, d = 1;
    for(int i = 0 ; i < n - 1 ; i++){
        int tmp = n - i;
        remain = f[i] % tmp;
        if(remain == 0) remain += tmp;
        while(remain != 1){
            now += d;
            if(now < 1) now = n;
            if(now > n) now = 1;
            if(exist[now])
                remain--;
        }
        if(p[now]) d *= -1;
        exist[now] = 0;
        while(!exist[now]){
            now += d;
            if(now < 1) now = n;
            if(now > n) now = 1;
        }
    }
    for(int i = 1 ; i <= n ;i++)
        if(exist[i])
            printf("%d\n", i);
}
int main(){
    f[0] = f[1] = 1;
    for(int i = 2 ; i < 35 ; i++)
        f[i] = f[i-1] + f[i-2];
    p[2] = p[3] = p[5] = p[7] = p[11] = p[13] = p[17] = p[19] = p[23] = p[29] = p[31] = 1;
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
    return 0;
}
