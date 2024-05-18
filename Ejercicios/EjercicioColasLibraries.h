#ifndef EJERCICIOCOLASLIBRARIES_H
#define EJERCICIOCOLASLIBRARIES_H
#include <iostream>
#include <queue>

enum class Option{
  Formar = 1,
  Extraer,
  Mostrar,  
  Salir,
};

Option get_option();
void menu();

#endif
