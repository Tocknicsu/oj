#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_SIZE 1024
class BIGNUM{
	private:
		bool flag;
		int v[MAX_SIZE];
	public:
		BIGNUM();
		BIGNUM(string);

		void init();
		
		BIGNUM abs() const ;

		BIGNUM add(BIGNUM const &a, BIGNUM const &b) const;
		BIGNUM minus(BIGNUM const &a, BIGNUM const &b) const;

		BIGNUM operator=(BIGNUM const &);

		BIGNUM operator+(BIGNUM const &) const;
		BIGNUM operator-(BIGNUM const &) const;
		BIGNUM operator*(BIGNUM const &) const;
		BIGNUM operator/(BIGNUM const &) const;
		BIGNUM operator/(int const &) const;
		
		BIGNUM operator>>(const int) const;
		BIGNUM operator<<(const int) const;


		bool operator<(BIGNUM const &) const;
		bool operator>(BIGNUM const &) const;
		bool operator>=(BIGNUM const &) const;
		bool operator<=(BIGNUM const &) const;
		bool operator==(BIGNUM const &) const;
		bool operator!=(BIGNUM const &) const;

		void format();

		friend istream& operator>>(istream& ifs, BIGNUM &b){
			string str;
			ifs >> str;
			if(str[0] == '(')
				str = str.substr(1, str.size()-2);
			b = BIGNUM(str);
			return ifs;
		}
		friend ostream& operator<<(ostream& ofs, BIGNUM const &b){
			if( b == BIGNUM("0") ){
				ofs << "0";
				return ofs;
			}
			if(b.flag) ofs << "-";
			bool first = false;
			for(int i = MAX_SIZE - 1 ; i >= 0 ; i--){
				if(first){
					ofs << b.v[i];
				} else {
					if(b.v[i]){
						first = true;
						ofs << b.v[i];
					}
				}
			}
			return ofs;
		}
};
BIGNUM::BIGNUM(){
	init();
}
BIGNUM::BIGNUM(string str){
	init();
	flag = str[0] == '-';
	int p = 0;
	for(int i = str.size() - 1 ; i >= flag ; i--)
		v[p++] = str[i] - '0';
}
void BIGNUM::init(){
	flag = 0;
	fill(v, v+MAX_SIZE, 0);
}
BIGNUM BIGNUM::abs() const {
	BIGNUM re = (*this);
	re.flag = false;
	return re;
}
BIGNUM BIGNUM::add(BIGNUM const &a, BIGNUM const &b) const {
	BIGNUM re;
	for(int i = 0 ; i < MAX_SIZE ; i++)
		re.v[i] = a.v[i] + b.v[i];
	re.format();
	return re;
}

BIGNUM BIGNUM::minus(BIGNUM const &a, BIGNUM const &b) const {
	BIGNUM re;
	for(int i = 0 ; i < MAX_SIZE ; i++)
		re.v[i] = a.v[i] - b.v[i];
	re.format();
	return re;
}
BIGNUM BIGNUM::operator=(BIGNUM const &b){
	flag = b.flag;
	for(int i = 0 ; i < MAX_SIZE ; i++)
		v[i] = b.v[i];
	return (*this);
}
BIGNUM BIGNUM::operator+(BIGNUM const &b) const {
	BIGNUM b1 = (*this).abs();
	BIGNUM b2 = b.abs();
	BIGNUM re;
	if( (*this).flag ^ b.flag ){
		if( b1 > b2 ){
			re = minus(b1, b2);
			re.flag = (*this).flag;
		} else {
			re = minus(b2, b1);
			re.flag = b.flag;
		}
	} else {
		re = add(b1, b2);
		re.flag = (*this).flag;
	}
	return re;
}
BIGNUM BIGNUM::operator-(BIGNUM const &b) const {
	BIGNUM b1 = b;
	b1.flag ^= 1;
	return (*this) + b1;
}
BIGNUM BIGNUM::operator*(BIGNUM const &b) const {
	BIGNUM re;
	re.flag = flag ^ b.flag;
	for(int i = 0 ; i < MAX_SIZE ; i++){
		for(int j = 0 ; i + j < MAX_SIZE ; j++)
			re.v[i+j] += v[i] * b.v[j];
	}
	re.format();
	return re;
}
BIGNUM BIGNUM::operator/(BIGNUM const &b) const {
	BIGNUM re, step = (*this);
	if( b == BIGNUM("0") ){
		cout << "Segment fault" << endl;
		exit(0);
	}
	while( step != BIGNUM("0") ){
		if( (re + step) * b <= (*this) ){
			re = re + step;
		} else {
			step = step / 2;
		}
	}
	re.flag = flag ^ b.flag;
	return re;
}
BIGNUM BIGNUM::operator/(int const &b) const {
	BIGNUM re;
	int x = 0;
	for(int i = MAX_SIZE - 1 ; i >= 0 ; i--){
		x = x * 10 + v[i];
		re.v[i] = x / b;
		x %= b;
	}
	return re;
}
bool BIGNUM::operator<(BIGNUM const &b) const {
	for(int i = MAX_SIZE - 1 ; i >= 0 ; i--){
		if(v[i] > b.v[i]) return false;
		else if(v[i] < b.v[i]) return true;
	}
	return false;
}
bool BIGNUM::operator>(BIGNUM const &b) const {
	return b < (*this);
}
bool BIGNUM::operator<=(BIGNUM const &b) const {
	return !((*this) > b);
}
bool BIGNUM::operator>=(BIGNUM const &b) const {
	return !((*this) < b);
}
bool BIGNUM::operator==(BIGNUM const &b) const {
	return !((*this) != b);
}
bool BIGNUM::operator!=(BIGNUM const &b) const {
	return (*this) > b || (*this) < b;
}
void BIGNUM::format(){
	for(int i = 0 ; i < MAX_SIZE ; i++){
		if(v[i]/10){
			v[i+1] += v[i] / 10;
			v[i] %= 10;
		}
		if(v[i] < 0){
			v[i] += 10;
			v[i+1] -= 1;
		}
	}
}
int main(){
	BIGNUM a, b;
	char c;
	while(cin >> a >> c >> b){
		switch (c){
			case '+':
				cout << a + b << endl; break;
			case '-':
				cout << a - b << endl; break;
			case '*':
				cout << a * b << endl; break;
			case '/':
				cout << a / b << endl; break;
			default:
				break;
		}
	}
	return 0;
}
