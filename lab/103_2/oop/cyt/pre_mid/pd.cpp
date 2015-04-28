#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
class SYS{
	private:
		struct USER{
			string name;
			vector<int> friends;
			USER(){}
			USER(string _name) : name(_name) {}
		};
		vector<USER> user_list;
		map<string, int> user_id;
		int current_user;
	public:
		SYS();
		void run();
		void Register(string);
		void login(string);
		void logout(string);
		void add(string);
		void sent(string, string);
		void show_1();
		void show_2();
		void show_3(string);
		void sort();
};
int main(){
	SYS sys;
	sys.run();
	return 0;
}
SYS::SYS(){
	current_user = -1;
}
void SYS::run(){
	string cmd;
	while(cin >> cmd){
		if(cmd == "/R"){
		} else if(cmd == "/Li") {
		} else if(cmd == "/Lo") {
		} else if(cmd == "/Add") {
		} else if(cmd == "/S") {
		} else if(cmd == "/S1") {
		} else if(cmd == "/S2") {
		} else if(cmd == "/S3") {
		} else if(cmd == "/sort") {
		}
	}
}
void SYS::Register(string name){
	if(user_id.find(name) != user_id.end()){
		user_id[name] = user_list.size();
		user_list.push_back(USER(name));
	}
}
