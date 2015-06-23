#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

class Employee{
	protected:
		vector<int> v[7];
		string name;
		int salary;
		int working_hour;
		int absence;
	public:
		Employee():salary(0),working_hour(0),absence(0){}
		Employee(string _name) : name(_name),salary(0),working_hour(0),absence(0){}
		virtual ~Employee(){}
		friend istream& operator>>(istream& is, Employee &b){
			vector<int> first_week;
			string str;
			while(getline(is, str), str.size() < 2);
			getline(is, str);
			stringstream ss(str);
			int tmp;
			while(ss >> tmp)
				first_week.push_back(tmp);
			for(int i = 0 ; i < (int)first_week.size() ; i++)
				b.v[7-first_week.size()+i].push_back(first_week[i]);

			while(getline(is, str), str.size() > 2){
				stringstream ss(str);
				int x = 0, tmp;
				while(ss >> tmp){
					b.v[x++].push_back(tmp);
				}
			}
				
			return is;
		}
		virtual void show() = 0;
		virtual void pay() = 0;
};
class Part_time : public Employee{
	public:
		Part_time(){}
		Part_time(string _name) : Employee(_name){}
		virtual void show(){
			cout << name << " part-time" << endl;
			cout << "Working hour:" << working_hour << " hours" << endl;
			cout << "Absence:" << absence << " days" << endl;
			cout << "Hourly wage:120" << endl;
			cout << "Salary: NT$" << salary << endl;
			cout << endl;
		}
		virtual void pay(){
			for(int i = 0 ; i < 7 ; i++){
				for(int j = 0 ; j < (int)v[i].size() ; j++){
					if(!v[i][j])
						absence++;
					working_hour += v[i][j];
				}
			}
			salary = 120 * working_hour - absence * 500;
		}
};
class Full_time : public Employee{
	private:
		int over;
	public:
		Full_time():over(0){}
		Full_time(string _name) : Employee(_name), over(0){}
		virtual void show(){
			cout << name << " full-time" << endl;
			cout << "Working hour:" << working_hour << " hours" << endl;
			cout << "Absence:" << absence << " days" << endl;
			cout << "Overtime hours:" << over << " hours" << endl;
			cout << "Daily wage:2000" <<endl;
			cout << "Salary: NT$" << salary << endl;
			cout << endl;
		}
		virtual void pay(){
			for(int i = 0 ; i < 7 ; i++){
				for(int j = 0 ; j < (int)v[i].size() ; j++){
					working_hour += v[i][j];
					if(i == 5 || i == 6){
						salary += min(v[i][j], 4) * 300;
						over += v[i][j];
					} else {
						if(v[i][j] > 8){
							salary += 2200;
							over += v[i][j] - 8;
						} else if(v[i][j] == 8){
							salary += 2000;
						} else if(0 < v[i][j]){
							salary += 1600;
						} else{
							absence++;
						}
					}
				}
			}
		}
};


int main(){
	freopen("workinghours.txt", "r", stdin);
	freopen("salary.txt", "w", stdout);
	string name, type;
	while(cin >> name >> type){
		Employee *obj;
		if(type == string("parttime")){
			obj = new Part_time(name);
		} else {
			obj = new Full_time(name);
		}
		cin >> (*obj);
		obj->pay();
		obj->show();
		delete obj;
	}
	return 0;
}
