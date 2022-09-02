#pragma once

template<typename T>
class searchers {
public:
	
	int linearSearch(T* arr, int N, int x);

	void binarySearch(int l, int r, int x);
};
