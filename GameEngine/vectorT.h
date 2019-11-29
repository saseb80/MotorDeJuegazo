#pragma once
#include <iostream>
template<class T>
class vectorT
{
private:
	T** arr;
	int _size;
	int current;
public:
	vectorT<T>() {
		_size = 0;
		
		for (int i = 0; i < _size; i++) {
			arr[i] = nullptr;
		}
	}
	vectorT<T>(int size) {
		_size = size;
		
		for (int i = 0; i < size; i++) {
			arr[i] = nullptr;
		}
	}
	void push(T data, int index);
	T at(int index);
	void pop();
	int sais();
	int getCapacity();
	void print();
	~vectorT(){}
};


template<class T>
void vectorT<T>::push(T data, int index) {

}

template<class T>
T vectorT<T>::at(int index) {

}

template<class T>
void vectorT<T>::pop() {

}

template<class T>
int vectorT<T>::sais() {

}

template<class T>
int vectorT<T>::getCapacity(){

}

template<class T>
void vectorT<T>::print() {
	for (int i = 0; i < _size; i++) {
		std::cout << arr[i] << " " <<std:: endl;
	}
}

