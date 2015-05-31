#include <cassert>
#include <algorithm>
#include <iostream>
#include <string>

#include "stable_vector.hpp"
using namespace std;
int main() {

	stable_vector<int> v1;

	for(int i = 0 ; i < (int)v1.size() ; i++)
		cout << v1[i] << ' ';
	cout << endl;

	cout << "origin front: " <<  v1.front() << endl;
	v1.front() = 1029384756;
	cout << "after: " << v1.front() << " (1029384756)" << endl;

	cout << "origin back: " <<  v1.back() << endl;
	v1.back() = -1029384756;
	cout << "after: " << v1.back() << " (-1029384756)" << endl;

	
	for(int i = 0 ; i < (int)v1.size() ; i++)
		cout << v1[i] << ' ';
	cout << endl;


    return 0;
}
