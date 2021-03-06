#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
int __table[4][4] = {
	{0, 0, 0, 0},
	{0, 0, 1, 1},
	{0, 0, 2, 2},
	{0, 0, 2, 3}
};
string __spec[4] = {"private", "protected", "public", "none"};
struct VAR{
	int type, from;
	string name;
	VAR(){}
	VAR(int _type, int _from, string _name) : type(_type), from(_from), name(_name) {}
};
struct CLASS{
	vector<VAR> var;
	int from, id, type;
	string name;	
};
vector<CLASS> Class;
int specifier(string str){
	for(int i = 0 ; i < 4 ; i++)
		if(str == __spec[i])
			return i+1;
	return 0;
}
int find_class_id(string str){
	for(int i = 0 ; i < (int)Class.size() ; i++)
		if(Class[i].name==str)
			return i;
	return -1;
}
int find_member_id(CLASS &cls, string str){
	for(int i = 0 ; i < (int)cls.var.size() ; i++)
		if(cls.var[i].name == str)
			return i;
	return -1;
}
int main(){
	freopen("hw5.in", "r", stdin);
	int n;
	cin >> n;
	Class = vector<CLASS>(n);
	for(int i = 0 ; i < n ; i++){
		string type, name, str, spec, from = "";
		cin >> type >> name >> str >> spec;
		Class[i].name = name;
		Class[i].id = i;
		if(specifier(spec)){
			if(spec != "none")
				cin >> from;
		} else {
			from = spec;
			spec = type == "class" ? "private" : "public";
		}
		string var_type, var_name;
		while(cin >> var_type, var_type != "end"){
			cin >> var_name;
			Class[i].var.push_back(VAR(specifier(var_type), i, var_name));
		}
		if(spec != "none"){
			int spec_type = specifier(spec);
			int spec_id = find_class_id(from);
			Class[i].from = spec_id;
			for(int j = 0 ; j < (int)Class[spec_id].var.size() ; j++){
				if(find_member_id(Class[i], Class[spec_id].var[j].name)==-1)
					Class[i].var.push_back(VAR(__table[spec_type][Class[spec_id].var[j].type], Class[spec_id].var[j].from, Class[spec_id].var[j].name));
			}
			Class[i].type = spec_type;
		} else {
			Class[i].from = i;
			Class[i].type = 0;
		}
	}
	string ncls, lcls, var;
	while(cin >> ncls >> lcls){
		for(int i = 0 ; i < (int)lcls.size() ; i++)
			if(lcls[i]=='.') lcls[i] = ' ';
		stringstream ss(lcls);
		ss >> lcls >> var;
		int nid = find_class_id(ncls);
		int lid = find_class_id(lcls);
		if(lid==-1){
			cout << "Class not found" << endl;
			continue;
		}
		CLASS& look = Class[lid], &now = Class[nid];
		int n_var_id = find_member_id(now, var), l_var_id = find_member_id(look, var);
		if(l_var_id==-1){
			cout << "Member not found" << endl;
			continue;
		}
		bool down = false, all_public = true;
		int now_id = lid;
		while(!down && now_id != Class[now_id].from){
			all_public = all_public && (Class[now_id].type == 3);
			now_id = Class[now_id].from;
			down = now_id == nid;
		}
		if((lid == nid && look.var[l_var_id].type) || (down && all_public && now.var[n_var_id].type) || look.var[l_var_id].type == 3){
			cout << Class[look.var[l_var_id].from].name << "." << look.var[l_var_id].name << endl;
		} else {
			cout << "Invalid access" << endl;
		}
	}
}
