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

void imprimirMenuHelp(){
	cout << " **** ­Comandos ****" << endl;
	cout << "­ a vendedores [path al archivo] Para dar de alta en Vendedores" << endl;
	cout << " ­a ventas [path al archivo] Para dar de alta en Ventas" << endl;
	cout << " ­a productos [path al archivo] Para dar de alta en Productos" << endl;
	cout << " ­a grupos [path al archivo] Para dar de alta en Grupos" << endl;
	cout << " ­b vendedores [path al archivo] Para dar de baja en Vendedores" << endl;
	cout << " ­b ventas [path al archivo] Para dar de baja en Ventas" << endl;
	cout << " ­b productos [path al archivo] Para dar de baja en Productos" << endl;
	cout << " ­b grupos [path al archivo] Para dar de baja en Grupos" << endl;
	cout << " ­m vendedores [path al archivo] Para modificar en Vendedores" << endl;
	cout << " ­m ventas [path al archivo] Para modificar en Ventas" << endl;
	cout << " ­m productos [path al archivo] Para modificar en Productos" << endl;
	cout << " ­m grupos [path al archivo] Para modificar en Grupos" << endl;
	cout << " ­q [Cod Consulta] [­f path al archivo] Para realizar una consulta" << endl;
	cout << " **** ­Codigos de Consulta ****" << endl;
	cout << " ­A Búsqueda de Vendedor por Identificador." << endl;
	cout << " ­B Búsqueda de Vendedor por Nombre." << endl;
	cout << " ­C Búsqueda de Venta por Código de Vendedor." << endl;
	cout << " ­D Búsqueda de Venta por Código de Producto." << endl;
	cout << " ­E Búsqueda de Producto por Identificador." << endl;
	cout << " ­F Búsqueda de Producto por Nombre." << endl;
	cout << " ­G Búsqueda de Grupo por Identificador." << endl;
	cout << " ­H Búsqueda de Vendedor por Identificador, con el índice." << endl;
	cout << " ­I Búsqueda de Vendedor por Nombre, con el índice." << endl;
	cout << " ­J Búsqueda de Venta por Código de Vendedor, con el índice." << endl;
	cout << " ­K Búsqueda de Venta por Código de Producto, con el índice." << endl;
	cout << " ­L Búsqueda de Producto por Identificador, con el índice." << endl;
	cout << " ­M Búsqueda de Producto por Nombre, con el índice." << endl;
	cout << " ­N Búsqueda de Grupo por Identificador, con el índice." << endl;
	cout << " ­O Informe: Listado de ventas por Vendedor." << endl;
	cout << " ­P Informe: Ahorro de espacio por compresión." << endl;
	cout << " ­La opción 'f' indica que se guardará el resultado en un archivo, caso contrario sale por pantalla." << endl;
}

void alta(ArbolLsm *arbol){
	char id;
	char codigo[3];
	char descripcion[1000];

	cout << "Ingrese un nuevo dato" << endl;
	cout << "Id: ";
	cin >> id;
	cout << "Codigo: ";
	cin >> codigo;
	cout << "Descripcion: ";
	cin >> descripcion;
	cout << endl;

	Dato nuevoDato;
	nuevoDato.cargar(id,codigo,descripcion);

	arbol->insertar(nuevoDato);

	//ACA HAY Q AGREGARLO AL ARBOL
	//PERO PRIMERO HAY Q CARGAR EL ARBOL DESDE EL ARCHIVO
	arbol->imprimir();
	cout << endl;
}

void baja(){
	cout << "Ingrese dato a eliminar" << endl;
}

void modificacion(){
	cout << "Ingrese dato a modificar" << endl;
}

int main(int argc, char *argv[]) {
	/*ArbolLsm arbol;
	Dato dato;

	dato.cargar(2,"2","pablo");
	arbol.insertar(dato);
	dato.cargar(3,"3","matu");
	arbol.insertar(dato);
	dato.cargar(4,"4","pepe");
	arbol.insertar(dato);
	dato.cargar(5,"5","carlo");
	arbol.insertar(dato);
	dato.cargar(6,"6","pelu");
	arbol.insertar(dato);

	arbol.modificarId(2);

	arbol.imprimir();*/

	ArbolLsm arbol;

	if (argc == 1) {
		//si no pasa ningun parametro al ejecutar
		imprimirMenuHelp();
	}
	/*MENU*/
	char opMenu;
	memcpy(&opMenu,&argv[1][1],1);
	switch (opMenu){
	case 'a':
		//ALTA
		arbol.cargarDesdeArchivo(&argv[3]);
		alta(&arbol);
		break;
	case 'b':
		//BAJA
		arbol.cargarDesdeArchivo(argv[3]);
		baja();
		break;
	case 'm':
		//MODIFICACION
		arbol.cargarDesdeArchivo(argv[3]);
		modificacion();
		break;
	case 'q':
		//CONSULTA
		arbol.cargarDesdeArchivo(argv[3]);
		char opMenuQ;
		memcpy(&opMenuQ,&argv[2][0],1);
		switch (opMenuQ){
			case 'A':
				//Búsqueda de Vendedor por Identificador
				break;
			case 'B':
				// Búsqueda de Vendedor por Nombre
				break;
			case 'C':
				//Búsqueda de Venta por Código de Vendedor
				break;
			case 'D':
				//Búsqueda de Venta por Código de Producto
				break;
			case 'E':
				//Búsqueda de Producto por Identificador
				break;
			case 'F':
				//Búsqueda de Producto por Nombre
				break;
			case 'G':
				//Búsqueda de Grupo por Identificador
				break;
			case 'H':
				//Búsqueda de Vendedor por Identificador, con el índice
				break;
			case 'I':
				//Búsqueda de Vendedor por Nombre, con el índice
				break;
			case 'J':
				//Búsqueda de Venta por Código de Vendedor, con el índice
				break;
			case 'K':
				//Búsqueda de Venta por Código de Producto, con el índice
				break;
			case 'L':
				//Búsqueda de Producto por Identificador, con el índice
				break;
			case 'M':
				//Búsqueda de Producto por Nombre, con el índice
				break;
			case 'N':
				//Búsqueda de Grupo por Identificador, con el índice
				break;
			case 'O':
				//Informe: Listado de ventas por Vendedor.
				break;
			case 'P':
				//Informe: Ahorro de espacio por compresión
				break;
			default:
				//imprimirMenuHelp();
				break;
		}
		break;
	default:
		imprimirMenuHelp();
}

	return 0;
}
