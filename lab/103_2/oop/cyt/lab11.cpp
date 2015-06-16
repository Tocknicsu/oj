#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class student{
    private:
        char *name;
        int height;
    public:
        student() : name(NULL){}
        student(const student &rhs) : name(NULL){
            set_name(rhs.name);
            set_height(rhs.height);   
        }
        ~student(){
            if(name != NULL)
                delete [] name;
        }
        student operator=(const student &rhs){
            set_name(rhs.name);
            set_height(rhs.height);
            return (*this);
        }
        bool operator<(const student &rhs) const {
            return height < rhs.height;
        }
        void set_name(char *_name){
            if(name != NULL)
                delete [] name;
            name = new char[strlen(_name)+1];
            strcpy(name, _name);
        }
        void set_height(int _height){
            height = _height;
        }
        int get_height(){
            return height;
        }
        char* get_name(){
            return name;
        }
};

template<typename T>
void my_sort(vector<T> &vec){
    for(int i = 0 ; i < (int)vec.size() ; i++){
        for(int j = (int)vec.size() - 1 ; j > 0 ; j--)
            if(vec[j] < vec[j-1])
                swap(vec[j], vec[j-1]);
    }
}

int main(){
    vector<int> part_a_int;
    vector<double> part_a_double;
    for(int i = 0 ; i < 10 ; i++)
        part_a_int.push_back(rand()%101);

    my_sort(part_a_int);

    for(auto x : part_a_int)
        cout << x << ' ';
    cout << endl;

    for(int i = 0 ; i < 10 ; i++)
        part_a_double.push_back(double(rand()%101)/(double)10);
    my_sort(part_a_double);
    for(auto x : part_a_double)
        cout << x << ' ';
    cout << endl;


    vector<student> data(10);
    char name[2] = {};
    for(char i = 'A' ; i <= 'J' ; i++){
        name[0] = i;
        data[i-'A'].set_name(name);
    }
    for(int i = 0 ; i < 10 ; i++)
        data[i].set_height(150 + rand()%31);
    for(int i = 0 ; i < (int)data.size() ; i++){
        cout << data[i].get_name() << ' ' << data[i].get_height() << endl;
    }
    cout << "=====sort=====" << endl;
    auto sit = data.begin();
    for(auto it = data.begin() ; it != data.end() ; ++it)
        sit = (*it).get_height() < (*sit).get_height() ? it : sit;
    data.erase(sit);

    my_sort(data);
    for(int i = 0 ; i < (int)data.size() ; i++){
        cout << data[i].get_name() << ' ' << data[i].get_height() << endl;
    }
    

    return 0;
}
