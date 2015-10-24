#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<int, int> PII;
#define MAX 131072
#define INF 1029384756
struct Point{
    int x, y, id;
    Point(){}
    Point(int _x, int _y, int _id) : x(_x), y(_y), id(_id){}
    bool operator<(const Point &b) const {
        return x < b.x;
    }
};
vector<Point> p;
struct ED{
    int a, b, c;
    ED(){}
    ED(int _a, int _b, int _c) : a(_a), b(_b), c(_c){}
    bool operator<(const ED &B) const {
        return c < B.c;
    }
};
namespace BIT{
    int v[MAX+1], id[MAX+1];
    void init(){
        for(int i = 0 ; i < MAX ; i++)
            v[i] = INF;
    }
    void add(int x, int now){
        for( ; x > 0 ; x -= x & -x)
            if(v[x] > p[now].x + p[now].y){
                v[x] = p[now].x + p[now].y;
                id[x] = now;
            }
    }
    int query(int x){
        int re = INF, reid = -1;
        for( ; x < MAX ; x += x & -x){
            if(v[x] < re){
                re = v[x], reid = id[x];
            }
        }
        return reid;
    }
};
namespace DS{
    int v[MAX];
    void init(){
        for(int i = 0 ; i < MAX ; i++)
            v[i] = i;
    }
    int find(int x){
        return x == v[x] ? v[x] : v[x] = find(v[x]);
    }
    bool merge(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return false;
        v[x] = y;
        return true;
    }
};
int __distance(int x, int y){
    return abs(p[x].x - p[y].x) + abs(p[x].y - p[y].y);
}
int main(){
    int n;
    scanf("%d", &n);
    p = vector<Point>(n);
    vector<PII> ord(n);
    vector<int> dis;
    vector<ED> ed;
    for(int i = 0 ; i < n ; i++){
        scanf("%d%d", &p[i].x, &p[i].y);
        p[i].id = i;
    }
    for(int k = 0 ; k < 4 ; k++){
        BIT::init();
        dis.clear();
        if(k == 2 || k == 4)
            for(int i = 0 ; i < n ; i++)
                swap(p[i].x, p[i].y);
        if(k == 3)
            for(int i = 0 ; i < n ; i++)
                p[i].x = -p[i].x;
        sort(p.begin(), p.end());
        for(int i = 0 ; i < n ; i++){
            ord[i].f = p[i].x - p[i].y, ord[i].s = i;
            dis.push_back(ord[i].f);
        }
        sort(ord.begin(), ord.end());
        sort(dis.begin(), dis.end());
        dis.resize(unique(dis.begin(), dis.end())-dis.begin());
        for(int i = n-1 ; i >= 0 ; i--){
            int x = lower_bound(dis.begin(), dis.end(), ord[i].f) - dis.begin() + 1;
            int y = BIT::query(x);
            if(y != -1){
                //ed.push_back(ED(1, 2, 3));
                ed.push_back( ED( p[ord[i].s].id, p[y].id, __distance(ord[i].s, y) )) ;
            } else {
            }
            BIT::add(x, ord[i].s);
        }
    }
    DS::init();
    sort(ed.begin(), ed.end());
    long long ans = 0;
    for(int i = 0 ; i < (int)ed.size() ; i++){
        if(DS::merge(ed[i].a, ed[i].b))
            ans += ed[i].c;
    }
    printf("%lld\n", ans);
    return 0;
}
