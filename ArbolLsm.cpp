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
		//ver el tema de insertar en c1 si falla c0
	}
}

void ArbolLsm::eliminar(int datoAEliminar) {
	if (!this->c0.eliminar(datoAEliminar)) {
			//ver el tema de eliminar en c1 si falla c0
		}
}

void ArbolLsm::consultar(int datoAConsultar) {
	if (!this->c0.consultar(datoAConsultar)) {
			//ver el tema de consultar en c1 si falla c0
		}
}

void ArbolLsm::imprimir() {
	c0.imprimir();
}

ArbolLsm::~ArbolLsm() {
	// TODO Auto-generated destructor stub
}

