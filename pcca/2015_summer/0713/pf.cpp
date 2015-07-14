#include <bits/stdc++.h>
using namespace std;
bool con[26][26];
string str[128];
int main(){
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> str[i];
    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ; j < n ; j++){
            int m = min(str[i].size(), str[j].size());
            for(int k = 0 ; k < m ; k++){
                if(str[i][k] != str[j][k]){
                    con[str[i][k]-'a'][str[j][k]-'a'] = 1;
                    break;
                } else if(k == m-1){
                    if(str[i].size() > str[j].size()){
                        cout << "Impossible" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    for(int k = 0 ; k < 26 ; k++){
        for(int i = 0 ; i < 26 ; i++){
            for(int j = 0 ; j < 26 ; j++)
                if(con[i][k] && con[k][j]) con[i][j] = 1;
        }
    }
    bool gg = false;
    for(int i = 0 ; i < 26 ; i++)
        gg |= con[i][i];
    if(gg){
        cout << "Impossible" << endl;
        return 0;
    }
    bool vis[26] = {};
    int deg[26] = {};
    int t = 26;
    for(int i = 0 ; i < 26 ; i++)
        for(int j = 0 ; j < 26 ; j++)
            deg[i] += con[j][i];
    while(t--){
        for(int i = 0 ; i < 26 ; i++){
            if(deg[i] == 0 && !vis[i]){
                cout << char(i+'a');
                for(int j = 0 ; j < 26 ; j++){
                    if(con[i][j]){
                        con[i][j] = 0;
                        deg[j]--;
                    }
                }
                vis[i] = 1;
                break;
            }
        }
    }

}
