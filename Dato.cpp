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

using namespace std;

Dato::Dato() {
	this->id = 0;
}

void Dato::cargar(int id,char codigo[3],char descripcion[1000]) {
	this->id = id;
	strcpy(this->codigo, codigo);
	strcpy(this->descripcion, descripcion);
}

int Dato::identificador() {
	return this->id;
}

void Dato::imprimir() {
	cout <<"\t" << "|id:" << this->id << " cod:" << this->codigo << " desc:" << this->descripcion <<" | ";
}

Dato::~Dato() {
	// TODO Auto-generated destructor stub
}

