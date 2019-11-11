#include "pch.h"
#include "List.h"	
#include "Player.h"	
#include <Windows.h>

void init_game();
bool exitKeyPressed();
void getInput();
void update();
void render();
List <GameObject> mainList;

int main() {

	//inicializa todo lo necesario para el juego
	init_game();

	//Ciclo principal del juego
	while (1) {
		getInput();
		if (exitKeyPressed()) {
			break;
		}
			update();
			render();
	}
	std::cout << "Hello World!" << std::endl;
}

void init_game() {
	mainList.Insert(GameObject(45));
	mainList.Insert(GameObject(78));
	mainList.Insert(Player(99));
	mainList.printFake();
}

void getInput() {

}

void render() {

}

bool exitKeyPressed() {
	return (GetKeyState(VK_ESCAPE) & 0x800);
}

void update() {
	Node<GameObject> *it = mainList.first;
	while (it){
		it->data.Update();
		it = it->next;
	}
}
//class Base {
//	public:
//		virtual void print() {
//			std::cout<< "Base" <<std::endl;
//		}
//};
//
//class Derivada : public Base {
//	public:
//		void print() {
//			std::cout << "Derivada" << std::endl;
//		}
//};
//
//class Derivada2 : public Derivada {
//	public:
//		void print2() {
//			std::cout << "lol" << std::endl;
//		}
//};	
//
//int main() {
//	Base* cb, ba;
//	cb = &ba;
//	cb->print();
//	Derivada d1;
//	cb = &d1; //Almacena la direccion de memoria de d1
//	static_cast <Derivada2*>(cb)->print2(); //Forma PRO de hacer casting
//    std::cout << "Hello World!\n";	
//}

