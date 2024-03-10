/* --- Presentacion ---
Nombre: Juan Fernando Gomez Navarro
Fecha: 10 de Marzo del 2024
Programa: Actividad de programacion - 10
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
Descripcion: Es un código que crea matrices en un rango entre 2x2
y 15x15, agrega valores aleatorios entre -200 y 400,hace suma,resta,
multiplicación,division,borra,edita y vacia las matrices.
*/
//Biblioteca de funciones
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

// Función para mostrar una matriz
void mostrarMatriz(const std::vector<std::vector<int>>& matriz, const std::string& nombre) {
    std::cout << "Matriz " << nombre << ":\n";
    for (const auto& fila : matriz) {
        for (int valor : fila) {
            std::cout << valor << "\t";
        }
        std::cout << std::endl;
    }
}

// Función para llenar la matriz con valores aleatorios entre -200 y 400
void llenarMatrizAleatoria(std::vector<std::vector<int>>& matriz) {
    for (auto& fila : matriz) {
        for (int& valor : fila) {
            valor = rand() % 601 - 200;  // Números aleatorios entre -200 y 400
        }
    }
}

// Función para llenar la matriz con valores ingresados por el usuario
void llenarMatrizUsuario(std::vector<std::vector<int>>& matriz, const std::string& nombre) {
    std::cout << "Ingrese los valores para la matriz " << nombre << ":\n";
    for (auto& fila : matriz) {
        for (int& valor : fila) {
            std::cout << "Ingrese el valor para la posicion (" << &fila - &matriz[0] + 1 << ", " << &valor - &fila[0] + 1 << "): ";
            std::cin >> valor;
        }
    }
}

// Función para crear una matriz de tamaño especificado por el usuario
std::vector<std::vector<int>> crearMatrizUsuario() {
    int filas, columnas;

    do {
        std::cout << "Ingrese el numero de filas (entre 2 y 15): ";
        std::cin >> filas;
    } while (filas < 2 || filas > 15);

    do {
        std::cout << "Ingrese el número de columnas (entre 2 y 15): ";
        std::cin >> columnas;
    } while (columnas < 2 || columnas > 15);

    return std::vector<std::vector<int>>(filas, std::vector<int>(columnas, 0));
}

