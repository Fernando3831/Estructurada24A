/* Presentacion
Nombre: Juan Fernando Gomez Navarro
Fecha: 04-Febrero-2024
Programa: Caracteres
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / 2DO SEMESTRE
PROFESOR: Sergio Franco Casillas
Descripcion: Es un codigo que imprime caracateres de escape y cadenas de control de tipo de salida
*/
#include <cstdio>
int main() {
    // Caracteres de escape
    printf("Caracteres de escape:\n");
    printf("1. Salto de linea: \n");// Sirve para dar un salto de linea para un mejor acomodo de los datos en vertical
    printf("2. Tabulacion: Texto\tdespues de la tabulacion\n");// Agrega una tabulacion despues del texto
    printf("3. Retroceso: \bTexto \bcon retroceso\n");// Retrocede un espacio al texto siguiente
    printf("4. Retorno de carro:\r Retorno de carro \n");// Envia al texto un linea antes
    printf("5. Comilla simple: \"Comillas dobles\"\n");// Arroja al texto entre comillas dobles
    printf("6. Diagonal invertida: Diagonal invertida\\ \n");// Nos imprime una diagonal en el texto
    printf("\n");
    // Cadenas de control de tipos de salida
    printf("Cadenas de control de tipos de salida:\n");
    printf("1. Entero Decimal: %d\n", 123);// Sirve para escribir datos enteros
    printf("2. Octal: %o\n", 123);// Esto convierte el decimal a sistena octal
    printf("3. Hexadecimal: %x\n", 123);// Pasa del decimal a hexadecimal
    printf("4. Notacion cientifica: %e\n", 1.23e4);// Convierte la notacion cientifica a decimal
    printf("5. Ajuste de ancho de campo: %10s\n", "Ancho");// Nos entrega los espacios que designemos
    printf("6. Rellenar con ceros: %03d\n", 42);// Agrega los ceros que se indiquen antes del numero

    return 0;
}
