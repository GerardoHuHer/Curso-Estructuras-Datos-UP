#pragma once
#include <iostream>
#define TAM 5

class Pilas{
private:
  int* original;
  int max, min, tope;
public:
  Pilas();
  int push(int);
  int pop();
  void mostrar();
};

void menu();
int depurar(Pilas original, Pilas dep, int num);
