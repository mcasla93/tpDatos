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
	cout << "­ -a vendedores [path al archivo] Para dar de alta en Vendedores" << endl;
	cout << " ­-a ventas [path al archivo] Para dar de alta en Ventas" << endl;
	cout << " ­-a productos [path al archivo] Para dar de alta en Productos" << endl;
	cout << " ­-a grupos [path al archivo] Para dar de alta en Grupos" << endl;
	cout << " ­-b vendedores [path al archivo] Para dar de baja en Vendedores" << endl;
	cout << " ­-b ventas [path al archivo] Para dar de baja en Ventas" << endl;
	cout << " ­-b productos [path al archivo] Para dar de baja en Productos" << endl;
	cout << " ­-b grupos [path al archivo] Para dar de baja en Grupos" << endl;
	cout << " ­-m vendedores [path al archivo] Para modificar en Vendedores" << endl;
	cout << " ­-m ventas [path al archivo] Para modificar en Ventas" << endl;
	cout << " ­-m productos [path al archivo] Para modificar en Productos" << endl;
	cout << " ­-m grupos [path al archivo] Para modificar en Grupos" << endl;
	cout << " ­-q [Cod Consulta] [­f path al archivo] Para realizar una consulta" << endl;
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
	if (dato.id != -1){
		arbol->eliminar(dato);
	}else cout << "No existe el dato a eliminar" << endl;
}

void modificacion(ArbolLsm *arbol){
	char opcion;
	cout << "Ingrese dato a modificar" << endl;
	cout << "i - ID" << endl;
	cout << "c - CODIGO" << endl;
	cout << "d - DESCRIPCION" << endl;

	cin >> opcion;
	Dato datoC;
	Dato nuevoDatoM;

	switch (opcion){
	case 'i':
		//aca deberia hacer lo de borrarlo, crear uno nuevo y acomodarlo.
		int id, nuevoId;

		cout << "Ingrese ID a modificar" << endl;
		cout << "Id: ";
		cin >> id;
		datoC = arbol->consultarId(id);
		if (datoC.id != -1){
			cout << "ingrese el NUEVO ID: ";
			cin >> nuevoId;
			nuevoDatoM.cargar(nuevoId, datoC.codigo, datoC.descripcion);
			arbol->eliminar(datoC);
			arbol->insertar(nuevoDatoM);
		}
		break;

	case 'c':
		char codigo[3];
		cout<< "ingrese el codigo:";
		cin >> codigo;
		datoC = arbol->consultarCodigo(codigo);
		if (strcmp(datoC.codigo,"-1") != 0){
			char codigoNuevo[3];
			cout<< "ingrese el NUEVO codigo:";
			cin >> codigoNuevo;

			nuevoDatoM.cargar(datoC.id , codigoNuevo, datoC.descripcion);

			arbol->modificar(datoC, nuevoDatoM);
		}
		break;
	case 'd':
		char descripcion[1000];
		cout<< "ingrese la descripcion:";
		cin >> descripcion;
		datoC = arbol->consultarDescripcion(descripcion);
		if (strcmp(datoC.descripcion,"NULL") != 0){
			char descripcionNueva[1000];
			cout << "ingrese la NUEVA descripcion: ";
			cin >> descripcionNueva;

			nuevoDatoM.cargar(datoC.id, datoC.codigo, descripcionNueva);
			arbol->modificar(datoC, nuevoDatoM);
		}
		break;
	}
}

void cargarArbolDesdeArchivo(string direccionArchivo,ArbolLsm *arbol){
	ifstream lectura(direccionArchivo.c_str(),ios::in | ios::binary);
	if (lectura.is_open()){
		while(!lectura.eof()) {
			Dato dato;
			lectura.read(reinterpret_cast<char *>(&dato),sizeof(Dato));

			if(lectura.eof())
				break;

			arbol->insertar(dato);
		}
	}
	lectura.close();
}

void guardarArbolEnArchivo(string direccionArchivo,ArbolLsm *arbol){
	arbol->guardarEnArchivo(direccionArchivo);
}

void mergeVentasxVendedor(){

}

