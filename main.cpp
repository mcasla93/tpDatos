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

	arbol.insertar(6);
	arbol.insertar(58);
	arbol.insertar(9);

	arbol.imprimir();

	return 0;
}
