#include <bits/stdc++.h>
using namespace std;
int d[6][3] = {{-1, 0, 0}, {1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
int calc(int a, int b, int c){
    return a * 100 + b * 10 + c;
}
int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        map<int, bool> s;
        int a, b, c, m;
        cin >> m;
        int ans = 6 * m;
        while(m--){
            cin >> a >> b >> c;
            s[calc(a, b, c)] = 1;
            for(int i = 0 ; i < 6 ; i++){
                int na = a + d[i][0];
                int nb = b + d[i][1];
                int nc = c + d[i][2];
                if(s[calc(na, nb, nc)]){
                    ans-=2;
                }
            }
        }
        cout << ans << endl;
    }

    
}
