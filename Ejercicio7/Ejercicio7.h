#pragma once
#include <iostream>
#include <string>

/*
Empleando C++ construye una aplicación qué:
Permita contratar y desocupar empleados mediante el esquema LIFO, empleando para ello una pila y sus operaciones.
La información de cada empleado es su clave, nombre y suelo.
*/

struct Persona{
  int clave;
  std::string nombre;
  double sueldo;
  Persona* anterior;
};


class Pila{
private:
  Persona* tope, *nodo;
public:
  Pila();
  void Ingresar(Persona);
  Persona Extraer();
  void Mostrar();
};

void menu();
