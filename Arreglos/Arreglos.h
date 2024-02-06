#pragma once
#include <iostream>
#include <string>
#define TAM 8
using namespace std;

class Arreglo{
public:
  // Arreglo();
  // ~Arreglo();
  void MostrarEnteros();
  void MostrarPalabras();
  void OrdenarEnteros_burbuja();
  void OrdenarPalabras_burbuja();
private:
  int enteros[TAM] = {15,21, 6, 19, 14, 18, 3};
  int ocupadosEnteros = 7;
  string palabras[TAM] {"salón", "burro", "torre", "mesa", "casa"};
  int ocupadosPalabras = 5;
};
