/* --- Presentacion ---
Nombre: Juan Fernando Gomez Navarro
Fecha: 08 de Marzo del 2024
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
#include "Actividad de programación - 9 + library.cpp"
int main() {
std::vector<char> conjuntoA, conjuntoB, universo;

    int opcion;
    do {
        std::cout << "\n--- Menu Principal ---" << std::endl;
        std::cout << " 1. Inserta elemento en conjunto A" << std::endl;
        std::cout << " 2. Borrar elemento en conjunto A" << std::endl;
        std::cout << " 3. Editar elemento en conjunto A" << std::endl;
        std::cout << " 4. Vaciar conjunto A" << std::endl;
        std::cout << " 5. Insertar elemento en conjunto B" << std::endl;
        std::cout << " 6. Borrar elemento en conjunto B" << std::endl;
        std::cout << " 7. Editar elemento en conjunto B" << std::endl;
        std::cout << " 8. Vaciar conjunto B" << std::endl;
        std::cout << " 9. Realizar union de conjuntos A y B" << std::endl;
        std::cout << "10. Realizar interseccion de conjuntos A y B" << std::endl;
        std::cout << "11. Realizar diferencia A - B" << std::endl;
        std::cout << "12. Realizar diferencia B - A" << std::endl;
        std::cout << "13. Mostrar conjuntos" << std::endl;
        std::cout << "14. Complemento de Conjunto respecto al Universo" << std:: endl;
        std::cout << "0. Salida" << std::endl;
        std::cout << "Ingresa la opcion deseada: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                insertarElemento(conjuntoA);
                break;
            case 2:
                borrarElemento(conjuntoA);
                break;
            case 3:
                editarElemento(conjuntoA);
                break;
            case 4:
                vaciarConjunto(conjuntoA);
                break;
            case 5:
                insertarElemento(conjuntoB);
                break;
            case 6:
                borrarElemento(conjuntoB);
                break;
            case 7:
                editarElemento(conjuntoB);
                break;
            case 8:
                vaciarConjunto(conjuntoB);
                break;
            case 9: {
                auto resultadoUnion = unionConjuntos(conjuntoA, conjuntoB);
                mostrarConjunto(resultadoUnion);
                break;
            }
            case 10: {
                auto resultadoInterseccion = interseccionConjuntos(conjuntoA, conjuntoB);
                mostrarConjunto(resultadoInterseccion);
                break;
            }
            case 11: {
                auto resultadoDiferenciaAB = diferenciaConjuntos(conjuntoA, conjuntoB);
                mostrarConjunto(resultadoDiferenciaAB);
                break;
            }
            case 12: {
                auto resultadoDiferenciaBA = diferenciaConjuntos(conjuntoB, conjuntoA);
                mostrarConjunto(resultadoDiferenciaBA);
                break;
            }
            case 13: {
                mostrarConjunto(conjuntoA);
                mostrarConjunto(conjuntoB);
                break;
            }
            case 14: {
                std::vector<char> complementoResult = complementoConjuntoUniverso(conjuntoA, universo);
                std::cout << "Complemento del Conjunto respecto al Universo: ";
                mostrarConjunto(complementoResult);
                break;
            }
            case 0:
                std::cout << "Saliendo del programa" << std::endl;
                break;
            default:
                std::cout << "Opcion no valida" << std::endl;
        }

    } while (opcion != 0);

    return 0;
}
