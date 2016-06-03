/*
 * ArbolLsm.h
 *
 *  Created on: 24/5/2016
 *      Author: matu
 */

#ifndef ARBOLLSM_H_
#define ARBOLLSM_H_

#include <iostream>
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
	void consultarId(int idAConsultar);
	void consultarCodigo(char codigoAConsultar[3]);
	void consultarDescripcion(char descripcionAConsultar[1000]);
	void imprimir();
	virtual ~ArbolLsm();
};

#endif /* ARBOLLSM_H_ */
