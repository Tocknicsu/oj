#include "xhost.h"
using namespace std;

int main(){
	xhost a("a"), b("b");
	a.send(b, "hello");
	b.send(b, "self");
	
	xhost c("c");
	reverse_plugin rp;
	c.register_send_plugin(rp);
	c.send(a, "123456789");
	xhost d("d");
	encrypt_plugin encp(5);
	decrypt_plugin decp(5);
	d.register_send_plugin(encp);
	c.register_recv_plugin(decp);
	d.send(c, "12389XYZabc}");
	xhost e("e");
	forward_plugin fpd(d);
	forward_plugin fpc(c);
	e.register_recv_plugin(fpd);
	e.register_recv_plugin(fpc);
	b.send(e, "test fwd");
	xhost f("f");
	echo_plugin ep;
	f.register_recv_plugin(ep);
	b.send(f, "test echo");
}
