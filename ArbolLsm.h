/*
 * ArbolLsm.h
 *
 *  Created on: 24/5/2016
 *      Author: matu
 */

#ifndef ARBOLLSM_H_
#define ARBOLLSM_H_

#include "Dato.h"
#include "MemArbol.h"
#include "DiskArbol.h"

class ArbolLsm {
private:
	MemArbol c0;
	DiskArbol c1;
public:
	ArbolLsm();
	void insertar(int datoAInsertar);
	void eliminar(int datoAEliminar);
	void consultar(int datoAConsultar);
	void imprimir();
	virtual ~ArbolLsm();
};

#endif /* ARBOLLSM_H_ */
