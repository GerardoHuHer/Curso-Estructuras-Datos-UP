#pragma once
#include <iostream>
#define TAM 6
/*
Empleando C++ crea una clase que implemente el TDA Fila de palabras en su
versión circular. Contruye una aplición que genere un objeto de la clase fila y
que haga lo siguiente. Cree una cola circular "C" de 6 elementos. Inicialmente
la cola está vacía. Muestre el estado de C luego realizar cada una de las
siguientes operaciones. 1) Insertar los elementos AA, BB y CC 2) Extraer el
elemento AA 3) Insertar los elementos DD, EE y FF. 4) Insertar el elemento GG 5)
Insertar el elemento HH 6) Extraer los elementos BB y CC ¿Con cuántos elementos
quedo C? ¿Hubo algún caso de error (desbordamiento o subdesbordamientos) en tal
caso expliquelo
*/

class ColaCirular {
private:
  int minimo, maximo;
  int inicio, final;
  std::string* palabras;
public:
  ColaCirular();
  int insertar(std::string);
  std::string extraer();
  void mostrar();
};
