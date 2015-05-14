#ifndef HOST_H
#define HOST_H
#include <string>
#include <iostream>
struct host {
	host(const std::string& name_) : name(name_) {}
	virtual void send(const host& other, const std::string& s) const {
		std::cout << "[" << name << " -> " << other.name << "] " << s << std::endl;
		other.handle_recv(*this, s);
	}
	const std::string name;
	virtual ~host() {}
	private:
	virtual void handle_recv(const host&, const std::string&) const {};
};
#endif
