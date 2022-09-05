#pragma once
#include <iostream>

template<typename T>
void linearSearch(T* arr, int N, int x) {

	std::cout << "Linear searching\n" << std::endl;
	
	for (int i = 0; i < N; i++) {
		if (arr[i] == x) {
			std::cout << "Element " << x << " is at index " << i << std::endl;
			return;
		}
	}
	std::cout << "Element " << x << " could not be found in the array" << std::endl;
	

}


template<typename T>
void binarySearch(int l, int r, int x) {
	
}
