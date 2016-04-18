#include <bits/stdc++.h>
using namespace std;
typedef pair<string, vector<int>* > PSV;

bool cmp(const PSV &a, const PSV &b){
    for(int i = 0 ; i < 50 ; i++){
        if( (*a.second)[i] != (*b.second)[i]){
            return (*a.second)[i] > (*b.second)[i];
        }
    }
    return a.first < b.first;
}


int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<PSV> p(n);
    string str, tmp;
    getline(cin, str);
    for(int i = 0 ; i < n ; i++){
        p[i].second = new vector<int>(50, 1);
        getline(cin, str);
        stringstream ss(str);
        ss >> tmp;
        p[i].first = tmp.substr(0, tmp.size()-1);
        stack<int> s;
        while(ss >> tmp, tmp != "class"){
            if(tmp[0] == 'l') s.push(0);
            else if(tmp[0] == 'm') s.push(1);
            else if(tmp[0] == 'u') s.push(2);
        }
        int now = 0;
        while(s.size()){
            (*p[i].second)[now++] = s.top();
            s.pop();
        }
    }
    sort(p.begin(), p.end(), cmp);
    for(int i = 0 ; i < n ; i++)
        cout << p[i].first << endl;

    return 0;
}
