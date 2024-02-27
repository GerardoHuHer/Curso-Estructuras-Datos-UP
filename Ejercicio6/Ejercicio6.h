#pragma once
#include <iostream>
#define TAM 5

class PilaEnteros{
public:
  PilaEnteros();
  int push(int);
  int pop();
  void show();
  int consultar();
private:
  int min, max, tope;
  int* pila;
};

void menu();


