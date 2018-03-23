#include "Herramienta.h"
#include <fstream>
#include <iostream>

using namespace std;
int pos = 0;
void creararchivo(){
	ofstream archivoOut("Herramienta.txt", ios::out | ios::app | ios::binary);
	if (!archivoOut) {
		cout << "ERROR ARCHIVO" << endl;
		return;
	}
	for (int x = 0; x < 100; x++) {
		Herramienta nuevo;
		nuevo.codigo = -1;
		strcpy(nuevo.nombre, "");
		nuevo.catidad = -1;
		nuevo.precio = -1;
		archivoOut.write(reinterpret_cast<const char *>(&nuevo), sizeof(Herramienta));
	}
	archivoOut.close();
}
void imprimirlista(){
	ifstream archivoIn("Herramienta.txt", ios::in | ios::binary);
	if (!archivoIn) {
		cout << "ERROR ARCHIVO" << endl;
		return;
	}
	archivoIn.seekg(0, ios::beg);
	int tamano = sizeof(Herramienta);
	cout << "\n\n * * * * * R E G I S T R O  D E  H E R R A M I E N T A S * * * * * \n\n";
	Herramienta actual;
	archivoIn.read(reinterpret_cast<char *>(&actual), sizeof(Herramienta));
	while (!archivoIn.eof())
	{
		cout << "Codigo: " << actual.codigo << "  ";
		cout << "Nombre: " << actual.nombre << "  ";
		cout << "Cantidad: " << actual.catidad << "  ";
		cout << "Precio: " << actual.precio 
		<< "\n--------------------------------------------------------------------\n";
		archivoIn.read(reinterpret_cast<char *>(&actual), sizeof(Herramienta));
	}
	archivoIn.close();
}
void agregar(){
	fstream archivoOut("Herramienta.txt", ios::in | ios::out | ios::binary);
	if (!archivoOut) {
		cout << "ERROR ARCHIVO" << endl;
		return;
	}
	archivoOut.seekp((pos) * sizeof(Herramienta), ios::beg);
	Herramienta nuevo;
	cout << "\nIngrese codigo: ";
	cin >> nuevo.codigo;
	cout << "Ingrese nombre: ";
	cin >> nuevo.nombre;
	cout << "Ingrese cantidad: ";
	cin >> nuevo.catidad;
	cout << "Ingrese precio: ";
	cin >> nuevo.precio;
	archivoOut.write(reinterpret_cast<const char *>(&nuevo), sizeof(Herramienta));
	cout << "HERRAMIENTA GUARDADA!" << endl;
	archivoOut.close();
	pos++;
}
int buscar(int x) {
	int tmpos = 0;
	ifstream archivoIn("Herramienta.txt", ios::in | ios::binary);
	if (!archivoIn) {
		cout << "ERROR ARCHIVO" << endl;
		return -1;
	}
	archivoIn.seekg(0, ios::beg);

	Herramienta actual;
	archivoIn.read(reinterpret_cast<char *>(&actual), sizeof(Herramienta));
	while (!archivoIn.eof()){
		if (actual.codigo == x) {
			return tmpos;
		}
		else {
			tmpos++;
		}
		archivoIn.read(reinterpret_cast<char *>(&actual), sizeof(Herramienta));
	}
	archivoIn.close();
	return -1;
}
void eliminar() {
	int cod;
	int pos;
	fstream modArchivo("Herramienta.txt", ios::in | ios::out | ios::binary);
	if (!modArchivo) {
		cout << "ERROR ARCHIVO" << endl;
		return;
	}
	cout << "Ingrese codigo de registro de la herramienta: ";
	cin >> cod;
	pos = buscar(cod);
	cout << pos << endl;
	modArchivo.seekp((pos) * sizeof(Herramienta), ios::beg);
	Herramienta nuevo;
	nuevo.codigo = -1;
	strcpy(nuevo.nombre, "");
	nuevo.catidad = -1;
	nuevo.precio = -1;
	modArchivo.write(reinterpret_cast<const char *>(&nuevo), sizeof(Herramienta));
	modArchivo.close();
}
void modificar() {
	int cod;
	int pos;
	fstream modArchivo("Herramienta.txt", ios::in | ios::out | ios::binary);
	if (!modArchivo) {
		cout << "ERROR ARCHIVO" << endl;
		return;
	}
	cout << "Ingrese codigo de registro de la herramienta: ";
	cin >> cod;
	pos = buscar(cod);
	cout << pos << endl;
	modArchivo.seekp((pos) * sizeof(Herramienta), ios::beg);
	Herramienta nuevo;
	cout << "\nIngrese codigo: ";
	cin >> nuevo.codigo;
	cout << "Ingrese nombre: ";
	cin >> nuevo.nombre;
	cout << "Ingrese cantidad: ";
	cin >> nuevo.catidad;
	cout << "Ingrese precio: ";
	cin >> nuevo.precio;
	modArchivo.write(reinterpret_cast<const char *>(&nuevo), sizeof(Herramienta));
	modArchivo.close();
}
