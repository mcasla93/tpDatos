/*
 * DiskArbol.cpp
 *
 *  Created on: 24/5/2016
 *      Author: matu
 */

#include "DiskArbol.h"
#include <iostream>

using namespace std;

DiskArbol::DiskArbol() {

}

bool DiskArbol::insertar(int datoAInsertar) {
	this->archivo.open("diskArbol.info");
	this->archivo << datoAInsertar << endl;
	this->archivo.close();
	return true;
}

bool DiskArbol::eliminar(int datoAEliminar) {
	this->archivo.open("diskArbol.info");
	// procedimiento para eliminar del archivo
	this->archivo.close();
	return true;
	return true;
}

bool DiskArbol::consultar(int datoAConsultar) {
	this->archivo.open("diskArbol.info");
	// procedimiento para buscar en archivo
	this->archivo.close();
	return true;
	return true;
}

void DiskArbol::imprimir() {
	this->archivo.open("diskArbol.info");
	cout << "ARCHIVOOOOOOOOOOOOOOO" << ends;
	while(!this->archivo.eof()) {
		char cadena[128];
		this->archivo.getline(cadena, 128);
		cout << cadena << ends;
	}

	this->archivo.close();
}

DiskArbol::~DiskArbol() {
	// TODO Auto-generated destructor stub
}
