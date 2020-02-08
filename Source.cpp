#include <iostream>

using namespace std;
class list {
private:
	struct elem
	{
		int data;
		elem* next;
	};
	elem* root;
public:

	list(int data_root) {
		root = new elem;
		root->data = data_root;
	}
	~list()
	{
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
	void print_data_of_this_elem(int number_of_elem) {
		int i = 0;
		elem* that = root;
		while (i != number_of_elem) {
			i++;
			if (that->next == NULL) {
				cout << "WARNING. OUT of LIST";
			}
			else {
				that = that->next;
			}
		}
		cout << that->data;
	}
	elem* give_marker_on_root() {
		return root;
	}
	void create_and_connect_new_elem(int data) {
		elem* new_elem = new elem;
		new_elem->data = data;
		new_elem->next = root->next;
		root->next = new_elem;
	}
 };
int main() {
	int data_root;
	cin >> data_root;
	int a[10];
	for (int i = 0; i < 10; i++) {
		cin >> a[i];
	}
	list l1(data_root);
	for (int i = 0; i < 10; i++) {
		l1.create_and_connect_new_elem(a[i]);
	}
	for (int i = 0; i < 11; i++) {
		l1.print_data_of_this_elem(i);
		cout << endl;
	}
	


	return 0;
}