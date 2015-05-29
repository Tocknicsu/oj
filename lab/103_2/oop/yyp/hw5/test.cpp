#include <iostream>
using namespace std;

struct A{
	int a;
	void call();
};
struct B : A{
	B() : a(4) {}
	public:
	   	int a;
	public:
		void print(){
			cout << a << endl;
		}
};
void A::call(){
	B b;
	b.a = 4;

}
//A b.a
int main(){
	B b;
	A* a = &b;
	a->a = 3;
	b.print();
}
