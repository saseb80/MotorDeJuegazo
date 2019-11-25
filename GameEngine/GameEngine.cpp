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

//Declaracion de los gameobjects para los sort
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

//int Partition(GameObject goArray[], int low, int high) {
//	GameObject pivot;
//	pivot = goArray[high];
//	int i = (low - 1);
//	for (int j = low; j <= high - 1; j++) {
//		if (goArray[j].GetID() < pivot.GetID()) {
//			i++;
//			Swapping(goArray[i], goArray[j]);
//		}
//	}
//	Swapping(goArray[i + 1], goArray[high]);
//	return (i + 1);
//}
//
//void QuickSort(GameObject goArray[], int low, int high) {
//	if (low < high) {
//		int pIndex = Partition(goArray, low, high);
//		QuickSort(goArray, low, pIndex - 1);
//		QuickSort(goArray, pIndex + 1, high);
//	}
//}

//void Heapify(GameObject arr[], int size, int i) {
//	int largest = i;
//	int l = 2 * i + 1;
//	int r = 2 * i + 2;
//	if (l < size && arr[l]._id > arr[largest]._id) {
//		largest = l;
//	}
//	if (r < size && arr[r]._id > arr[largest]._id) {
//		largest = r;
//	}
//	if (largest != i) {
//		Swapping(arr[i], arr[largest]);
//		Heapify(arr, size, largest);
//	}
//}
//
//void HeapSort(GameObject arr[], short size) {
//	for (int i = size / 2 - 1; i >= 0; i--) {
//		Heapify(arr, size, i);
//	}
//	for (int i = size - 1; i >= 0; i--) {
//		Swapping(arr[0], arr[i]);
//		Heapify(arr, i, 0);
//	}
//}

void QuickSort(GameObject arr[]) {

}

//rellena el mapa de buscaminas de forma aleatoria
void RellenarMapa(int arr[10][10],int nBombas) {
	int random;
	int contador = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0;j < 10; j++) {
			//rand es un numero aleatorio entre 0 y 9
			random = rand() % 7;
			//El contador limita el numero de bombas
			if (contador < nBombas && random == 1) {
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

void cm(int arr[10][10],int f,int c) {

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++){
			if (arr[i][j] == 0) {

			}
		}
	}
}

void ContarMinas(int arr[10][10]) {
	int array[10][10];
	int val;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			//cuando esta enmedio
			val = 0;
			if (arr[i][j] == 0 && i > 0 && j > 0) {
				val = array[i - 1][j] + array[i + 1][j + 1] + array[i][j + 1] + array[i - 1][j + 1] +
					  array[i + 1][j] + array[i + 1][j - 1] + array[i][j - 1] + array[i - 1][j - 1];
				arr[i][j] = val;
			}
			else if(arr[i][j] == 0 && i == 0&& j == 0){
				val = array[i+1][j] + array[i+1][j+1] + array[i][j+1];
				array[i][j];
				arr[i][j] = val;
			}
			
			std::cout << "|_" << arr[i][j] << "_";
		}
		std::cout << "|" << std::endl;
	}
}

int main() {
	int arr[10][10];
	srand(time(NULL));
	RellenarMapa(arr,23);
	std::cout << std::endl;
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

