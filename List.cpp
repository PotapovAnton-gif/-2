#include <iostream>

using namespace std;


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

	struct elem
	{
		int data = 0;
		elem* next = NULL;
	};
	elem* root;

public:

	list(int data_root);
	~list();


	void print () {
		elem* temp =this->root;
	
		while (temp -> next != NULL) {
			
			cout << temp->data << endl;

			temp = temp->next;
		}
		
	}

	void remove(int value) {
		if (root->next == NULL){
			cout << "YOU CAN'T REMOVE ROOT" << endl;
		} else {
		elem* that = root->next;
		elem* prev = root;
		while (that->next != NULL && that->data != value) {
			prev = prev->next;
			that = that->next;
		}
			prev->next = that->next;
			delete[] that;
		}
	}

	elem* give_marker_on_root() {
		return root;
	}
	bool exists(int value) {
		elem* that = root;
		while (that -> next != NULL && that->data != value) {
			that = that->next;
		} if (that-> next != NULL) {
			return true;
		} else {
			return false;
		}

	}
	void insert (int data) {
		
		elem* new_elem = new elem;
		
		new_elem->data = data;
		
		new_elem->next = root->next;
		
		root->next = new_elem;
	}
 };

list::list(int data_root) {
	this->root = new elem;
	this->root->next = NULL;
	this->root->data = data_root;
	cout << root->data << endl;
}

list::~list() {
	elem* current_elem = root->next;
	elem* prev_elem = root;
	if (current_elem->next != NULL) {
		delete[] prev_elem;
		prev_elem = current_elem;
		current_elem = current_elem->next;
	}
	else {
		delete[] current_elem;
	}

}


int main()

{

    list c(0);



    for(int i = 1; i < 10; i++)

        c.insert(i*i);



    cout << "Container after creation:" << endl;
    c.print();


    if(c.exists(25))

        cout << "Search for value 25: found" << endl;



    if(!c.exists(111))

        cout << "Search for value 111: not found" << endl;



    c.remove(25);

    cout << "Container after deletion of the element:" << endl;

    c.print();

    return 0;

}