// Función para realizar la suma de dos matrices
std::vector<std::vector<int>> sumarMatrices(const std::vector<std::vector<int>>& matrizA, const std::vector<std::vector<int>>& matrizB) {
    std::vector<std::vector<int>> resultado(matrizA.size(), std::vector<int>(matrizA[0].size(), 0));

    for (size_t i = 0; i < matrizA.size(); ++i) {
        for (size_t j = 0; j < matrizA[0].size(); ++j) {
            resultado[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }

    return resultado;
}

// Función para realizar la resta de dos matrices
std::vector<std::vector<int>> restarMatrices(const std::vector<std::vector<int>>& matrizA, const std::vector<std::vector<int>>& matrizB) {
    std::vector<std::vector<int>> resultado(matrizA.size(), std::vector<int>(matrizA[0].size(), 0));

    for (size_t i = 0; i < matrizA.size(); ++i) {
        for (size_t j = 0; j < matrizA[0].size(); ++j) {
            resultado[i][j] = matrizA[i][j] - matrizB[i][j];
        }
    }

    return resultado;
}

// Función para realizar la multiplicación de dos matrices
std::vector<std::vector<int>> multiplicarMatrices(const std::vector<std::vector<int>>& matrizA, const std::vector<std::vector<int>>& matrizB) {
    std::vector<std::vector<int>> resultado(matrizA.size(), std::vector<int>(matrizB[0].size(), 0));

    for (size_t i = 0; i < matrizA.size(); ++i) {
        for (size_t j = 0; j < matrizB[0].size(); ++j) {
            for (size_t k = 0; k < matrizA[0].size(); ++k) {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }

    return resultado;
}

// Función para realizar la división de dos matrices
std::vector<std::vector<int>> dividirMatrices(const std::vector<std::vector<int>>& matrizNumerador, const std::vector<std::vector<int>>& matrizDenominador) {
    std::vector<std::vector<int>> resultado(matrizNumerador.size(), std::vector<int>(matrizNumerador[0].size(), 0));

// Matriz denominador es invertible
    for (size_t i = 0; i < matrizNumerador.size(); ++i) {
        for (size_t j = 0; j < matrizNumerador[0].size(); ++j) {
            resultado[i][j] = matrizNumerador[i][j] / matrizDenominador[i][j];
        }
    }

    return resultado;
}

// Función para borrar todos los elementos de una matriz
void vaciarMatriz(std::vector<std::vector<int>>& matriz) {
    for (auto& fila : matriz) {
        for (int& valor : fila) {
            valor = 0;
        }
    }
}

// Función para editar un elemento de la matriz
void editarElemento(std::vector<std::vector<int>>& matriz, const std::string& nombre) {
    int fila, columna, nuevoValor;
    std::cout << "Ingrese la posicion (fila y columna) del elemento que desea editar en la matriz " << nombre << ":\n";
    std::cout << "Fila: ";
    std::cin >> fila;
    std::cout << "Columna: ";
    std::cin >> columna;

    if (fila > 0 && fila <= matriz.size() && columna > 0 && columna <= matriz[0].size()) {
        std::cout << "Ingrese el nuevo valor: ";
        std::cin >> nuevoValor;
        matriz[fila - 1][columna - 1] = nuevoValor;
        std::cout << "Elemento editado correctamente.\n";
    } else {
        std::cout << "Posicion invalida.\n";
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    std::vector<std::vector<int>> matrizA, matrizB, resultado;

    int opcion;
    do {
        std::cout << "\n--- Operaciones de Matrices ---\n";
        std::cout << "1. Crear Matrices\n";
        std::cout << "2. Llenar Matrices con Valores Aleatorios\n";
        std::cout << "3. Llenar Matrices con Valores del Usuario\n";
        std::cout << "4. Mostrar Matrices\n";
        std::cout << "5. Sumar Matrices\n";
        std::cout << "6. Restar Matrices\n";
        std::cout << "7. Multiplicar Matrices\n";
        std::cout << "8. Dividir Matrices (por elementos)\n";
        std::cout << "9. Borrar Elemento de Matriz\n";
        std::cout << "10. Vaciar Matrices\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                matrizA = crearMatrizUsuario();
                matrizB = crearMatrizUsuario();
                break;
            case 2:
                llenarMatrizAleatoria(matrizA);
                llenarMatrizAleatoria(matrizB);
                break;
            case 3:
                llenarMatrizUsuario(matrizA, "A");
                llenarMatrizUsuario(matrizB, "B");
                break;
            case 4:
                mostrarMatriz(matrizA, "A");
                mostrarMatriz(matrizB, "B");
                break;
            case 5:
                resultado = sumarMatrices(matrizA, matrizB);
                mostrarMatriz(resultado, "Suma");
                break;
            case 6:
                resultado = restarMatrices(matrizA, matrizB);
                mostrarMatriz(resultado, "Resta");
                break;
            case 7:
                resultado = multiplicarMatrices(matrizA, matrizB);
                mostrarMatriz(resultado, "Multiplicacion");
                break;
            case 8:
                resultado = dividirMatrices(matrizA, matrizB);
                mostrarMatriz(resultado, "Division");
                break;
            case 9:
                editarElemento(matrizA, "A");
                editarElemento(matrizB, "B");
                break;
            case 10:
                vaciarMatriz(matrizA);
                vaciarMatriz(matrizB);
                std::cout << "Matrices vaciadas correctamente.\n";
                break;
            case 0:
                std::cout << "Saliendo del programa.\n";
                break;
            default:
                std::cout << "Opcion no valida. Intenta de nuevo.\n";
        }

    } while (opcion != 0);

    return 0;
}//Fin main
