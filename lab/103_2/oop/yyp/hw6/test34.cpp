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

	cout << "======= stage2 end =======" << endl << endl;
	
	for(int i = 0 ; i < (int)v1.size() ; i++)
		cout << v1[i] << ' ';
	cout << endl;

	stable_vector<int>::iterator it(v1.begin());
	cout << "origin begin: " << *it << endl;
	*it = 12345;
	cout << "after begin: " << *it << " (12345)" << endl;

	it = stable_vector<int>::iterator(v1.end());
	cout << "origin end: " << *it << endl;
	*it = -12345;
	cout << "after end: " << *it << " (-12345)" << endl;
	cout << "If your size doesn't contain end node, you would not see -12345 in next line." << endl;
	for(int i = 0 ; i < (int)v1.size() ; i++)
		cout << v1[i] << ' ';
	cout << endl;

	cout << "======= stage4 end =======" << endl << endl;

	return 0;
}
