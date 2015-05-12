#include<iostream>
#include"vec.h"
using namespace std;
///
///Stack & Queue must inherit protected vec
///

class Queue : protected vec{
	private:
		int front, rear;
	public:
		Queue() : front(0), rear(0) {}
		Queue(int _n) : vec(_n), front(0), rear(0){}
		void Push(int x){
			int sz = get_size();
			if(rear >= front + sz){
				cout << "Full" << endl;
				return;
			}
			set(rear%sz, x);
			rear++;
		}
		int Front(){
			int sz = get_size();
			return get_data(front%sz);
		}
		void Pop(){
			front++;
		}
		bool isEmpty(){
			if(front >= rear){
				cout << endl << "Empty" << endl;
				return true;
			}
			return false;
		}
};

class Stack : protected vec{
	private:
		int top;
	public:
		Stack() : top(0) {}
		Stack(int _n) : vec(_n), top(0) {}
		void Push(int x){
			if(top >= get_size()){
				cout << "Full" << endl;
				return;
			}
			set(top++, x);
		}
		int Top(){
			//if(top)
				return get_data(top-1);
		}
		void Pop(){
			top--;
		}
		bool isEmpty(){
			if(!top){
				cout << endl << "Empty" << endl;
				return true;
			}
			return false;
		}
};
int main()
{
	cout<<"Test Stack"<<endl;
	Stack s(5);
	// Push 0~5 into Stack s
	for(int i=0;i<6;i++)
		s.Push(i);
	// Print Stack s
	while(!s.isEmpty()){
		cout<<s.Top()<<" ";
		s.Pop();
	}
	cout<<endl;
	s.Pop();
	cout<<endl;
	cout<<"Test Queue"<<endl;
	Queue test(10); 
	// Push 1~3 into Queue test
	for (int i = 1; i < 4; i++)test.Push(i);
	Queue test1(test); // content of test1 are 1~3 by copy constructor
	// Push 4~11 into Queue test1
	for (int i = 4; i <= 11; i++)test1.Push(i);
	test1.Pop(); test1.Pop(); test1.Push(11);
	// Print Queue test1
	while(!test1.isEmpty()){
		cout<<test1.Front()<<" ";
		test1.Pop();
	}
	cout<<endl;
	test1.Pop();

    system("pause");
    return 0;
}
