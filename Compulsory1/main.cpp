#include <iostream>
#include <vector>

// Add elements to the array - done!
// Remove elements from the array - done?
// Expand the array - done!
// Shrink the array - done!
// Search the array using a search algorithm
	// Linear Search - functioning
	// Binary Search

// Use 4 of the sorting algorithms
	// Selection Sort
	// Bubble Sort
	// Merge Sort
	// Quick Sort
	// Heap Sort

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
	int* arrey; // by being a pointer it let's me put different things into it, like an array (I think)

	// Search an array of N elements, find first instance of x
	int linearSearchArray(int* arr, int N, int x);
	void binarySearchArray(int l, int r, int x);

	void selectionSort(int* arr, int n);
	void bubbleSort(int* arr, int n);
	void mergeSort(int* arr, const int begin, const int end);
	void quickSort(int* arr, int low, int high);
	void heapSort(int* arr, int N);

	// return current size of arrey
	int retSize();
	
	~DArray();
	
private:

	int capacity; // How long the array is, should always be 1 more than arreySize
	int arreySize; // How many elements currently held, should always be 1 less than capacity

};


DArray::DArray() {
	this->capacity = 1;
	this->arreySize = 0;
	arrey = new int[capacity]; // puts an array into arrey
}


// Adds value at the end of the array
void DArray::addValue(int value) {

	// 
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
void DArray::expand() {

	this->capacity += 1;
	int* temp_arrey = new int[capacity];

	// Copy elements form arrey to temp_arrey
	for (size_t i = 0; i < (capacity - 1); i++)
	{
		temp_arrey[i] = arrey[i];
	}
	
	delete[] arrey;
	arrey = temp_arrey;
}


// Remove an element at a specific position
void DArray::removeAt(int position) {

	
	// Making sure we remove an element at a position that actually exists
	if (position < 0 || position >= capacity) {
		std::cout << "Out of array bounds, unable to remove element" << std::endl;
		return;
	}

	capacity -= 1;
	arreySize -= 1;
	int* temp_arrey = new int[capacity];

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
void DArray::shorten() {

}


int DArray::linearSearchArray(int* arr, int N, int x) {

	for (int i = 0; i < N; i++) {
		if (arr[i] == x) {
			return i;
		}
	}
	//return;
}


//void DArray::binarySearchArray(int searchIndex) {
	
//}


void DArray::selectionSort(int* arr, int n)
{
	
	for (int i = 0; i < n-1; i++) {

		int minIndex = i;


		// Find element of lowest value
		for (int j; j < n; j++) {

			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}

			if (minIndex != i) {
				// Swap(&arr[minIndex], &arr[i]);
			}
		}
	}
}


int DArray::retSize() {
	return arreySize;
}

// Goodbye
DArray::~DArray() {
	delete[] this->arrey;
}


int main() {

	DArray Ayy1;

	// insert values
	Ayy1.addValue(10);
	Ayy1.addValue(7);
	
	Ayy1.removeAt(1);
	
	Ayy1.addValue(69);

	std::cout << "\nChecking all elements: " << std::endl;
	for (int i = 0; i < Ayy1.retSize(); i++) {
		std::cout << Ayy1.arrey[i]<< std::endl;
	}

	int x = 10;

	// linear search
	std::cout << "Element " << x << " is at index " << Ayy1.linearSearchArray(Ayy1.arrey, Ayy1.retSize(), x) << std::endl;
	

	
	
	return 0;
}
