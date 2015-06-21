#include <list>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class OverLargest{
    public:
        string what(){
            return string("largest overflow");
        }
};

class OverLowest{
    public:
        string what(){
            return string("lowest overflow");
        }
};

template<typename T>
class listX : public list<T>{
    public:
        listX(){
        }
        listX(int sz, T *arr){
            for(int i = 0 ; i < sz ; i++)
                list<T>::push_back(arr[i]);
        }
        listX(int sz, T value){
            for(int i = 0 ; i < sz ; i++)
                list<T>::push_back(value);
        }
        T sum(){
            T re = 0;
            if(std::numeric_limits<T>::is_signed){
                vector<T> tmp(list<T>::begin(), list<T>::end());
                sort(tmp.begin(), tmp.end());
                for(int i = 0 ; i <= int(tmp.size() / 2) ; i++){
                    int x = i, y = tmp.size() - i - 1;
                    T add = tmp[x];
                    if(x != y){
                        add += tmp[y];
                        if(std::numeric_limits<T>::is_iec559){
                            if( tmp[x] && tmp[y] && (add == tmp[x] || add == tmp[y])){
                                T judge = add == tmp[x] ? tmp[x] : tmp[y];
                                if(judge > 0)
                                    throw OverLargest();
                                else
                                    throw OverLowest();
                            }
                        } else {
                            if( add - tmp[y] != tmp[x] ){
                                if(tmp[x] > 0)
                                    throw OverLargest();
                                if(tmp[x] < 0)
                                    throw OverLowest();
                            }
                        }
                    }
                    T sre = re;
                    re += add;
                    if(std::numeric_limits<T>::is_iec559){
                        if( sre && add && (re == sre || re == add)){
                            T judge = re == sre ? sre : add;
                            if(judge > 0)
                                throw OverLargest();
                            else
                                throw OverLowest();
                        }
                    } else {
                        if( re - add != sre ){
                            if(sre > 0){
                                throw OverLargest();
                            }
                            if(sre < 0){
                                throw OverLowest();
                            }
                        }
                    }
                }
            } else {
                for(auto x : (*this)){
                    T sre = re;
                    re += x;
                    if( re - x != sre )
                        throw OverLargest();
                }
            }
            return re;
        }
        friend ostream& operator<<(ostream& ofs, const listX &b){
            for(auto x : b)
                ofs << x << ' ';
            return ofs;
        }
};
