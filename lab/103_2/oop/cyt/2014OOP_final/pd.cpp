#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Account{
    protected:
        string account;
        int id;
    public:
        Account(){}
        virtual ~Account(){}
        Account(string _account, int _id) : account(_account), id(_id){}
        virtual bool login() = 0;
        string get_account(){
            return account;
        }
};

class Standard_user : protected Account{
    public:
        Standard_user(){}
        Standard_user(string _account, int _id) : Account(_account, _id){}
        virtual bool login() override {
            cout << "Sorry, Account<" << id << "><SU>: " << account << " don't have the priviledge to log in !!!" << endl;
            return 0;
        }
};

class Administrator : protected Account{
    public:
        Administrator(){}
        Administrator(string _account, int _id) : Account(_account, _id){}
        virtual bool login() override {
            cout << "Hello Account<" << id << "><AD>: " << account << ", Welcome!!!" << endl;
            return 1;
        }
};
class Server{
    private:
        int login_num;
        vector<Account*> account;
    public:
        Server() : login_num(0){}
        ~Server(){
            for(int i = 0 ; i < (int)account.size() ; i++)
                delete account[i];
        }
        void add(string n, int type){
            if(type == 0){
                account.push_back((Account*) new Administrator(n, account.size()+1));
            } else {
                account.push_back((Account*) new Standard_user(n, account.size()+1));
            }
        }
        void login(string str){
            for(auto x : account){
                if(x->get_account() == str){
                    login_num += x->login();
                    return;
                }
            }
            cout << "Sorry, " << str << " has not registered!!!" << endl;
        }
        int get_login_num(){
            return login_num;
        }
        int get_reg_num(){
            return account.size();
        }
};
int main(){
    Server server;
    cout << "The number of register account: " << server.get_reg_num() << endl;
    cout << "There is no any account." << endl;
    server.add("James", 1);
    server.add("Kobe", 0);
    server.add("Gasol", 0);
    cout << "-----After registratrion-----" << endl;
    cout << "The number of register account: " << server.get_reg_num() << endl;
    server.login("James");
    server.login("FUCK");
    server.login("Kobe");
    server.login("Gasol");
    cout << "The number of log in account: " << server.get_login_num() << endl;
    
    return 0;
}
