#include <iostream>
using namespace std;
struct A{
	public:
		int a;
	protected:
		int b;
	private:
		int c;
};
struct B : private A{
	void XD(){
		cout << a << b << endl;
	}
};
struct C : B{
};
int main(){
	B *b;;
	C c;
	b = &c;
	b->XD();
}
