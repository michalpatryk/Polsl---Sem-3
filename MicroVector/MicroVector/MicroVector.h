#pragma once
#ifndef ___MicroVector___
#define ___MicroVector___
#include <iostream>
#include  <type_traits>
template<class T>
class MicroVector {
	int length;
	int size;
	T* vecArray;
public:
	MicroVector();
	MicroVector(int size_);
	void push_back(T & input);
	T &operator[](int i);

	bool empty();

	~MicroVector();
};


template<class T>

inline MicroVector<T>::MicroVector() :size(10), length(0) { vecArray = new T[size](); }

template<class T>
inline MicroVector<T>::MicroVector(int size_) : size(size_), length(0) { vecArray = new T[size](); }

template<class T>
inline void MicroVector<T>::push_back(T & input)
{
	length++;
	if (length > size) {
		int oldSize = size;
		size *= 2;
		T *temp = vecArray;
		vecArray = new T[size];
		for (int i = 0; i < oldSize - 1; i++) {
			vecArray[i] = temp[i];
		}
		delete[] temp;
	}
	vecArray[length - 1] = input;

}

template<class T>
inline T & MicroVector<T>::operator[](int i)
{
	if (i < size) return vecArray[i];
	else throw std::out_of_range("Out of scope");
}



template<class T>
inline bool MicroVector<T>::empty()
{
	if (length == 0) return true;
	else return false;
}



template<class T>
inline MicroVector<T>::~MicroVector()
{
	if (vecArray != nullptr) {
		delete[] this->vecArray;
		vecArray = nullptr;
	}
	std::cout << "Deleting";

}
#endif // ! MicroVector
