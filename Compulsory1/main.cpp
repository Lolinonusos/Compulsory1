#include <iostream>
//#include "sorters.h"
//#include "searchers.h"

// Add elements to the array - done!
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
	
	void insertAt(int index, int value); // Insert somwhere specific
	void addValue(int value); // Insert something at the end
	void removeAt(int position); // Remove element at a specific position
	
	void expand(); // Expand array
	void shorten(); // Shrink array

	//int currentlyContains(); // Showcase elements currently held in array
	
	int index; //  
	T* arrey; // by being a pointer it let's me put different things into it, like an array (I think)

	// Search an array of N elements, find first instance of x
	int linearSearchArray(T* arr, int N, int x);
	void binarySearchArray(int l, int r, int x);

	void swap(T* xp, T* yp);

	void selectionSort(T* arr, int n);
	
	void bubbleSort(T* arr, int n);
	
	void mergeSort(T* arr, const int begin, const int end);
	void merge(T* arr, const int begin, const int middle, const int end);
	
	void quickSort(T* arr, int begin, int end);
	int partition(T* arr, int begin, int end);
	
	void heapSort(T* arr, int N);
	void heapify(T* arr, int N, int i);
	
	// return current size of arrey
	int retSize();

	void printArrey(T* arr);
	
	~DArray();
	
private:

	int capacity; // How long the array is, should always be 1 more than arreySize
	int arreySize; // How many elements currently held, should always be 1 less than capacity

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
	for (size_t i = 0; i < (capacity - 1); i++)
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
	T* temp_arrey = new int[capacity];

	//moveBack(position);
	//arrey[position] = NULL;

	// Copy everything before removed element
	for (int i = 0; i < position; i++) {
		temp_arrey[i] = arrey[i];
	}

	// Move everything from position 1 space back
	for (int i = position; i < arreySize - 1; i++){
		temp_arrey[i] = arrey[i + 1];
	}

	delete[] arrey;
	arrey = temp_arrey;
	std::cout << "Element removed" << std::endl;
}


// Shorten the array when unnecessary long
template <typename T>
void DArray<T>::shorten() {

}


template <typename T>
int DArray<T>::linearSearchArray(T* arr, int N, int x) {

	for (int i = 0; i < N; i++) {
		if (arr[i] == x) {
			// std::cout << "Element " << x << " is at index " << i << std::endl;
			return i;
		}
	}
	// std::cout << "Element " << x << " could not be found in the array" << std::endl;
	//return;
}


template <typename T>
void DArray<T>::binarySearchArray(int l, int r, int x) {
	
}


template <typename T>
void DArray<T>::selectionSort(T* arr, int n)
{

	std::cout << "Selection sorting \n" << std::endl;

	// Loops through the array
	for (int i = 0; i < n-1; i++) {
		int minIndex = i;
		
		// Find element of lowest value
		for (int j = i +1; j < n; j++) {
			// Keeps track of current lowest element
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		// Swaps positions of elements
		if (minIndex != i) {
			swap(&arr[minIndex], &arr[i]);
		}
	}
}
template <typename T>
void DArray<T>::swap(T* xp, T* yp) {
	T temp_arrey = *xp;
	*xp = *yp;
	*yp = temp_arrey;
}


template <typename T>
void DArray<T>::bubbleSort(T* arr, int n) {

	std::cout << "Bubble sorting \n" << std::endl;
	
	//bool swapped;
	for(int i = 0; i < n; i++) {

		//swapped = false;

		for(int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				//swapped = true;
				//bubbleSwap(arr, j);
				swap(&arr[j], &arr[j + 1]);
		
			}
		}
	}
}


template <typename T>
void DArray<T>::mergeSort(T* arr, const int begin, const int end) {

	std::cout << "Merge sorting\n" << std::endl;
	
	if (begin > end) {
		return;
	}
	
	auto middle = (begin + end) / 2;
	
	mergeSort(arr, begin, middle);
	mergeSort(arr, middle + 1, end);
	merge(arr, begin, middle, end);
}
template <typename T>
void DArray<T>::merge(T* arr, const int begin, const int middle, const int end) {
	
}


template <typename T>
void DArray<T>::quickSort(T* arr, int begin, int end) {

	std::cout << "Quick sorting \n" << std::endl;

	if(begin < end) {

		// pi becomes the pivot point in the partition function
		int pi = partition(arr, begin, end);

		//
		quickSort(arr, begin, pi - 1);
		quickSort(arr, pi + 1, end);
	}
}
template <typename T>
int DArray<T>::partition(T* arr, int begin, int end) {

	int pivot = arr[end];
	int i = (begin - 1);

	for (int j = begin; j <= end - 1; j++) {

		if (arr[j] < pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
		
	}

	swap(&arr[i + 1], &arr[end]);
	return(i + 1);
}


template <typename T>
void DArray<T>::heapSort(T* arr, int N) {

	std::cout << "Heap sorting\n" << std::endl;

	// Create a heap of the array
	for (int i = N / 2 - 1; i >= 0; i--) {
		
		heapify(arr, N, i);
	}
	

	// Extract elements one by one from the heap
	for (int i = N - 1; i > 0; i--) {

		//
		swap(&arr[0], &arr[i]);
		
		//
		heapify(arr, i, 0);
	}
	
}
template <typename T>
void DArray<T>::heapify(T* arr, int N, int i) {

	// Largest shall become the root of the heap
	int largest = i;

	int left = 2 * i + 1;

	int right = 2 * i + 2;
	
	if (left < N && arr[left] > arr[largest]) {
		largest = left;
	}
	
	if (right < N && arr[right] > arr[largest]) {
		largest = right;
	}

	// If largest is not the root of the heap
	if (largest != i) {
		swap(&arr[i], &arr[largest]);

		heapify(arr, N, largest);
	}
	
		
}


template <typename T>
int DArray<T>::retSize() {
	return arreySize;
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

	std::cout << "\nChecking all elements: " << std::endl;

	int x = 10;

	// linear search
	
	//Ayy1.selectionSort(Ayy1.arrey, Ayy1.retSize());
	//Ayy1.bubbleSort(Ayy1.arrey, Ayy1.retSize());
	//Ayy1.mergeSort(Ayy1.arrey, 0, Ayy1.retSize());
	//Ayy1.quickSort(Ayy1.arrey, 0, Ayy1.retSize() - 1);
	Ayy1.heapSort(Ayy1.arrey, Ayy1.retSize());
	
	std::cout << "Element " << x << " is at index " << Ayy1.linearSearchArray(Ayy1.arrey, Ayy1.retSize(), x) << std::endl;
	
	for (int i = 0; i < Ayy1.retSize(); i++) {
		std::cout << Ayy1.arrey[i]<< std::endl;
	}
	
	return 0;
}
