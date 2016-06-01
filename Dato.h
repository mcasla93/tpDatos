/*
 * Dato.h
 *
 *  Created on: 24/5/2016
 *      Author: matu
 */

#ifndef DATO_H_
#define DATO_H_

#include <string>
#include <cstring>
#include <iostream>

using namespace std;

    struct Dato {
		int id;
		char codigo[3];
		char descripcion[1000];
		void cargar(int id, char codigo[3], char descripcion[1000]) {
			this->id = id;
			strcpy(this->codigo,codigo);
			strcpy(this->descripcion,descripcion);
		}
		void imprimir(){
			cout << "id:" << this->id << " cod:" << this->codigo << " dscr:" << this->descripcion << " | ";
		}
		int identificador(){
			return this->id;
		}
    };


#endif /* DATO_H_ */
