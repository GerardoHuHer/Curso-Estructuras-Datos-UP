#ifndef EJERCICIO15_H
#define EJERCICIO15_H
#include <iostream>

// ENUM CLASS for every option in menu
enum class Option{
  INSERTAR_INICIO = 1,
  INSERTAR_INTER,
  INSERTAR_FINAL,
  EXTRAER_INICIO = 1,
  EXTRAER_INTER,
  EXTRAER_FINAL,
  DISPLAY,
  SALIR
};

// FUNCTIONS
Option enter_option();
void menu();

// node struct
struct Nodo{
  std::string palabra;
  Nodo* sig, *prev;
};

// List class
class Lista{
public:
  Lista();
  void display();
  void insertar_inicio(const std::string&);
  void insertar_intermedio(const std::string&, const std::string&);
  void insertar_final(const std::string&);
  std::string extraer_inicio();
  std::string extraer_intermedio(const std::string&);
  std::string extraer_final();
private:
  Nodo* head, *final;
  Nodo* nodo;
};

#endif
