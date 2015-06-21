#include <bits/stdc++.h>
using namespace std;
struct S{
    int id, high, rank;
    S(){}
    S(int _id, int _high) : id(_id), high(_high) {}
};
bool sort_by_high(const S& a, const S& b){
    return a.high > b.high;
}
bool sort_by_id(const S& a, const S& b){
    return a.id < b.id;
}
int main(){
    int n, tmp;
    vector<S> vec;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> tmp;
        vec.push_back(S(i, tmp));
    }
    sort(vec.begin(), vec.end(), sort_by_high);
    vec[0].rank = 1;
    for(int i = 1 ; i < (int)vec.size() ; i++)
        vec[i].rank = vec[i].high == vec[i-1].high ? vec[i-1].rank : i+1;
    sort(vec.begin(), vec.end(), sort_by_id);
    for(auto x : vec)
        cout << x.rank << ' ';
    return 0;
}
