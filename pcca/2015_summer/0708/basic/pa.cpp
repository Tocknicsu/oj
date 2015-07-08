#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void Solve(vector<int> &s){
    stack<int> a, b;
    for(int i = s.size() ; i > 0 ; i--)
        a.push(i);
    for(int i = 0 ; i < (int)s.size() ; i++){
        while(a.size() && a.top() < s[i]){
            b.push(a.top());
            a.pop();
        }
        if(a.size() && a.top() == s[i]){
            a.pop();
        } else if(b.size() && b.top() == s[i]) {
            b.pop();
        } else {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}


void Run(int n){
    int c;
    while(cin >> c, c){
        vector<int> s;
        s.push_back(c);
        for(int i = 1 ; i < n ; i++)
            cin >> c, s.push_back(c);
        Solve(s);
    }
    cout << endl;
}

int main(){
    int n;
    while(cin >> n, n){
        Run(n);
    }
    return 0;
}
