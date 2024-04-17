/* Presentacion
Nombre: Juan Fernando Gomez Navarro
Fecha: 16 de Abril del 2024
Programa: Actividad de programación - 14
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
Descripcion: Es un codigo que tiene una funcion parecida al juego
del ahorcado y cumple con las siguientes condiciones, como un
banco de almenos 20 palabras en donde la computadora elige una al
azar y el usuario debe adivinar el resultado, si el usuario
selecciona una vocal se penaliza recortando una oportundiad y
cuenta el numero de intentos por jugador.
*/

//Declaracion de bibliotecas
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

// Banco de palabras
const vector<string> palabras = {
    "pizarra", "silla", "mesa", "lapiz", "borrador",
    "marcador", "pluma", "tijeras", "libro", "mochila",
    "regla", "calculadora", "mapa", "reloj", "papel",
    "cuaderno", "escritorio", "papelera", "proyector", "computadora"
};

// Funcion para elegir una palabra al azar
string elegirPalabra() {
    srand(static_cast<unsigned int>(time(nullptr)));
    int indice = rand() % palabras.size();
    return palabras[indice];
}

// Funcion que muestra la palabra oculta con guiones bajos
string ocultarPalabra(const string& palabra) {
    string palabraOculta;
    for (char letra : palabra) {
        palabraOculta += "_ ";
    }
    return palabraOculta;
}

// Funcion para verificar si la letra esta en la palabra
bool letraEnPalabra(char letra, const string& palabra) {
    return palabra.find(letra) != string::npos;
}

int main() {
    string palabraSeleccionada = elegirPalabra();
    string palabraOculta = ocultarPalabra(palabraSeleccionada);
    int intentos = 6; // Número máximo de intentos

    cout << "Adivina palabras relacionadas a..." << endl;
    cout << "-Cosas que puedes encontrar en el salon de clase-" << endl;
    cout << "Palabra a adivinar: " << palabraOculta << endl;

    while (intentos > 0) {
        char letra;
        cout << "Ingresa una letra: ";
        cin >> letra;

        if (letraEnPalabra(letra, palabraSeleccionada)) {
            // Actualizar la palabra oculta con la letra correcta
            for (size_t i = 0; i < palabraSeleccionada.length(); ++i) {
                if (palabraSeleccionada[i] == letra) {
                    palabraOculta[i * 2] = letra;
                }
            }
        } else {
            cout << "Letra incorrecta. Pierdes 1 intento." << endl;
            --intentos;
        }

        cout << "Palabra actual: " << palabraOculta << endl;

        if (palabraOculta.find("_") == string::npos) {
            cout << "Ganaste. Has adivinado la palabra :) " << endl;
            break;
        }
    }

    if (intentos == 0) {
        cout << "Terminaste los intentos. La palabra era: " << palabraSeleccionada << endl;
    }

    return 0;
}
