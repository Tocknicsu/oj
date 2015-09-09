#include <bits/stdc++.h>
using namespace std;
int calc(vector<int>& vec){
    int tmp = 0;
    tmp = vec[0] + vec[1] + vec[2];
    tmp = max(tmp, vec[0] * vec[1] * vec[2]);
    tmp = max(tmp, (vec[0] * 10 + vec[1]) + vec[2]);
    tmp = max(tmp, (vec[0] * 10 + vec[1]) * vec[2]);
    tmp = max(tmp, vec[0] + (vec[1] * 10 + vec[2]));
    tmp = max(tmp, vec[0] * (vec[1] * 10 + vec[2]));
    return tmp;
}
int main(){
    vector<int> vec(3);
    while(cin >> vec[0] >> vec[1] >> vec[2]){
        cout << calc(vec) << endl;
    }
    return 0;
}
