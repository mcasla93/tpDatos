/*
 * Dato.h
 *
 *  Created on: 24/5/2016
 *      Author: matu
 */

#ifndef DATO_H_
#define DATO_H_

#include <string>

class Dato {
private:
	int id;
	char codigo[3];
	char descripcion[1000];
public:
	Dato(int id,char codigo[3],char descripcion[1000]);
	virtual ~Dato();
};

#endif /* DATO_H_ */
