#ifndef LISTASCIRCULARES_H
#define LISTASCIRCULARES_H
#include <iostream>


enum class Option{
  INSERTAR = 1,
  BUSCAR,
  MOSTRAR,
  MOSTRAR_FINAL,
  SALIR
};

Option enter_option();

struct Nodo {
  int dato;
  Nodo* sig;
};

class Lista{
private:  
  Nodo* head, *final;
  Nodo* revisado;
  Nodo* nodo;
public:
  Lista();
  void insertar_final(const int&);
  bool busqueda(const int&);
  void extraer_inicio();
  void extraer_final();
  void extraer_inter();
  void extraccion_impares();
  void display_inicio();
  void display_revisado();
};


void menu();
#endif

