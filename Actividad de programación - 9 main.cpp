/* --- Presentacion ---
Nombre: Juan Fernando Gomez Navarro
Fecha: 01 de Marzo del 2024
Programa: Actividad de programacion - 9
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
Descripcion: Es un codigo que funge como el main de una biblioteca
de funciones, en donde la libreria creada elabora operaciones de conjuntos,
inserta valores por parte del usuario ya sean textuales o
numericos,borra y edita los elementos, vaciado de conjuntos,
operaciones de union, diferencia y complemento.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include "Actividad de programación - 9 mylib.cpp"
int main() {
    std::vector<char> conjunto1, conjunto2, universo;

    int opcion;
    do {
        std::cout << "\n--- Operaciones de Conjuntos ---\n";
        std::cout << "1. Mostrar Conjuntos\n";
        std::cout << "2. Insertar Elemento\n";
        std::cout << "3. Borrar Elemento\n";
        std::cout << "4. Editar Elemento\n";
        std::cout << "5. Vaciar Conjunto\n";
        std::cout << "6. Union de Conjuntos\n";
        std::cout << "7. Interseccion de Conjuntos\n";
        std::cout << "8. Diferencia de Conjuntos\n";
        std::cout << "9. Complemento de Conjunto respecto al Universo\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarConjunto(conjunto1);
                mostrarConjunto(conjunto2);
                break;
            case 2:
                insertarElemento(conjunto1);
                break;
            case 3:
                borrarElemento(conjunto1);
                break;
            case 4:
                editarElemento(conjunto1);
                break;
            case 5:
                vaciarConjunto(conjunto1);
                break;
            case 6: {
                std::vector<char> unionResult = unionConjuntos(conjunto1, conjunto2);
                std::cout << "Union de Conjuntos: ";
                mostrarConjunto(unionResult);
                break;
            }
            case 7: {
                std::vector<char> interseccionResult = interseccionConjuntos(conjunto1, conjunto2);
                std::cout << "Interseccion de Conjuntos: ";
                mostrarConjunto(interseccionResult);
                break;
            }
            case 8: {
                std::vector<char> diferenciaResult = diferenciaConjuntos(conjunto1, conjunto2);
                std::cout << "Diferencia de Conjuntos: ";
                mostrarConjunto(diferenciaResult);
                break;
            }
            case 9: {
                std::vector<char> complementoResult = complementoConjuntoUniverso(conjunto1, universo);
                std::cout << "Complemento del Conjunto respecto al Universo: ";
                mostrarConjunto(complementoResult);
                break;
            }
            case 0:
                std::cout << "Saliendo del programa.\n";
                break;
            default:
                std::cout << "Opcion no valida.\n";
        }

    } while (opcion != 0);

    return 0;
}
