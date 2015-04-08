#include <cmath>
#include <math.h>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <iostream>
using namespace std;
typedef pair<int, int> PII;
struct POINT{
	int x, y;
	POINT(){}
	POINT(int _x, int _y){
		x = _x, y = _y;
	}
};

double dis(POINT a, POINT b, POINT c){

	double tmp = a.x * b.y + b.x * c.y * c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;

	double l = sqrt( (a.x-b.x) * (a.x-b.x) + (a.y-b.y) * (a.y-b.y));
	return abs(tmp / l);
}

int main(){
	POINT l1, l2;
	cin >> l1.x >> l1.y >> l2.x >> l2.y;
//	scanf("%d %d %d %d", &l1.x, &l1.y, &l2.x, &l2.y);
	POINT r1, r2;
	scanf("%d %d %d %d", &r1.x, &r2.x, &r1.y, &r2.y);
	
	double ans = 1029384576;
	ans = min(ans, dis(l1, l2, r1));
	ans = min(ans, dis(l1, l2, r2));
	ans = min(ans, dis(l1, l2, POINT(r1.x, r2.y)));
	ans = min(ans, dis(l1, l2, POINT(r2.x, r1.y)));
	printf("%.1lf\n", ans);
}
