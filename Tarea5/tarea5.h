#pragma once
#include <iostream>
#define TAM 15

struct Boleto {
  std::string nombre;
  int no_boleto;
  bool descuento;
};

class Cola {
private:
  Boleto *boletos;
  int maxi, mini;
  int principio, final;
public:
  Cola();
  int insertar();
  Boleto extraer();
  void mostrar();
};
