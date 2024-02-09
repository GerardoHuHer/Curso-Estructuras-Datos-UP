#pragma once
#include <iostream>
#include <string>

/*¿Qué es un registro?
Es un tipo de dato estructurado que consiste en un conjunto finito de elementos.
Difiere de los arreglos en que sus elementos pueden ser de diferente tipo.
A cada elemento del registro se le llama campo. Cada campo tiene un nombre único, por lo tanto, otra diferencia respecto a los arreglos es que a los campos se les llama por su nombre y no por su posición (índice) dentro de la estructura.
A los registros también se les conoce como estructuras.*/

//Ejemplo Aplicación que genere un registro de mascota con los campos nombre y edad
struct Mascota{
  std::string nombre;
  int edad;
};
//Ejemplo 2: Aplicación que genere una lista de alumnos, nombre, edad y tres calificaciones pida el nombre del alumno y lo busca en la lista. En caso de existir muestra sus calificaciones.
struct Alumno{
  std::string nombre;
  int edad;
  int calif[3];
  void mostrar();
};
