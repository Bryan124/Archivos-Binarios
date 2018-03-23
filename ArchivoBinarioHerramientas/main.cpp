#include <iostream>
#include <string>
#include "Herramienta.h"

using namespace std;

int main() {
	int opcion;
	creararchivo();
	do {
		cout << "* * * * * M E N U * * * * *" << endl;
		cout << "1. Imprimir Registro de Herramienta" << endl;
		cout << "2. Registrar Herramienta" << endl;
		cout << "3. Modificar Herramienta" << endl;
		cout << "4. Eliminar Herramienta" << endl;
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

	} while (opcion != 0);

	system("pause>NUL");
}