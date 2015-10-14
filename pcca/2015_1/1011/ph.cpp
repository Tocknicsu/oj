#include <bits/stdc++.h>
using namespace std;
vector<int> ed[1024];
typedef pair<string, string> PSS;
map<PSS, int> m;
bool v[1024];
bool go[1024];
void dfs(int x){
    for(int i = 0 ; i < (int)ed[x].size() ; i++)
        if(!v[ed[x][i]]){
            v[ed[x][i]] = true;
            dfs(ed[x][i]);
        }
}
PSS get_next(){
    char s[64];
    scanf("%s", s);
    int len = strlen(s);
    for(int i = 0 ; i < len ; i++)
        if(s[i] == ':')
            return PSS(string(s, s+i), string(s+i+2, s+len));
    return PSS(string(""), string(""));
}
int main(){
    //freopen("ph.3.in", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++){
        
        PSS now = get_next();
        if(!m[now]) m[now] = m.size()+1;
        int x = m[now];
        if(now.second == "PROGRAM")
            go[x] = true;
        int t;
        scanf("%d", &t);
        for(int j = 0 ; j < t ; j++){
            PSS from = get_next();
            if(!m[from]) m[from] = m.size()+1;
            int y = m[from];
            ed[y].push_back(x);
        }
    }
    for(int i = 0 ; i < 1024 ; i++)
        if(go[i] && !v[i]){
            v[i] = true;
            dfs(i);
        }
    int t = 0;
    for(int i = 0 ; i < 1024 ; i++)
        if(v[i]) ++t;
    printf("%d\n", (int)m.size() - t);
    return 0;
}
