#pragma once
#include <iostream>
#include <string>

struct Camion {
  std::string placas;
  std::string producto;
  Camion *sig;
};

class Cola {
private:
  Camion *inicio, *final;
  Camion *nodo;
public:
  Cola();
  void insertar(const Camion&);
  std::string extraer();
  void mostrar();
};

void menu();
