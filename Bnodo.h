/*
 * Bnodo.h
 *
 *  Created on: 31/05/2016
 *      Author: pablo
 */

#ifndef BNODO_H_
#define BNODO_H_

#include "Dato.h"

namespace std {

class Bnodo {

private:
	int count;
	int orden;
	Dato dato[orden-1];
	Bnodo *hijos[orden];

public:
	Bnodo();
	virtual ~Bnodo();
};

} /* namespace std */

#endif /* BNODO_H_ */
