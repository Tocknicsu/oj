#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
#define MAX 262144
#define f first
#define s second
int d[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
namespace DS{
    int v[MAX];
    void init(){
        for(int i = 0 ; i < MAX ; i++)
            v[i] = i;
    }
    int find(int x){
        return x == v[x] ? v[x] : v[x] = find(v[x]);
    }
    void merge(int x, int y){
        v[find(x)] = find(y);
    }
};
int main(){
    int n;
    string s[512];
    cin >> n;
    DS::init();
    vector<PII> x;
    for(int i = 0 ; i < n ; i++){
        cin >> s[i];
        for(int j = 0 ; j < n ; j++)
            if(s[i][j] == 'x')
                x.push_back(PII(i, j));
    }
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++){
            if(s[i][j] == '#') continue;
            for(int k = 0 ; k < 4 ; k++){
                int nx = i + d[k][0];
                int ny = j + d[k][1];
                if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if(s[nx][ny]=='#') continue;
                DS::merge(i*n+j, nx*n+ny);
            }
        }
    for(int i = 1 ; i < (int)x.size() ; i++){
        if(DS::find(x[i-1].f*n+x[i-1].s) != DS::find(x[i].f*n+x[i].s)){
            cout << "Weak!" << endl;
            return 0;
        }
    }
    cout << "Strong!" << endl;
    return 0;
}
