#include <iostream>
using namespace std;

struct node{
	node* next;
	int value;
};
node* head;
void insert(int);
void trave();
void delete_ele(int);
void unique();
void slice(int, int);
void delete_all();
int main(){
	head = new node;
	head->next = NULL;
	int ch;
	int l, r, v;
	while(cout << "(1)Insert (2)Traverse (3)Delete (4)Unique (5)Slice (6)Exit:", cin >> ch, ch != 6){
		switch (ch){
			case 1:
				cout << "Enter the value of the new node: ";
				cin >> v;
				insert(v);
				break;
			case 2:
				trave();
				break;
			case 3:
				cout << "Enter the value to be deleted: ";
				cin >> v;
				delete_ele(v);
				break;
			case 4:
				unique();
				break;
			case 5:
				cout << "Enter the range for slicing: ";
				cin >> l >> r;
				slice(l, r);
				break;
			default:
				break;
		}
		cout << endl;
	}
	delete_all();
}
void insert(int value){
	node* p = head;
	while( p->next != NULL && p->next->value < value )
		p = p->next;
	node* q = new node;
	q->value = value;
	q->next = p->next;
	p->next = q;
}
void trave(){
	node* p = head->next;
	while(p != NULL){
		cout << p->value << ' ';
		p = p->next;
	}
	cout << endl;
}
void delete_ele(int value){
	node *p = head;
	while( p->next != NULL && p->next->value != value )
		p = p->next;
	if( p->next != NULL && p->next->value == value){
		node* q = p->next;
		p->next = p->next->next;
		delete q;
		return;
	}
	cout << "Node with value " << value << " is not found" << endl;
}
void unique(){
	node *p = head->next;
	while( p != NULL ){
		if( p->next != NULL && p->value == p->next->value){
			node *q = p->next;
			p->next = p->next->next;
			delete q;
		} else {
			p = p->next;
		}
	}
}
void slice(int l, int r){
	node *p = head;
	while( p->next != NULL &&  p->next->value < l ){
		node *q = p->next;
		p->next = p->next->next;
		delete q;
	}
	while( p->next != NULL && p->next->value <= r){
		p = p->next;
	}
	while( p->next != NULL ){
		node *q = p->next;
		p->next = p->next->next;
		delete q;
	}
}
void delete_all(){
	node *p = head;
	while( p != NULL ){
		node *q = p;
		p = p->next;
		delete q;
	}
}
