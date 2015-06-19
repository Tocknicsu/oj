#include <iostream>
#include <vector>
using namespace std;

class FRUIT{
    private:
        string name;
        int cost;
    public:
        FRUIT(){}
        FRUIT(string _name, int _cost) : name(_name), cost(_cost){}
        string get_name(){
            return name;
        }
        int get_cost(){
            return cost;
        }
};
vector<FRUIT> fruit;
class GUEST{
    private:
        string name;
        int cost;
        vector<string> fruit;
    public:
        GUEST(){}
        GUEST(string _name, int _cost, vector<string> _fruit) : name(_name), cost(_cost), fruit(_fruit){}
        string get_name(){
            return name;
        }
        int get_cost(){
            return cost;
        }
        vector<string> get_fruit(){
            return fruit;
        }
};
vector<GUEST> guest;
int main(){
    freopen("pc.txt", "r", stdin);
    vector<int> COST;
    cout << "part 1:" << endl;
    string name, fruit_name;
    int value, fruit_num, num;
    for(int i = 0 ; i < 5 ; i++){
        cin >> name >> value;
        fruit.push_back(FRUIT(name, value));
    }
    cout << "part 2:" << endl;
    for(int i = 0 ; i < 3 ; i++){
        cin >> name >> num;
        int cost = 0;
        vector<string> tmp;
        for(int j = 0 ; j < num ; j++){
            cin >> fruit_name >> fruit_num;
            tmp.push_back(fruit_name);
            for(auto k : fruit)
                if(k.get_name() == fruit_name)
                    cost += k.get_cost() * fruit_num;
        }
        guest.push_back(GUEST(name, cost, tmp));
        COST.push_back(cost);
    }
    for(int i = 0 ; i < (int)COST.size() ; i++)
        for(int j = (int)COST.size() - i ; j > 0 ; j--)
            if(COST[j-1] < COST[j])
                swap(COST[j-1], COST[j]);
    for(int i = 0 ; i < (int)COST.size() ; i++)
        cout << COST[i] << endl;
    cout << "part 3:" << endl;
    for(vector<GUEST>::iterator it = guest.begin() ; it != guest.end() ; ++it)
        cout << it->get_name() << ' ' << it->get_cost() << endl;
    cout << "part 4:" << endl;
    for(int i = 0 ; i < (int)guest.size() ; i++){
        vector<string> f = guest[i].get_fruit();
        cout << guest[i].get_name() << endl;
        for(int j = 0 ; j < (int)f.size() ; j++)
            cout << f[j] << ' ';
        cout << endl;
    }
}
