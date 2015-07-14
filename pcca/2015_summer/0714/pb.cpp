#include <cstdio>
using namespace std;
namespace DS{
    const int MAX = 262144;
    int v[MAX];
    void init(int n){
        for(int i = 0 ; i < n ; i++)
            v[i] = i;
    }
    int find(int x){
        return v[x] == x ? v[x] : v[x] = find(v[x]);
    }
    void merge(int x, int y){
        x = find(x), y = find(y);
        v[x] = y;
    }
};
void Solve(){
    int n, m;
    scanf("%d %d", &n, &m);
    DS::init(2*n);
    char s[2];
    for(int i = 0 ; i < m ; i++){
        int a, b;
        scanf("%s %d %d", s, &a, &b);
        a--, b--;
        if(s[0]=='D'){
            DS::merge(a+n, b);
            DS::merge(a, b+n);
        } else {
            if(DS::find(a) == DS::find(b)){
                puts("In the same gang.");
            } else if(DS::find(a) == DS::find(b+n)){
                puts("In different gangs.");
            } else {
                puts("Not sure yet.");
            }
        }
    }
}
int main(){
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
}
