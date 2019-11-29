#pragma once
#include "vectorT.h"
#include "GameObject.h"
#include <cmath>

template<class T>
class TablaHash
{
public:
	vectorT<T> teibol;
	int hash;
	int index;
	TablaHash() { }
	int GenCodigoHash(GameObject g);
	~TablaHash() {}
};

template <class T>
int TablaHash<T>::GenCodigoHash(GameObject g) {
	hash = g._idNum*g._idStr.length();	
	index = hash % 13;
	std::cout <<"El codigo es: "<< hash<<std::endl;
	std::cout << "El indice es: "<<index<<std::endl;
	return index;
}
