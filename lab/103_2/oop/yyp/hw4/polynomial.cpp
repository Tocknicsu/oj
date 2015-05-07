#include "polynomial.h"
#include <iostream>
using namespace std;
polynomial::polynomial(const int x0){
	if(x0)
		coe.push_back(x0);
}
polynomial::polynomial(const vector<int>& _coe){
	coe = _coe;
}
polynomial::polynomial(const polynomial& _p){
	coe = _p.coe;
}
polynomial& polynomial::operator=(const polynomial& _p){
	coe = _p.coe;
	return (*this);
}
polynomial::~polynomial(){
	coe.clear();
}
polynomial operator-(polynomial p){
	for(int i = 0 ; i < (int)p.coe.size() ; i++)
		p.coe[i] *= -1;
	return p;
}
polynomial operator+(polynomial a, const polynomial& b){
	int sz = max(int(a.coe.size()), int(b.coe.size()));
	polynomial ret;
	ret.coe = vector<int>(sz);
	for(int i = 0 ; i < int(a.coe.size()) ; i++)
		ret.coe[i] += a.coe[i];
	for(int i = 0 ; i < int(b.coe.size()) ; i++)
		ret.coe[i] += b.coe[i];
	while(ret.coe.size() && (ret.coe.back() == 0))
		ret.coe.pop_back();
	return ret;
}
polynomial& operator+=(polynomial& a, const polynomial& b){
	return a = a + b;
}
polynomial operator-(polynomial a, const polynomial& b){
	return a + -b;
}
polynomial& operator-=(polynomial& a, const polynomial& b){
	return a = a - b;
}
polynomial operator*(polynomial a, const polynomial& b){
	polynomial ret;
	ret.coe = vector<int>(a.coe.size()+b.coe.size()-1);
	for(int i = 0 ; i < int(a.coe.size()) ; i++)
		for(int j = 0 ; j < int(b.coe.size()) ; j++)
			ret.coe[i+j] += a.coe[i] * b.coe[j];
	while(ret.coe.size() && (ret.coe.back() == 0))
		ret.coe.pop_back();
	return ret;
}
polynomial& operator*=(polynomial& a, const polynomial& b){
	return a = a * b;
}
double polynomial::operator() (const double x) const {
	double now = 1, ans = 0;
	for(int i = 0 ; i < (int)coe.size() ; i++, now *= x)
		ans += coe[i] * now;
	return ans;
}
bool operator==(const polynomial& a, const polynomial b){
	return a.coe == b.coe;
}
bool operator!=(const polynomial& a, const polynomial b){
	return !(a==b);
}
polynomial::operator bool() const {
	return coe.size() != 0;
}
size_t polynomial::degree() const {
	return coe.size() > 0 ? coe.size()-1 : 0;
}
polynomial polynomial::derivate() const {
	polynomial ret;
	for(int i = 1 ; i < (int)coe.size() ; i++)
		ret.coe.push_back(i * coe[i]);
	return ret;
}
istream& operator>>(istream &in, polynomial &p){
	p.coe.clear();
	while(in.peek() != '\n'){
		int tmp;
		in >> tmp;
		p.coe.push_back(tmp);
	}
	while(p.coe.size() && (p.coe.back() == 0))
		p.coe.pop_back();
	in.ignore();
	return in;
}
ostream& operator<<(ostream &out, const polynomial &p){
	if(p.coe.size()){
		for(int i = 0 ; i < int(p.coe.size()) ; i++)
			out << p.coe[i] << ' ';
	} else {
		out << "0";
	}
	return out;
}
