#pragma once
#ifndef ___MicroVector___
#define ___MicroVector___
#include <iostream>
template<class T>
class MicroVector {
	int length;
	int size;
	T* vecArray;
public:
	MicroVector();
	MicroVector(int size_);
	void push_back(T input);
	T &operator[](int i);

	~MicroVector();
};


#endif // ! MicroVector

template<class T>

inline MicroVector<T>::MicroVector() :size(10), length(0) { vecArray = new T[size]; }

template<class T>
inline MicroVector<T>::MicroVector(int size_) : size(size_), length(0) { vecArray = new T[size]; }

template<class T>
inline void MicroVector<T>::push_back(T input)
{
	length++;
	if (length > size) {
		int oldSize = size;
		size *= 2;
		T *temp = vecArray;
		vecArray = new T[size];
		for (int i = 0; i < oldSize-1; i++) {
			vecArray[i] = temp[i];
		}
		delete[] temp;
	}
	vecArray[length-1] = input;
}

template<class T>
inline T & MicroVector<T>::operator[](int i)
{
	if (i > length) return vecArray[i];
	else std::cout << "Out of bound!" << std::endl;
}

template<class T>
inline MicroVector<T>::~MicroVector()
{
	std::cout << "Deleting";
	delete[] vecArray;
}
