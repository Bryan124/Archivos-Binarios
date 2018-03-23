#include <iostream>
#include <string>
#include "Herramienta.h"

using namespace std;

int main() {
	int opcion;
	//Cada vez que se ejecuta genera otros 10 espacios vacios, para evitar esto se puede comentar la funcion creararchivo();
	do {
		cout << "* * * * * M E N U * * * * *" << endl;
		cout << "1. Imprimir Registro de Herramienta" << endl;
		cout << "2. Registrar Herramienta" << endl;
		cout << "3. Modificar Herramienta" << endl;
		cout << "4. Eliminar Herramienta" << endl;
		cout << "5. Crear Registro de Herramientas" << endl;
		cout << "6. Salir" << endl;
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
		case 5: {
			cout << "Si selecciono esta opcion con anteoridad se generaran otros 100 espacios en el registro!!!" << endl;
			creararchivo();
		}
		}
	} while (opcion != 6);
	system("pause>NUL");
}