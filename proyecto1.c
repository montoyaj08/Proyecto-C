/*
Jose Montoya Hernandez, C05066
Ebandry Calderón Araya B81372
Susan Morales A94203

Descripcion del programa: El siguiente programa le permite al usuario conocer
el camino mas corto entre dos ciudades que el mismo solicite. Para ello,
se le pide que ingrese el numero de ciudades y la distancia entre ellas con el
fin de calcular todos los posibles caminos y asì determinar cual es el mas corto.
*/

#include <stdio.h>
#include <stdbool.h>

int ciudad_visitada(int camino[], int visitados, int ciudad){
    /* Se itera por la lista de ciudades visitadas para comprobar
    que la ciudad en cuestion esta o no esta. Se devuelve un valor
    booleano para indicarlo. */
    for (int i = 0; i < visitados; i++){
        if (camino[i] == ciudad){
            return false; 
        }
    }
    return true;
}

void caminos(
    int num_ciudades, int matrix[num_ciudades][num_ciudades], int actual, int destino, int camino[], 
    int distancia, int visitados, int *punt_distancia, int min_camino[], int *punt_visitados){
    // Guarda la ciudad actual en la lista de caminos visitados.
    camino[visitados] = actual;
    // Se ejecuta si la ciudad actual es la ciudad de destino dada por el usuario.
    if (actual == destino) {
        /* Actualizacion de la distancia recorrida mas corta y de las ciudadades visitadas
        en este caso. */ 
        if (distancia < *punt_distancia) {
            *punt_distancia = distancia;
            *punt_visitados = visitados;
            for (int i = 0; i <= visitados; i++) {
                min_camino[i] = camino[i];
            }
        }
    }
    // Si todavia no se ha llegado al destino se siguen dando pasos a las demas ciudades.
    else {
        // Se itera por cada uno de los posbles caminos a tomar segun la ciudad actual.
        for (int i = 0; i < num_ciudades; i++) {
            /* Se comprueba que la ciudad que se quiere visitar no este dentro de los casos 0 o -1.
            Ademas, mediante la funcion 'ciudad_visitada' tambien se comprueba que no este dentro
            de la lista de ciudades visitadas. */
            if (matrix[actual][i] != 0 && matrix[actual][i] != -1 && ciudad_visitada(camino, visitados, i)) {
                // Se hace una llamada recursiva de la funcion 'caminos' con los parametros actualizados.
                caminos(num_ciudades, matrix, i, destino, camino, distancia + matrix[actual][i], visitados + 1,
                punt_distancia, min_camino, punt_visitados);
            }
        }
    }
    // Se eliminan las acciones del ultimo paso si por el camino tomado no se pudo llegar al destino.
    visitados = visitados - 1;
    distancia = distancia - matrix[camino[visitados - 1]][actual];
}

int main(){
    // Se le pide al usuario que ingrese el numero de ciudades.
    int num_ciudades;
    printf("Ingrese el numero de ciudades: ");
    scanf("%d", &num_ciudades);
    // Se crea una matriz nxn con las dimensiones igual a 'num_ciudades'.
    int matrix[num_ciudades][num_ciudades];
    int distancia;
    /* Ya que la matriz es simetrica, se itera por las entradas de la mitad inferior
    solicitando al usuario la distancia entre ciudades. */
    printf("A continuacion, ingrese la distancia entre ciudades y utilice -1 si entre dos ciudades NO hay camino:\n");
    for (int i = 1; i < num_ciudades; i++){
        for (int j = 0; j < i; j++){
            printf("Ingrese la distancia entre la ciudad %d y la ciudad %d: ", i, j);
            scanf("%d", &distancia);
            matrix[i][j] = distancia;
            matrix[j][i] = distancia;
        }
    }
    // Se establece que la distancia entre una ciudad y ella misma es de cero.
    for (int i = 0; i < num_ciudades; i++) {
        matrix[i][i] = 0;
    }
    // Se imprime la representacion en matriz de las distancias entre ciudades. 
    printf("Representacion en matriz:\n");
    for (int i = 0; i < num_ciudades; i++) {
        for (int j = 0; j < num_ciudades; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    // Se le pida al usuario la ciudad de origen y de destino.
    int origen, destino;
    printf("Indique la ciudad de origen: ");
    scanf("%d", &origen);
    printf("Indique la ciudad de destino: ");
    scanf("%d", &destino);
    /* Array que guarda el camino recorrido en cada intento de la funcion 'caminos'
    para llegar al destino. */
    int camino[num_ciudades];
    /* Inicializacion de entero que se actualiza en la funcion 'caminos' cada vez
    que se encuentra un camino mas corto. */ 
    int mejor_distancia = 1000000;
    /* Array que se actualiza junto con 'mejor_distancia' para guardar el recorrido
    realizado en el camino mas corto. */
    int mejor_camino[num_ciudades];
    /* Entero que guarda el numero de ciudades visitada en el camino mas corto. */
    int mejor_visitados = 0;
    /* Se llama a la funcion recursiva 'caminos'. Los parametros que inicial en cero,
    representan la distancia y las ciudades visitadas en cada intento. */
    caminos(num_ciudades, matrix, origen, destino, camino, 0, 0, &mejor_distancia, mejor_camino, &mejor_visitados);
    // Muestra al usuario el camino mas corto y la distancia total recorrida.
    printf("Camino más corto: ");
    for (int i = 0; i < mejor_visitados; i++) {
        printf("%d -> ", mejor_camino[i]);
    }
    printf("%d", mejor_camino[mejor_visitados]);
    printf("\n");
    printf("Distancia total del camino más corto: %d\n", mejor_distancia);
    return 0;
}