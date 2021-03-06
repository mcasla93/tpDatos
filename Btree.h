#ifndef BTREE_H
#define BTREE_H
#include "B_node.h"
#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace std;

template <class Type, int order> class Btree {

protected: // dato members
	B_node<Type, order> *root;
	Type *cte;
private:
	void recInorder(B_node<Type, order> * current );
	void guardarInorder(B_node<Type, order> *current, ofstream *escritura);
	bool Encontrar( B_node<Type, order> *current, Type &target);
	bool EncontrarId( B_node<Type, order> *current, int idConsultado, Type *datoConsultado);
	bool EncontrarCodigo( B_node<Type, order> *current, char codigoConsultado[3], Type *datoConsultado);
	bool EncontrarDescripcion( B_node<Type, order> *current, char descripcionConsultada[1000], Type *datoConsultado);

public: // publics.
	Btree();
	// travesling
	void inOrder();
	bool buscar( Type &searchitem );
	bool buscarId( int idConsultado, Type *datoConsultado );
	bool buscarIdEnNodo(B_node<Type, order> *current, int idConsultado,int &position);
	bool buscarCodigo( char codigoConsultado[3], Type *datoConsultado );
	bool buscarDescripcion( char descripcionConsultada[1000], Type *datoConsultado );
	void mostrarArbol();
	// insertion
	bool buscarEnNodo( B_node<Type, order> *current, Type &target, int &position );
	void modificarId( Type &searchitem, int idNuevo);
	void modificarDescripcion( Type &searchitem, char descripcionNueva[1000]);
	void modificarCodigo(Type &searchitem, char codigoNuevo[3]);
	bool modificar(Type &searchitem, Type datoNuevo);
	void insertar(Type &new_entry);
	void insertarEnRecursion( B_node<Type, order> *current, Type &new_entry,Type &median,B_node<Type, order> * &rightchilds , bool &result );
	void insertarEnNodo(B_node<Type, order> *current, const Type &entry, B_node<Type, order> *rightchilds, int position);
	void dividirNodo( B_node<Type, order> *current,  const Type &extra_entry,   B_node<Type, order> *extra_childs,  int position, 
		B_node<Type, order> * &right_half,   Type &median);
	// eliminacion

	bool remover( Type &target );
	bool removerEnRecursion( B_node<Type, order> *current, Type &target );
	void removerDato(  B_node<Type, order> *current, int position  );
	void copiarDePredecesor(  B_node<Type, order> *current, int position );
	// funciones para restaurar despues de la eliminacion
	void restaurar( B_node<Type, order> *current ,int position  );
	void moverAlaIzquierda( B_node<Type, order> *current , int position );
	void moverAlaDerecha( B_node<Type, order> *current , int position );
	void combinar( B_node<Type, order> *current, int position );
	
	void imprimirArbol( B_node<Type, order> *current );

	void guardarEnArchivo(string direccionArchivo);

	void vaciar();
};

template <class Type, int order> Btree<Type,order>::Btree(){
	root = NULL;
	cte = NULL;
}

template <class Type, int order> void Btree<Type,order>::inOrder(){  
	return recInorder( root );   
}

template <class Type, int order> void Btree<Type,order>::recInorder(B_node<Type, order> * current ){
	if ( current != NULL )
	{
		recInorder( current->childs[0]);
		for (int i = 0; i < current->count; i++){
			//current->data[i].imprimir();
			recInorder(current->childs[i + 1]);
		}
	}
}

template <class Type, int order> bool Btree<Type,order>::buscarId(int idConsultado, Type *datoConsultado){
	return EncontrarId( root , idConsultado, datoConsultado );
}

template <class Type, int order> bool Btree<Type,order>::buscarCodigo(char codigoConsultado[3], Type *datoConsultado){
	return EncontrarCodigo( root , codigoConsultado, datoConsultado );
}

template <class Type, int order> bool Btree<Type,order>::buscarDescripcion(char descripcionConsultada[1000], Type *datoConsultado){
	return EncontrarDescripcion( root , descripcionConsultada, datoConsultado );
}

template <class Type, int order> bool Btree<Type,order>::Encontrar( B_node<Type, order> *current, Type &target ){
	bool result = false;
	int position;
	if (current != NULL) {
		result = buscarEnNodo(current, target, position);
		if (result == false)
			result = Encontrar(current->childs[position], target);
		else{
			target = current->data[position];//->getData();
			cte = &(current->data[position]);
		}
	}
	return result;
}

