#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
class S{
	private:
		string name, code2;
		int code10;
	public:
		S(){}
		S(string _name, string _code2) : name(_name), code2(_code2), code10(0){
			for(int i = (int)code2.size() - 1, v = 1 ; i >= 0 ; i--, v*=2)
				code10 += v * (code2[i] - '0');
		}
		bool operator<(const S& b) const { return code10 < b.code10; }
		string get_name(){	return name;}
		int get_code10(){return code10;}
};
int main(){
	ifstream ifs("lab9.in");
	ofstream ofs("lab9.in", ofstream::app);
	string a, b;
	vector<S> vec;
	while(ifs >> a >> b){
		vec.push_back(S(a, b));
		cout << a << ' ' << b << endl;
	}
	ifs.close();
	sort(vec.begin(), vec.end());
	for(auto &s : vec) ofs << s.get_name() << ' ' << s.get_code10() << endl;
	ofs.close();
	return 0;
}
