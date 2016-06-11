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

void ArbolLsm::guardarEnDisco(){
	this->c0.guardarEnArchivo(c1.rutaArchivo());
	c0.vaciar();
}

void ArbolLsm::insertar(Dato datoAInsertar) {
	if (!this->c0.insertar(datoAInsertar))
		this->guardarEnDisco();
}


void ArbolLsm::eliminar(Dato datoAEliminar) {
	if (!this->c0.eliminar(datoAEliminar)) {
		this->c1.eliminar(datoAEliminar);
	}
}

void ArbolLsm::modificar(Dato datoActual, Dato datoNuevo) {
	if (!this->c0.modificar(datoActual,datoNuevo)) {
		this->c1.modificar(datoActual,datoNuevo);
	}

}

Dato ArbolLsm::consultarId(int idAConsultar) {
	Dato datoConsultado;
	datoConsultado.cargar(-1,"-1","NULL");
	if (!this->c0.consultarId(idAConsultar,&datoConsultado)) {
		if (!this->c1.consultarId(idAConsultar,&datoConsultado)){
			//si entra aca es xq no existe el dato a consultar me oiste
		}
	}
	return datoConsultado;
}

Dato ArbolLsm::consultarCodigo(char codigoAConsultar[3]) {
	Dato datoConsultado;
	datoConsultado.cargar(-1,"-1","NULL");
	if (!this->c0.consultarCodigo(codigoAConsultar,&datoConsultado)) {
		if (!this->c1.consultarCodigo(codigoAConsultar,&datoConsultado)){
			//si entra aca es xq no existe el dato a consultar
		}
	}
	return datoConsultado;
}

Dato ArbolLsm::consultarDescripcion(char descripcionAConsultar[1000]) {
	Dato datoConsultado;
	datoConsultado.cargar(-1,"-1","NULL");
	if (!this->c0.consultarDescripcion(descripcionAConsultar,&datoConsultado)) {
		if (!this->c1.consultarDescripcion(descripcionAConsultar,&datoConsultado)){
			//si entra aca es xq no existe el dato a consultar
		}
	}
	return datoConsultado;
}

void ArbolLsm::imprimir() {
	c0.imprimir();
	c1.imprimir();
}

bool ArbolLsm::memoriaLlena(){
    return c0.memoriaLlena();
}


void ArbolLsm::guardarEnArchivo(string direccionArchivo){
	//solo guardo el arbolb dsps hay q adaptar el del archivo
	c0.guardarEnArchivo(direccionArchivo);
	c1.guardarEnArchivo(direccionArchivo);
}

ArbolLsm::~ArbolLsm() {
	// TODO Auto-generated destructor stub
}

