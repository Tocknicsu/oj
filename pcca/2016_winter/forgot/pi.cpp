#include <bits/stdc++.h>
using namespace std;
struct Point{
    double x, y;
    Point(){}
    Point(int _x, int _y) : x(_x), y(_y){}
    Point operator-(Point b){
        return Point(x - b.x, y - b.y);
    }
};
inline double sqr(int x){
    return x * x;
}
double cross(Point a, Point b){
    return a.x * b.y - a.y * b.x;
}
bool iscross(Point a, Point b, Point c, Point d){
    return cross(c-a,b-a) * cross(b-a,d-a) > 0 && cross(a-c,d-c) * cross(d-c, b-c) > 0;
}

int main(){
    Point a, b;
    int t = 1;
    while(scanf("%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y), a.x || a.y || b.x || b.y){
        Point wa, wb;
        scanf("%lf%lf%lf%lf", &wa.x, &wa.y, &wb.x, &wb.y);
        double ans;
        if(iscross(a, b, wa, wb)){
            ans = min(
                sqrt(sqr(a.x-wa.x)+sqr(a.y-wa.y)) + sqrt(sqr(b.x-wa.x)+sqr(b.y-wa.y)),
                sqrt(sqr(a.x-wb.x)+sqr(a.y-wb.y)) + sqrt(sqr(b.x-wb.x)+sqr(b.y-wb.y))
            );
        } else {
            ans = sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
        }
        printf("Case %d: %.3f\n", t++, ans/2);
    }
    return 0;
}
