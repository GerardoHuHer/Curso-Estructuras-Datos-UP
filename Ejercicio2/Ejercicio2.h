#pragma once
#include <iostream>
#define TAM 8

class Arreglo{
  private: 
    int enteros[TAM] = {3,6,9,12}; 
    int ocupados {4};
  public:  
    int insertar(int);
    void mostrar();
  };

