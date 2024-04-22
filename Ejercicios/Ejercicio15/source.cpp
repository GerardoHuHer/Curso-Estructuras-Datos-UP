#include "Ejercicio15.h"
int main() {
  // menu();
  std::string word;
  Lista lista = Lista();
  lista.insertar_inicio("Primera");
  lista.display();
  word = lista.extraer_inicio();
  std::cout << word << std::endl;
  word = lista.extraer_inicio();
  if (word == "") {
    std::cout << "La lista está vacía "<< std::endl;
  }
  // lista.insertar_inicio("a");
  // lista.insertar_inicio("b");
  // lista.insertar_inicio("c");
  // lista.insertar_inicio("d");
  // lista.display();
  // lista.insertar_final("a1");
  // lista.insertar_final("a2");
  // lista.insertar_final("a3");
  // lista.insertar_final("a4");
  // lista.display();
  // lista.insertar_intermedio("Prueba","a1");
  // lista.insertar_intermedio("Prueba2","aq41");
  // lista.display();
  // std::string word = lista.extraer_inicio();
  // std::cout << word << std::endl;
  // lista.display();
  return 0;
}
