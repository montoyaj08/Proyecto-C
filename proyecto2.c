/*
Integrantes:

1. Jose Montoya Hernandez, C05066
2. Ebandry Calderón Araya, B81372
3. Susan Morales Alfaro, A94203

Descripcion del programa: El siguiente programa le permite solicitar al usuario un numero 
determinado de coordenadas y a partir de esas coordenadas el programa primeramente revisa
que el poligono ingresado sea convexo y si se cumple, procede a calcular cada uno de los
angulos internos de este.
*/

// Bibliotecas necesarias
#include <stdio.h>
#include <math.h>

// Se crea una funcion para que se guarden las coordenadas en el plano cartersiano
typedef struct {
    float x, y;  
} punto;

// Lo primero es detectar si el poligono ingresado es convexo, 
// esto con el metodo de la orientacion de puntos (leer en README)
// Funcion para calcular el producto punto
float productoCruz(punto a, punto b, punto c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

// Funcion para determinar la orientacion de tres puntos (coordenadas) en el plano
int orientacion(punto a, punto b, punto c) {
    float cruz = productoCruz(a, b, c);
    if (cruz == 0) return 0;  
    return (cruz > 0) ? 1 : -1;  
}

// Funcion para verificar si cumple la condicion de si es convexo
int esConvexo(punto poligono[], int n) {
    if (n < 3) return 0;  

    int orientInicial = orientacion(poligono[0], poligono[1], poligono[2]);

    for (int i = 1; i < n - 1; i++) {
        int orientActual = orientacion(poligono[i], poligono[i + 1], poligono[(i + 2) % n]);

        if (orientActual != orientInicial) {
            return 0;  
        }
    }

    return 1;  
}

// Luego de verificar si es convexo, se procede a calcular los angulos internos
// Se detalla un poco mas en el README
// Funcion para calcular el angulo entre tres puntos en el plano
float funAngulo(punto p1, punto p2, punto p3) {
    float a1 = atan2(p2.y - p1.y, p2.x - p1.x);
    float a2 = atan2(p3.y - p2.y, p3.x - p2.x);
    float angulo = a2 - a1;

    if (angulo < 0) {
        angulo += 2 * M_PI;
    }

    return angulo * 180 / M_PI;
}

// Funcion para imprimir el valor de cada angulo interno y dar la suma de todos los angulos internos
void impAngulo(punto vertices[], int numVertices) {
    printf("Su polígono tiene los siguientes ángulos:\n");

    float sumaAngulos = 0.0;
    for (int i = 0; i < numVertices; i++) {
        int j = (i + 1) % numVertices;

        float angulo = 180.0 - funAngulo(vertices[i], vertices[j], vertices[(i + 2) % numVertices]);

        sumaAngulos += angulo;

        // Se obtiene el valor absoluto porque en algunos casos los angulos resultan negativos
        printf("Ángulo %d: %.2f grados\n", i + 1, fabs(angulo));
    }

    // De igual manera, se utiliza valor absoluto para obtener el resultado positivo
    printf("La suma total de sus ángulos es: %.2f grados\n", fabs(sumaAngulos));
}

// Funcion principal, solicita las coordenadas al usuario y hace el llamado de las funciones anteriores 
int main() {
    int num_puntos;

    printf("Digite cuantas coordenadas desea agregar: ");
    scanf("%d", &num_puntos);

    // Condicion porque un poligono debe de tener 3 o mas lados
    if (num_puntos < 3) {
        printf("Un polígono tiene 3 o mas vertices. Saliendo del programa.\n");
        return 1; 
    }

    punto poligono[num_puntos];

    for (int i = 0; i < num_puntos; ++i) {
    printf("Digite las coordenadas para el vertice %d (x y): ", i + 1);
    
    // Condicion por si no se respeta como se deben de ingresar las coordenadas
    if (scanf("%f %f", &poligono[i].x, &poligono[i].y) != 2) {
        printf("Debe ingresar valores numéricos para las coordenadas. Saliendo del programa.\n");
        return 1; 
    }
    }

    // Mensajes para indicar si el poligono ingresado es convexo o concavo
    if (esConvexo(poligono, num_puntos)) {
        printf("El polígono es convexo.\n");
        
        impAngulo(poligono, num_puntos);
    } else {
        printf("El polígono no es convexo.\n");
    }

    return 0;
}

 