#include <cs50.h>
#include <stdio.h>

// Función para verificar si un número es par
int esPar(int numero) {
    return numero % 2 == 0;
}

// Función para verificar si un número es impar
int esImpar(int numero) {
    return !esPar(numero);
}

// Función para imprimir números de un tipo específico y calcular su suma
void imprimirNumerosYSumar(int inicio, int fin, int (*criterio)(int)) {
    int suma = 0;
    printf("Números: ");
    for (int i = inicio; i <= fin; i++) {
        if (criterio(i)) {
            printf("%d ", i);
            suma += i;
        }
    }
    printf("\nSuma: %d\n", suma);
}

// Función para manejar las opciones y delegar tareas
void manejarOpciones(int inicio, int fin) {
    int opcion;
    do {
        printf("\nElige una opción:\n");
        printf("1. Mostrar números pares y calcular su suma.\n");
        printf("2. Mostrar números impares y calcular su suma.\n");
        printf("3. Mostrar pares e impares con sus respectivas sumas.\n");
        printf("4. Salir.\n");
        opcion = get_int("Opción: ");

        switch (opcion) {
            case 1:
                printf("\nNúmeros pares:\n");
                imprimirNumerosYSumar(inicio, fin, esPar);
                break;
            case 2:
                printf("\nNúmeros impares:\n");
                imprimirNumerosYSumar(inicio, fin, esImpar);
                break;
            case 3:
                printf("\nNúmeros pares:\n");
                imprimirNumerosYSumar(inicio, fin, esPar);
                printf("\nNúmeros impares:\n");
                imprimirNumerosYSumar(inicio, fin, esImpar);
                break;
            case 4:
                printf("\nSaliendo del programa.\n");
                break;
            default:
                printf("\nOpción inválida. Intenta de nuevo.\n");
                break;
        }
    } while (opcion != 4);
}

// Programa principal
int main() {
    int inicio, fin;

    // Validar rango
    do {
        inicio = get_int("Ingresa el valor inicial del rango: ");
        fin = get_int("Ingresa el valor final del rango: ");

        if (inicio > fin) {
            printf("El valor inicial debe ser menor o igual al valor final. Intenta de nuevo.\n");
        }
    } while (inicio > fin);

    // Manejar opciones
    manejarOpciones(inicio, fin);

    return 0;
}
