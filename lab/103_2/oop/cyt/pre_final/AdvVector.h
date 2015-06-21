#include <vector>
#include <iostream>
using namespace std;

template<typename T>
class AdvVector : public vector<T> {
    public:
        AdvVector(){
        }
        AdvVector(int size, const T* arr){
            for(int i = 0 ; i < size ; i++)
                vector<T>::push_back(arr[i]);
        }
        AdvVector(int size, T value = T()){
            for(int i = 0 ; i < size ; i++)
                vector<T>::push_back(value);
        }
        ostream& operator<<(ostream& ofs) const {
//            for(auto x : )
//                ofs << "(" << x <<")"<< ' ';
            return ofs;
        }
};

template<typename T>
class AdvVectorI : public virtual AdvVector<T> {
    public:
        AdvVectorI(){}
        AdvVectorI(int size, T value = T()) : AdvVector<T>(size, value){}
        AdvVectorI(int size, const T* arr) : AdvVector<T>(size, arr) {}
        /*
        ostream& operator<<(ostream& ofs){
            for(auto x : (*this))
                ofs << "(" << x <<")"<< ' ';
            return ofs;
        }
        */
};

template<typename T>
class AdvVectorO : public virtual AdvVector<T> {
    public:
        AdvVectorO(){}
        AdvVectorO(int size, T value = T()) : AdvVector<T>(size, value){}
        AdvVectorO(int size, const T* arr) : AdvVector<T>(size, arr) {}
};
template<typename T>
class AdvVectorIO : public AdvVectorI<T>, public AdvVectorO<T> {
    public:
        AdvVectorIO(int size, T value = T()) : AdvVector<T>(size, value) {}
        AdvVectorIO(int size, const T* arr) : AdvVector<T>(size, arr) {}
        AdvVectorIO(const AdvVectorI<T>& b){
            for(auto x : b)
                vector<T>::push_back(x);
        }
        AdvVectorIO(const AdvVectorO<T>& b){
            for(auto x : b)
                vector<T>::push_back(x);
        }
};
