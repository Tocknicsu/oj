#include <iostream>
#include <sstream>
#include <cstdio>
using namespace std;

template <typename T>
class My_vector{
	private:
		T* data;
		int data_size;
		int container_size;
	public:
		My_vector() : data(NULL), data_size(0), container_size(0){}
		~My_vector(){ if(data_size!=0)delete [] data;}
		int size(){return data_size;}
		int c_size(){return container_size;}
		void push_back(T b){
			if(container_size == 0){
				container_size = 1;
				data = new T[container_size];
			}
			if(data_size == container_size){
				T* old = data;
				container_size *= 2;
				data = new T[container_size];
				for(int i = 0 ; i < data_size ; i++)
					data[i] = old[i];
				delete [] old;
			}
			data[data_size++] = b;
		}
		void pop_back(){
			data_size--;
			if(data_size < container_size / 2){
				T* old = data;
				container_size /= 2;
				if(container_size)
					data = new T[container_size];
				for(int i = 0 ; i < data_size ; i++)
					data[i] = old[i];		
				delete [] old;
			}
		}
		T& operator[](int x){
			return data[x];
		}
};
class tag{
	private:
		string id, name;
	public:
		tag(){}
		tag(string _id, string _name) : id(_id), name(_name){}
		bool operator<(const tag &b){
			return name < b.name;
		}
		friend ostream& operator<<(ostream& os, const tag &b){
			os << b.id << " " << b.name;
			return os;
		}
};
template <typename T>
T str2T(string a){
	stringstream ss(a);
	T re;
	ss >> re;
	return re;
}
template <typename T>
void sort(My_vector<T> &b){
	for(int i = 0 ; i < b.size() ; i++)
		for(int j = i ; j > 0 ; j--)
			if(b[j] < b[j-1]){
				T tmp = b[j];
				b[j] = b[j-1];
				b[j-1] = tmp;
			}
}
template <typename T>
void print(My_vector<T> &b){
	for(int i = 0 ; i < b.size() ; i++)
		cout << b[i] << ' ';
	cout << "(" << b.size() << "/" << b.c_size() << ")" << endl;
}
int main(){
	freopen("input.txt", "r", stdin);
	freopen("0316239_output.txt", "w", stdout);
	My_vector<int> iv;
	My_vector<double> dv;
	My_vector<tag> tv;
	string str, str2;

	while(cin >> str, str != string("end"))
		iv.push_back(str2T<int>(str));
	while(cin >> str, str != string("end"))
		dv.push_back(str2T<double>(str));
	while(cin >> str, str != string("end")){
		cin >> str2;
		tv.push_back(tag(str, str2));
	}
	int pop_time = 7;
	sort(iv);
	print(iv);
	while(pop_time--) iv.pop_back();
	cout << "after pop 7 times:";
	print(iv);
	sort(dv);
	print(dv);
	pop_time = 2;
	while(pop_time--) dv.pop_back();
	cout << "after pop 2 times:";
	print(dv);
	sort(tv);
	pop_time = 2;
	print(tv);
	while(pop_time--) tv.pop_back();
	cout << "after pop 2 times:";
	print(tv);
	
	return 0;
}
