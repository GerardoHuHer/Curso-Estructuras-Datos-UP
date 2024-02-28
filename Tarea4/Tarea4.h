#pragma once
#include <iostream>
#define TAM 5

class Pilas{
private:
  int* original, depurada;
  int maxo, mino, topeo;
  int maxd, mind, toped;
public:
  int push(int);
  int pop();
  void popd();
  void pushd(int);
  void mostrar();
  void mostrard();
  int depurar();
};
