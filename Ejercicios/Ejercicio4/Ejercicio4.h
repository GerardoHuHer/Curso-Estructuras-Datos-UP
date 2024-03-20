#pragma once
#include <iostream>
#include <string>
#define TAM 6

// Escribir con C++ el código de un algoritmo que genere un conjunto de registros que almacene las sucursales de una cadena de tiendas.
// Debe almacenar el número de la sucursal, el nombre del gerente y el importe de ventas de los últimos dos meses (empleando arreglos).
// Que las ordene en forma ascendente de acuerdo al número de sucursal, empleando el método de la búrbuja.

struct Sucursal{
  int num_sucursal;
  std::string gerente;
  double ventas[2];
  void mostrar();
};

class Arreglo{
private:
  Sucursal obj[TAM];
  int ocupados;
public:
  Arreglo();
  void bubble_sort();
  void mostrar();
  int llenado();
};

void menu();
  

