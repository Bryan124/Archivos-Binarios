#include <iostream>
#include <string>
#include "Herramienta.h"

using namespace std;

int main() {
	int opcion;
	//Cada vez que se ejecuta genera otros 100 espacios vacios, para evitar esto se puede comentar la funcion creararchivo();
	creararchivo();
	do {
		cout << "* * * * * M E N U * * * * *" << endl;
		cout << "1. Imprimir Registro de Herramienta" << endl;
		cout << "2. Registrar Herramienta" << endl;
		cout << "3. Modificar Herramienta" << endl;
		cout << "4. Eliminar Herramienta" << endl;
		cout << "5. Salir" << endl;
		cin >> opcion;
		switch (opcion) {
		case 1: {
			imprimirlista();
			system("pause>NUL");
			break;
		}
		case 2: {
			agregar();
			system("pause>NUL");
			break;
		}
		case 3: {
			modificar();
			system("pause>NUL");
			break;
		}
		case 4: {
			eliminar();
			system("pause>NUL");
			break;
		}
		}
	} while (opcion != 5);
	system("pause>NUL");
}