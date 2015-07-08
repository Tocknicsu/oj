#include <iostream>
#include <queue>
using namespace std;

void Solve(int n){
    queue<int> q;
    for(int i = 1 ; i <= n ; i++)
        q.push(i);
    bool start = true;
    cout << "Discarded cards:";
    while(q.size() != 1){
        if(start) start = false;
        else cout << ",";
        cout << " ";
        cout << q.front();
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout << endl << "Remaining card: " << q.front() << endl;
}

int main(){
    int n;
    while(cin >> n){
        if(n)
            Solve(n);
        else
            return 0;
    }
}
