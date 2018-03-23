#pragma once

#ifndef HERRAMIENTA
#define HERRAMIENTA

struct Herramienta {
	int codigo;			//4
	char nombre[30];	//30
	int catidad;		//4
	float precio;		//8
						//44
};

void creararchivo();
void agregar();
void modificar();
void eliminar();
int buscar(int);
void imprimirlista();

#endif // !HERRAMIENTA