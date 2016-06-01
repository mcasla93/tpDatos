/*
 * DiskArbol.cpp
 *
 *  Created on: 24/5/2016
 *      Author: matu
 */

#include "DiskArbol.h"
#include <iostream>
#include <string>

using namespace std;

DiskArbol::DiskArbol() {
	// CREAR ARCHIVO
	this->archivo.open(RUTAARCHIVO.c_str(),ofstream::out);
	this->archivo.close();
}

bool DiskArbol::insertar(struct Dato datoAInsertar) {
	ofstream escritura(RUTAARCHIVO.c_str(),ios::app);

	escritura.write(reinterpret_cast<char *>(&datoAInsertar),sizeof(struct Dato));

	escritura.close();

	return true;
}

bool DiskArbol::eliminar(Dato datoAEliminar) {
	//this->archivo.open("diskArbol.info");
	// procedimiento para eliminar del archivo
	//this->archivo.close();
	return true;
}

bool DiskArbol::consultar(Dato datoAConsultar) {
	//this->archivo.open("diskArbol.info");
	// procedimiento para buscar en archivo
	//this->archivo.close();
	return true;
}

void DiskArbol::imprimir() {
	ifstream lectura(RUTAARCHIVO.c_str(),ios::in | ios::binary);

	while(!lectura.eof()) {
		Dato dato;
		lectura.read(reinterpret_cast<char *>(&dato),sizeof(struct Dato));

		if(lectura.eof())
			break;

		dato.imprimir();
	}

	lectura.close();
}

DiskArbol::~DiskArbol() {
	// TODO Auto-generated destructor stub
}
