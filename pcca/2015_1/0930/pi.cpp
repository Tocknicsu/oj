#include <bits/stdc++.h>
using namespace std;
#define eps 1e-9
struct S{
    int x, y;
    int id;
    S(){}
    S(int _x, int _y, int _id){
        x = _x;
        y = _y;
        id = _id;
    }
    bool operator<(const S& a) const {
        if(fabs(atan2(y, x) - atan2(a.y, a.x)) < eps ){
            if(y == a.y)
                return x < a.x;
            return y > a.y;
        }
        return atan2(y, x) < atan2(a.y, a.x);
    }
};

void Solve(){
    int n;
    scanf("%d", &n);
    vector<S> s(n);
    
    int mx = -16384, my = 16384;
    for(int i = 0 ; i < n ; i++){
        scanf("%d%d", &s[i].x, &s[i].y);
        if(s[i].y < my){
            my = s[i].y;
            mx = s[i].x;
        } else if (s[i].y == my){
            mx = max(mx, s[i].x);
        }
        s[i].id = i;
    }
    for(int i = 0 ; i < n ; i++){
        s[i].x -= mx;
        s[i].y -= my;
    }
    sort(s.begin(), s.end());
    /*
    for(int i = 0 ; i < (int)s.size() ; i++){
        cout << s[i].x << ' ' << s[i].y << ' ' << s[i].id << endl;
    }
    cout << endl;
    */
    for(int i = 0 ; i < (int)s.size() ; i++){
        printf("%d ", s[i].id);
    }
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        Solve();
    return 0;
}
/*
8
0 0
1 0
2 0
2 1
2 2
1 2
0 2
0 1
*/
