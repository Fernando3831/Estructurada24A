/* Presentacion
Nombre: Juan Fernando Gomez Navarro
Fecha: 21 de Febrero del 2024
Programa: Actividad de programación - 7
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
Descripcion: Es un codigo que sirve como calculadora de matrices,
la cual realiza sumas, restas y mutliplicaciones de 2 matrices. Tiene
caracteristicas de matriz cuadrada minima de 2x2 y maximo de 10x10,
los valores los ingresa el usuario e inidicara en que matriz ira el valor,
se podra elegir de ser llenada con valores aleatorios entre -100 y 100,
ejecutara la operacion que diga el usuario y tendra opcion de borrado, edicion
de elementos y vaciado de matrices.
*/
#include <iostream>
#include <cstdlib>
using namespace std;
const int MAX_SIZE = 10;

// Funcion para llenar una matriz con valores aleatorios entre -100 y 100
void llenarMatrizAleatoria(int matriz[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matriz[i][j] = rand() % 201 - 100;  // Números aleatorios entre -100 y 100
        }
    }
}

// Función para mostrar una matriz
void mostrarMatriz(int matriz[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}

// Función para realizar la suma de dos matrices
void sumarMatrices(int matrizA[MAX_SIZE][MAX_SIZE], int matrizB[MAX_SIZE][MAX_SIZE], int resultado[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            resultado[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }
}

// Función para realizar la resta de dos matrices
void restarMatrices(int matrizA[MAX_SIZE][MAX_SIZE], int matrizB[MAX_SIZE][MAX_SIZE], int resultado[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            resultado[i][j] = matrizA[i][j] - matrizB[i][j];
        }
    }
}

// Función para realizar la multiplicación de dos matrices
void multiplicarMatrices(int matrizA[MAX_SIZE][MAX_SIZE], int matrizB[MAX_SIZE][MAX_SIZE], int resultado[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            resultado[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
}

int main() {
    int size;

    // Pedir al usuario el tamaño de las matrices
    do {
        cout << "Ingresa las dimensiones de las matrices (entre 2 y " << MAX_SIZE << "): ";
        cin >> size;
    } while (size < 2 || size > MAX_SIZE);

    int matrizA[MAX_SIZE][MAX_SIZE];
    int matrizB[MAX_SIZE][MAX_SIZE];
    int resultado[MAX_SIZE][MAX_SIZE];

    // Opcion de llenado de matrices con valores proporcionados por el usuario o aleatorios
    char opcion;
    cout << "Deseas llenar las matrices manualmente (M) o con valores aleatorios (A)? ";
    cin >> opcion;

    if (opcion == 'M' || opcion == 'm') {
        cout << "Llenar la Matriz A:" << endl;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                cout << "Ingrese el valor en la posicion [" << i << "][" << j << "]: ";
                cin >> matrizA[i][j];
            }
        }

        cout << "Llenar la Matriz B:" << endl;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                cout << "Ingrese el valor en la posicion [" << i << "][" << j << "]: ";
                cin >> matrizB[i][j];
            }
        }
    } else if (opcion == 'A' || opcion == 'a') {
        llenarMatrizAleatoria(matrizA, size);
        llenarMatrizAleatoria(matrizB, size);
        cout << "Matrices llenadas con valores aleatorios." << endl;
    } else {
        cout << "Opcion no valida. Saliendo del programa." << endl;
        return 1;
    }

    // Menu principal
    int operacion;
    do {
        cout << "\n*** Menu Principal ***" << endl;
        cout << "1. Sumar Matrices" << endl;
        cout << "2. Restar Matrices" << endl;
        cout << "3. Multiplicar Matrices" << endl;
        cout << "4. Mostrar Matrices" << endl;
        cout << "5. Editar Elemento de Matriz" << endl;
        cout << "6. Borrar Elemento de Matriz" << endl;
        cout << "7. Vaciar Matrices" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese la opcion deseada: ";
        cin >> operacion;

        switch (operacion) {
            case 1:
                sumarMatrices(matrizA, matrizB, resultado, size);
                cout << "Resultado de la suma:" << endl;
                mostrarMatriz(resultado, size);
                break;
            case 2:
                restarMatrices(matrizA, matrizB, resultado, size);
                cout << "Resultado de la resta:" << endl;
                mostrarMatriz(resultado, size);
                break;
            case 3:
                multiplicarMatrices(matrizA, matrizB, resultado, size);
                cout << "Resultado de la multiplicacion:" << endl;
                mostrarMatriz(resultado, size);
                break;
            case 4:
                cout << "Matriz A:" << endl;
                mostrarMatriz(matrizA, size);
                cout << "Matriz B:" << endl;
                mostrarMatriz(matrizB, size);
                break;
            case 5:
                int fila, columna, nuevoValor;
                cout << "Ingrese la posicion (fila y columna) del elemento a editar en la Matriz A:" << endl;
                cout << "Fila: ";
                cin >> fila;
                cout << "Columna: ";
                cin >> columna;
                cout << "Ingrese el nuevo valor: ";
                cin >> nuevoValor;
                if (fila >= 0 && fila < size && columna >= 0 && columna < size) {
                    matrizA[fila][columna] = nuevoValor;
                    cout << "Elemento editado correctamente." << endl;
                } else {
                    cout << "Posicion fuera de rango. No se pudo editar el elemento." << endl;
                }
                break;
            case 6:
                cout << "Ingrese la posición (fila y columna) del elemento a borrar en la Matriz B:" << endl;
                cout << "Fila: ";
                cin >> fila;
                cout << "Columna: ";
                cin >> columna;
                if (fila >= 0 && fila < size && columna >= 0 && columna < size) {
                    matrizB[fila][columna] = 0;  // Borrar asignando cero
                    cout << "Elemento borrado correctamente." << endl;
                } else {
                    cout << "Posicion fuera de rango. No se pudo borrar el elemento." << endl;
                }
                break;
            case 7:
                // Vaciar matrices asignando cero a todos los elementos
                for (int i = 0; i < size; ++i) {
                    for (int j = 0; j < size; ++j) {
                        matrizA[i][j] = 0;
                        matrizB[i][j] = 0;
                    }
                }
                cout << "Matrices vaciadas correctamente." << endl;
                break;
            case 0:
                cout << "Saliendo del programa" << endl;
                break;
            default:
                cout << "Opcion no valida. Intentalo nuevamente." << endl;
        }

    } while (operacion != 0);

    return 0;
}
