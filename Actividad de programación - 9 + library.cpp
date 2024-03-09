/* --- Presentacion ---
Nombre: Juan Fernando Gomez Navarro
Fecha: 08 de Marzo del 2024
Programa: Actividad de programacion - 9
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
Descripcion: Es un codigo que funge como biblioteca de funciones,
que elabora operaciones de conjuntos,
inserta valores por parte del usuario ya sean textuales o
numericos,borra y edita los elementos, vaciado de conjuntos,
operaciones de union, diferencia y complemento.
*/

// Biblioteca de funciones
template <typename T>// Inicio de declaracion para funcion de plantilla
void mostrarConjunto(const std::vector<T>& conjunto) {// Funcion que no devuleve ningun valor,nombre de la funcion,parametros de la funcion,conjunto es un vector (std::vector) que contiene elementos de tipo T. El vector se pasa por referencia constante (const&), lo que significa que la función no modificará el contenido del vector original.
    std::cout << "Conjunto: { ";//Imprimir en consola
    for (const auto& elemento : conjunto) {//Itera a través de cada elemento en el vector conjunto.
        std::cout << elemento << " ";//Imprime cada elemento del conjunto seguido por un espacio en blanco.
    }
    std::cout << "}" << std::endl;//Finaliza la representación del conjunto con "}"
}

template <typename T>//Inicio declaracion
bool contieneElemento(const std::vector<T>& conjunto, const T& elemento) {//funcion de valor booleano,
    return std::find(conjunto.begin(), conjunto.end(), elemento) != conjunto.end();//Nombre de funcion, parametros de funcion, vector
}

template <typename T>
void insertarElemento(std::vector<T>& conjunto) {
    T elemento;
    std::cout << "Ingrese un elemento: ";
    std::cin >> elemento;

    if (!contieneElemento(conjunto, elemento)) {
        conjunto.push_back(elemento);
        std::cout << "Elemento insertado correctamente." << std::endl;
    } else {
        std::cout << "El elemento ya existe en el conjunto. No se permite repetir elementos." << std::endl;
    }
}

template <typename T>
void borrarElemento(std::vector<T>& conjunto) {
    if (!conjunto.empty()) {
        T elemento;
        std::cout << "Ingrese el elemento a borrar: ";
        std::cin >> elemento;

        auto it = std::find(conjunto.begin(), conjunto.end(), elemento);
        if (it != conjunto.end()) {
            conjunto.erase(it);
            std::cout << "Elemento borrado correctamente." << std::endl;
        } else {
            std::cout << "El elemento no existe en el conjunto." << std::endl;
        }
    } else {
        std::cout << "El conjunto esta vacio, no se pueden borrar elementos." << std::endl;
    }
}

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

            if (!contieneElemento(conjunto, valorNuevo)) {
                *it = valorNuevo;
                std::cout << "Elemento editado correctamente." << std::endl;
            } else {
                std::cout << "El nuevo valor ya existe en el conjunto. No se permite repetir elementos." << std::endl;
            }
        } else {
            std::cout << "El elemento no existe en el conjunto." << std::endl;
        }
    } else {
        std::cout << "El conjunto esta vacio, no se pueden editar elementos." << std::endl;
    }
}

template <typename T>
void vaciarConjunto(std::vector<T>& conjunto) {
    conjunto.clear();
    std::cout << "Conjunto vaciado correctamente." << std::endl;
}

template <typename T>
std::vector<T> unionConjuntos(const std::vector<T>& conjuntoA, const std::vector<T>& conjuntoB) {
    std::vector<T> resultado = conjuntoA;
    for (const auto& elemento : conjuntoB) {
        if (!contieneElemento(resultado, elemento)) {
            resultado.push_back(elemento);
        }
    }
    return resultado;
}

template <typename T>
std::vector<T> interseccionConjuntos(const std::vector<T>& conjuntoA, const std::vector<T>& conjuntoB) {
    std::vector<T> resultado;
    for (const auto& elemento : conjuntoA) {
        if (contieneElemento(conjuntoB, elemento)) {
            resultado.push_back(elemento);
        }
    }
    return resultado;
}

template <typename T>
std::vector<T> diferenciaConjuntos(const std::vector<T>& conjuntoA, const std::vector<T>& conjuntoB) {
    std::vector<T> resultado;
    for (const auto& elemento : conjuntoA) {
        if (!contieneElemento(conjuntoB, elemento)) {
            resultado.push_back(elemento);
        }
    }
    return resultado;
}

template <typename T>
std::vector<T> complementoConjuntoUniverso(const std::vector<T>& conjunto, const std::vector<T>& universo) {
    return diferenciaConjuntos(universo, conjunto);
}// Fin de la biblioteca de funciones
