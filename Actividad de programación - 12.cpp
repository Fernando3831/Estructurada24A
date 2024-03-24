/* --- Presentacion ---
Nombre: Juan Fernando Gomez Navarro
Fecha: 23 de Marzo del 2024
Programa: Actividad de programacion - 12
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
Descripcion: Es un código que recrea el juego de las Torres de Hanoi
utilizando el programa en C++, donde se cuentan el numero de movimientos
necesario para ganar el juego, se pueden utilizar de 3 a 8 discos dependiendo
lo que ingrese el usuario, utilizando las librerias de iostream y vector,
ademas de usar funciones e implementar un metodo recursivo para funcionar.
*/
//Declaracion de bibliotecas
#include <iostream>
#include <vector>

using namespace std;

// Función recursiva para resolver el problema de las Torres de Hanoi.
void torresDeHanoi(int n, int origen, int destino, int auxiliar, int &movimientos) {
    if (n == 1) {
        // Si solo hay un disco, moverlo directamente de origen a destino.
        cout << "Mover disco de " << origen << " a " << destino << endl;
        movimientos++;
    } else {
        // Mover n-1 discos de origen a auxiliar usando destino.
        torresDeHanoi(n - 1, origen, auxiliar, destino, movimientos);

        // Mover el disco más grande de origen a destino.
        cout << "Mover disco de " << origen << " a " << destino << endl;
        movimientos++;

        // Mover n-1 discos de auxiliar a destino usando origen.
        torresDeHanoi(n - 1, auxiliar, destino, origen, movimientos);
    }
}

int main() {//Inicio de main
    int n;
    cout << "Ingrese el numero de discos (entre 3 y 8): ";
    cin >> n;

    if (n < 3 || n > 8) {
        cout << "Numero de discos no valido. Debe estar entre 3 y 8." << endl;
        return 1;
    }
//Declara variable "movimientos" de tipo entero con un valor inicial de 0. Esta variable se utiliza para contar el número de movimientos realizados.
    int movimientos = 0;
//Llama a la funciOn torresDeHanoi con los siguientes argumentos: n=numero de discos,1=torre origen,3=torre destino,2=torre auxiliar,
//Lo que permite a la funcion torresDeHanoi que actualice el numero de movimientos realizados.
    torresDeHanoi(n, 1, 3, 2, movimientos);//

    cout << "Se realizaron " << movimientos << " movimientos." << endl;

    return 0;
}//Fin de main