template <class Type, int order> bool Btree<Type,order>::EncontrarId(B_node<Type,order> *current,int idConsultado,Type *datoConsultado){
	bool result = false;
	int position;
	if (current != NULL) {
		result = buscarIdEnNodo(current, idConsultado, position);
		if (result == false)
			result = EncontrarId(current->childs[position], idConsultado, datoConsultado);
		else{
			datoConsultado->cargar(current->data[position].id, current->data[position].codigo, current->data[position].descripcion);
			//esto guarda en datoConsultado el dato consultado del arbol.
		}
	}
	return result;
}

template <class Type, int order> bool Btree<Type,order>::EncontrarCodigo(B_node<Type,order> *current, char codigoConsultado[3],Type *datoConsultado){
	bool result = false;
	if (current != NULL){
		EncontrarCodigo(current->childs[0],codigoConsultado,datoConsultado);
		for (int i = 0; i < current->count; i++){
			if (strcmp(codigoConsultado,current->data[i].codigo)==0){
				datoConsultado->cargar(current->data[i].id, current->data[i].codigo, current->data[i].descripcion);
				result = true;
				cte = &(current->data[i]);
				break;
			}
			EncontrarCodigo(current->childs[i + 1],codigoConsultado,datoConsultado);
		}
	}
	return result;
}

template <class Type, int order> bool Btree<Type,order>::EncontrarDescripcion(B_node<Type,order> *current, char descripcionConsultada[1000],Type *datoConsultado){
	bool result = false;

	if (current != NULL){
		EncontrarDescripcion(current->childs[0],descripcionConsultada,datoConsultado);
		for (int i = 0; i < current->count; i++){
			if (strcmp(descripcionConsultada,current->data[i].descripcion)==0){
				datoConsultado->cargar(current->data[i].id, current->data[i].codigo, current->data[i].descripcion);
				result = true;
				cte = &(current->data[i]);
				break;
			}
			EncontrarDescripcion(current->childs[i + 1],descripcionConsultada,datoConsultado);
		}
	}
	return result;
}

template <class Type, int order> bool Btree<Type,order>::buscarEnNodo( B_node<Type, order> *current, Type &target, int &position ){
	position=0;
	while ((position < current->count) && (target.identificador() > current->data[position].identificador()))
		position++; 
	if ((position < current->count) && (target.identificador() == current->data[position].identificador()))
		return true;
	else
		return false;
}

template <class Type, int order> bool Btree<Type,order>::buscarIdEnNodo(B_node<Type, order> *current,int idConsultado,int &position){
	position=0;
	while ((position < current->count) && (idConsultado > current->data[position].id))
		position++;
	if ((position < current->count) && (idConsultado == current->data[position].id)){
		return true;
	}else
		return false;
}

template <class Type, int order> void Btree<Type,order>::modificarId( Type &searchitem, int idNuevo){
	bool resultado;
	Type modificado;
	modificado->cargar(idNuevo,searchitem->codigo,searchitem->descripcion);
	remover( searchitem );
	insertar(modificado);
}

template <class Type, int order> void Btree<Type,order>::modificarDescripcion( Type &searchitem, char descripcionNueva[1000]){
	bool resultado;
	resultado = Encontrar( root , searchitem );
	if (resultado){
	    Type nuevo;
		nuevo.cargar(cte->id,cte->codigo,descripcionNueva);
		memcpy(cte,&nuevo,sizeof(Type));
	}
}

template <class Type, int order> void Btree<Type,order>::modificarCodigo( Type &searchitem, char codigoNuevo[3]){
	bool resultado;
	resultado = Encontrar( root , searchitem );
	if (resultado){
	    Type nuevo;
		nuevo.cargar(cte->id,codigoNuevo,cte->descripcion);
		memcpy(cte,&nuevo,sizeof(Type));
	}
}

template <class Type, int order> bool Btree<Type,order>::modificar(Type &searchitem, Type datoNuevo){
	if (cte==NULL) return false;

	memcpy(cte,&datoNuevo,sizeof(Type));
	return true;
}


