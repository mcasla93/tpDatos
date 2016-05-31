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

bool MemArbol::eliminar(int datoAEliminar) {
	//this->arbol.remover(datoAEliminar);
	return true;
}

bool MemArbol::consultar(int datoAConsultar) {
	//this->arbol.buscar(datoAConsultar);
	return true;
}

void MemArbol::imprimir() {
	this->arbol.mostrarArbol();
}

MemArbol::~MemArbol() {
	// TODO Auto-generated destructor stub
}

