#include <bits/stdc++.h>
using namespace std;

vector<int> ed[81];
bool exist[81];
int v[81];
void dfs(int x, int p){
    v[x]++;
    if(v[x] > 1) return;
    for(int i = 0 ; i < (int)ed[x].size() ; i++){
        if(ed[x][i]==p) continue;
        dfs(ed[x][i], x);
    }
}

int main(){
    int n;
    cin >> n;
    string str;
    getline(cin, str);
    while(n--){
        getline(cin, str);
        for(int i = 0 ; i < (int)str.size() ; i++)
            if(str[i] == ',') str[i] = ' ';
        stringstream ss(str);
        int a, b;
        for(int i = 0 ; i < 81 ; i++)
            ed[i].clear();
        fill(exist, exist+81, 0);
        fill(v, v+81, 0);
        while(ss >> a >> b){
            exist[a] = exist[b] = 1;
            ed[a].push_back(b);
            ed[b].push_back(a);
        }
        int s = -1;
        for(int i = 0 ; i < 81 ; i++)
            if(exist[i]) s = i;
        dfs(s, -1);
        bool ok = true;
        for(int i = 0 ; i < 81 ; i++){
            if(exist[i]){
                if(v[i] != 1)
                    ok = false;
            }
        }
        cout << (ok?"T":"F") << endl;
        
    }
    return 0;
}
