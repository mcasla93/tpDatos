/*
 * DiskArbol.h
 *
 *  Created on: 24/5/2016
 *      Author: matu
 */

#ifndef DISKARBOL_H_
#define DISKARBOL_H_

#include "Dato.h"
#include <iostream>
#include <fstream>
#include <cstring>

const std::string RUTAARCHIVO = "diskArbol.dat";

class DiskArbol {
private:
	std::fstream archivo;
public:
	DiskArbol();
	bool insertar(Dato datoAInsertar);
	bool eliminar(Dato datoAEliminar);
	bool consultarId(int idAConsultar, Dato *datoConsultado);
	bool consultarCodigo(char codigoAConsultar[3], Dato *datoConsultado);
	bool consultarDescripcion(char descripcionAConsultar[1000], Dato *datoConsultado);
	void imprimir();
	virtual ~DiskArbol();
};


#endif /* DISKARBOL_H_ */
