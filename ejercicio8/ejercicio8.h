#pragma once
#include <iostream>
#define TAM 5

/*
Empleand C++ construye una aplicación que permita Inserta y Extraer palabras en
una cola secuencial, mediante la implementación estática de TDA Cola, o sea,
implementada mediante arreglos. También debe ofrecer la opción de mostrar el
arreglo completo y los páramentros de la fila
*/

class Estructura {
public:
  std::string extraer();
  int insertar(std::string);
  void mostrar();
  Estructura();
private:
  std::string cola[TAM];
  int principio, final;
  int maximo, minimo;
};

void menu();

