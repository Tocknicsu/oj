#include "listX.h"
#include <iostream>
#include <numeric>
#include <limits>
#include <cstdlib>
using namespace std;

/* 
   Finish this function template, SumVector.
   SumVector calls listX::sum() and catch two exceptions thrown by listX::sum(), OverLargest and OverLowest.
*/
template <class T>
void SumVector(listX<T>& v){
    try{
        cout << v.sum() << endl;
    } catch (OverLargest e){
        cout << e.what() << endl;
    } catch (OverLowest e){
        cout << e.what() << endl;
    }

}

// DO NOT change main().
int main(){
    
    cout <<  "--- unsigned long long test ---" << endl;
    unsigned long long LL[5] ={ 0, 7, numeric_limits<unsigned long long>::max() - 3, 1, 3};
    listX<unsigned long long> vll1(5, LL), vll2(5, 6), vll3 = vll1;
    
    cout << "vll1 = " << vll1 << endl;
    cout << "vll2 = " << vll2 << endl;
    cout << "vll3 = " << vll3 << endl;
    
   
    SumVector(vll3);
    
    cout << "ACC:" << accumulate(vll3.begin(), vll3.end(), 0) << endl;
    
    *(++++++vll3.begin()) >>= 2;
    cout << "vll3 = " << vll3 << endl;
    SumVector(vll3);
    
    
    cout <<  "--- integer test ---" << endl;
    int A[7] = {0, -10, 0, numeric_limits<int>::min() + 3, 6, 7,  numeric_limits<int>::max() - 3};
    //int A[6] = {123, -10, 0, 6, 7, -3};
    listX<int> vi1, vi2(5, 6), vi3(7, A), vi4 = vi3;
    
    cout << "vi1 = " << vi1 << endl;
    cout << "vi2 = " << vi2 << endl;
    cout << "vi3 = " << vi3 << endl;
    cout << "vi4 = " << vi4 << endl;
    
    SumVector(vi3);
    cout << "ACC:" << accumulate(vi3.begin(), vi3.end(), 0) << endl;
    
    *vi4.begin() =  *(++vi4.begin()) = 0;
    cout << "vi4 = " << vi4 << endl;
    SumVector(vi4);
    
    vi4 = vi3;
    
    listX<int>::iterator itr = vi4.begin();
    for(int i=0; i<4; ++i, ++itr);
    *itr = 0;
    *(++itr) = 0;
    *(++itr) = 0;
    cout << "vi4 = " << vi4 << endl;
    SumVector(vi4);
    
    itr = vi4.begin();

    *itr = numeric_limits<int>::min();
    *(++itr) = numeric_limits<int>::min();
    *(++itr) = numeric_limits<int>::min();
    ++itr;
    *(++itr) = numeric_limits<int>::max();
    *(++itr) = numeric_limits<int>::max();
    *(++itr) = numeric_limits<int>::max();
    
    cout << "vi4 = " << vi4 << endl;
    SumVector(vi4);
    cout << "ACC:" << accumulate(vi4.begin(), vi4.end(), 0) << endl;
    
    itr = vi4.begin();
    *(++itr) = 100;//numeric_limits<int>::min() + 20;
    int x = numeric_limits<int>::min() / 2 - 5;
    *(++itr) = x;
    *(++itr) = x;
    cout << "vi4 = " << vi4 << endl;
    SumVector(vi4);
    cout << "ACC:" << accumulate(vi4.begin(), vi4.end(), 0) << endl;

    cout <<  "--- float test ---" << endl;
    float F[5] ={ 1.73f, numeric_limits<float>::max() - 0.5f, 0.0f, -1.0f, -numeric_limits<float>::max() + 0.5f};
    float F2[5] ={ -numeric_limits<float>::max(), -numeric_limits<float>::max(), 0.0f, 0.0f, numeric_limits<float>::max()};
    listX<float> vf1(5, F), vf2 = vf1, vf3(5, F2);
    
    cout << "vf1 = " << vf1 << endl;
    cout << "vf2 = " << vf2 << endl;
    cout << "vf3 = " << vf3 << endl;
    
    SumVector(vf2);
    cout << "ACC:" << accumulate(vf2.begin(), vf2.end(), 0.0f) << endl;
    SumVector(vf3);
    cout << "ACC:" << accumulate(vf3.begin(), vf3.end(), 0.0f) << endl;
    
    *(++vf2.begin()) = 0.0f;
    cout << "vf2 = " << vf2 << endl;
    SumVector(vf2);
    
    vf2 = vf1;
    *(--vf2.end()) = 0.0f;
    cout << "vf2 = " << vf2 << endl;
    SumVector(vf2);
    

    
    cout <<  "--- double test ---" << endl;
    double D[5] ={ 1.56, numeric_limits<double>::max() - 0.5, 0.0, -1.0, -numeric_limits<double>::max() + 0.5};
    listX<double> vd1(5, D), vd2 = vd1;
    
    cout << "vd1 = " << vd1 << endl;
    cout << "vd2 = " << vd2 << endl;
    
    SumVector(vd2);
    
    
    *(++vd2.begin()) = 0.0f;
    cout << "vd2 = " << vd2 << endl;
    SumVector(vd2);
    
    
    vd2 = vd1;
    *(--vd2.end()) = 0.0f;
    cout << "vd2 = " << vd2 << endl;
    SumVector(vd2);
   
}

