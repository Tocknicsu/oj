#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<int, int> PII;
typedef pair<char, int> Tri;
typedef pair<Tri, int> Trii;
vector<Trii> tri;
bool cmp(const PII &a, const PII &b){
    return a.f > b.f;
}
void Solve(){
    tri.clear();
    int n;
    scanf("%d", &n);
    char s[9];
    for(int i = 0 ; i < n ; i++){
        scanf("%s", s);
        for(int j = 0 ; j < 4 ; j++)
            tri.push_back(Trii(Tri(s[j*2], s[j*2+1]-'0'),i));
    }
    for(int i = 0 ; i < (int)tri.size() ; i++){
        cout << tri[i].f.f << ' ' << tri[i].f.s << ' ' << endl;
    }
    vector<PII> vec;
    for(int i = 4 ; i < (int)tri.size() ; i++){
        int S = 0;
        for(int j = 0 ; j < 4 ; j++)
            S += tri[(i/4) * 4 + j].f.s;
        for(int j = 0 ; j < 4 ; j++){
            if(tri[i].f.f == tri[j].f.f){
                int score = 0;
                int x = tri[j].f.s;
                int c = tri[i].f.f;
                if(c == 'B')
                    score = S - x;
                else if(c == 'G')
                    score = S + x;
                else if(c == 'R')
                    score = S * x;
                else if(c == 'Y'){
                    if(x > 0){
                        score = S % x;
                    }
                }
                cout << "match: " << i << ' ' << j << ' ' << score << endl;
                vec.push_back(PII(score, i));
            }
        }
    }
    sort(vec.begin(), vec.end(), cmp);
    bool ok[4] = {0};
    int num = 0;
    int ans = 0;
    map<int, bool> use;
    for(int i = 0 ; i < (int)vec.size() ; i++){
        cout << vec[i].f << ' ' << vec[i].s << endl;
        int x = vec[i].s;
        if(use[x/4]) continue;
        for(int j = 0 ; j < 4 ; j++){
            if(ok[j]) continue;
            if(tri[i].f.f == tri[j].f.f){
                ok[j] = true;
                use[x/4] = 1;
                ans += vec[i].f;
                num++;
                if(num == 4){
                    cout << ans << endl;
                    return;
                }
            }
        }
    }
    cout << ans << endl;
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        Solve();
    return 0;
}
