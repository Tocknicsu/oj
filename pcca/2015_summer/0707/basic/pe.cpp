#include <bits/stdc++.h>
using namespace std;
vector<int> alpha[3];


void test(vector<int> vec, int a_t, bool &ok, int &b_t){
    b_t = 1029384756;
    for(int i = 0 ; i < 26 ; i++){
        vec[i] -= a_t * alpha[1][i];
        if(vec[i] < 0){
            ok = false;
            return;
        }
        if(alpha[2][i] != 0)
            b_t = min(b_t, vec[i] / alpha[2][i]);
    }
    ok = true;
}

int main(){
    int ans = 0, ans_a = 0;
    string str[3];
    for(int i = 0 ; i < 3 ; i++){
        cin >> str[i];
        alpha[i] = vector<int>(26);
        for(int j = 0 ; j < (int)str[i].size() ; j++)
            ++alpha[i][str[i][j]-'a'];
    }
    for(int i = 0 ; i <= (int)str[0].size() ; i++){
        bool ok;
        int b_t;
        test(alpha[0], i, ok, b_t);
        if(ok){
            if(i+b_t > ans){
                ans = i+b_t;
                ans_a = i;
            }
        } else break;
    }
    for(int i = 0 ; i < ans ; i++)
        cout << (i < ans_a ? str[1] : str[2]);
    for(int i = 0 ; i < 26 ; i++){
        int x = alpha[0][i] - alpha[1][i]*ans_a - alpha[2][i]*(ans-ans_a);
        for(int j = 0 ; j < x ; j++)
            cout << char('a'+i);
    }
}
