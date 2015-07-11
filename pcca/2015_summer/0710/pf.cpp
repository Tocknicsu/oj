#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
#define f first
#define s second
char s[128][128];
int v[128][128];
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
        cin >> s[i];
    int ans = 0;
    for(int i = n - 1 ; i >= 0 ; i--){
        for(int j = m - 1 ; j >= 0 ; j--){
            int goal = s[i][j] == 'B' ? -1 : 1;
            int diff = goal - v[i][j];
            if(diff){
                for(int x = 0 ; x <= i ; x++)
                    for(int y = 0 ; y <= j ; y++)
                        v[x][y] += diff;
                ans++;
            }
        }
    }
    cout << ans << endl;
}
