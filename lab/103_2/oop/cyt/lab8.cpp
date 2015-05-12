#include <iostream>
#include <string>
using namespace std;
class Device {
	private:
		int mount_ID;
		string mount_NAME;
	public:
		virtual void print(){}
		int get_ID(){ return mount_ID; }
		string get_NAME(){ return mount_NAME; }
		void set_ID(int _id){ mount_ID = _id; }
		void set_NAME(string _NAME){ mount_NAME = _NAME; }
};
class CD_ROM : Device {
	public:
		virtual void print(){
			cout << "Device<" << get_ID() << ">: <CD>" << get_NAME() << endl;
		}
};
class HardDisk : Device {
	public:
		virtual void print(){
			cout << "Device<" << get_ID() << ">: <HD>" << get_NAME() << endl;
		}
};
class Host{
	
};
int main(){
}
