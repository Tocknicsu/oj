#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
class COURSE{
	private:
		string name;
		vector<int> time;
	friend class SYSTEM;
};
class USER{
	private:
		string name;
		vector<int> course;
	public:
		USER();
		void init();
	friend class SYSTEM;
};
class SYSTEM{
	private:
		vector<USER> user_list;
		vector<COURSE> course_list;
		int current_user;
	public:
		SYSTEM();
		bool is_login();
		void add();
		void login();
		void choose_course();
		void show_course();
		void logout();
};
int main(){
	SYSTEM sys;
	int ch;
	while(cout << (!sys.is_login()?"0) New user 1) Login":"2) Choose course 3) Print course 4) Logout") << ": ", cin >> ch){
		switch (ch){
			case 0:
				sys.add(); break;
			case 1:
				sys.login(); break;
			case 2:
				sys.choose_course(); break;
			case 3:
				sys.show_course(); break;
			case 4:
				sys.logout(); break;
			default:
				break;
		}
	}
	return 0;
}
USER::USER(){
	init();
}
void USER::init(){
	name = string("");
}
SYSTEM::SYSTEM(){
	current_user = -1;
	course_list = vector<COURSE>(6);
	course_list[0].name = "CO";
	course_list[0].time.push_back(0);
	course_list[0].time.push_back(1);
	course_list[0].time.push_back(2);
	course_list[1].name = "NP";
	course_list[1].time.push_back(2);
	course_list[1].time.push_back(3);
	course_list[1].time.push_back(4);
	course_list[2].name = "DS";
	course_list[2].time.push_back(18);
	course_list[2].time.push_back(19);
	course_list[2].time.push_back(20);
	course_list[3].name = "PL";
	course_list[3].time.push_back(20);
	course_list[3].time.push_back(21);
	course_list[3].time.push_back(22);
	course_list[4].name = "LA";
	course_list[4].time.push_back(36);
	course_list[4].time.push_back(37);
	course_list[4].time.push_back(38);
	course_list[5].name = "OS";
	course_list[5].time.push_back(37);
	course_list[5].time.push_back(38);
	course_list[5].time.push_back(39);
}
bool SYSTEM::is_login(){
	return current_user != -1;
}
void SYSTEM::add(){
	string name;
	cin >> name;
	for(int i = 0 ; i < user_list.size() ; i++){
		if(name == user_list[i].name){
			cout << "This user has been registered!" << endl;
			return;
		}
	}
	USER user;
	user.name = name;
	user_list.push_back(user);
	cout << "User " << user.name << " has been created!" << endl;
}
void SYSTEM::login(){
	if( current_user != -1){
		cout << "Allow one user at the same time!" << endl;
		return;
	}
	string name;
	cin >> name;
	for(int i = 0 ; i < user_list.size() ; i++){
		if(user_list[i].name == name){
			current_user = i;
			cout << "Welcome! " << user_list[current_user].name << endl;
			return;
		}
	}
	cout << "Not register yet!" << endl;
}
void SYSTEM::choose_course(){
	string course_name;
	while(cout << "Enter course name: ", cin >> course_name, course_name != "END"){
		for(int i = 0 ; i < course_list.size() ; i++){
			if(course_name == course_list[i].name){
				bool coll = false;
				for(int j = 0 ; j < user_list[current_user].course.size() ; j++){
					vector<int> tmp1 = course_list[i].time;
					vector<int> tmp2 = course_list[user_list[current_user].course[j]].time;
					for(int x = 0 ; x < tmp1.size() ; x++){
						for(int y = 0 ; y < tmp2.size() ; y++){
							if(tmp1[x] == tmp2[y])
								coll = true;
						}
					}
				}
				if(coll){
					cout << "Course " << course_name << " overlap!" << endl;
				} else {
					cout << course_name << " choosed!" << endl;
					user_list[current_user].course.push_back(i);
				}
			}
		}
	}
}
void SYSTEM::show_course(){
	string week[] = {"MON", "TUE", "WED", "THU", "FRI"};
	for(int i = 0 ; i < user_list[current_user].course.size() ; i++){
		int course_id = user_list[current_user].course[i];
		cout << course_list[course_id].name << ' ' << week[course_list[course_id].time[0]/8] << ' ';
		for(int j = 0 ; j < course_list[course_id].time.size() ; j++){
			cout << course_list[course_id].time[j] % 8 + 1;
		}
		cout << endl;
	}
}
void SYSTEM::logout(){
	current_user = -1;
	cout << "Logout!" << endl;
}
