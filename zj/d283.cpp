#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000
struct NUM{
    int v[1000];
    NUM(){
        init();
    }
    NUM(int x){
        init();
        v[0] = x;
    }
    void init(){
        memset(v, 0, sizeof(v));
    }
    NUM operator+(const NUM &b) const {
        NUM re;
        for(int i = 0 ; i < 1000 ; i++)
            re.v[i] = v[i] + b.v[i];
        re.format();
        return re;
    }
    void format(){
        for(int i = 0 ; i < 1000 ; i++)
            if(v[i] > MOD){
                v[i+1] += v[i] / MOD;
                v[i] %= MOD;
            }
    }
    void print(){
        bool first = false;
        for(int i = 999 ; i >= 0 ; i--){
            if(first){
                printf("%06d", v[i]);
            } else {
                if(v[i]){
                    printf("%d", v[i]);
                    first = true;
                }
            }
        }
        printf("\n");
    }
};
    NUM ans[20001];
int main(){
    ans[1] = NUM(1), ans[2] = NUM(1);
    for(int i = 3 ; i < 20001 ; i++){
        ans[i] = ans[i-1] + ans[i-2];
    }
    int n;
    while(~scanf("%d", &n)){
        ans[n].print();
    }
}
