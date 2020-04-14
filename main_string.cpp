#include "Update_list.h"

int main(int argc, const char** argv) {

Container<string>* c = new list<string>("");
string a, b, k, d, l;
a = "odin";
b = "dva";
k = "tri";
d = "chetyre";
l = "pyt'";
cout << "Container after creation" << endl;
c->insert(a);
c->insert(b);
c->insert(k);
c->insert(d);
c->insert(l);
cout << "Container after insert strings" << endl;
c->print();
c->remove(a);
cout << "Container after remove a" << endl;
c->print();

    
    delete c;
    return 0;
}