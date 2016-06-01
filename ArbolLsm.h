/*
 * ArbolLsm.h
 *
 *  Created on: 24/5/2016
 *      Author: matu
 */

#ifndef ARBOLLSM_H_
#define ARBOLLSM_H_

#include "MemArbol.h"
#include "DiskArbol.h"

class ArbolLsm {
private:
	MemArbol c0;
	DiskArbol c1;
public:
	ArbolLsm();
	void insertar(Dato datoAInsertar);
	void eliminar(Dato datoAEliminar);
	void consultar(Dato datoAConsultar);
	void imprimir();
	virtual ~ArbolLsm();
};

#endif /* ARBOLLSM_H_ */