int main(int argc, char *argv[]) {
	ArbolLsm arbol;

	if (argc < 2) {
		imprimirMenuHelp();
	}else{

	/*MENU*/
	char opMenu;
	memcpy(&opMenu,&argv[1][1],1);

	switch (opMenu){
	case 'a':
		//ALTA
		cargarArbolDesdeArchivo(argv[3],&arbol);
		arbol.imprimir();
		alta(&arbol);
		guardarArbolEnArchivo(argv[3],&arbol);
		break;
	case 'b':
		//BAJA
		cargarArbolDesdeArchivo(argv[3],&arbol);
		arbol.imprimir();
		baja(&arbol);
		guardarArbolEnArchivo(argv[3],&arbol);
		break;
	case 'm':
		//MODIFICACION
		cargarArbolDesdeArchivo(argv[3],&arbol);
		arbol.imprimir();
		modificacion(&arbol);
		guardarArbolEnArchivo(argv[3],&arbol);
		break;
	case 'q':
		//CONSULTA
		cargarArbolDesdeArchivo(argv[3],&arbol);
		arbol.imprimir();
		char opMenuQ;
		memcpy(&opMenuQ,&argv[2][0],1);
		Dato datoC;
		int id;
		char codigo[3];
		char descripcion[1000];
		switch (opMenuQ){
			case 'A':
				//Búsqueda de Vendedor por Identificador
				cout << "Ingrese el Identificador: ";
				cin >> id;
				datoC = arbol.consultarId(id);
				datoC.imprimir();
				cout << endl;
				break;
			case 'B':
				// Búsqueda de Vendedor por Nombre
				cout << "Ingrese Descripcion: ";
				cin >> descripcion;
				datoC = arbol.consultarDescripcion(descripcion);
				datoC.imprimir();
				cout << endl;
				break;
			case 'C':
				//Búsqueda de Venta por Código de Vendedor
				cout << "Ingrese Codigo: ";
				cin >> codigo;
				datoC = arbol.consultarCodigo(codigo);
				datoC.imprimir();
				cout << endl;
				break;
			case 'D':
				//Búsqueda de Venta por Código de Producto
				cout << "Ingrese Descripcion: ";
				cin >> descripcion;
				datoC = arbol.consultarDescripcion(descripcion);
				datoC.imprimir();
				cout << endl;
				break;
			case 'E':
				//Búsqueda de Producto por Identificador
				cout << "Ingrese el Identificador: ";
				cin >> id;
				datoC = arbol.consultarId(id);
				datoC.imprimir();
				cout << endl;
				break;
			case 'F':
				//Búsqueda de Producto por Nombre
				cout << "Ingrese Descripcion: ";
				cin >> descripcion;
				datoC = arbol.consultarDescripcion(descripcion);
				datoC.imprimir();
				cout << endl;
				break;
			case 'G':
				//Búsqueda de Grupo por Identificador
				cout << "Ingrese el Identificador: ";
				cin >> id;
				datoC = arbol.consultarId(id);
				datoC.imprimir();
				cout << endl;
				break;
			case 'H':
				//Búsqueda de Vendedor por Identificador, con el índice
				cout << "Ingrese el Identificador: ";
				cin >> id;
				datoC = arbol.consultarId(id);
				datoC.imprimir();
				cout << endl;
				break;
			case 'I':
				//Búsqueda de Vendedor por Nombre, con el índice
				cout << "Ingrese Descripcion: ";
				cin >> descripcion;
				datoC = arbol.consultarDescripcion(descripcion);
				datoC.imprimir();
				cout << endl;
				break;
			case 'J':
				//Búsqueda de Venta por Código de Vendedor, con el índice
				cout << "Ingrese Codigo: ";
				cin >> codigo;
				datoC = arbol.consultarCodigo(codigo);
				datoC.imprimir();
				cout << endl;
				break;
			case 'K':
				//Búsqueda de Venta por Código de Producto, con el índice
				cout << "Ingrese Descripcion: ";
				cin >> descripcion;
				datoC = arbol.consultarDescripcion(descripcion);
				datoC.imprimir();
				cout << endl;
				break;
			case 'L':
				//Búsqueda de Producto por Identificador, con el índice
				cout << "Ingrese el Identificador: ";
				cin >> id;
				datoC = arbol.consultarId(id);
				datoC.imprimir();
				cout << endl;
				break;
			case 'M':
				//Búsqueda de Producto por Nombre, con el índice
				cout << "Ingrese Descripcion: ";
				cin >> descripcion;
				datoC = arbol.consultarDescripcion(descripcion);
				datoC.imprimir();
				cout << endl;
				break;
			case 'N':
				//Búsqueda de Grupo por Identificador, con el índice
				cout << "Ingrese el Identificador: ";
				cin >> id;
				datoC = arbol.consultarId(id);
				datoC.imprimir();
				cout << endl;
				break;
			case 'O':
				//Informe: Listado de ventas por Vendedor.
				mergeVentasxVendedor();
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
	}
	return 0;
}
