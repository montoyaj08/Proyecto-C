#include <stdio.h>
#include <stdbool.h>

int ciudad_visitada(int camino[], int visitados, int ciudad) {
    for (int i = 0; i < visitados; i++) {
        if (camino[i] == ciudad) {
            return false; 
        }
    }
    return true;
}

void caminos(int num_ciudades, int matrix[num_ciudades][num_ciudades], int actual, int destino, int camino[], int distancia, int visitados, int *punt_distancia, int min_camino[], int *punt_visitados){

    camino[visitados] = actual;

    if (actual == destino) {
        if (distancia < *punt_distancia) {
            *punt_distancia = distancia;
            *punt_visitados = visitados;
            for (int i = 0; i <= visitados; i++) {
                min_camino[i] = camino[i];
            }
        }
    } 

    else {

        for (int i = 0; i < num_ciudades; i++) {
            if (matrix[actual][i] != 0 && matrix[actual][i] != -1 && ciudad_visitada(camino, visitados, i)) {
                caminos(num_ciudades, matrix, i, destino, camino, distancia + matrix[actual][i], visitados + 1, punt_distancia, min_camino, punt_visitados);
            }
        }
    }

    visitados = visitados - 1;
    distancia = distancia - matrix[camino[visitados - 1]][actual];
}

int main(){

    int num_ciudades;
    printf("Ingrese el numero de ciudades: ");
    scanf("%d", &num_ciudades);

    int matrix[num_ciudades][num_ciudades];
    int distancia;
    for (int i = 1; i < num_ciudades; i++){
        for (int j = 0; j < i; j++){
            printf("Ingrese la distancia entre la ciudad %d y la ciudad %d: ", i, j);
            scanf("%d", &distancia);
            matrix[i][j] = distancia;
            matrix[j][i] = distancia;
        }
    }

    for (int i = 0; i < num_ciudades; i++) {
        matrix[i][i] = 0;
    }

// ****************************************************
    printf("Matriz:\n");
    for (int i = 0; i < num_ciudades; i++) {
        for (int j = 0; j < num_ciudades; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
// ****************************************************
    
    int origen, destino;
    printf("Indique el origen y el destino: ");
    scanf("%d", &origen);
    scanf("%d", &destino);

    int camino[num_ciudades];
    int mejor_distancia = 1000000;
    int mejor_camino[num_ciudades];
    int mejor_visitados = 0;
    caminos(num_ciudades, matrix, origen, destino, camino, 0, 0, &mejor_distancia, mejor_camino, &mejor_visitados);

    printf("Camino más corto: ");
    for (int i = 0; i < mejor_visitados + 1; i++) {
        printf("%d ", mejor_camino[i]);
    }
    printf("\n");

    // Imprimir la distancia total del camino más corto
    printf("Distancia total del camino más corto: %d\n", mejor_distancia);

    return 0;
}