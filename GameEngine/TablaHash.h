#pragma once
#include "vectorT.h"
#include "GameObject.h"
#include <cmath>

template<class T>
class TablaHash
{
public:
	int size;
	vectorT<T>* teibol;
	int hash;
	int index;
	TablaHash() {
		GameObject* teibol = new GameObject();
	}
	TablaHash(int size) {
		teibol = new vectorT<GameObject>(size);
	}
	void print();
	int GenCodigoHash(GameObject g);
	void insertar(GameObject g);
	~TablaHash() {}
};

//GENERA UN CODIGO HASH e imprime los codigos
template <class T>
int TablaHash<T>::GenCodigoHash(GameObject g) {
	hash = g._idNum*g._idStr.length();	
	index = hash %teibol->sais();
	std::cout <<"La llave: "<< g._idStr<<" "<<g._idNum<<std::endl;
	std::cout <<"El hash es: "<< hash<<std::endl;
	std::cout << "El indice es: "<<index<<std::endl;
	return index;
}

//Inserta los objetos
template <class T>
void TablaHash<T>::insertar(GameObject g) {
	int index = GenCodigoHash(g);
	teibol->push(g, index);
}

//template<class T>
//void TablaHash<T>::print() {
//	for (int i = 0; i < teibol->sais();i++) {
//		std::cout << "Valores del la papa: " << teibol->at(i)._idNum<<std::endl;
//	}
//}
