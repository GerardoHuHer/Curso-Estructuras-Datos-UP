#ifndef GRAFOS_H
#define GRAFOS_H
#include <iostream>

class MatrizAdy {
private:
  int buscar_nodo(char);
  char* nodos;
  int** arcos;
  int max_nodos, ocupados, pos_origen, pos_destino, peso;
public:
  MatrizAdy(int);
  int insertar_nodo(char);
  int insertar_ady(char, char, int); // origen, destino, peso
  void mostrar();
};

#endif
