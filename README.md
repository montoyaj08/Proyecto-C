# Proyecto-C

Parte 2: Ángulos

Indicación para introducir las coordenas (x, y): ingrese solamente sus coordenadas (entero o flotando) separado de un espacio. 
Ejemplo: 0.0 0.5


Método esConvexo: 
El primer paso es determinar si el polígono ingresado es convexo. El método de la orientación de puntos calcula el producto cruz de vectores formados por puntos consecutivos en el polígono y luego revisa el signo de estos productos cruzados. Si todos los productos cruz tienen el mismo signo, entonces el polígono es convexo, si hay algún cambio en el signo de los productos cruzados, el polígono es no convexo. Este método funciona con el hecho de que en un polígono convexo, todos los ángulos internos son menores a 180 grados. Esto implica que los vectores formados por puntos consecutivos en el polígono tienen el mismo sentido, y como resultado, el producto cruz entre dichos vectores siempre tiene el mismo signo.


Método calculo de ángulos internos:
Para calcular los ángulos internos entre tres puntos en el plano es mediante la trigonometría y la obtención de ángulos polares. 
Se calculan los vectores AB y BC.
Se utiliza la función arcotangente para obtener los ángulos polares de los vectores AB y BC.
Se calcula los ángulos entre los vectores.
Se establece el rango [0, 2π). 
Se convierten los angulos de radianes a grados.
