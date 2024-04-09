/* --- Presentacion ---
Nombre: Juan Fernando Gomez Navarro
Fecha: 09 de Abril del 2024
Programa: Actividad de programacion - 13
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
Descripcion: Es un código que recrea el juego de las Torres de Hanoi
utilizando el programa en C++ que le requiere al ususario ingresar
una palabra o frase, que deba contar el numero de vocales, consonantes,
y espacios, que determine si es una palabra de tipo palíndromo, convierte
la palabra o frase a Mayúsculas y minúsculas, y solicita otra palabra o frase
y que se concatene con la anterior.
*/
//Declaracion de bibliotecas
#include <iostream>
#include <cctype> // Para usar las funciones tolower y toupper

using namespace std;

bool is_palindrome(const string& input) {
    // Elimina los espacios y convierte a minusculas
    string cleaned_input;
    for (char c : input) {
        if (isalpha(c)) {
            cleaned_input += tolower(c);
        }
    }

    // Verifica si la entrada limpia es un palindromo
    for (int i = 0; i < cleaned_input.length() / 2; i++) {
        if (cleaned_input[i] != cleaned_input[cleaned_input.length() - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    string input;
    cout << "Ingresa una palabra o frase: ";
    getline(cin, input); // Leer la entrada completa tomando en cuenta los espacios

    int vowels = 0;
    int consonants = 0;
    int spaces = 0;

    for (char c : input) {
        if (isalpha(c)) { // Verifica si es una letra
            char lowercase_c = tolower(c); // Convierte a minusculas para comparar con las vocales
            if (lowercase_c == 'a' || lowercase_c == 'e' || lowercase_c == 'i' || lowercase_c == 'o' || lowercase_c == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        } else if (isspace(c)) { // Verifica si es un espacio
            spaces++;
        }
    }

    cout << "Numero de vocales: " << vowels << endl;
    cout << "Numero de consonantes: " << consonants << endl;
    cout << "Numero de espacios: " << spaces << endl;

    // Verifica si es un palindromo
    if (is_palindrome(input)) {
        cout << "Es un palindromo" << endl;
    } else {
        cout << "No es palindromo" << endl;
    }

    // Convertir a mayusculas
    for (char& c : input) {
        c = toupper(c);
    }
    cout << "Version en mayusculas: " << input << endl;

    // Convertir a minusculas
    for (char& c : input) {
        c = tolower(c);
    }
    cout << "Version en minusculas: " << input << endl;

    // Solicitar otra palabra o frase y concatenar
    string new_input;
    cout << "Ingresa otra palabra o frase: ";
    getline(cin, new_input);
    input += " " + new_input;
    cout << "Palabra o frase concatenada: " << input << endl;

    return 0;
}
