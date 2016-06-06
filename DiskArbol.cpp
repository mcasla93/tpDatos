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
	ofstream escritura("temporal",ios::app);
	ifstream lectura(RUTAARCHIVO.c_str(),ios::in | ios::binary);

	while(!lectura.eof()) {
		Dato dato;
		lectura.read(reinterpret_cast<char *>(&dato),sizeof(struct Dato));
		if(lectura.eof())
			break;

		if (datoAEliminar.id != dato.id){
			escritura.write(reinterpret_cast<char *>(&dato),sizeof(struct Dato));
		}
	}

	lectura.close();
	escritura.close();

	rename("temporal",RUTAARCHIVO.c_str());

	return true;
}

bool DiskArbol::modificar(Dato datoActual, Dato datoNuevo) {
	ofstream escritura("temporal",ios::app);
	ifstream lectura(RUTAARCHIVO.c_str(),ios::in | ios::binary);

	while(!lectura.eof()) {
		Dato dato;
		lectura.read(reinterpret_cast<char *>(&dato),sizeof(struct Dato));
		if(lectura.eof())
			break;

		if (datoActual.id != dato.id){
			escritura.write(reinterpret_cast<char *>(&dato),sizeof(struct Dato));
		}else escritura.write(reinterpret_cast<char *>(&datoNuevo),sizeof(struct Dato));
	}

	lectura.close();
	escritura.close();

	rename("temporal",RUTAARCHIVO.c_str());

	return true;
}

bool DiskArbol::consultarId(int idAConsultar, Dato *datoConsultado) {
	ifstream lectura(RUTAARCHIVO.c_str(),ios::in | ios::binary);
	bool result = false;

	while(!lectura.eof()) {
		Dato dato;
		lectura.read(reinterpret_cast<char *>(&dato),sizeof(struct Dato));

		if(lectura.eof())
			break;

		if (idAConsultar == dato.id){
			datoConsultado->cargar(dato.id,dato.codigo,dato.descripcion);
			result = true;
		}
	}

	lectura.close();

	return result;
}

bool DiskArbol::consultarCodigo(char codigoAConsultar[3], Dato *datoConsultado) {
	ifstream lectura(RUTAARCHIVO.c_str(),ios::in | ios::binary);
	bool result = false;

	while(!lectura.eof()) {
		Dato dato;
		lectura.read(reinterpret_cast<char *>(&dato),sizeof(struct Dato));

		if(lectura.eof())
			break;

		if (strcmp(codigoAConsultar,dato.codigo)==0){
			datoConsultado->cargar(dato.id,dato.codigo,dato.descripcion);
			result = true;
		}
	}

	lectura.close();

	return result;
}

bool DiskArbol::consultarDescripcion(char descripcionAConsultar[1000], Dato *datoConsultado) {
	ifstream lectura(RUTAARCHIVO.c_str(),ios::in | ios::binary);
	bool result = false;

	while(!lectura.eof()) {
		Dato dato;
		lectura.read(reinterpret_cast<char *>(&dato),sizeof(struct Dato));

		if(lectura.eof())
			break;

		if (strcmp(descripcionAConsultar,dato.descripcion)==0){
			datoConsultado->cargar(dato.id,dato.codigo,dato.descripcion);
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
