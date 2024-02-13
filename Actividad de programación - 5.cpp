/* Presentacion
Nombre: Juan Fernando Gomez Navarro
Fecha: 13 de Febrero del 2024
Programa: Actividad de programación - 5
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
Descripcion: Es un codigo de suma de un arreglo que tiene maximo
10 espacios,usuario final elige cuando entra un valor a cada posicon,
muestra lista de valores, muestra la sumatoria, borrado,
edicion y vaciado de arreglo.
*/
#include "stdio.h"
#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	//Declaracion de variables
	int arreglo[10];
	int suma = 0;
	int contador = 0;
	int opcion = 0;
	int posicion = 0;
	int valor = 0;
	//Ciclo para el menu
	do {
		cout << "1. Ingresar valor" << endl;
		cout << "2. Mostrar valores" << endl;
		cout << "3. Mostrar suma" << endl;
		cout << "4. Borrar valor" << endl;
		cout << "5. Editar valor" << endl;
		cout << "6. Vaciar arreglo" << endl;
		cout << "7. Salir" << endl;
		cin >> opcion;
		switch (opcion) {
		case 1:
			if (contador < 10) {
				cout << "Ingrese el valor: ";
				cin >> valor;
				arreglo[contador] = valor;
				contador++;
			}
			else {
				cout << "El arreglo esta lleno" << endl;
			}
			break;
		case 2:
			cout << "Los valores son: ";
			for (int i = 0; i < contador; i++) {
				cout << arreglo[i] << " ";
			}
			cout << endl;
			break;
		case 3:
			suma = 0;
			for (int i = 0; i < contador; i++) {
				suma += arreglo[i];
			}
			cout << "La suma es: " << suma << endl;
			break;
		case 4:
			cout << "Ingrese la posicion a borrar: ";
			cin >> posicion;
			if (posicion < contador) {
				for (int i = posicion; i < contador; i++) {
					arreglo[i] = arreglo[i + 1];
				}
				contador--;
			}
			else {
				cout << "Posicion no valida" << endl;
			}
			break;
		case 5:
			cout << "Ingrese la posicion a editar: ";
			cin >> posicion;
			if (posicion < contador) {
				cout << "Ingrese el valor: ";
				cin >> valor;
				arreglo[posicion] = valor;
			}
						else {
				cout << "Posicion no valida" << endl;
			}
			break;
		case 6:
			contador = 0;
			break;
		}
	} while (opcion != 7);
	_getch();
	return 0;//Fin de main
}
