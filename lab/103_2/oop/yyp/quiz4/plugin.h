#ifndef PLUGIN_H
#define PLUGIN_H
#include <string>
#include "host.h"
struct send_plugin {
	virtual std::string operator()(std::string s) const = 0;
	virtual ~send_plugin() {}
	protected:
	send_plugin() = default;
	private:
	send_plugin(const send_plugin&) = default;
	send_plugin& operator=(const send_plugin&) = default;
};
struct recv_plugin {
	virtual void operator()(const host& from, const host& to, const std::string& s) const = 0;
	virtual ~recv_plugin() {}
	protected:
	recv_plugin() = default;
	private:
	recv_plugin(const recv_plugin&) = default;
	recv_plugin& operator=(const recv_plugin&) = default;
};
#endif
