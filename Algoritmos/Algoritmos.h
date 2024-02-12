#pragma once
#include <iostream>
#define TAM 8

class Arreglo{
private:
  int arr[TAM] = {1,2,3,4};
  int ocupados = 4;
public:
  // Arreglo();
  int borrar(int);
  void bubble_sort();
  int insertar(int);
  void mostrar();
  void llenado();
};

void menu();
