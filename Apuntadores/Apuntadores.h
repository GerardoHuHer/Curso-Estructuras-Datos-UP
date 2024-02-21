#pragma once
#include <iostream>
#include <stdlib.h>
#include <malloc.h>

/*
Los apuntadores son variables que almacenan direcciones de memoria, también son llamadas variables de tipo apuntador o puntero.
Difieren de las demás variables en que no alamacenan directamente los datos, sino la dirección en memoria en que se encuentra el dato.
La utilidad del empleo de apuntadores se verá después de mostrar algunos ejemplos de su uso.
La aritmética de apuntadores se refiere a las operaciones de suma y resta de constantes que se pueden realizar sobre las variables de tipo apuntador. Al sumar 1 a un apuntador, se obtiene la dirección de la siguiente localidad de memoria.
Es importante hacer notar que a un apuntador no se le puede sumar o restar otro apuntador, solamente se le puede sumar o restar una constante entera.
*/

// Clase
class Apuntador{
private: 
  
public: 
  void Ejemplo_1();
  void Ejemplo_2();
  void Ejemplo_3();
  void AsignacionEst(int);
};