template <class Type, int order> void Btree<Type,order>::insertar(Type &new_entry){
	Type median;
	B_node<Type, order> *rightchilds, *new_root;
	bool  result ; 
	insertarEnRecursion(root, new_entry, median, rightchilds , result);
	if(result) { 
		new_root = new B_node<Type, order>;
		new_root->count = 1;
		new_root->data[0] = median;
		new_root->childs[0] = root;
		new_root->childs[1] = rightchilds;
		root = new_root;
	}
}

template <class Type, int order> void Btree<Type,order>::insertarEnRecursion( B_node<Type, order> *current,
	Type &new_entry,Type &median,B_node<Type, order> * &rightchilds , bool &result ){

		int position;
		if (current == NULL) {

			median = new_entry;
			rightchilds = NULL;
			result = true;
		}
		else { 
			bool fl = buscarEnNodo(current, new_entry, position);
			if ( fl ){
				result = false;
				return; 
			}
			else {
				Type extra_entry;
				B_node<Type, order> *extra_childs;

				insertarEnRecursion(current->childs[position], new_entry,extra_entry, extra_childs , result);
				if ( result ) {
					if ( !current->NodeFull() ) {
						result = false;
						insertarEnNodo(current, extra_entry, extra_childs, position);
					}
					else 
						dividirNodo( current, extra_entry, extra_childs, position,rightchilds, median);
				}

			}
		}
}

template <class Type, int order> void Btree<Type,order>::insertarEnNodo(B_node<Type, order> *current,
	const Type &entry, B_node<Type, order> *rightchilds, int position){
		int i; 
		for(i=current->count-1;i>= position;i--){ 
			current->data[i+1]=current->data[i];
			current->childs[i+2]=current->childs[i+1]; 
		} 
		current->data[position]= entry; 
		current->childs[i+2]=rightchilds ;
		current->count++;
}

template <class Type, int order> void Btree<Type,order>::dividirNodo( B_node<Type, order> *current,  const Type &extra_entry,   B_node<Type, order> *extra_childs,  int position, 
	B_node<Type, order> * &right_half,   Type &median){

		right_half = new B_node<Type,order>;
		int mid = order/2;
		if( position <= mid ){
			for(int i = mid;i < order-1;i++ ){
				right_half->data[i-mid] = current->data[i];
				right_half->childs[i+1-mid] = current->childs[i+1];
			}
			current->count = mid;
			right_half->count = order-1-mid;
			insertarEnNodo( current , extra_entry , extra_childs , position );
		} else {
			mid++;
			for(int i = mid;i < order-1;i++ ){
				right_half->data[i-mid] = current->data[i];
				right_half->childs[i+1-mid] = current->childs[i+1];
			}
			current->count = mid;
			right_half->count = order-1-mid;
			insertarEnNodo( right_half , extra_entry , extra_childs , position - mid);
		}
		median = current->data[current->count - 1];
		right_half->childs[0] = current->childs[current->count];
		current->count--;
}

template <class Type, int order> bool Btree<Type,order>::remover( Type &target ){
	bool result;
	result = removerEnRecursion( root , target );
	if( root != NULL && root->count == 0 ){
		B_node<Type, order> *delete_root = root;
		root = root->childs[0];
		delete delete_root;
	}
	return result;
}

template <class Type, int order> bool Btree<Type,order>::removerEnRecursion( B_node<Type, order> *current, Type &target ){
	bool result = false;
	int position;
	if( current != NULL ){
		bool fl = buscarEnNodo( current , target ,position );
		if( fl ){
			if(current->childs[position] != NULL ){
				copiarDePredecesor( current , position );
				removerEnRecursion( current->childs[position], current->data[position]);
			}else
				removerDato( current , position );
			result = true;
		}else
			removerEnRecursion( current->childs[position], target );

		if( current->childs[position] != NULL )
			if( current->childs[position]->NodeEmpty() )
				restaurar( current , position );
	}
	return result;
}

template <class Type, int order> void Btree<Type,order>::removerDato(  B_node<Type, order> *current, int position  ){

	for(int i = position; i < current->count-1 ;i++)
		current->data[i] = current->data[i+1];
	current->count--;
}

template <class Type, int order> void Btree<Type,order>::copiarDePredecesor(  B_node<Type, order> *current, int position ){

	B_node<Type, order> * leaf = current->childs[position];

	while( leaf->childs[leaf->count] != NULL )
		leaf = leaf->childs[leaf->count]; //mover hacia al hijo mas derecho
	current->data[position] = leaf->data[leaf->count-1];
}

