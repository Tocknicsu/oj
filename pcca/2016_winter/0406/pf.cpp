#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
set<PII> S;
unordered_map<char, int> B;
int b[8][4];
void print(int now){
    for(int i = 0 ; i < 10 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            printf("%d", bool(now & (1<<(3*i+j))));
        }
        printf("\n");
    }
    printf("======\n");
}

int main(){
    B['T'] = 0;
    B['X'] = 1;
    B['R'] = 2;
    B['S'] = 3;
    B['Z'] = 4;
    B['V'] = 5;
    B['7'] = 6;
    B['W'] = 7;
    b[0][0] = 466;
    b[0][1] = 316;
    b[0][2] = 151;
    b[0][3] = 121;
    b[1][0] = 186;
    b[1][1] = 186;
    b[1][2] = 186;
    b[1][3] = 186;
    b[2][0] = 242;
    b[2][1] = 314;
    b[2][2] = 158;
    b[2][3] = 185;
    b[3][0] = 214;
    b[3][1] = 313;
    b[3][2] = 214;
    b[3][3] = 313;
    b[4][0] = 403;
    b[4][1] = 124;
    b[4][2] = 403;
    b[4][3] = 124;
    b[5][0] = 295;
    b[5][1] = 79;
    b[5][2] = 457;
    b[5][3] = 484;
    b[6][0] = 410;
    b[6][1] = 188;
    b[6][2] = 179;
    b[6][3] = 122;
    b[7][0] = 307;
    b[7][1] = 94;
    b[7][2] = 409;
    b[7][3] = 244;
    char s[32];
    scanf("%s", s);
    int len = strlen(s);
    queue<PII> Q;
    Q.push(PII(0, 0));
    int ans = 0;
    set<int> S2;
    
    while(Q.size()){
        int now = Q.front().second;
        int piece = B[s[Q.front().first % len]];
        int step = Q.front().first;
        if(ans != step){
            int t = (step - 1)%len;
            for(auto x : S2)
                if(S.count(PII(t, x)) == 1)
                    continue;
                else
                    S.insert(PII(t, x));
            S2.clear();
            ans = step;
        }
        Q.pop();
        for(int i = 0 ; i < 4 ; i++){
            //fill
            int next_state = -1;
            for(int j = 0 ; j < 7 ; j++){
                if(now & (b[piece][i] << (3*j)))
                    continue;
                next_state = now | (b[piece][i] << (3*j));
                break;
            }
            //eliminate
            if(next_state == -1)
                continue;
            for(int i = 0 ; i < 10 ; i++){
                if((next_state >> (3 * i) & 7) == 7){
                    int _down = ((1 << (3 * i)) - 1) & next_state;
                    int _up = (next_state >> (3 * (i+1))) << (3 * (i));
                    next_state = _down + _up;
                    i--;
                }
            }
            if(S.count(PII(step%len, next_state)) == 1){
                printf("forever\n");
                return 0;
            }
            Q.push(PII(step+1, next_state));
            S2.insert(next_state);
        }
    }
    printf("%d\n", ans);

    return 0;
}

