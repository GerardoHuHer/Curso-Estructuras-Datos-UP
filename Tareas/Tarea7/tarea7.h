#ifndef TAREA7_H
#define TAREA7_H
#include <iostream>

enum class Option {
  INSERTAR = 1,
  EXTRAER,
  EXTRAER_INICIO,
  EXTRAER_FINAL,
  DISPLAY,
  EXIT
};

const Option enter_option();
void menu();

struct Nodo {
  int dato;
  Nodo *sig;
};

class Lista {
private:
  Nodo* final, *head;
  Nodo* nodo;
public:
  Lista();
  void insertar_intermedio(const int&);
  void insertar_final(const int&);
  void insertar_inicio(const int&);
  const int extraer_inicio();
  const int extraer_final();
  const int extraer_intermedio(const int&);
  void display();
};

#endif
