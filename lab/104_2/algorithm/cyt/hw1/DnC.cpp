#include <bits/stdc++.h>
using namespace std;
#define INF 1029384756
struct Point{
    float x, y;
    Point(){}
    Point(int _x, int _y) : x(_x), y(_y){}
    bool operator<(const Point& b) const {
        return x == b.x ? y < b.y : x < b.x;
    }
};
vector<Point> p;
vector<Point> tmp;

inline double sqr(double x){
    return x * x;
}

double dis(const Point &a, const Point &b){
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

double dnc(int l, int r){
    if(r-l == 1){
        return INF;
    }
    int mid = (l+r) / 2;
    Point t = p[mid];
    // recursive
    double ans = min(dnc(l, mid), dnc(mid, r));

    // merge sort by y-axis
    int index_l = l, index_r = mid;
    int now = l;
    while(index_l != mid && index_r != r){
        if(p[index_l].y < p[index_r].y)
            tmp[now++] = p[index_l++];
        else
            tmp[now++] = p[index_r++];
    }
    while(index_l != mid)
        tmp[now++] = p[index_l++];
    while(index_r != r)
        tmp[now++] = p[index_r++];
    for(int i = l ; i < r ; i++)
        p[i] = tmp[i];
    
    // take all possible points
    vector<Point> C;
    for(int i = l ; i < r ; i++){
        if(abs(t.x - p[i].x) <= ans){
            C.push_back(p[i]);
        }
    }
    // most important observation
    for(int i = 0 ; i < (int)C.size() ; i++){
        for(int j = 1 ; j <= 3 && i+j < (int)C.size() ; j++){
            ans = min(dis(C[i], C[i+j]), ans);
        }
    }
    return ans;
}
int main(int argc, char* argv[]){
    freopen(argv[1], "r", stdin);
    int n;
    scanf("%d", &n);
    p = vector<Point>(n);
    tmp = vector<Point>(n);
    for(int i = 0 ; i < n ; i++)
        scanf("%f%f", &p[i].x, &p[i].y);
    sort(p.begin(), p.end());
    printf("%f\n", dnc(0, n));
    return 0;
}
