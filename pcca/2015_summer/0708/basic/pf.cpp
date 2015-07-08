#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
int p;
bool run(){
    int end = -vec[p];
    int tmp = 0;
    for(p++ ; vec[p]!=end ; p++){
        tmp += abs(vec[p]);
        if(!run())
            return false;
    }
    return tmp < end;
}

int main(){
    string str;
    while(getline(cin, str), str.size()){
        vec.clear();
        stringstream ss(str);
        int x;
        while(ss >> x)
            vec.push_back(x);
        p = 0;
        cout << (run() ? ":-) Matrioshka!" : ":-( Try again.") << endl;
    }
    return 0;

}
