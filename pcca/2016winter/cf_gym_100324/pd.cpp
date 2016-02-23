#include <bits/stdc++.h>
using namespace std;

string start, _end;

unordered_set<string> m;

bool dfs(string now, int depth){
    if(now == _end) return true;
    if(depth == 4){
        return false;
    } else {
        for(int i = 0 ; i < (int)now.size() ; i++){
            for(int j = i + 2; j < (int)now.size() ; j++){
                string a = now.substr(0, i);
                string b = now.substr(i, j - i);
                string c = now.substr(j, now.size() - j);
                reverse(b.begin(), b.end());
                if(dfs(a + b + c, depth+1)){
                    return true;
                }
            }
        }
        return false;
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> start >> _end;
    cout << (dfs(start, 0)?"Similar":"Different") << endl;
    return 0;
}
