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
	this->archivo.close();
}

bool DiskArbol::insertar(int datoAInsertar) {
	ofstream escritura("diskArbol.txt",ios::app);
	escritura << datoAInsertar << endl;
	escritura.close();
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
	ifstream lectura("diskArbol.txt");

	while(!lectura.eof()) {
		int dato;
		lectura >> dato;
		if(lectura.eof())
			break;
		cout << dato << endl;
	}

	lectura.close();
}

DiskArbol::~DiskArbol() {
	// TODO Auto-generated destructor stub
}
