#pragma once
#include <iostream>
using namespace std;
/*
INSERTAR
1) Crear nodo.
2) nodo.dat = datos
3) Nodo.sig = NULL
4) Si princ == NULL
  princ = nodo
5) Si final!= NULL
  final.sig = nodo
6) final = nodo
EXTRAER
1) Si princ == Null -> Está vacía  
2) nodo = princ
3) Tomar nodo.dat
4) princ = nodo.sig
5) si princ=null
6) liberar nodo
*/


struct Entero {
  int num;
  Entero *sig;
};

class ColaLigada {
private:
  Entero* nodo;
  Entero* inicio, *final;
public:
  ColaLigada();
  int consultar();
  int extraer();
  void insertar(int);
  void mostrar();
};

void menu();
