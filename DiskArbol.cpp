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
	this->archivo.open(RUTA.c_str(),ofstream::out);
}

bool DiskArbol::insertar(int datoAInsertar) {
	//this->archivo.open(RUTA.c_str(),ofstream::out);

	this->archivo << datoAInsertar << endl;

	//this->archivo.close();
	return true;
}

bool DiskArbol::eliminar(int datoAEliminar) {
	//this->archivo.open("diskArbol.info");
	// procedimiento para eliminar del archivo
	//this->archivo.close();
	return true;
}

bool DiskArbol::consultar(int datoAConsultar) {
	//this->archivo.open("diskArbol.info");
	// procedimiento para buscar en archivo
	//this->archivo.close();
	return true;
}

void DiskArbol::imprimir() {
	this->archivo.close();
	this->archivo.open(RUTA.c_str(),ifstream::in);
	//this->archivo.seekg(0,ios_base::beg);

	while(!this->archivo.eof()) {
		int dato;
		this->archivo >> dato;
		cout << dato << endl;
	}
	this->archivo.close();
	cout << "sali guachen" << endl;
}

DiskArbol::~DiskArbol() {
	// TODO Auto-generated destructor stub
}
