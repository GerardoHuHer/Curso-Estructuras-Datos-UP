#pragma once
#include <iostream>
#include <string>
#define TAM 8

using namespace std;

/*Empleando C++, construye una aplicación orientada a objetos que contenga un arreglo con los empleados de una empresa, conteninedo para cada uno, nombre, estatura en centímetros y sueldo semanal.
Inicializar en desorden, mostrar el arreglo.
Ordenar alfabéticamente el arreglo, de la A a la Z, por el método de la búrbuja y mostrarlo.
Ofrecer las opciones insertar y borrar, con base en el nombre.
*/
struct Empleado{
  string nombre;
  int estatura;
  double sueldo;

};

class Arreglo{
private:
  int ocupados;
  Empleado arr[TAM];
public:
  Arreglo();
  int borrar(string);
  int insertar(Empleado);
  void bubble_sort();
  void mostrar();
  int llenado();
};

Empleado crearEmp();
  

void menu();

