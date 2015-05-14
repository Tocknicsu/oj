#ifndef XHOST_H
#define XHOST_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "host.h"
#include "plugin.h"
using namespace std;
struct reverse_plugin : send_plugin{
	virtual string operator()(string s) const {
		reverse(s.begin(), s.end());
		return s;
	}
};
struct encrypt_plugin : send_plugin{
	const char k;
	encrypt_plugin(const char _k) : k(_k) {}
	virtual string operator()(string s) const {
		for(int i = 0 ; i < (int)s.size() ; i++){
			s[i] = (s[i] - 0x20 + k) % (0x7F - 0x20) + 0x20;
		}
		return s;
	}
};
struct decrypt_plugin : recv_plugin{
	const char k;
	decrypt_plugin(const char _k) : k(_k) {}
	virtual void operator()(const host& from, const host& to, const string& s)const{
		string str = s;
		for(int i = 0 ; i < (int)str.size() ; i++){
			str[i] = (str[i] - 0x20 - k + 0x7F - 0x20) % (0x7F - 0x20) + 0x20;
		}
		cout << ("[") << (to.name) << "] " << str << endl;
	}
};
struct forward_plugin : recv_plugin{
	const host& dst;
	forward_plugin(const host& _dst) : dst(_dst) {}
	virtual void operator()(const host& from, const host& to, const string& s)const{
		to.send(dst, s);
	}
};
struct echo_plugin : recv_plugin{
	virtual void operator()(const host& from, const host& to, const string& s)const{
		to.send(from, s);
	}
};
struct xhost:host{
	vector<const send_plugin*> SP;
	vector<const recv_plugin*> RP;
	xhost(const string& _name) : host(_name) {}
	void register_send_plugin(const send_plugin& p);
	void register_recv_plugin(const recv_plugin& p);
	virtual void send(const host& other, const string& s) const;
	virtual void handle_recv(const host& other, const std::string& s) const;
};

void xhost::register_send_plugin(const send_plugin& p){
	SP.push_back(&p);
}
void xhost::register_recv_plugin(const recv_plugin& p){
	RP.push_back(&p);
}
void xhost::send(const host& other, const string& s) const {
	string str = s;
	for(int i = 0 ; i < (int)SP.size() ; i++)
		str = (*SP[i])(str);
	host::send(other, str);
}
void xhost::handle_recv(const host& other, const string& s) const {
	string str = s;
	for(int i = 0 ; i < (int)RP.size() ; i++)
		(*RP[i])(other, (*this), str);
}
#endif
