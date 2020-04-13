#include <iostream>

using namespace std;
class Container
{
public:
	// Виртуальные методы, должны быть реализованы вашим контейнером
	virtual void insert(int value) = 0;
	
	virtual bool exists(int value) = 0;
	
	virtual void remove(int value) = 0;

	// И этот тоже, хотя к нему потом ещё вернёмся
	virtual void print() = 0;

	// Виртуальный деструктор (пока просто поверьте, что он нужен)
	virtual ~Container() { };
};
class list : public Container{

private:

	struct elem
	{
		int data;
		elem* next;
	};
	elem* root;
public:

	list(int data_root);
	
	~list();

	void print () {
	
		elem* temp = root;
	
		while (temp != nullptr) {
			cout << temp->data << endl;
			temp = temp->next;
		}
	
	}

	void remove(int value) {
	
		int i = 1;
	
		elem* that = root->next;
	
		elem* prev = root;
	
		while (that->data != value && that->next != nullptr) {
			prev = prev->next;
			that = that->next;
		}
			prev->next = that->next;
			delete that;
	}
	
	bool exists(int value) {
		
		elem* that = root;
		
		while (that->data != value && that->next != nullptr)
			that = that->next;
		
		if (that->data == value)
			return true;
		else 
			return false;
	}

	void insert (int data) {
	
		elem* new_elem = new elem;
	
		new_elem->data = data;
	
		new_elem->next = root->next;
	
		root->next = new_elem;
	}
};

list::list(int data_root) {
	
	root = new elem;
	
	root->next = nullptr;
	
	root->data = data_root;

}

list::~list() {
	
	elem* current_elem = root->next;
	
	elem* prev_elem = root;
	
	while (current_elem->next != nullptr) {
		delete prev_elem;
		prev_elem = current_elem;
		current_elem = current_elem->next;
	}
	
		delete current_elem;
		delete prev_elem;

}
int main(int argc, const char** argv) {

Container* c = new list(0);

    for(int i = 1; i < 10; i++)
        c->insert(i*i);

    cout << "Container after creation:" << endl;
    c->print();

    if(c->exists(25))
        cout << "Search for value 25: found" << endl;

    if(!c->exists(111))
        cout << "Search for value 111: not found" << endl;

    c->remove(25);
    cout << "Container after deletion of the element:" << endl;
    c->print();

    delete c;
    return 0;
}