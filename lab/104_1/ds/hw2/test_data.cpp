#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]){
    vector<int> to_insert(atoi(argv[1]));
    freopen(argv[2], "w", stdout);
    for(int i = 0 ; i < (int)to_insert.size() ; i++){
        to_insert[i] = i;
    }
    random_shuffle(to_insert.begin(), to_insert.end());

    int times = 2 * to_insert.size();
    vector<int> to_delete;
    while(times--){
        if((rand()%100 > 80 && to_delete.size())||to_insert.empty()){
            random_shuffle(to_delete.begin(), to_delete.begin());
            cout << "D " << to_delete.back() << endl;
            to_delete.pop_back();
        } else {
            cout << "I " << to_insert.back() << endl;
            to_delete.push_back(to_insert.back());
            to_insert.pop_back();
        }
        cout << "B" << endl << "C" << endl;
    }

    return 0;
}
