#include <iostream>

#include "sorters.h"
#include "searchers.h"

// Add elements to the array - done!
// Insert elements and values at specific indexes - done!
// Remove elements from the array - done?
// Expand the array - done!
// Shrink the array - done!
// Search the array using a search algorithm
	// Linear Search - functioning
	// Binary Search

// Use 4 of the sorting algorithms
	// Selection Sort - functioning
	// Bubble Sort - functioning
	// Merge Sort
	// Quick Sort - functioning
	// Heap Sort - functioning

template <typename T>
class DArray {
public:

	DArray();
	
	void addValue(int value); // Insert something at the end
	void removeAt(int position); // Remove element at a specific position
	void insertAt(int index, int value); // Insert somewhere specific
	
	void expand(); // Expand array
	void shorten(); // Shrink array

	//int currentlyContains(); // Showcase elements currently held in array
	
	T* arrey; // by being a pointer it let's me put different things into it, like an array (I think)
	
	// return current size of arrey
	int retSize();

	void printArrey(T* arr);
	
	~DArray();
	
private:

	 
	int capacity = 0; // How long the array is, should always be 1 more than arreySize
	int arreySize = 0; // How many elements currently held, should always be 1 less than capacity

};


template <typename T>
DArray<T>::DArray() {
	this->capacity = 1;
	this->arreySize = 0;
	arrey = new T[capacity]; // puts an array into arrey
}


// Adds value at the end of the array
template <typename T>
void DArray<T>::addValue(int value) {
	if (this->arreySize < this->capacity) {
		std::cout << "Adding value without problem\n" << std::endl;
		this->arrey[arreySize] = value;
		std::cout << this->arrey[arreySize] << std::endl;
		arreySize += 1;
	}
	else { // Array is full, expand it
		std::cout << "Expanding\n" << std::endl;
		this->expand();
		this->arrey[arreySize] = value;
		std::cout << this->arrey[arreySize] << std::endl;
		arreySize += 1;
	}
}


// Expand array when it is to short
template <typename T>
void DArray<T>::expand() {

	this->capacity += 1;
	T* temp_arrey = new int[capacity];

	// Copy elements form arrey to temp_arrey
	for (int i = 0; i < (capacity - 1); i++)
	{
		temp_arrey[i] = arrey[i];
	}
	
	delete[] arrey;
	arrey = temp_arrey;
}


// Remove an element at a specific position
template <typename T>
void DArray<T>::removeAt(int position) {

	
	// Making sure we remove an element at a position that actually exists
	if (position < 0 || position >= capacity) {
		std::cout << "Out of array bounds, unable to remove element" << std::endl;
		return;
	}

	capacity -= 1;
	arreySize -= 1;
	T* temp_arrey = new T[capacity];

	//moveBack(position);
	//arrey[position] = NULL;

	// Copy everything before removed element
	for (int i = 0; i < position; i++) {
		temp_arrey[i] = arrey[i];
	}

	// Move everything from position one space back
	for (int i = position; i < arreySize - 1; i++){
		temp_arrey[i] = arrey[i + 1];
	}

	delete[] arrey;
	arrey = temp_arrey;
	std::cout << "Element removed" << std::endl;
}


template <typename T>
void DArray<T>::insertAt(int index, int value)
{
	// Do this if trying to insert at a position less than 0
	if (index < 0) {
		
		int moves = 0;
		
		std::cout << "Out of array bounds, expanding" << std::endl;
		for (int i = 0; i > index; i--) {
			expand();
			moves += 1;
		}
		arreySize += moves;
		index = 0;
		T* temp_arrey = new T[capacity];

		for (int i = 0; i < capacity; i++) {
			if (i == index) {
				temp_arrey[i] = value;
			}
			else if(i >= moves) {
				temp_arrey[i] = arrey[i - moves];
			}
			else {
				temp_arrey[i] = NULL;
			}
			std::cout << temp_arrey[i] << std::endl;
		}
		
		delete[] arrey;
		arrey = temp_arrey;
		
	}
	// Do this if trying to insert at a position larger than the arrays capacity
	else if(index >= capacity) {
		std::cout << "Out of array bounds, expanding" << std::endl;
		int prevSize = 0;
		
		int prevCap = index - capacity - 1;
		
		for (int i = 0; i <= (prevCap + 1); i++) {
			expand();
			prevSize += 1;
		}
		
		arreySize += prevSize;
		T* temp_arrey = new T[capacity];

		for (int i = 0; i < capacity; i++)
		{
			if (i == index) {
				temp_arrey[i] = value;
			}
			else if (i < prevCap) {
				temp_arrey[i] = arrey[i];
			}
			else {
				temp_arrey[i] = NULL;
			}
		}
		delete[] arrey;
		arrey = temp_arrey;
	}
	else
	{
		arrey[index] = value;
	}
	
}

// Shorten the array when unnecessary long
template <typename T>
void DArray<T>::shorten() {

}


template <typename T>
int DArray<T>::retSize() {
	return arreySize;
}

template <typename T>
void DArray<T>::printArrey(T* arr)
{
}

// Goodbye
template <typename T>
DArray<T>::~DArray() {
	delete[] this->arrey;
}


int main() {

	DArray<int> Ayy1;

	// insert values
	Ayy1.addValue(10);
	Ayy1.addValue(7);
	Ayy1.addValue(100);
	Ayy1.addValue(1);
	Ayy1.addValue(20);

	//Ayy1.removeAt(1);
	
	Ayy1.addValue(69);
	Ayy1.addValue(34);

	Ayy1.insertAt(1, 8);
	
	std::cout << "\nChecking all elements: " << std::endl;

	int x = 10;

	//selectionSort(Ayy1.arrey, Ayy1.retSize());
	//bubbleSort(Ayy1.arrey, Ayy1.retSize());
	//mergeSort(Ayy1.arrey, 0, Ayy1.retSize());
	//quickSort(Ayy1.arrey, 0, Ayy1.retSize() - 1);
	heapSort(Ayy1.arrey, Ayy1.retSize());

	
	
	
	// linear search
	linearSearch(Ayy1.arrey, Ayy1.retSize(), x);
	
	for (int i = 0; i < Ayy1.retSize(); i++) {
		std::cout << Ayy1.arrey[i]<< std::endl;
	}
	
	return 0;
}
