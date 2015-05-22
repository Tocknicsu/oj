#include <bits/stdc++.h>>
using namespace std;
typedef pair<int, string> VAR;
typedef pair<set<string>, map<string, VAR> > Class_Info;
int __table[4][4] = {{0, 0, 0, 0},{0, 0, 1, 1},{0, 0, 2, 2},{0, 0, 2, 3}}, n;
string __spec[4] = {"private", "protected", "public", "none"}, type, name, str, spec, from, var_type, var_name, ncls, lcls, var;
map<string, Class_Info> Class;
int specifier(string str){
	for(int i = 0 ; i < 4 ; i++)
		if(str == __spec[i])
			return i+1;
	return 0;
}
int main(){
	freopen("hw5.in", "r", stdin);
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		Class_Info class_info;
		cin >> type >> name >> str >> spec;
		if(specifier(spec)){
			if(spec != "none")
				cin >> from;
		} else {
			from = spec;
			spec = type == "class" ? "private" : "public";
		}
		if(spec != "none")
			for(auto &x : Class[from].second)
				class_info.second[x.first] = VAR(__table[specifier(spec)][x.second.first], x.second.second);
		if(spec == "public"){
			class_info.first = Class[from].first;
			class_info.first.insert(from);
		}
		while(cin >> var_type, var_type != "end"){
			cin >> var_name;
			class_info.second[var_name] = VAR(specifier(var_type), name);
		}
		Class[name] = class_info;
	}
	while(cin >> ncls >> lcls){
		for(int i = 0 ; i < (int)lcls.size() ; i++)
			if(lcls[i]=='.') lcls[i] = ' ';
		stringstream ss(lcls);
		ss >> lcls >> var;
		if(Class.find(lcls) == Class.end()) {
			cout << "Class not found" << endl;
		} else if(Class[lcls].second.find(var) == Class[lcls].second.end()) {
			cout << "Member not found" << endl;
		} else if((ncls == lcls && Class[lcls].second[var].first) || (Class[lcls].first.find(ncls) != Class[lcls].first.end() && Class[ncls].second[var].first) || Class[lcls].second[var].first == 3) {
			cout << Class[lcls].second[var].second << "." << var << endl;
		} else {
			cout << "Invalid access" << endl;
		}
	}
}
