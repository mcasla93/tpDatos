/*
 * DiskArbol.h
 *
 *  Created on: 24/5/2016
 *      Author: matu
 */

#ifndef DISKARBOL_H_
#define DISKARBOL_H_

#include <iostream>
#include <fstream>
#include <cstring>

const std::string RUTA = "diskArbol.txt";

class DiskArbol {
private:
	std::fstream archivo;
public:
	DiskArbol();
	bool insertar(int datoAInsertar);
	bool eliminar(int datoAEliminar);
	bool consultar(int datoAConsultar);
	void imprimir();
	virtual ~DiskArbol();
};


#endif /* DISKARBOL_H_ */
