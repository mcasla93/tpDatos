/*
 * MemArbol.cpp
 *
 *  Created on: 24/5/2016
 *      Author: matu
 */

#include "MemArbol.h"

MemArbol::MemArbol() {
	limiteMemoria = 0;
}

bool MemArbol::insertar(Dato datoAInsertar) {
	  this->arbol.insertar(datoAInsertar);
	  this->limiteMemoria++;
	  if (this->memoriaLlena()){
		  return false;
	  }
	  return true;
}

bool MemArbol::eliminar(Dato datoAEliminar) {
	return this->arbol.remover(datoAEliminar);
}

bool MemArbol::modificar(Dato datoActual, Dato datoNuevo) {
	return this->arbol.modificar(datoActual, datoNuevo);
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

bool MemArbol::memoriaLlena(){
	if (this->limiteMemoria==4)
    	return true;
    return false;
}

void MemArbol::guardarEnArchivo(string direccionArchivo){
	arbol.guardarEnArchivo(direccionArchivo);
	limiteMemoria=0;
}

void MemArbol::vaciar(){
	arbol.vaciar();
}

MemArbol::~MemArbol() {
}

