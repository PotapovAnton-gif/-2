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
class list:public Container{
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
	void print (int number_of_elem) {
		elem* temp = root;
		while (temp != nullptr) {
			cout << temp->data;
			temp = temp->next;
		}
	}
	void remove(int value) {
		int i = 1;
		elem* that = root->next;
		elem* prev = root;
		while (that->data != value || that->next != nullptr) {
			prev = prev->next;
			that = that->next;
		}
			prev->next = that->next;
			delete[] that;
	
	}
	elem* give_marker_on_root() {
		return root;
	}
	bool exists(int value) {
		elem* that = root;
		while (that->data != value || that != nullptr) {
			that = that->next;
		} if (that->data == value) {
			return true;
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
	root = new elem;
	root->next = nullptr;
	root->data = data_root;
}
list::~list() {
	elem* current_elem = root->next;
	elem* prev_elem = root;
	if (current_elem->next != nullptr) {
		delete[] prev_elem;
		prev_elem = current_elem;
		current_elem = current_elem->next;
	}
	else {
		delete[] current_elem;
	}

}
