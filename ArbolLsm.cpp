/*
 * ArbolLsm.cpp
 *
 *  Created on: 24/5/2016
 *      Author: matu
 */

#include "ArbolLsm.h"

ArbolLsm::ArbolLsm() {
}

void ArbolLsm::insertar(int datoAInsertar) {
	if (!this->c0.insertar(datoAInsertar)) {
		if (!this->c1.insertar(datoAInsertar)){
			//si entra aca es xq es dato duplicado
		}
	}
}

void ArbolLsm::eliminar(int datoAEliminar) {
	if (!this->c0.eliminar(datoAEliminar)) {
		if (!this->c1.eliminar(datoAEliminar)){
			//si entra aca es xq no existe el dato a borrar
		}
	}
}

void ArbolLsm::consultar(int datoAConsultar) {
	if (!this->c0.consultar(datoAConsultar)) {
		if (!this->c1.consultar(datoAConsultar)){
			//si entra aca es xq no existe el dato a consultar me oiste
		}
	}
}

void ArbolLsm::imprimir() {
	c0.imprimir();
	c1.imprimir();
}

ArbolLsm::~ArbolLsm() {
	// TODO Auto-generated destructor stub
}

