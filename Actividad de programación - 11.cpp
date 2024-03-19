/* --- Presentacion ---
Nombre: Juan Fernando Gomez Navarro
Fecha: 11 de Marzo del 2024
Programa: Actividad de programacion - 11
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
Descripcion: Es un código que funciona con punteros, donde los datos
solo seran numericos, los valores se acomodan de menor a mayor, si el
valor ya fue insertado envia mensaje de que ya existe, los valores
se insertan cuando el usuario lo indique y utiliza funciones y librerias.
*/
#include <iostream>
#include <cstdlib> // Para la función atoi
#include <algorithm> // Para la función sort
using namespace std;
const int MAX_VALORES = 50;

// Función para verificar si un string es numérico
bool esNumerico(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

// Función para insertar un valor en el arreglo
void insertarValor(int* arreglo[], int& tamano) {
    string entrada;
    int valor;
    bool valorValido = false;

    do {
        cout << "Ingresa un valor numerico: ";
        cin >> entrada;

        if (!esNumerico(entrada)) {
            cout << "Valor no valido, ingresa un valor numerico." << endl;
        } else {
            valor = atoi(entrada.c_str());
            valorValido = true;
        }
    } while (!valorValido);

    // Comprobar si el valor ya existe en el arreglo
    bool valorExiste = false;
    for (int i = 0; i < tamano; ++i) {
        if (*arreglo[i] == valor) {
            valorExiste = true;
            break;
        }
    }

    if (valorExiste) {
        cout << "El valor " << valor << " ya existe." << endl;
    } else {
        // Insertar el valor en el arreglo
        arreglo[tamano] = new int(valor);
        ++tamano;

        // Ordenar el arreglo
        sort(arreglo, arreglo + tamano, [](int* a, int* b) {
            return *a < *b;
        });

        // Imprimir el arreglo ordenado
        cout << "Valores ordenados de menor a mayor: ";
        for (int i = 0; i < tamano; ++i) {
            cout << *arreglo[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int* arreglo[MAX_VALORES];
    int tamano = 0;
    char continuar;

    do {
        insertarValor(arreglo, tamano);

        cout << "¿Quieres insertar otro valor? (s/n): ";
        cin >> continuar;
    } while ((continuar == 's' || continuar == 'S') && tamano < MAX_VALORES);

    // Liberar la memoria asignada a los elementos del arreglo
    for (int i = 0; i < tamano; ++i) {
        delete arreglo[i];
    }

    return 0;
}
