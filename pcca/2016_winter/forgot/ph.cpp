#include <bits/stdc++.h>
using namespace std;
struct ARM{
    int dl, dr, tl, tr, nl, nr;
    ARM();
    ARM(int _dl, int _dr, int _tl, int _tr, int _nl, int _nr){
        dl = _dl;
        dr = _dr;
        tl = _tl;
        tr = _tr;
        nl = _nl;
        nr = _nr;
    }
};
int head[128];
ARM arm[128];
int main(){
    int n;
    while(scanf("%d", &n), n){
        memset(head, 0, sizeof(head));
        for(int i = 1 ; i <= n ; i++){
            int dl, dr, nl, nr;
            char _tl[2], _tr[2];
            scanf("%d%d%s%s%d%d", &dl, &dr, _tl, _tr, &nl, &nr);
            arm[i] = ARM(dl, dr, _tl == 'A', _tr == 'A', nl, nr);
        }
    }
    return 0;
}
