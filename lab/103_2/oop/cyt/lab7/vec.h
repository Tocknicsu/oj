#include<iostream>
using namespace std;
class vec
{
    private:
        int* data; // store data
        int size; // data length
    public:
    	~vec(){delete [] data;}
        int get_size(){return size;}
		int get_data(int index){ if(index<size && index>=0)return data[index]; }
		
		// implement following function
		vec(); // default constructor
        vec(int n); // constructor with container size n
        vec(vec& b); // copy constructor
        vec(int n,int* initial); // [optional]
        void print(); // [optional]
        void set(int index,int n); // Set n into data array[index] , please make sure you won't cause buffer overflow
        void operator=(vec& b); // [optional]
};

vec::vec(){
	size = 0;
}

vec::vec(int n){
	size = n;
	data = new int[n];
}

vec::vec(vec& b){
	size = b.size;
	data = new int[size];
	for(int i = 0 ; i < size ; i++)
		data[i] = b.data[i];
}

vec::vec(int n, int* initial){
	size = n;
	data = new int[size];
	for(int i = 0 ; i < size ; i++)
		data[i] = initial[i];
}

void vec::print(){
	for(int i = 0 ; i < size ; i++)
		cout << data[i] << ' ';
	cout << endl;
}

void vec::set(int index, int n){
	data[index] = n;
}

void vec::operator=(vec& b){
	delete [] data;
	data = new int[b.size];
	size = b.size;
	for(int i = 0 ; i < size ; i++)
		data[i] = b.data[i];
}
