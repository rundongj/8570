#ifndef CLICK_MYNOTHINGELEMENT_HH
#define CLICK_MYNOTHINGELEMENT_HH
#include <click/element.hh>
CLICK_DECLS
class MyNothingElement : public Element { public:
    MyNothingElement() { }
    ~MyNothingElement() { }
    const char *class_name() const { return "MyNothingElement"; }
    const char *port_count() const { return PORTS_1_1; }
    void push(int port, Packet *p) {
        p = simple_action(p);
        if (p)
            output(port).push(p);
    }
    Packet *pull(int port) {
        Packet *p = input(port).pull();
        if (p)
            p = simple_action(p);
        return p;
    }
};
CLICK_ENDDECLS
#endif
