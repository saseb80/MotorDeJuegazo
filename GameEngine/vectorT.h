#pragma once
#include <iostream>
#include "GameObject.h"
template<class T>
class vectorT
{
private:
	T** arr;
	int current;
	int col;
	int last;
	int _size;
public:
	vectorT<T>() {
		_size = 100;
		arr = new T*[_size];
		for (int i = 0; i < _size; i++) {
			arr[i] = nullptr;
		}
	}
	vectorT<T>(int size) {
		_size = size;
		arr = new T*[size];
		for (int i = 0; i < size; i++) {
			arr[i] = nullptr;
		}
	}
	void push(GameObject data, int index);
	GameObject at(int index);
	void pop();
	int sais();
	int getCapacity();
	void print();
	~vectorT(){}
};

//AGREGA OBJETOS
template<class T>
void vectorT<T>::push(GameObject data, int index) {
	if (_size>index) {
		if (arr[index] != nullptr) {
			data.colisionIndex += 1;
			arr[index][data.colisionIndex] = data;
		}
		else if (arr[index] == nullptr){
			arr[index] = &data;
		}
	}
	else if (_size<index) {
		std::cout << "No se puede agregar ahi" << std::endl;
	}
}

//devuelve un opbejto
template<class T>
GameObject vectorT<T>::at(int index){
	return arr[index];
}

template<class T>
void vectorT<T>::pop() {
	arr[_size] = nullptr;
	_size = _size - 1;
}

//devuelve el size
template<class T>
int vectorT<T>::sais() {
	return _size;
}

template<class T>
int vectorT<T>::getCapacity(){

}

template<class T>
void vectorT<T>::print() {
	for (int i = 0; i < _size; i++) {
		std::cout << arr[i] << " " << std::endl;
	}
}

