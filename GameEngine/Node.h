#pragma once
#include "GameObject.h"

template <class T> class Node {
	public:
		Node<T> *next;
		Node<T> *prev;
		T data;
		int index;
		Node(T dat);
		Node();
		~Node();
};

template <class T> Node<T>::Node() {
	next = nullptr;
	prev = nullptr;
}

template <class T> Node<T>::Node(T dat) {
	next = nullptr;
	prev = nullptr;
	data = dat;
}

template <class T> Node<T>::~Node() {
}