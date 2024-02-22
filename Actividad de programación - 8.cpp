/* --- Presentacion ---
Nombre: Juan Fernando Gomez Navarro
Fecha: 21 de Febrero del 2024
Programa: Actividad de programacion - 8
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
Descripcion: Es un codigo que elabora operaciones de conjuntos,
inserta valores por parte del usuario ya sean textuales o
numericos,borra y edita los elementos, vaciado de conjuntos,
operaciones de union, diferencia y complemento.
*/
// Declaracion de bibliotecas
#include <iostream>
#include <vector>
#include <algorithm>

// Funcion para mostrar los elementos de un conjunto
template <typename T>
void mostrarConjunto(const std::vector<T>& conjunto) {
    std::cout << "Conjunto: { ";
    for (const auto& elemento : conjunto) {
        std::cout << elemento << " ";
    }
    std::cout << "}" << std::endl;
}

// Funcion para insertar un valor en un conjunto
template <typename T>
void insertarElemento(std::vector<T>& conjunto) {
    T valor;
    std::cout << "Ingresa el valor a insertar: ";
    std::cin >> valor;
    conjunto.push_back(valor);
    std::cout << "Elemento insertado correctamente" << std::endl;
}

// Función para borrar un elemento de un conjunto
template <typename T>
void borrarElemento(std::vector<T>& conjunto) {
    if (!conjunto.empty()) {
        T valor;
        std::cout << "Ingresa el valor a borrar: ";
        std::cin >> valor;
        auto it = std::find(conjunto.begin(), conjunto.end(), valor);
        if (it != conjunto.end()) {
            conjunto.erase(it);
            std::cout << "Elemento borrado correctamente" << std::endl;
        } else {
            std::cout << "El elemento no existe en el conjunto" << std::endl;
        }
    } else {
        std::cout << "El conjunto esta vacio. No se puede borrar elementos" << std::endl;
    }
}

// Funcion para editar un elemento de un conjunto
template <typename T>
void editarElemento(std::vector<T>& conjunto) {
    if (!conjunto.empty()) {
        T valorAntiguo, valorNuevo;
        std::cout << "Ingrese el valor a editar: ";
        std::cin >> valorAntiguo;
        auto it = std::find(conjunto.begin(), conjunto.end(), valorAntiguo);
        if (it != conjunto.end()) {
            std::cout << "Ingrese el nuevo valor: ";
            std::cin >> valorNuevo;
            *it = valorNuevo;
            std::cout << "Elemento editado correctamente" << std::endl;
        } else {
            std::cout << "El elemento no existe en el conjunto" << std::endl;
        }
    } else {
        std::cout << "El conjunto esta vacío. No se puede editar elementos" << std::endl;
    }
}

// Funcion para vaciar un conjunto
template <typename T>
void vaciarConjunto(std::vector<T>& conjunto) {
    conjunto.clear();
    std::cout << "Conjunto vaciado correctamente" << std::endl;
}

// Funcion para realizar la union de dos conjuntos
template <typename T>
std::vector<T> unionConjuntos(const std::vector<T>& conjuntoA, const std::vector<T>& conjuntoB) {
    std::vector<T> resultado = conjuntoA;
    for (const auto& elemento : conjuntoB) {
        if (std::find(resultado.begin(), resultado.end(), elemento) == resultado.end()) {
            resultado.push_back(elemento);
        }
    }
    return resultado;
}

// Funcion para efectuar interseccion de dos conjuntos
template <typename T>
std::vector<T> interseccionConjuntos(const std::vector<T>& conjuntoA, const std::vector<T>& conjuntoB) {
    std::vector<T> resultado;
    for (const auto& elemento : conjuntoA) {
        if (std::find(conjuntoB.begin(), conjuntoB.end(), elemento) != conjuntoB.end()) {
            resultado.push_back(elemento);
        }
    }
    return resultado;
}

// Funcion para realizar la diferencia de dos conjuntos (A - B)
template <typename T>
std::vector<T> diferenciaConjuntos(const std::vector<T>& conjuntoA, const std::vector<T>& conjuntoB) {
    std::vector<T> resultado;
    for (const auto& elemento : conjuntoA) {
        if (std::find(conjuntoB.begin(), conjuntoB.end(), elemento) == conjuntoB.end()) {
            resultado.push_back(elemento);
        }
    }
    return resultado;
}

int main() {
    std::vector<int> conjuntoA;
    std::vector<int> conjuntoB;

    int opcion;
    do {
        std::cout << "\n--- Menu Principal ---" << std::endl;
        std::cout << "1. Insertar elemento en conjunto A" << std::endl;
        std::cout << "2. Borrar elemento en conjunto A" << std::endl;
        std::cout << "3. Editar elemento en conjunto A" << std::endl;
        std::cout << "4. Vaciar conjunto A" << std::endl;
        std::cout << "5. Insertar elemento en conjunto B" << std::endl;
        std::cout << "6. Borrar elemento en conjunto B" << std::endl;
        std::cout << "7. Editar elemento en conjunto B" << std::endl;
        std::cout << "8. Vaciar conjunto B" << std::endl;
        std::cout << "9. Realizar union de conjuntos A y B" << std::endl;
        std::cout << "10. Realizar interseccion de conjuntos A y B" << std::endl;
        std::cout << "11. Realizar diferencia A - B" << std::endl;
        std::cout << "12. Realizar diferencia B - A" << std::endl;
        std::cout << "13. Mostrar conjuntos" << std::endl;
        std::cout << "0. Salir" << std::endl;
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
            case 13:
                mostrarConjunto(conjuntoA);
                mostrarConjunto(conjuntoB);
                break;
            case 0:
                std::cout << "Saliendo del programa" << std::endl;
                break;
            default:
                std::cout << "Opcion no valida" << std::endl;
        }

    } while (opcion != 0);

    return 0;
}
