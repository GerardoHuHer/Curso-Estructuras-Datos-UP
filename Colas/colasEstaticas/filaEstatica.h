#pragma once
#include <iostream>
#define TAM 8 
/*
Las filas funcionan con un esquema FIFO (First In First Out).
*/

/*
Insertar
a) Verificar que existe capacidad disponible en el arreglo si final es igual a máximo, la cola está llena.
b) Incrementar el valor de final.
c) Insertar el nuevo valor en la posición de final.

Extraer
a) Verificar si hay valor en la cola.
b) Si final y principio son menores que mínimo, la cola está vacía.
Si "Principio" es mayor que "Final" la cola está vacía
c) Extraer el valor de la posición señalada por "Principio".
d) Incrementar el valor de "Principio"
*/

class Colas{
public:
  Colas();
  int extrar();
  int insertar(int);
  void mostrar();
private:
  int cola[TAM];
  int principio, final;
  int maximo, minimo;
};

void menu();
