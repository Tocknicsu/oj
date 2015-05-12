#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Device {
	private:
		int mount_ID;
		string mount_NAME;
	public:
		Device(){}
		Device(int _id, string _name) : mount_ID(_id), mount_NAME(_name) {}
		virtual void show() = 0;
		int get_ID(){ return mount_ID; }
		string get_NAME(){ return mount_NAME; }
		void set_ID(int _id){ mount_ID = _id; }
		void set_NAME(string _NAME){ mount_NAME = _NAME; }
};
class CD_ROM : Device {
	public:
		CD_ROM(){}
		CD_ROM(int _id, string _name) : Device(_id, _name) {}
		virtual void show(){
			cout << "Device<" << get_ID() << ">: <CD>" << get_NAME() << endl;
		}
};
class HardDisk : Device {
	public:
		HardDisk(){}
		HardDisk(int _id, string _name) : Device(_id, _name) {}
		virtual void show(){
			cout << "Device<" << get_ID() << ">: <HD>" << get_NAME() << endl;
		}
};
class Host{
	private:
		vector<Device*> device;
	public:
		void show(int &num){
			if(device.size()){
				for(int i = 0 ; i < (int)device.size() ; i++){
					cout << "[" << num++ << "]";
					device[i]->show();
				}
			} else {
				cout << "The number of mounted device is 0" << endl;
				cout << "There is no any device in the host" << endl;
			}
		}
		void mount(Device *b){
			device.push_back(b);
			b->set_ID(device.size());
		}
};
int main(){
	int num = 1;
	Device *(list[6]);
	CD_ROM cd_rom[3];
	HardDisk harddisk[3];
	Host host;
	cd_rom[0] = CD_ROM(0, "ASUS-E818A");
	cd_rom[1] = CD_ROM(0, "SONY-1642");
	cd_rom[2] = CD_ROM(0, "PHILIPS-SPD2514");
	harddisk[0] = HardDisk(0, "Western Digital-750G");
	harddisk[1] = HardDisk(0, "HITACHI-500G");
	harddisk[2] = HardDisk(0, "SEAGATE-750G");
	cout << "**************************************************" << endl;
	cout << "Part1.Initiation(Use own class function to print)" << endl;
	cout << "[" << num++ << "]";
	host.show(num);
	cout << "Device list: " << endl;
	cout << "[" << num++ << "]"; harddisk[0].show();
	cout << "[" << num++ << "]"; cd_rom[0].show();
	cout << "[" << num++ << "]"; harddisk[1].show();
	cout << "[" << num++ << "]"; cd_rom[1].show();
	cout << "[" << num++ << "]"; cd_rom[2].show();
	cout << "[" << num++ << "]"; harddisk[2].show();
	cout << "**************************************************" << endl;
	cout << "Part2.Mounting device(Use polymorphism method)" << endl;
	list[0] = (Device*)&harddisk[0];
	list[1] = (Device*)&cd_rom[1];
	list[2] = (Device*)&cd_rom[2];
	list[3] = (Device*)&harddisk[1];
	list[4] = (Device*)&harddisk[2];
	list[5] = (Device*)&cd_rom[0];
	for(int i = 0 ; i < 6 ; i++){
		cout << "[" << num++ << "]";
		host.mount(list[i]);
		list[i]->show();
	}
	cout << "**************************************************" << endl;
	cout << "Part3.Renaming(Use Host class function to print)" << endl;
	list[3]->set_NAME("MAXTOR-160G");
	list[5]->set_NAME("PHILIPS-SPD2514");
	host.show(num);
}
