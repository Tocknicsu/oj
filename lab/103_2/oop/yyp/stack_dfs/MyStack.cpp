#include <iostream>
#include "MyStack.h"
#include <cstddef> // for std:size_t
using namespace std;

	template <class T>
MyStack<T>::Node::Node(T& A, Node* n):value(A),next(n)
{
}
	template <class T>
MyStack<T>::MyStack()
{
	size=0;
	head=NULL;
}

	template <class T>
MyStack<T>::~MyStack()
{

}

	template <class T>
void MyStack<T>::push(T& a)
{
	++size;
	Node* ptr=head;
	while(!ptr)	ptr=ptr->next;
	ptr = new Node(a,NULL);
	ptr->next=NULL;
}

	template <class T>
void MyStack<T>::pop()
{
	--size;
	Node* ptr=head;
	head=head->next;
	delete ptr;
}

	template <class T>
T& MyStack<T>::top()
{
	return head->value;
}

template <class T>
size_t MyStack<T>::getSize() const
{	
	return size;
}

template <class T>
bool MyStack<T>::empty() const
{
	if(size==0) return true;
	return false;
}


template class MyStack <char>;
int main(){
}
