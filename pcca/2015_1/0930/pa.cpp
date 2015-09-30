#include <bits/stdc++.h>
using namespace std;
#define MAX 10000000
bool prime[MAX];
void build(){
    prime[0] = prime[1] = 1;
    for(int i = 4 ; i < MAX ; i+=2)
        prime[i] = 1;
    for(int i = 3 ; i * i < MAX ; i += 2)
        if(!prime[i])
            for(int j = i * i ; j < MAX ; j += 2 * i)
                prime[j] = 1;
}
void Solve(){
    char s[8];
    scanf("%s", s);
    int len = strlen(s);
    sort(s, s+len);
    set<int> ans;
    do{
        for(int i = 0 ; i < len ; i++){
            int v = atoi(s+i);
            if(!prime[v])
                ans.insert(v);
        }

    } while (next_permutation(s, s+len));
    printf("%d\n", (int)ans.size());
}

int main(){
    build();
    int t;
    scanf("%d", &t);
    while(t--)
        Solve();
    return 0;
}
