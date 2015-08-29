#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 0, x;
    priority_queue<int> PQ;
    cin >> x;
    for(int i = 1 ; i < n ; i++){
        int tmp;
        cin >> tmp;
        PQ.push(tmp);
    }
    while(PQ.top() >= x){
        int tmp = PQ.top();
        PQ.pop();
        x++;
        PQ.push(tmp-1);
        ans++;
    }
    cout << ans << endl;
    return 0;
}
