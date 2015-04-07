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
		
		BIGNUM abs();

		friend istream& operator>>(istream& ifs, BIGNUM &b){
			/* input goes here */
			return ifs;
		}
		friend ostream& operator<<(ostream& ofs, BIGNUM const &b){
			/* output goes here */
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
BIGNUM BIGNUM::abs(){
	BIGNUM re = (*this);
	re.flag = false;
	return re;
}
int main(){
	BIGNUM a, b;
	char c;
	while(cin >> a >> c >> b){
		switch (c){
			/*
			case '+':
				cout << a + b << endl; break;
			case '-':
				cout << a - b << endl; break;
			case '*':
				cout << a * b << endl; break;
			case '/':
				cout << a / b << endl; break;
				*/
			default:
				break;
		}
	}
	return 0;
}
