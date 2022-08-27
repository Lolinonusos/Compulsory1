#include <iostream>

class DArray {
public:

	DArray();

	void addValue();

	void expand();
	void removeAt(int index);
	int* ærrey; // by being a pointer it let's me put different things into it, like an array (I think)

	
private:

	int capacity;
	int ærreySize;
	int index;

};


DArray::DArray() {
	this->capacity = 1;
	ærrey = new int[capacity]; // puts an array into ærrey
}


void DArray::addValue() {





}


void DArray::expand() {

	this->capacity += 1;
	int* temp_ærrey = new int[capacity];

	for (size_t i = 0; i < (capacity - 1); i++)
	{
		temp_ærrey[i] = ærrey[i];
	}

	delete[] ærrey;
	ærrey = temp_ærrey;
}


int main() {

	DArray Ayy1;

	// insert values


	int ærreyLength = 0;
	ærreyLength = sizeof(Ayy1.ærrey) / sizeof(Ayy1.ærrey[0]);

	std::cout << ærreyLength << std::endl;

	Ayy1.expand();
	Ayy1.expand();
	Ayy1.expand();


	ærreyLength = sizeof(Ayy1.ærrey) / sizeof(Ayy1.ærrey[0]);

	std::cout << ærreyLength << std::endl;


	return 0;
}
