/*
 * Dato.h
 *
 *  Created on: 24/5/2016
 *      Author: matu
 */

#ifndef DATO_H_
#define DATO_H_

#include <string>


    struct Dato {
	int id;
	char codigo[3];
	char descripcion[1000];
	void guardar(int id, char codigo[], char desc[]) {
		this->id = id;
		this->codigo= codigo;
		this->descripcion=desc;
	}

    } dato;


#endif /* DATO_H_ */
