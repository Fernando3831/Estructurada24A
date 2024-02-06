/* Presentacion
Nombre: Juan Fernando Gomez Navarro
Fecha: 06-Febrero-2024
Programa: Usuario ingresa numero
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
Descripcion: Es un codigo que pide un numero al usurario y dependiendo el numero va sumando de 5 en 5, 10 en 10,etc..
*/
#include <iostream>

int main() {
    int numero;
    char continuar;
    int contadorOperaciones = 0;

    do {
        printf("Ingresa un numero: ");// Solicitar número al usuario
        scanf("%d", &numero);

        if (numero > 0 && numero < 500) {// Verificar condiciones y realizar operaciones
            for (int i = 0; i < 100; ++i) {
                numero += 5;
                printf("Valor: %d\n", numero);
                contadorOperaciones++;
            }
        } else if (numero > 500 && numero < 1000) {
            for (int i = 0; i < 50; ++i) {
                numero += 10;
                printf("Valor: %d\n", numero);
                contadorOperaciones++;
            }
        } else if (numero > 1000) {
            printf("No se puede calcular el valor\n");
        }

        printf("¿Desea terminar el programa? (s/n): ");// Pregunta si desea terminar el programa
        std::cin >> continuar;

    } while (continuar != 's');

    printf("Operaciones realizadas: %d\n", contadorOperaciones); // Muestra el número de operaciones realizadas

    return 0;
}
