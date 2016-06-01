/*
 * MemArbol.h
 *
 *  Created on: 24/5/2016
 *      Author: matu
 */

#ifndef MEMARBOL_H_
#define MEMARBOL_H_

#include <string>
#include <iostream>
#include "Btree.h"
#include "Dato.h"

using namespace std;

class MemArbol {
private:
	Btree<Dato,5> arbol;
public:
	MemArbol();
	bool insertar(Dato datoAInsertar);
	bool eliminar(Dato datoAEliminar);
	bool consultar(Dato datoAConsultar);
	void imprimir();
	virtual ~MemArbol();
};

#endif /* MEMARBOL_H_ */
