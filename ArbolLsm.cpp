/*
 * ArbolLsm.cpp
 *
 *  Created on: 24/5/2016
 *      Author: matu
 */

#include "ArbolLsm.h"
#include "MemArbol.h"
#include "DiskArbol.h"

ArbolLsm::ArbolLsm() {
}

void ArbolLsm::insertar(Dato datoAInsertar) {
	//if (!this->c0.insertar(datoAInsertar)) {
		if (!this->c1.insertar(datoAInsertar)){
			//si entra aca es xq es dato duplicado
		}
	//}
}

void ArbolLsm::eliminar(Dato datoAEliminar) {
	if (!this->c0.eliminar(datoAEliminar)) {
		if (!this->c1.eliminar(datoAEliminar)){
			//si entra aca es xq no existe el dato a borrar
		}
	}
}

void ArbolLsm::consultarId(int consultarId) {
	//if (!this->c0.consultarId(datoAConsultar)) {
		if (!this->c1.consultarId(consultarId)){
			//si entra aca es xq no existe el dato a consultar me oiste
		}
	//}
}

void ArbolLsm::consultarCodigo(char codigoAConsultar[3]) {
	//if (!this->c0.consultarCodigo(codigoAConsultar)) {
		if (!this->c1.consultarCodigo(codigoAConsultar)){
			//si entra aca es xq no existe el dato a consultar me oiste
		}
	//}
}

void ArbolLsm::consultarDescripcion(char descripcionAConsultar[1000]) {
	//if (!this->c0.consultarDescripcion(descripcionAConsultar)) {
		if (!this->c1.consultarDescripcion(descripcionAConsultar)){
			//si entra aca es xq no existe el dato a consultar me oiste
		}
	//}
}

void ArbolLsm::imprimir() {
	//c0.imprimir();
	c1.imprimir();
}

ArbolLsm::~ArbolLsm() {
	// TODO Auto-generated destructor stub
}

