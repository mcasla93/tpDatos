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
	int id;
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
}

void baja(ArbolLsm *arbol){
	int id;

	cout << "Ingrese ID a eliminar" << endl;
	cout << "Id: ";
	cin >> id;
	cout << endl;

	Dato dato = arbol->consultarId(id);
	arbol->eliminar(dato);
}

void modificacion(){
	cout << "Ingrese dato a modificar" << endl;
}

void cargarArbolDesdeArchivo(string direccionArchivo,ArbolLsm *arbol){
	ifstream lectura(direccionArchivo.c_str(),ios::in | ios::binary);

	while(!lectura.eof()) {
		Dato dato;
		lectura.read(reinterpret_cast<char *>(&dato),sizeof(Dato));

		if(lectura.eof())
			break;

		arbol->insertar(dato);
	}
	lectura.close();
}

void guardarArbolEnArchivo(string direccionArchivo,ArbolLsm *arbol){
	arbol->guardarEnArchivo(direccionArchivo);
}

int main(int argc, char *argv[]) {
	ArbolLsm arbol;

	/* CREACION DEL ARCHIVO PARA PRUEBAS
	fstream archivo;
	archivo.open("vendedores.txt",ofstream::out);
	archivo.close();

	ofstream escritura("vendedores.txt",ios::app);
	Dato dato;
	dato.cargar(2,"2","pablo");
	escritura.write(reinterpret_cast<char *>(&dato),sizeof(struct Dato));
	dato.cargar(3,"3","matu");
	escritura.write(reinterpret_cast<char *>(&dato),sizeof(struct Dato));
	dato.cargar(4,"4","pepe");
	escritura.write(reinterpret_cast<char *>(&dato),sizeof(struct Dato));
	dato.cargar(5,"5","carlo");
	escritura.write(reinterpret_cast<char *>(&dato),sizeof(struct Dato));
	dato.cargar(6,"6","pelu");
	escritura.write(reinterpret_cast<char *>(&dato),sizeof(struct Dato));
	escritura.close();
	*/
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
		cargarArbolDesdeArchivo(argv[3],&arbol);
		arbol.imprimir();
		alta(&arbol);
		arbol.imprimir();
		guardarArbolEnArchivo(argv[3],&arbol);
		break;
	case 'b':
		//BAJA
		cargarArbolDesdeArchivo(argv[3],&arbol);
		arbol.imprimir();
		baja(&arbol);
		arbol.imprimir();
		guardarArbolEnArchivo(argv[3],&arbol);
		break;
	case 'm':
		//MODIFICACION
		cargarArbolDesdeArchivo(argv[3],&arbol);
		modificacion();
		guardarArbolEnArchivo(argv[3],&arbol);
		break;
	case 'q':
		//CONSULTA
		cargarArbolDesdeArchivo(argv[3],&arbol);
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
