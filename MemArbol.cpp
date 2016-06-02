/*
 * MemArbol.cpp
 *
 *  Created on: 24/5/2016
 *      Author: matu
 */

#include "MemArbol.h"

MemArbol::MemArbol() {

}

bool MemArbol::insertar(Dato datoAInsertar) {
	this->arbol.insertar(datoAInsertar);
	return true;
}

bool MemArbol::eliminar(Dato datoAEliminar) {
	this->arbol.remover(datoAEliminar);
	return true;
}

bool MemArbol::consultarId(int idAConsultar) {
	Dato datoConsultado;
	if (this->arbol.buscarId(idAConsultar, &datoConsultado)){
		datoConsultado.imprimir();
		cout << "encontre" << endl;
	}
	return true;
}

bool MemArbol::consultarCodigo(char codigoAConsultar[3]) {
	/*Dato datoConsultado;
	if (this->arbol.buscarId(codigoAConsultar, &datoConsultado)){
		datoConsultado.imprimir();
		cout << "encontre" << endl;
	}*/
	return true;
}

bool MemArbol::consultarDescripcion(char descripcionAConsultar[1000]) {
	/*Dato datoConsultado;
	if (this->arbol.buscarId(descripcionAConsultar, &datoConsultado)){
		datoConsultado.imprimir();
		cout << "encontre" << endl;
	}*/
	return true;
}


void MemArbol::imprimir() {
	this->arbol.mostrarArbol();
}

MemArbol::~MemArbol() {
	// TODO Auto-generated destructor stub
}

