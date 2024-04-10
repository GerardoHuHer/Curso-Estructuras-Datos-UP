#ifndef EJERCICIO12_H
#define EJERCICIO12_H
#include <iostream>
#include <string>

enum class Option {
  INSERTAR_INICIO = 1,
  INSERTAR_FINAL,
  INSERTAR,
  DISPLAY,
  EXIT
};

Option enter_option();
void menu();

struct Nodo {
  std::string dato;
  Nodo *sig;
};

class Lista {
private:
  Nodo* final, *head;
  Nodo* nodo;
public:
  Lista();
  void insertar_inicio(const std::string&);
  int insertar_intermedio(std::string, std::string);
  int insertar_final(std::string);
  void display();
};

#endif
