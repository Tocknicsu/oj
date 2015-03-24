#include <iostream>
using namespace std;

class PolySeq{
	public:
		PolySeq(int*, int*, int);
		PolySeq();
		PolySeq(int n);
		PolySeq(const PolySeq&);
		PolySeq operator -(PolySeq p);
		PolySeq operator *(PolySeq p);
		int get_num_of_terms();
		int* get_coe();
		int* get_exp();
		int getvalue(int);
	private:
		int coe[128], exp[128];
		int num_of_terms;
};
PolySeq::PolySeq(int *_coe, int *_exp, int _n){
	num_of_terms = _n;
	for(int i = 0 ; i < num_of_terms ; i++){
		coe[i] = _coe[i];
		exp[i] = _exp[i];
	}
}
PolySeq::PolySeq(){
	num_of_terms = 0;
}
PolySeq::PolySeq(int _n){
	num_of_terms = _n;
}
PolySeq::PolySeq(const PolySeq &p){
	num_of_terms = p.num_of_terms;
	for(int i = 0 ; i < p.num_of_terms ; i++){
		coe[i] = p.coe[i];
		exp[i] = p.exp[i];
	}
}
PolySeq PolySeq::operator-(PolySeq p){
	/*
	int a, b;
	int _coe[128], _exp[128], _n = 0;
	a = b = 0;
	while( a != num_of_terms && b != p.num_of_terms ){
		if( exp[a] > p.exp[b] ) {
			_coe[_n] = coe[a];
			_exp[_n] = exp[a];
			_n++;
			a++;
		} else if (exp[a] < p.exp[b]) {
			_coe[_n] = p.coe[b];
			_exp[_n] = p.exp[b];
			_n++;
			b++;
		} else {
			if( coe[a] != p.coe[b] ){
				_coe[_n] = coe[a] - p.coe[b];
				_exp[_n] = exp[a];
				_n++;
			}
			a++, b++;
		}
	}
	while( a != num_of_terms ){
		_coe[_n] = coe[a];
		_exp[_n] = exp[a];
		a++;
		_n++;
	}
	while( b != p.num_of_terms ){
		_coe[_n] = -p.coe[b];
		_exp[_n] = p.exp[b];
		b++;
		_n++;
	}
	return PolySeq(_coe, _exp, _n);
	*/
	int _coe[128] = {0};
	for( int i = 0 ; i < num_of_terms ; i++ )
		_coe[exp[i]] += coe[i];
	for( int i = 0 ; i < p.num_of_terms ; i++ )
		_coe[p.exp[i]] -= p.coe[i];
	int re_coe[128], re_exp[128], re_n = 0;
	for(int i = 127 ; i >= 0 ; i--){
		if( _coe[i] ){
			re_coe[re_n] = _coe[i];
			re_exp[re_n++] = i;
		}
	}
	return PolySeq(re_coe, re_exp, re_n);
}
PolySeq PolySeq::operator*(PolySeq p){
	int _coe[128] = {0};
	for(int i = 0 ; i < num_of_terms ; i++){
		for(int j = 0 ; j < p.num_of_terms ; j++){
			_coe[exp[i]+p.exp[j]] += coe[i] * p.coe[j];
		}
	}
	int re_coe[128], re_exp[128], re_n = 0;
	for(int i = 127 ; i >= 0 ; i--){
		if( _coe[i] ){
			re_coe[re_n] = _coe[i];
			re_exp[re_n++] = i;
		}
	}
	return PolySeq(re_coe, re_exp, re_n);
}
int PolySeq::get_num_of_terms(){
	return num_of_terms;
}
int* PolySeq::get_coe(){
	return coe;
}
int* PolySeq::get_exp(){
	return exp;
}
int PolySeq::getvalue(int x){
	int t = 1, e = 0;
	int re = 0;
	for(int i = num_of_terms - 1 ; i >= 0 ; i--){
		while( e < exp[i] )
			e++, t *= x;
		re += coe[i] * t;
	}
	return re;
}
ostream& operator << (ostream& out, PolySeq p){
	int *coe, *exp, n;
	n = p.get_num_of_terms();
	coe = p.get_coe();
	exp = p.get_exp();
	for(int i = 0 ; i < n ; i++){
		if( i ) out << " + ";
		out << coe[i] << " X^" << exp[i];
	}
	return out;
}

int main(){
	PolySeq p[2];
	for(int i = 0 ; i < 2 ; i++){
		int coi[128], exp[128], n;
		cout << "Enter Num of Terms of Poly" << i+1 << ":" << endl;
		cin >> n;
		cout << "Enter Coefficients of Poly" << i+1 << ":" << endl;
		for( int j = 0 ; j < n ; j++ )
			cin >> coi[j];
		cout << "Enter Exponentials of x in Poly" << i+1 << ":" << "(from high to low)" << endl;
		for( int j = 0 ; j < n ; j++)
			cin >> exp[j];
		p[i] = PolySeq(coi, exp, n);
	}
	int x;
	cout << "Enter the value of x:" << endl;
	cin >> x;
	PolySeq p01 = p[0] - p[1];
	PolySeq p10 = p[1] - p[0];
	PolySeq m10 = p[0] * p[1];
	cout << "P1 - P2: " << p01 << endl;
	cout << "P2 - P1: " << p10 << endl;
	cout << "P1 * P2: " <<  m10 << endl;
	cout << "P1(x1): " << p[0].getvalue(x) << endl;
	cout << "P2(x1): " << p[1].getvalue(x) << endl;
	cout << "(P1-P2)(x1): " << p01.getvalue(x) << endl;
	cout << "(P2-P1)(x2): " << p10.getvalue(x) << endl;
	cout << "(P1*P2)(x1): " << m10.getvalue(x) << endl;
}
