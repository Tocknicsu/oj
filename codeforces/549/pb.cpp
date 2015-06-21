#include <bits/stdc++.h>
using namespace std;
bool m[128][128];
int de[128];
bool v[128];
int n;
int ans(){
    for(int i = 0 ; i < n ; i++)
        if(!de[i])
            return i;
    return -1;
}
int main(){
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        string tmp;
        cin >> tmp;
        for(int j = 0 ; j < n ; j++)
            m[i][j] = tmp[j] == '1';
    }
    for(int i = 0 ; i < n ; i++)
        cin >> de[i];
    int now = 0;
    while(now <= n){
        int x = ans();
        if(x == -1){
            cout << now << endl;
            for(int i = 0 ; i < n ; i++)
                if(v[i])
                    cout << i+1 << ' ';
            return 0;
        }
        v[x] = true;
        for(int i = 0 ; i < n ; i++)
            if(m[x][i])
                de[i]--;
        now++;
    }
    cout << "-1" << endl;
    return 0;
}
