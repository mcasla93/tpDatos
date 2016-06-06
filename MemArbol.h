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
	bool modificar(Dato datoActual, Dato datoNuevo);
	bool consultarId(int idAConsultar, Dato *datoConsultado);
	bool consultarCodigo(char codigoAConsultar[3], Dato *datoConsultado);
	bool consultarDescripcion(char descripcionAConsultar[1000], Dato *datoConsultado);
	void imprimir();
	virtual ~MemArbol();
};

#endif /* MEMARBOL_H_ */
