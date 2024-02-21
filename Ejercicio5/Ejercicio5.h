#pragma once
#include <iostream>
#include <string>

/*
Empleando C++ construya una aplicación que:
a) Lea un nombre con apellidos, Declare y lea un arreglo de enteros, dinámico de dos dimensiones
b) Muestre el nombre leído, Empleando apuntadores muestre el arreglo de enteros.
c) Ordene ascendentemente (de mayor a menor) cada renglón del arreglo y muestre todos los renglones
*/

class Arreglo{
public:
  Arreglo();
  void show();
  void sort();
  void insert();
  void namefn();
private:
  std::string name;
  int** arr;
  int row;
  int col;
};
