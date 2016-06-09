/*
 * ArbolLsm.cpp
 *
 *  Created on: 24/5/2016
 *      Author: matu
 */

#include "ArbolLsm.h"
#include "Dato.h"
#include "MemArbol.h"
#include "DiskArbol.h"

ArbolLsm::ArbolLsm() {
}

void ArbolLsm::insertar(Dato datoAInsertar) {
	if (!this->c0.insertar(datoAInsertar)) {
		if (!this->c1.insertar(datoAInsertar)){
			//si entra aca es xq es dato duplicado
		}
	}
}

void ArbolLsm::eliminar(Dato datoAEliminar) {
	if (!this->c0.eliminar(datoAEliminar)) {
		if (!this->c1.eliminar(datoAEliminar)){
			//si entra aca es xq no existe el dato a borrar
		}
	}
}

void ArbolLsm::modificar(Dato datoActual, Dato datoNuevo) {
	if (!this->c0.modificar(datoActual,datoNuevo)) {
		if (!this->c1.modificar(datoActual,datoNuevo)){
			//si entra aca es xq no existe el dato a borrar
		}
	}
}

Dato ArbolLsm::consultarId(int idAConsultar) {
	Dato datoConsultado;
	if (!this->c0.consultarId(idAConsultar,&datoConsultado)) {
		if (!this->c1.consultarId(idAConsultar,&datoConsultado)){
			//si entra aca es xq no existe el dato a consultar me oiste
		}
	}
	return datoConsultado;
}

Dato ArbolLsm::consultarCodigo(char codigoAConsultar[3]) {
	Dato datoConsultado;
	if (!this->c0.consultarCodigo(codigoAConsultar,&datoConsultado)) {
		if (!this->c1.consultarCodigo(codigoAConsultar,&datoConsultado)){
			//si entra aca es xq no existe el dato a consultar me oiste
		}
	}
	return datoConsultado;
}

Dato ArbolLsm::consultarDescripcion(char descripcionAConsultar[1000]) {
	Dato datoConsultado;
	if (!this->c0.consultarDescripcion(descripcionAConsultar,&datoConsultado)) {
		if (!this->c1.consultarDescripcion(descripcionAConsultar,&datoConsultado)){
			//si entra aca es xq no existe el dato a consultar me oiste
		}
	}
	return datoConsultado;
}

void ArbolLsm::imprimir() {
	c0.imprimir();
	c1.imprimir();
}

void ArbolLsm::guardarEnArchivo(string direccionArchivo){
	//solo guardo el arbolb dsps hay q adaptar el del archivo
	c0.guardarEnArchivo(direccionArchivo);
}

ArbolLsm::~ArbolLsm() {
	// TODO Auto-generated destructor stub
}

