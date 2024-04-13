#ifndef LISTASD_H
#define LISTASD_H
#include <iostream>

/*
Insertar intermedio:
- Localizar la posición en que se insertará.
- Crear un nodo nuevo.
- Llenar el campo de informacion del nodo nuevo.
- Colocar en el enlace del nodo nuevo el enlace del nodo anterior.
- En el enlace del nodo anterior colocar la dirección del nodo nuevo.

Insertar al principio:
- Crear un nodo nuevo.
- Llenar el campo de infomación del nodo nuevo.
- Llenar el campo de enlace del nodo nuevo, con la dirección de cabecera.
- Igualar "cabecera" a la dirección del nuevo nodo.

Insertar al final:
- Crear un nodo nuevo.
- Llenar el campo de información del nodo nuevo.
- Apuntar a NULO el campo de enlace del nuevo nodo.
- Apuntar a nuevo nodo el campo de enlace de FINAL. 
- FINAL ahora apunta al nuevo nodo. 

Remover:
Final:
Localizar el nodo final y su anterior.
Tomar e informar la información del nodo a extraer.
Apuntar a NULO el enlace del nodo anterir.

Intermedio:
Localizar el nodo a extraer, conservando el nodo anterior.
Tomar el informar la información a extraer.
Apuntar al enlace de ndoo anterior al nodo que sigue al extraído.

*/

struct Nodo{
  int data;
  Nodo* next;
}; 

class List{
private:
  Nodo* nodo, *head;
public:
  int insertar(int); 
};

enum class Opcion{
  INSERTAR,
};

Opcion enterOption();
void menu();

#endif
