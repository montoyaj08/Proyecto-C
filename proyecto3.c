#include <stdio.h>
#include <stdlib.h>

// La función retorna un número entero: 0 si no hay errores, -1 si hubo algún error
int obtenerDirecciones(int **matriz, int filas, int columnas, int ***direcciones) {
    if (matriz == NULL || direcciones == NULL) {
        return -1; // Error si la matriz o las direcciones son nulas
    }

    *direcciones = (int **)malloc(filas * sizeof(int *));

    if (*direcciones == NULL) {
        return -1; // Error si no se pudo reservar memoria
    }

    for (int i = 0; i < filas; i++) {
        (*direcciones)[i] = &matriz[i][0]; // Almacenar la dirección de inicio de cada fila
    }

    return 0; // No hay errores
}

int main() {
    int filas, columnas;

    // Se solicita al usuario las dimensiones de la matriz
    printf("Ingrese el número de filas: ");
    scanf("%d", &filas);
    printf("Ingrese el número de columnas: ");
    scanf("%d", &columnas);

    // Se reserva la memoria para la matriz
    int **matriz = (int **)malloc(filas * sizeof(int *));
    for (int i = 0; i < filas; i++) {
        matriz[i] = (int *)malloc(columnas * sizeof(int));
    }

    // Se solicita al usuario los números enteros 
    // que representan las posiciones en la matriz
    printf("Ingrese los números enteros para la matriz:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Se obtienen las direcciones de inicio de cada fila
    int **direcciones;
    int resultado = obtenerDirecciones(matriz, filas, columnas, &direcciones);

    if (resultado == 0) {
        // Imprimir las direcciones de inicio de cada fila
        printf("Direcciones de inicio de cada fila:\n");
        for (int i = 0; i < filas; i++) {
            printf("%p\n", (void *)direcciones[i]);
        }

        // Liberar memoria utilizada
        free(direcciones);
        for (int i = 0; i < filas; i++) {
            free(matriz[i]);
        }
        free(matriz);
    } else {
        printf("Error al obtener direcciones.\n");
    }

    return 0;
}
