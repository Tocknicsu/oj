#include <iostream>
using namespace std;
const int MAX = 8;
class MATRIX{
	private:
		int r, c;
		int v[MAX][MAX];
	public:
		MATRIX();
		MATRIX(const MATRIX&);
		MATRIX(const int, const int);
		void set_value(const int*);
		void print();

		MATRIX operator+(const MATRIX&) const;
		MATRIX operator-(const MATRIX&) const;
		MATRIX operator*(const MATRIX&) const;

		MATRIX Transpose() const;
};
MATRIX::MATRIX(){
	r = c = 0;
	for(int i = 0 ; i < MAX ; i++)
		for(int j = 0 ; j < MAX ; j++)
			v[i][j] = 0;
}
MATRIX::MATRIX(const MATRIX &b){
	r = b.r, c = b.c;
	for(int i = 0 ; i < r ; i++)
		for(int j = 0 ; j < c ; j++)
			v[i][j] = b.v[i][j];
}
MATRIX::MATRIX(const int _r, const int _c){
	r = _r, c = _c;
	for(int i = 0 ; i < MAX ; i++)
		for(int j = 0 ; j < MAX ; j++)
			v[i][j] = 0;
}
void MATRIX::set_value(const int* _v){
	for(int i = 0 ; i < r ; i++)
		for(int j = 0 ; j < c ; j++)
			v[i][j] = _v[i*c+j];
}
void MATRIX::print(){
	for(int i = 0 ; i < r ; i++){
		for(int j = 0 ; j < c ; j++)
			cout << v[i][j] << ' ';
		cout << endl;
	}
}
MATRIX MATRIX::operator+(const MATRIX& b) const {
	if(r != b.r || c != b.c){
		cout << "*warning" << endl;
		return MATRIX(0, 0);
	}
	MATRIX re(r, c);
	for(int i = 0 ; i < r ; i++)
		for(int j = 0 ; j < c ; j++)
			re.v[i][j] = v[i][j] + b.v[i][j];
	return re;
}
MATRIX MATRIX::operator-(const MATRIX& b) const {
	if(r != b.r || c != b.c){
		cout << "*warning" << endl;
		return MATRIX(0, 0);
	}
	MATRIX re(r, c);
	for(int i = 0 ; i < r ; i++)
		for(int j = 0 ; j < c ; j++)
			re.v[i][j] = v[i][j] - b.v[i][j];
	return re;
}
MATRIX MATRIX::operator*(const MATRIX& b) const {
	if(c != b.r){
		cout << "*warning" << endl;
		return MATRIX(0, 0);
	}
	MATRIX re(r, b.c);
	for(int i = 0 ; i < r ; i++)
		for(int j = 0 ; j < b.c ; j++)
			for(int k = 0 ; k < b.r ; k++)
				re.v[i][j] += v[i][k] * b.v[k][j];
	return re;
}
MATRIX MATRIX::Transpose() const {
	MATRIX re(c, r);
	for(int i = 0 ; i < c ; i++)
		for(int j = 0 ; j < r ; j++)
			re.v[i][j] = v[j][i];
	return re;
}
void print_line(){
	for(int i = 0 ; i < 25 ; i++)
		cout << "-";
	cout << endl;
}
int main(){
	freopen("pc.in", "r", stdin);
	MATRIX m[5];
	int v[MAX * MAX];
	for(int i = 0 ; i < 4 ; i++){
		int r, c;
		cin >> r >> c;
		m[i] = MATRIX(r, c);
		for(int i = 0 ; i < r * c ; i++)
			cin >> v[i];
		m[i].set_value(v);
	}
	(m[0]+m[1]).print();
	print_line();
	(m[0]-m[1]).print();
	print_line();
	(m[0]*m[1].Transpose()).print();
	print_line();
	(m[2]+m[3]).print();
	print_line();
	(m[2]-m[3]).print();
	print_line();
	(m[2]*m[3]).print();
	print_line();
}
