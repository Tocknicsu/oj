#include <iostream>
#include <string>
using namespace std;

class Register{
    private:
        string name, id;
    public:
        Register(){
        }
        Register(string _name, string _id) : name(_name), id(_id) {}
        bool verify_ID(){
            if(id.size() != 10) return false;
            if(!isalpha(id[0])) return false;
            int tmp = 0;
            for(int i = 1 ; i < 10 ; i++){
                if(!isdigit(id[i]))
                    return false;
                tmp += id[i] - '0';
            }
            if(tmp % 10) return false;
            return true;
        }
        const string get_name() const {
            return name;
        }
        const string get_id() const {
            return id;
        }
};

class StudentID : public Register{
    private:
        string student_id;
    public:
        StudentID(){}
        StudentID(string _name, string _id) : Register(_name, _id){
            if(Register::verify_ID()){
                student_id = string("103") + _id.substr(1, 2) + _id.substr(8, 2);
            }
        }
        friend ostream& operator<<(ostream& os, const StudentID &b){
            os << "Name:" << b.get_name() << endl;
            os << "ID number:" << b.get_name();
            if(!b.student_id.size()){
               cout << "(Wrong ID number!!!)" << endl;
            } else {
               cout << endl;
               cout << "Student ID:" << b.student_id << endl;
            }
            return os;
        }
};

int main(){
    freopen("test.txt", "r", stdin);
    freopen("ans.txt", "w", stdout);
    string name, id;
    while(cin >> name >> id)
        cout << StudentID(name, id);
}
