/* Presentacion
Nombre: Juan Fernando Gomez Navarro
Fecha: 20 de Febrero del 2024
Programa: Actividad de programación - 6
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
Descripcion: Es un codigo de suma de un vector que no tiene
limite de espacios,usuario final elige cuando entra un valor a
cada posicon, muestra lista de valores, muestra la sumatoria, borrado,
edicion y vaciado de arreglo.
*/
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main() {
    vector<int> Vec;
    int Valor;
    char Opcion;
    int Posicion;
    int Sumatoria = 0;

    do {
        cout << "Ingrese un valor: ";
        cin >> Valor;
        Vec.push_back(Valor);
        cout << "Desea agregar otro valor? (S/N)";
        cin >> Opcion;
    } while (Opcion == 'S' || Opcion == 's');

    for (int i = 0; i < Vec.size(); i++) {
        Sumatoria += Vec[i];
    }

    cout << "La sumatoria de los elementos del vector es: " << Sumatoria << endl;
    cout << "Desea editar o borrar algun elemento del vector? (S/N)";
    cin >> Opcion;

    if (Opcion == 'S' || Opcion == 's') {
        do {
            cout << "Desea editar o borrar algun elemento? (E/B)";
            cin >> Opcion;

            if (Opcion == 'E' || Opcion == 'e') {
                cout << "Ingrese la posicion del elemento a editar: ";
                cin >> Posicion;
                cout << "Ingrese el nuevo valor: ";
                cin >> Valor;
                Vec[Posicion] = Valor;
                cout << "Elemento editado" << endl;
            } else if (Opcion == 'B' || Opcion == 'b') {
                cout << "Ingrese la posicion del elemento a borrar: ";
                cin >> Posicion;
                Vec.erase(Vec.begin() + Posicion);
                cout << "Elemento borrado" << endl;
            }

            cout << "Desea editar o borrar otro elemento? (S/N)";
            cin >> Opcion;
        } while (Opcion == 'S' || Opcion == 's');
    }

    cout << "Desea vaciar el vector? (S/N)";
    cin >> Opcion;

    if (Opcion == 'S' || Opcion == 's') {
        Vec.clear();
        cout << "Vector vaciado" << endl;
    }

    return 0;
}
