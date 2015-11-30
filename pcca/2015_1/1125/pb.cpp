#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<int, int> PII;
string str;
vector<PII> v;
int ans;

bool check_m(){
    vector<PII> now = v;
    vector<PII> after;
    for(int i = 0 ; i < (int)now.size() ; i++){
        if(now[i].f == 1 && now[i].s == 1){
            after.back().s *= now[i+1].s;
            i++;
        } else {
            after.push_back(now[i]);
        }
    }
    int sum = 0;
    for(int i = 0 ; i < (int)after.size() ; i++){
        sum += after[i].f == 0 ? after[i].s : 0;
    }
    return sum == ans;
}

bool check_l(){
    vector<PII> now = v;
    int sum = now[0].s;
    for(int i = 1 ; i < (int)now.size() ; i+=2){
        if(now[i].s == 0){
            sum += now[i+1].s;
        } else {
            sum *= now[i+1].s;
        }

    }
    return sum == ans;
}

int main(){
//    freopen("pb.in", "r", stdin);
    ios_base::sync_with_stdio(0), cin.tie(0);
    while(cin >> str >> ans){
        v.clear();
        for(int i = 0 ; i < (int)str.size() ; i++){
            if(str[i] == '+' || str[i] == '*'){
                v.push_back(PII(1, str[i] == '*'));
            } else {
                v.push_back(PII(0, str[i]-'0'));
            }
        }
        bool m = check_m();
        bool l = check_l();
        if(m && l){
            cout << "U" << endl;
        } else if(m) {
            cout << "M" << endl;
        } else if(l) {
            cout << "L" << endl;
        } else {
            cout << "I" << endl;
        }
    }
    return 0;
}
