#pragma once
#include <iostream>
#include <string>

struct Frase {
  std::string frase;
  Frase *sig;
};

class Cola {
private:
  Frase *final, *inicio;
  Frase *nodo;

public:
  Cola();
  std::string consultar();
  std::string extraer();
  void insertar(std::string);
  void mostrar();
};

void menu(); 
