/*
 * main.cpp
 *
 *  Created on: 26/5/2016
 *      Author: matu
 */

#include <iostream>
#include "ArbolLsm.h"
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
	ArbolLsm arbol;
	Dato dato;

	dato.cargar(2,"2","pablo");
	arbol.insertar(dato);
	dato.cargar(1,"3","matu");
	arbol.insertar(dato);

	dato = arbol.consultarDescripcion("pablo");
	Dato datoNuevo;
	datoNuevo.cargar(dato.id,"22","descr nueva");

	arbol.modificar(dato,datoNuevo);
	arbol.imprimir();

	return 0;
}
