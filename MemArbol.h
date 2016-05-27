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
	Btree<int,5> arbol;
public:
	MemArbol();
	bool insertar(int datoAInsertar);
	bool eliminar(int datoAEliminar);
	bool consultar(int datoAConsultar);
	void imprimir();
	virtual ~MemArbol();
};

#endif /* MEMARBOL_H_ */
