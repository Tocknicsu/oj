#include <bits/stdc++.h>
using namespace std;
struct P{
    float x, y;
    P(){}
    P(float _x, float _y) : x(_x), y(_y) {}
};
float total_ans;
vector<P> p;
bool ok(float s){
    P t[3];
    int n = p.size();
    float now = 0;
    for(int i = 0 ; i < (int)p.size() ; i++){
        t[0] = P((p[(i+n-1)%n].x+p[i].x*(s-1))/s,
                 (p[(i+n-1)%n].y+p[i].y*(s-1))/s
                );
        t[1] = p[i];
        t[2] = P((p[(i+1)%n].x+p[i].x*(s-1))/s,
                 (p[(i+1)%n].y+p[i].y*(s-1))/s
                );
        float tmp = 0;
        for(int j = 0 ; j < 3 ; j++){
            tmp += t[j].x * t[(j+1)%3].y;
            tmp -= t[j].y * t[(j+1)%3].x;
        }
        tmp = abs(tmp) / 2;
        now += tmp; 
    }
   // printf("%.10f %.10f %.10f\n", s, now, total_ans);
    return now >= total_ans;
}
int main(){
    freopen("pc.3.in", "r", stdin);
    float a;
    int n;
    scanf("%f%d", &a, &n);
    for(int i = 0 ; i < n ; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        p.push_back(P(x, y));
    }
    for(int i = 0 ; i < n ; i++){
        total_ans += p[i].x * p[(i+1)%n].y;
        total_ans -= p[i].y * p[(i+1)%n].x;
    }
    total_ans = (abs(total_ans) / 2) * (1-a);
    /*
    float ans = 2, step = 22000;
    int times = 10000;
    while(times--){
        if(ok(ans+step))
            ans += step;
        else
            step /= 2;
    }
    printf("%.6f\n", min(ans, float(1000.0)));
    */
    float l = 2.0, r = 1000.0;
    int times = 1000;
    while(times--){
        float mid = (l+r)/2;
        if(ok(mid))
            l = mid;
        else
            r = mid;
    }
    printf("%.6f\n", l);
}
