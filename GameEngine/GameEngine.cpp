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
 
//pa swapear 2 elementos
void Cambiar(GameObject &a, GameObject &b) {
	GameObject temp;
	temp = a;
	a = b;
	b = temp;

}

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

//agarra 2 pivotes y los separa 2 arrays
int Partition(GameObject arr[], int low, int high) {
	GameObject pivote;
	pivote = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++) {
		if (arr[j]._id < pivote._id) {
			i++;
			Cambiar(arr[i], arr[j]);
		}
	}
	Cambiar(arr[i + 1], arr[high]);
	return (i + 1);
}

void QuickSort(GameObject arr[], int low, int high) {
	if (low < high) {
		int index = Partition(arr, low, high);
		QuickSort(arr, low, index - 1);
		QuickSort(arr, index + 1, high);
	}
}

//escoge el nuevo pivote
void Heapify(GameObject arr[], int size, int i) {
	int largest = i;
	int izq = 2 * i + 1;
	int der = 2 * i + 2;
	if (izq < size && arr[izq]._id > arr[largest]._id) {
		largest = izq;
	}
	if (der < size && arr[der]._id > arr[largest]._id) {
		largest = der;
	}
	if (largest != i) {
		Cambiar(arr[i], arr[largest]);
		Heapify(arr, size, largest);
	}
}

//se forma un arbol y se toma la root para comparar
void HeapSort(GameObject arr[], short size) {
	for (int i = size / 2 - 1; i >= 0; i--) {
		Heapify(arr, size, i);
	}
	for (int i = size - 1; i >= 0; i--) {
		//Mueve la raiz al final
		Cambiar(arr[0], arr[i]);
		Heapify(arr, i, 0);
	}
}

void print(GameObject arr[], int size) {
	//esto ni se tiene que explicar ez :v
	for (int i = 0; i < size; i++) {
		std::cout<< arr[i]._id << " " << std::endl;
	}
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

//busca las bombas 
void cm(int arr[10][10], int x, int y) {
	int contador = 0;
	if (arr[x][y] == 0){
		cm(arr,x,y);
	}
	if (arr[x + 1][y] == 0){
		contador = arr[x-1][y] + arr[x][y];
		cm(arr, x + 1,y);
	}
	if (arr[x-1][y] == 0) {
		cm(arr,x-1,y);
	}
	if (arr[x][y+1] == 0) {
		cm(arr, x, y+1);
	}
	if (arr[x][y - 1] == 0) {
		cm(arr, x, y-1);
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
	//cm(arr,0,0);
	print(arr1,7);
	HeapSort(arr1,7);
	print(arr1,7);
	
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

