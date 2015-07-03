#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, group = 0;
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        group++;
        int x;
        cin >> x;
        vector<int> tmp(x);
        for(int j = 0 ; j < x ; j++)
            cin >> tmp[j];
        if(tmp[0] == 1){
            for(int j = 1 ; j < x ; j++)
                if(tmp[j] != tmp[j-1]+1){
                    group += x - j;
                    break;
                }
        }
        else{
            group += x - 1;
        }
    }
   // cout << group << endl;
    cout << 2 * group - m  - 1 << endl;
}