template <class Type, int order> void Btree<Type,order>::restaurar( B_node<Type, order> *current ,int position  ){

	if( position == current->count )
		if( current->childs[position-1]->count > (order-1)/2 )
			moverAlaDerecha( current , position-1);
		else
			combinar( current , position );
	else if( position == 0 )
		if( current->childs[1]->count > (order-1)/2)
			moverAlaIzquierda( current , 1 );
		else
			combinar( current , 1 );
	else
		if( current->childs[position-1]->count > (order-1)/2 )
			moverAlaDerecha( current , position-1 );
		else if( current->childs[position+1]->count > (order-1)/2 )
			moverAlaIzquierda( current , position+1 );
		else
			combinar( current, position );
}

template <class Type, int order> void Btree<Type,order>::moverAlaIzquierda( B_node<Type, order> *current , int position ){

	B_node<Type, order> *leftchilds = current->childs[position-1],
		*rightchilds = current->childs[position];
	leftchilds->data[leftchilds->count] = current->data[position-1];

	leftchilds->childs[++leftchilds->count] = rightchilds->childs[0];
	current->data[position-1] = rightchilds->data[0];

	rightchilds->count--;
	for(  int i =0;i < rightchilds->count;i++ ){
		rightchilds->data[i] = rightchilds->data[i+1];
		rightchilds->childs[i] = rightchilds->childs[i+1];
	}
	rightchilds->childs[rightchilds->count] = rightchilds->childs[rightchilds->count +1];

}

template <class Type, int order> void Btree<Type,order>::moverAlaDerecha( B_node<Type, order> *current , int position ){

	B_node<Type, order>*rightchilds = current->childs[position+1],
		*leftchilds = current->childs[position];

	rightchilds->childs[rightchilds->count+1] = rightchilds->childs[rightchilds->count];

	for( int i=rightchilds->count; i > 0;i-- ){
		rightchilds->data[i] = rightchilds->data[i-1];
		rightchilds->childs[i] = rightchilds->childs[i-1];
	}

	rightchilds->count++;
	rightchilds->data[0] = current->data[position];

	rightchilds->childs[0] = leftchilds->childs[leftchilds->count--];
	current->data[position] = leftchilds->data[leftchilds->count];
}

template <class Type, int order> void Btree<Type,order>::combinar( B_node<Type, order> *current, int position ){

	int i;
	B_node<Type, order> *leftchilds = current->childs[position-1],
		*rightchilds = current->childs[position];

	leftchilds->data[leftchilds->count] = current->data[position-1];
	leftchilds->childs[++leftchilds->count] = rightchilds->childs[0];

	for( i =0;i < rightchilds->count;i++){
		leftchilds->data[leftchilds->count] = rightchilds->data[i];
		leftchilds->childs[++leftchilds->count] = rightchilds->childs[i+1];
	}
	current->count--;

	for( i=position-1; i < current->count; i++ ){
		current->data[i] = current->data[i+1];
		current->childs[i+1] = current->childs[i+2];
	}

	delete rightchilds;
}

template <class Type, int order> void Btree<Type,order>::imprimirArbol( B_node<Type, order> *current ){
	
	int i;
	if(!current) 
		return; 
	static int k = 1;
	current->mostrarNodo(); 
	k++;
	for( i=0; i<= current->count ;i++) 
		imprimirArbol( current->childs[i] );
}

template <class Type, int order> void Btree<Type,order>::mostrarArbol(){

	if ( root != NULL )
		imprimirArbol( root );

}

template <class Type, int order> void Btree<Type,order>::guardarInorder(B_node<Type, order> *current, ofstream *escritura) {
	if ( current != NULL ){
		guardarInorder( current->childs[0],escritura);
		for (int i = 0; i < current->count; i++){
			escritura->write(reinterpret_cast<char *>(&current->data[i]),sizeof(Type));
			guardarInorder(current->childs[i + 1],escritura);
		}
	}
}

template <class Type, int order> void Btree<Type,order>::guardarEnArchivo(string direccionArchivo){
	fstream archivo;
	archivo.open(direccionArchivo.c_str(),ofstream::out);
	archivo.close();

	ofstream escritura(direccionArchivo.c_str(),ios::app);
	guardarInorder(root,&escritura);
	escritura.close();
}

template <class Type, int order> void Btree<Type,order>::vaciar(){
	root = NULL;
	cte = NULL;
}

#endif
