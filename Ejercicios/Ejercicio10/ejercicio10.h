#pragma once
#include <iostream>
#include <ostream>
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
  friend std::ostream& operator<<(std::ostream& os, const Cola& a);
};



void menu(); 

template<typename T> 
void mostrar(const T& a);
