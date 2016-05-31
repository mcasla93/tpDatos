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

int main() {
	ArbolLsm arbol;
	Dato dato;

	char* cod = "2";
	char* desc = "pablito";
	dato.cargar(1,cod,desc);
	arbol.insertar(dato);

	cod = "3";
	desc = "matu";
	dato.cargar(2,cod,desc);
	arbol.insertar(dato);

	//arbol.insertar(58);
	//arbol.insertar(9);

	arbol.imprimir();

	return 0;
}
