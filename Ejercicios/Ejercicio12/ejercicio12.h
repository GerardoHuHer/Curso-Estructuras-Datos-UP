#ifndef EJERCICIO12_H
#define EJERCICIO12_H
#include <iostream>
#include <string>

enum class Option {
  INSERTAR_INICIO = 1,
  INSERTAR_FINAL,
  INSERTAR,
  EXTRAER_INICIO,
  EXTRAER_FINAL,
  EXTRAER,
  DISPLAY,
  EXIT
};

const Option enter_option();
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
  const int insertar_intermedio(const std::string&, const std::string&);
  const int insertar_final(const std::string& );
  const std::string extraer_inicio();
  const std::string extraer_intermedio(const std::string&);
  const std::string extraer_final();
  void display();
};

#endif
