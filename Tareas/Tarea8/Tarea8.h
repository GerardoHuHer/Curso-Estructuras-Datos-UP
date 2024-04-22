#ifndef TAREA8_H
#define TAREA8_H
#include <iostream>
#include <string>

using namespace std;

struct Nodo {
  string dato;
  Nodo *sig;
};

class Lista {

public:
  Lista();
  void insertar_inicio(const string&);
  void insertar_final(const string&);
  bool extraer_impares();
  string extraer_pos(const int&);
  void display();
  int getSize();

private:
  Nodo *cabecera, *final;
  Nodo* nodo;
  int numNodos;
};

void menu();
void mostrar_valor(const string&, const int&);

#endif
