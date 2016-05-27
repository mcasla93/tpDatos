/*
 * Dato.cpp
 *
 *  Created on: 24/5/2016
 *      Author: matu
 */

#include <iostream>
#include <string>
#include <cstring>
#include <memory>
#include "Dato.h"

Dato::Dato(int id,char codigo[3],char descripcion[1000]) {
	this->id = id;
	strcpy(this->codigo, codigo);
	strcpy(this->descripcion, descripcion);
}

Dato::~Dato() {
	// TODO Auto-generated destructor stub
}

