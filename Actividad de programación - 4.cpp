/* Presentacion
Nombre: Juan Fernando Gomez Navarro
Fecha: 06 de Febrero del 2024
Programa: Actividad de programacion - 4
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
Descripcion: Es un codigo que elabora la serie Fibonacci utilizando los 3 ciclos basicos (for, while y do-while).
*/
#include <stdio.h>

int main() {// Inicio de main
    // Declaración de variables
    char opcion;
    int valorLimite, a = 0, b = 1, temp;

    // Bucle principal del programa
    do {
        // Solicita al usuario un valor limite para la serie Fibonacci
        printf("Ingrese un valor limite para la serie Fibonacci: ");
        scanf("%d", &valorLimite);

        // Solicitar al usuario que elija el ciclo (for, while, do-while) o salir
        printf("Elija el ciclo (f - for, w - while, d - do-while, s - salir): ");
        scanf(" %c", &opcion);

        // Switch para manejar la eleccion del usuario
        switch (opcion) {
            case 'f':
            case 'F':
                // Serie Fibonacci con ciclo for
                printf("Serie Fibonacci con ciclo for:\n");
                for (; a <= valorLimite;) {
                    // Imprimir el valor actual de la serie
                    printf("%d ", a);

                    // Calcular el siguiente numero de Fibonacci
                    temp = a + b;
                    a = b;
                    b = temp;
                }
                break;

            case 'w':
            case 'W':
                // Serie Fibonacci con ciclo while
                printf("Serie Fibonacci con ciclo while:\n");
                while (a <= valorLimite); {
                    // Imprimir el valor actual de la serie
                    printf("%d ", a);

                    // Calcular el siguiente numero de Fibonacci
                    temp = a + b;
                    a = b;
                    b = temp;
                }
                break;

            case 'd':
            case 'D':
                // Serie Fibonacci con ciclo do-while
                printf("Serie Fibonacci con ciclo do-while:\n");
                do {
                    // Imprimir el valor actual de la serie
                    printf("%d ", a);

                    // Calcular el siguiente numero de Fibonacci
                    temp = a + b;
                    a = b;
                    b = temp;
                } while (a <= valorLimite);
                break;

            case 's':
            case 'S':
                // Mensaje de salida del programa
                printf("Saliendo del programa.\n");
                break;

            default:
                // Mensaje en caso de una opción no valida
                printf("Opcion no valida. Por favor, elija de nuevo.\n");
        }

    } while (opcion != 's' && opcion != 'S');  // Salir del bucle si el usuario elige 's' o 'S'

    return 0;
}// Fin de main
