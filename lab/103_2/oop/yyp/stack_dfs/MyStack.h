#ifndef MYSTACK_H_INCLUDED
#define MYSTACK_H_INCLUDED
#include <cstddef> // for std:size_t
using namespace std;

template <class T>
class MyStack{
	public:
		MyStack();
		~MyStack();
		void push(T&);
		void pop();
		T& top();
		size_t getSize() const;
		bool empty() const;
	private:
		class Node {
			friend class MyStack<T>;
			public:
			Node(T&, Node*);
			private:
			T &value;   // the value of the node
			Node *next; // a pointer to the next node
		};
		Node *head;  // a pointer to the head of the linked list
		// also a pointer to the top of the stack
		size_t size; // the number of elements in the stack
};
#endif // MYSTACK_H_INCLUDED
