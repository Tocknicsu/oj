#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

template<typename T>
class Object{
    private:
        T rate;
        string name;
    public:
        Object();
        Object(T _rate, string _name) : rate(_rate), name(_name){}
        bool operator<(const Object& b) const {
            return rate > b.rate;
        }
        friend ostream& operator<<(ostream& os, const Object<T> &b){
            os << b.rate << ": " << b.name;
            return os;
        }
};
template<typename T>
void func(T obj){
    for(auto x : obj)
        cout << x << endl;
    sort(obj.begin(), obj.end());
    cout << "After Ordering rating:" << endl;
    for(auto x : obj)
        cout << x << endl;
}

int main(){
    vector<Object<int> > obj1;
    vector<Object<double> > obj2;
    freopen("problem.txt", "r", stdin);
    string name, tmp;
    int i_rate;
    double d_rate;
    for(int i = 0 ; i < 4 ; i++){
        while(getline(cin, name), name.size() < 2);
        cin >> i_rate;
        obj1.push_back(Object<int>(i_rate, name));
    }
    for(int i = 0 ; i < 7 ; i++){
        while(getline(cin, name), name.size() < 2);
        cin >> d_rate;
        obj2.push_back(Object<double>(d_rate, name));
    }
    func(obj1);
    func(obj2);
}
