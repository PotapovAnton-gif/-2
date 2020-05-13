#include <iostream>

using namespace std;


template <typename T> 

class Container {

public:
	// Виртуальные методы, должны быть реализованы вашим контейнером
	virtual void insert(const T &value) = 0;
	
	virtual bool exists(const T &value) = 0;
	 
	virtual void remove(const T &value) const = 0;

	// И этот тоже, хотя к нему потом ещё вернёмся
	virtual void print() = 0;

	// Виртуальный деструктор (пока просто поверьте, что он нужен)
	virtual ~Container() { };
};
template <typename T>
class list : public Container<T>{

private:

	struct elem {
		
		T data;
		elem* next;
	};
	elem* root;
public:

	list() {
	
	root = new elem;
	
	root->next = nullptr;

	}

	
	~list() {

	elem* current_elem = root->next;
	
	elem* prev_elem = root;
	
	if(current_elem == nullptr) {
		delete prev_elem;
	}
	else {

		while (current_elem->next != nullptr) {
			delete prev_elem;
			prev_elem = current_elem;
			current_elem = current_elem->next;
		}
	
		delete current_elem;
		delete prev_elem;
		}
	}

	void print () {
	
		elem* temp = root->next;
	
		while (temp != nullptr) {
			cout << temp->data << endl;
			temp = temp->next;
			}
		}
	

	void remove(const T &value) const {
	
		elem* that = root->next;
	
		elem* prev = root;
		if (that != nullptr) {
		while (that->data != value && that->next != nullptr) {
			prev = prev->next;
			that = that->next;
		}
			prev->next = that->next;
			delete that;
	}
	}
	
	bool exists(const T &value) {
		
		elem* that = root->next;
		
		if (that == nullptr) {
			return false;
		}
		
		else {
		
		while (that->data != value && that->next != nullptr)
			that = that->next;
		
		if (that->data == value)
			return true;
		else 
			return false;
		}	
	}

	void insert (const T &data) {
	
		elem* new_elem = new elem;
	
		new_elem->data = data;
	
		new_elem->next = root->next;
	
		root->next = new_elem;
	}
};
