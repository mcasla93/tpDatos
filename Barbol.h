/*
 * Barbol.h
 *
 *  Created on: 31/05/2016
 *      Author: pablo
 */

#ifndef BARBOL_H_
#define BARBOL_H_

#include "Bnodo.h"

namespace std {

class Barbol {


	private:
	    Bnodo *raiz;
		void recInorder(B_node<Dato, order> * current );
		bool  Encontrar( B_node<Type, order> *current, Type &target);

	public: // publics.
		Barbol();
		void inOrder();
		bool buscar( Type &searchitem );
		void mostrarArbol();
		// insertion
		bool buscarEnNodo( B_node<Type, order> *current, const Type &target, int &position );
		void insertar(const Type &new_entry);
		void insertarEnRecursion( B_node<Type, order> *current, const Type &new_entry,Type &median,B_node<Type, order> * &rightchilds , bool &result );
		void insertarEnNodo(B_node<Type, order> *current, const Type &entry, B_node<Type, order> *rightchilds, int position);
		void dividirNodo( B_node<Type, order> *current,  const Type &extra_entry,   B_node<Type, order> *extra_childs,  int position,
			B_node<Type, order> * &right_half,   Type &median);
		// eliminacion

		void remover( const Type &target );
		void removerEnRecursion( B_node<Type, order> *current, const Type &target );
		void removerDato(  B_node<Type, order> *current, int position  );
		void copiarDePredecesor(  B_node<Type, order> *current, int position );
		// funciones para restaurar despues de la eliminacion
		void restaurar( B_node<Type, order> *current ,int position  );
		void moverAlaIzquierda( B_node<Type, order> *current , int position );
		void moverAlaDerecha( B_node<Type, order> *current , int position );
		void combinar( B_node<Type, order> *current, int position );

		void imprimirArbol( B_node<Type, order> *current );
		virtual ~Barbol();
	};


};

} /* namespace std */

#endif /* BARBOL_H_ */
