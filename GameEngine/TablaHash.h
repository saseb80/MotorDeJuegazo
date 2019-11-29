#pragma once
#include "vectorT.h"
#include "GameObject.h"
#include <cmath>

template<class T>
class TablaHash
{
public:
	int size;
	vectorT<T> teibol;
	int hash;
	int index;
	TablaHash() {
	}
	int GenCodigoHash(GameObject g);
	void insertar(GameObject g, int index);
	~TablaHash() {}
};

template <class T>
int TablaHash<T>::GenCodigoHash(GameObject g) {
	hash = g._idNum*g._idStr.length();	
	index = hash % 22;
	std::cout <<"El codigo es: "<< hash<<std::endl;
	std::cout << "El indice es: "<<index<<std::endl;
	return index;
}

template <class T>
void TablaHash<T>::insertar(GameObject g, int index) {
	teibol.push(g, index);
}
