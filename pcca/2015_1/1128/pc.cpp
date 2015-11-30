#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define MAX 8192
typedef pair<int, int> PII;

int fed[MAX];
vector<PII> ed[MAX];
bool infed[26];
int s, t;

void Solve(){
    for(int i = 0 ; i < MAX ; i++)
        ed[i].clear();
    int n, now, m, to;
    char tick[12];
    char sfed[2];
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &now);
        scanf("%s", sfed);
        fed[now] = sfed[0] - 'A';
        scanf("%d", &m);
        for(int j = 0 ; j < m ; j++){
            scanf("%s%d", tick, &to);
            ed[now].push_back(PII(atoi(tick+1), to));
        }
    }
    scanf("%d", &n);
    char sinfed[32];
    for(int i = 0 ; i < n ; i++){
        scanf("%d%d%s", &s, &t, sinfed);
        memset(infed, 0, sizeof(infed));
        for(int j = 0 ; sinfed[j] ; j++){
            infed[sinfed[j]-'A'] = 1;
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
    return 0;
}
