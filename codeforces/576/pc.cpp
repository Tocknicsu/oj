#include <bits/stdc++.h>
using namespace std;
#define ALL(v) v.begin(), v.end()
#define f first
#define s second
typedef pair<int, int> PII;
typedef pair<PII, int> PPI;
#define MAX 1024
vector<PPI> p[1024][1024];
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int a, b;
        cin >> a >> b;
        p[a/MAX][b/MAX].push_back(PPI(PII(a, b), i+1));
    }
    for(int i = 0 ; i < MAX ; i++)
        for(int j = 0 ; j < MAX ; j++)
            sort(ALL(p[i][j]));

    for(int i = 0 ; i < MAX ; i++)
        if(i&1){
            for(int j = MAX - 1 ; j >= 0 ; j--){
                for(int k = 0 ; k < (int)p[i][j].size() ; k++)
                    cout << p[i][j][k].s << ' ';
            }
        }
        else{
            for(int j = 0 ; j < MAX ; j++){
                for(int k = 0 ; k < (int)p[i][j].size() ; k++)
                    cout << p[i][j][k].s << ' ';
            }
        }

}
