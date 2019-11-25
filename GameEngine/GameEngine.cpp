#include "pch.h"
#include <stdlib.h>
#include <ctime>
#include "List.h"	
#include "Player.h"	
#include <Windows.h>

void init_game();
bool exitKeyPressed();
void getInput();
void update();
void render();
List <GameObject> mainList;

GameObject g1(1);
GameObject g2(2);
GameObject g3(3);
GameObject g4(4);
GameObject g5(5);
GameObject g6(6);
GameObject g7(7);
GameObject g8(8);

GameObject arr1[] = {g2,g8,g5,g3,g6,g4,g1,g7};
GameObject arr2[] = {g2,g8,g5,g3,g6,g4,g1,g7};
GameObject arr3[] = {g2,g8,g5,g3,g6,g4,g1,g7};
GameObject arr4[] = {g2,g8,g5,g3,g6,g4,g1,g7};
 

void MergeSort(GameObject arr[]) {
}

void SelectionSort(GameObject arr[],int t) {
	GameObject arrei[100];	
	for (int i = 0; i < t - 1;i++) {
		int min = i;
		
		for (int j = i + 1; j < t; j++) {
			if (arr[j]._id < arr[min]._id) {
				min = j;
			}
		}
		if (min != i) {
			arrei[min] = arr[min];
			arr[min] = arr[i];
			arr[i] = arrei[min];
		}
	}
	for (int p = 0; p < t - 1; p++) {
		std::cout << arr[p]._id;
	}
}

void HeapSort(GameObject arr[]) {

}

void QuickSort(GameObject arr[]) {

}

void RellenarMapa(int arr[10][10]) {
	int random;
	int contador = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0;j < 10; j++) {
			random = rand() % 9;
			if (contador < 20 && random == 1) {
				contador = contador + 1;
				arr[i][j] = 1;
			}
			else {
				arr[i][j] = 0;
			}
			std::cout <<"|_"<< arr[i][j]<<"_";
		}			
		std::cout <<"|"<< std::endl;
	}
}

void ContarMinas(int arr[10][10]) {

}
void print(int arr[10][10]) {

}

int main() {
	int arr[10][10];
	srand(time(NULL));
	RellenarMapa(arr);
	ContarMinas(arr);	
	
	//SelectionSort(arr1, 8);
	////inicializa todo lo necesario para el juego
	//init_game();

	//SelectionSort(arr1, 30);

	//Ciclo principal del juego
	//while (1) {
	//	getInput();
	//	if (exitKeyPressed()) {
	//		break;
	//	}
	//		update();
	//		render();
	//}
	//std::cout << "Hello World!" << std::endl;
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

