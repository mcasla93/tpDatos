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

bool DiskArbol::consultarId(int idAConsultar) {
	ifstream lectura(RUTAARCHIVO.c_str(),ios::in | ios::binary);
	bool result = false;

	while(!lectura.eof()) {
		Dato dato;
		lectura.read(reinterpret_cast<char *>(&dato),sizeof(struct Dato));

		if(lectura.eof())
			break;

		if (idAConsultar == dato.id){
			dato.imprimir();
			cout << endl;
			result = true;
		}
	}

	lectura.close();

	return result;
}

bool DiskArbol::consultarCodigo(char codigoAConsultar[3]) {
	ifstream lectura(RUTAARCHIVO.c_str(),ios::in | ios::binary);
	bool result = false;

	while(!lectura.eof()) {
		Dato dato;
		lectura.read(reinterpret_cast<char *>(&dato),sizeof(struct Dato));

		if(lectura.eof())
			break;

		if (strcmp(codigoAConsultar,dato.codigo)==0){
			dato.imprimir();
			cout << endl;
			result = true;
		}
	}

	lectura.close();

	return result;
}

bool DiskArbol::consultarDescripcion(char descripcionAConsultar[1000]) {
	ifstream lectura(RUTAARCHIVO.c_str(),ios::in | ios::binary);
	bool result = false;

	while(!lectura.eof()) {
		Dato dato;
		lectura.read(reinterpret_cast<char *>(&dato),sizeof(struct Dato));

		if(lectura.eof())
			break;

		if (strcmp(descripcionAConsultar,dato.descripcion)==0){
			dato.imprimir();
			cout << endl;
			result = true;
		}
	}

	lectura.close();

	return result;
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
