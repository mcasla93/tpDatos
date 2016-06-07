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

int main(int argc, char *argv[]) {
	ArbolLsm arbol;
	Dato dato;

	if ((argc == 1) || (strcmp(argv[1],"h")==0) ) {
		imprimirMenuHelp();
	}
	char opMenu;
	memcpy(&opMenu,&argv[1],1);
	switch (opMenu){
		case 'a':
			break;
		case 'b':
			break;
		case 'm':
			break;
		case 'h':
			imprimirMenuHelp();
			break;
		default:
			imprimirMenuHelp();
	}

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

	arbol.consultarId(2);

	arbol.imprimir();

	return 0;
}
