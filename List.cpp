#include <iostream>

using namespace std;

class elem {

private:

elem* p;
int data;
elem* next;
public:
	
	elem() {
		p = new elem;
		p->data = 0;
		p->next = NULL;
	}

	elem(int data) {
		p = new elem;
		p->data = data;
	}
	
	~elem() {
		delete p;
	}
	
	elem* give_next() {
		return next;
	}
	int give_data() {
		return data;
	}
	void change(elem* new_next) {
		next = new_next;
	}

	void change(int new_data) {
		data = new_data;
	}

};


class Container {

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


class list:public Container{

private:

	elem* root;

public:

	list(int data_root) {
		root = new elem(data_root);
	}

	~list() {
		delete root;
	}

	void print() {
		elem* temp = root;
		while (temp != NULL) {
			cout << temp->give_data();
			temp = temp->give_next();
		}
	}

	void insert(int value) {
		
		elem* new_ = new elem;
		elem* temp = root->give_next();
		
		root->change(new_);
		new_->change(temp);
		new_->change(value);
	
	}
	
	bool exists(int data) {
		
		elem* temp = root;
		
		while (temp->give_data() != data && temp != NULL)
			temp = temp->give_next();
		
		if(temp == NULL) {
			return 0;
		} else {
			return 1;
		}
				
	}
	void remove(int data) {
		
		elem* temp = root;
		elem* priv = root;

		while (temp->give_data() != data && temp!= NULL) {
			priv = temp;
			temp = temp->give_next();
		}

		if (temp != NULL) {
			priv->change(temp->give_next());
			delete temp;
		}
	
	}


};

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