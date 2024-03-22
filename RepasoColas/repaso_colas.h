#ifndef REPASO_COLAS_H
#define REPASO_COLAS_H
#include <iostream>
#include <string>

struct Nodo {
  std::string autor;
  std::string titulo;
  Nodo *sig;
};

class Cola {
private:
  Nodo *inicio, *final;
  Nodo *nodo;
public:
  Cola();
  void insertar(Nodo);
  std::string extraer();
  void mostrar();
};

void menu();

#endif
