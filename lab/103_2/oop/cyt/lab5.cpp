#include <iostream>
#include <cstring>
using namespace std;
class USER{
	private:
		int sum;
		char name[16];
		char code[7];
	public:
		USER();
		void set_name(char[]);
		void set_code(char[]);
		char* get_name();
		void print_name();
		void print_code();
		void print_sum();
		void calc_sum();
		bool operator>(const USER&);
		void operator+=(const USER&);
};
USER::USER(){
}
void USER::set_name(char _name[]){
	strcpy(name, _name);
}
void USER::set_code(char _code[]){
	strcpy(code, _code);
}
char* USER::get_name(){
	return name;
}
void USER::print_name(){
	cout << "User_Name: " << name << endl;
}
void USER::print_code(){
	cout << "Zip_Code: " << code << endl;
}
void USER::print_sum(){
	cout << "Sum: " << sum << endl;
}
void USER::calc_sum(){
	sum = 0;
	for(int i = 0 ; i < 5 ; i++){
		int p = i + (i > 2);
		sum += code[p] - '0';
	}
}
void USER::operator+=(const USER &b){
	for(int i = 0 ; i < 5 ; i++){
		int p = i + (i > 2);
		code[p] = (code[p] - '0' + b.code[p] - '0') % 10 + '0';
	}
}
bool USER::operator>(const USER &b){
	return sum > b.sum;
}
USER user[128];
int num = 0;
void create_user(){
	char _name[16];
	cin >> _name;
	user[num].set_name(_name);
	user[num].print_name();
	cout << "User Created" << endl;
	num++;
}
void set_code(){
	char _name[16];
	char _code[7];
	int p = -1;
	cin >> _name;
	for(int i = 0 ; i < num ; i++){
		if( !strcmp(_name, user[i].get_name()) ){
			p = i;
		}
	}
	if( p == -1 ){
		cout << "There's no that user!" << endl;
		return;
	}
	cin >> _code;
	user[p].set_code(_code);
	user[p].print_name();
	user[p].print_code();
}
void add(){
	char _name[2][16];
	int p[2] = {-1, -1};
	for(int i = 0 ; i < 2 ; i++){
		cin >> _name[i];
		for(int j = 0 ; j < num ; j++){
			if( !strcmp(_name[i], user[j].get_name()) ){
				p[i] = j;
			}
		}
	}
	if(p[0] == -1 || p[1] == -1){
		cout << "Can't find user." << endl;
	}
	user[p[0]] += user[p[1]];
	user[p[0]].print_name();
	user[p[0]].print_code();
	user[p[1]].print_name();
	user[p[1]].print_code();
}
void sort_all(){
	for(int i = 0 ; i < num ; i++){
		user[i].calc_sum();
		user[i].print_name();
		user[i].print_sum();
	}
	for(int i = 0 ; i < num ; i++){
		for(int j = num ; j > i ; j--){
			if(user[j] > user[j-1]){
				USER tmp;
				tmp = user[j];
				user[j-1] = user[j];
				user[j] = tmp;
			}
		}
	}
	for(int i = 0 ; i < num ; i++){
		if(i) cout << " > ";
		cout << user[i].get_name();
	}
}
int main(){
	int ch;
	while(cin >> ch, ch != 4){
		if(ch == 0){
			create_user();
		} else if (ch == 1){
			set_code();
		} else if (ch == 2){
			add();
		} else if (ch == 3){
			sort_all();
		}
	}
}
