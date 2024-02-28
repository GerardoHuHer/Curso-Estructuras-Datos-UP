#pragma once
#include <iostream>
/*
Pilas
Es un dato estructurado lineal, no fundamental, homogéneo y finito. Se caracteriza por tres parámetros o propiedades: mínimo, máximo y tope. Con el que se pueden realizar por dos operaciones: insertar y extraer. Ambas operaciones solamente se pueden realizar por el extremo que corresponde al tope, como muestra la figura.
*/

/*
Insertar (Push)(Insertar un elemento de la pila)
a) Verificar que existe capacidad disponible en la pila. Si tope es igual a máximo la pila está llena.
b) Incrementar el valor de tope.
c) Insertar el nuevo valor en la posición señalada por Tope

Extraer(Pop)(Eliminar un elemento de la pila)
a) Verificar que hay valores en la pila.Si tope es menor que mínimo, la pila está vacía
b) Extraer el valor de la posición señalada por tope.
c) Decrementar el valor de tope.

Cosultar(peek)(Consultar los datos de la pila)
a) Verificar que hay valores en la pila. Si tope es menor que mínimo, la pila está vacía.
b) Mostrar el valor de la posición señalada por "Tope".

PILAS LIGADAS
Una forma frecuente de implementar las pilas en la computadora es por medio de arreglos, mismos que cuentan con la característica de consecutividad, sin embargo, no siempre se cuenta con esta posibilidad.
Cuando no se cuenta con localidades consecutivas de memoria para la implementación de las pilas, se puede recurrir a las "pilas ligadas".

Insertar (push):
1) Crear un "nodo"
2) Registrar los datos en el campo de información del nodo.
3) El campo de enlace del nodo hacerlo igual al "tope".
4) "tope" apuntarlo al nuevo nodo.

Elminar (pop)
1) Verificar que hay valores en la pila. Si "tope" apunta a NULL, la pila está vacía.
2) Extraer información del "tope", igualando "extraído" a "tope".
3) Descender "tope", igualando "tope" al campo de enlace de "extraido"
4) Entregar los datos del campo de información de "extraido"
5) Liberar "extraido"
*/
 
struct Entero{
  int dato;
  Entero* anterior;
};

class Pila{
public:
  Pila();
  int Consultar();
  int Extraer();
  void Insertar(int);
  void Mostrar();
private:
  Entero* tope, *nodo;
};

