#include <bits/stdc++.h>
using namespace std;
inline int squ(int x){
    return x * x;
}
struct S{
    int a, b, c;
    string name;
    S(){}
    S(int _a, int _b, int _c, string _name) : a(_a), b(_b), c(_c), name(_name){}
    int operator-(const S& _) const {
        return squ(a - _.a) + squ(b - _.b) + squ(c - _.c);
    }
};


int main(){
    //freopen("pb.in", "r", stdin);
    vector<S> s;
    s.push_back(S(255, 255, 255, "White"));
    s.push_back(S(192, 192, 192, "Silver"));
    s.push_back(S(128, 128, 128, "Gray"));
    s.push_back(S(0, 0, 0, "Black"));
    s.push_back(S(255, 0, 0, "Red"));
    s.push_back(S(128, 0, 0, "Maroon"));
    s.push_back(S(255, 255, 0, "Yellow"));
    s.push_back(S(128, 128, 0, "Olive"));
    s.push_back(S(0, 255, 0, "Lime"));
    s.push_back(S(0, 128, 0, "Green"));
    s.push_back(S(0, 255, 255, "Aqua"));
    s.push_back(S(0, 128, 128, "Teal"));
    s.push_back(S(0, 0, 255, "Blue"));
    s.push_back(S(0, 0, 128, "Navy"));
    s.push_back(S(255, 0, 255, "Fuchsia"));
    s.push_back(S(128, 0, 128, "Purple"));
    int a, b, c;
    while(scanf("%d%d%d", &a, &b, &c), a != -1 && b != -1 && c != -1){
        string ans;
        int dis = 1029384756;
        S now(a, b, c, "");
        for(int i = 0 ; i < (int)s.size() ; i++){
            int d = now - s[i];
            if(d < dis){
                dis = d;
                ans = s[i].name;
            }
        }
        printf("%s\n", ans.c_str());
    }
    return 0;
}
