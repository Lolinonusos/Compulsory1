#include <iostream>

class DArray {
public:

	DArray();

	void addValue();

	void expand();
	void removeAt(int index);
	int* �rrey; // by being a pointer it let's me put different things into it, like an array (I think)

	
private:

	int capacity;
	int �rreySize;
	int index;

};


DArray::DArray() {
	this->capacity = 1;
	�rrey = new int[capacity]; // puts an array into �rrey
}


void DArray::addValue() {





}


void DArray::expand() {

	this->capacity += 1;
	int* temp_�rrey = new int[capacity];

	for (size_t i = 0; i < (capacity - 1); i++)
	{
		temp_�rrey[i] = �rrey[i];
	}

	delete[] �rrey;
	�rrey = temp_�rrey;
}


int main() {

	DArray Ayy1;

	// insert values


	int �rreyLength = 0;
	�rreyLength = sizeof(Ayy1.�rrey) / sizeof(Ayy1.�rrey[0]);

	std::cout << �rreyLength << std::endl;

	Ayy1.expand();
	Ayy1.expand();
	Ayy1.expand();


	�rreyLength = sizeof(Ayy1.�rrey) / sizeof(Ayy1.�rrey[0]);

	std::cout << �rreyLength << std::endl;


	return 0;
}
