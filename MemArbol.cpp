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

bool MemArbol::modificar(Dato datoActual, Dato datoNuevo) {
	this->arbol.modificar(datoActual, datoNuevo);

	return true;
}

bool MemArbol::consultarId(int idAConsultar, Dato* datoConsultado) {
	return this->arbol.buscarId(idAConsultar, datoConsultado);
}

bool MemArbol::consultarCodigo(char codigoAConsultar[3], Dato* datoConsultado) {
	return this->arbol.buscarCodigo(codigoAConsultar, datoConsultado);
}

bool MemArbol::consultarDescripcion(char descripcionAConsultar[1000], Dato* datoConsultado) {
	return this->arbol.buscarDescripcion(descripcionAConsultar, datoConsultado);
}

void MemArbol::imprimir() {
	this->arbol.mostrarArbol();
}

void MemArbol::guardarEnArchivo(string direccionArchivo){
	arbol.guardarEnArchivo(direccionArchivo);
}

MemArbol::~MemArbol() {
}

