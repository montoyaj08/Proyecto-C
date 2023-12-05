#include <stdio.h>
         
void funcion(int matrix, int num_ciudades, int actual, int destino, int camino[], int distancia, int visitados){

    camino[visitados] = actual;

    if (actual == destino) {
        printf("Encontrado un camino nuevo");
    } 

    else {

        for (int i = 0; i < num_ciudades; i++) {
            if (matrix[actual][i] != 0 && matrix[actual][i] != -1) {
                funcion(matrix, num_ciudades, i, destino, camino, distancia + matrix[actual][i], visitados + 1);
            }
        }
    }

    camino[visitados] = 0;
}

int main(){
    int num_ciudades;
    printf("Ingrese en numero de ciudades: ");
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

    printf("Matriz:\n");
    for (int i = 0; i < num_ciudades; i++) {
        for (int j = 0; j < num_ciudades; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    int origen, destino, min_distancia;

    printf("Indique el origen y el destino: ");
    scanf("%d %d", &origen, &destino);

    int camino[];
    funcion(matrix, num_ciudades, origen, destino, camino, 0, 0);

    return 0;
}