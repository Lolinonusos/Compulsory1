#pragma once

template<typename T>
class sorters {
public:

	void swap(T* xp, T* yp);

	void selectionSort(T* arr, int n);
	
	void bubbleSort(T* arr, int n);
	
	void mergeSort(T* arr, const int begin, const int end);
	void merge(T* arr, const int begin, const int middle, const int end);
	
	void quickSort(T* arr, int begin, int end);
	int partition(T* arr, int begin, int end);
	
	void heapSort(T* arr, int N);
	void heapify(T* arr);
};


